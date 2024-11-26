import re


def solution(word, pages):
    url2idx = {}
    move_data = [[[], []] for _ in range(len(pages))]
    scores = [0] * len(pages)

    for i, page in enumerate(pages):
        # 1. 페이지 주소 가져오기
        # page_url = re.search('<meta property="og:url" content="(\S+)"', page).group(1) -> 정규표현식 버전
        # page_url = page.split('"og:url" content="')[1].split('"/>')[0] -> 틀림 : "og.url"이라는게 다른 곳에 있으면 털림
        page_url = page.split('<meta property="og:url" content="')[1].split('"/>')[0]
        url2idx[page_url] = i

    for i, page in enumerate(pages):
        # 2. body 부분 추출
        body = page.split("<body>")[1].split("</body>")[0]

        # 3. 링크 추출
        # exiosLink = re.findall('<a href="(.+)">', '<a href="https://rerfdb"> test="dfdqom">') -> 뒤에 >가 있으면 틀림
        # exiosLink = re.findall('<a href="(https://[\S]*)"', page) -> 이렇게 해야함
        links = list(map(lambda x: x.split('">')[0], body.split('<a href="')[1:]))
        # links = body.split('<a href="')[1:]

        # 4. link 반영
        for link in links:
            if url2idx.get(link) is not None:
                move_data[i][1].append(
                    url2idx[link]
                )  # [1] = 이 페이지에서 어디 페이지로 가냐
                move_data[url2idx[link]][0].append(i)  # [0] = 이 페이지로 오는 페이지들
            else:
                move_data[i][1].append("x")

        # # 5. text 추출
        # texts = list(
        #     map(lambda x: x.split("<a href")[0].lower().strip(), body.split("</a>"))
        # )

        # 6. 기본점수 계산
        for w in re.findall("[a-z]+", page.lower()):  # 페이지 전체에서 단어검색
            if w == word.lower():
                scores[i] += 1

    # print(scores)
    cur_max_score = 0
    cur_max_i = 0
    for i in range(len(pages)):
        final_score = 0
        final_score += scores[i]

        for adjacent in move_data[i][0]:
            final_score += scores[adjacent] / len(move_data[adjacent][1])

        if cur_max_score < final_score:
            cur_max_score = final_score
            cur_max_i = i

    return cur_max_i
