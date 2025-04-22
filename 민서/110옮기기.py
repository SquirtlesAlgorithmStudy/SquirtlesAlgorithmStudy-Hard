def solve(s):
    stack = []
    n_110 = 0
    for c in s:
        if c == "0" and len(stack) >= 2 and stack[-1] == "1" and stack[-2] == "1":
            stack.pop()
            stack.pop()
            n_110 += 1
        else:
            stack.append(c)
    s = stack
    cnt = 0
    idx = None
    for i, c in enumerate(s):
        if c == "1":
            cnt += 1
        else:
            cnt = 0
        if cnt == 3:
            idx = i - 2
    if idx is None:
        idx = len(s) - cnt
    return "".join(s[:idx]) + "110" * n_110 + "".join(s[idx:])
def solution(s):
    answer = [solve(x) for x in s]
    return answer
