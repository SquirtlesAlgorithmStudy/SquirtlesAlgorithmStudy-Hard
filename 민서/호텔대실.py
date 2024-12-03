import heapq as hq
def solution(book_time):
    def HM2M(string):
        h, m = string.split(":")
        return int(h) * 60 + int(m)
    book_time = [[HM2M(s), HM2M(e) + 10] for s, e in book_time]
    book_time = sorted(book_time)
    answer = 0
    que = []
    for s, e in book_time:
        while que and que[0] <= s:
            hq.heappop(que)
        hq.heappush(que, e)
        answer = max(len(que), answer)
    return answer
