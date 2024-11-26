def solution(word, pages):
    import re
    n_pages = len(pages)
    url2idx = {}
    link_lists = [[] for _ in range(n_pages)]
    basic_score = [0] * n_pages
    for i, p in enumerate(pages):
        url = re.search('<meta property="og:url" content="(.+?)"/>', p).group(1)
        url2idx[url] = i
    for i, p in enumerate(pages):
        link_lists[i] = [url2idx[l] if l in url2idx else -1 for l in re.findall('<a href="(.+?)">', p)]
        new_p = re.sub('[^A-Za-z]', ' ', p)
        basic_score[i] = len(re.findall(rf"\b{word}\b", new_p, flags=re.IGNORECASE))
    matching_score = basic_score[:]
    for i, links in enumerate(link_lists):
        for j in links:
            if j >= 0:
                matching_score[j] += basic_score[i] / len(links)
    answer = 0
    mx = 0
    for i, s in enumerate(matching_score):
        if s > mx:
            mx = s
            answer = i
    return answer
