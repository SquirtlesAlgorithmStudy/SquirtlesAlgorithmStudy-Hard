def solution(n, works):
    if sum(works) <= n:
        return 0
    def work_value(cut):
        res = 0
        for w in works:
            res += max(0, w - cut)
        return res
    l, r = 0, max(works)
    while l + 1 < r:
        m = (l + r) // 2
        if work_value(m) > n:
            l = m
        else:
            r = m
    remain = n - work_value(r)
    works = sorted(works)
    answer = 0
    i = 0
    while works[i] < r:
        answer += works[i] * works[i]
        i += 1
    equals = len(works) - i
    answer += (equals - remain) * r * r
    answer += remain * (r - 1) * (r - 1)
    return answer
