input = open(0).readline
code = input().rstrip()
N = len(code)
memo = [0] * (N + 1)
memo[0] = 1
S = set()
for i in range(1, 26 + 1):
    S.add(f"{i}")
if code[0] in S:
    memo[1] = 1
for i in range(1, N):
    if code[i] in S:
        memo[i + 1] += memo[i]
        memo[i + 1] %= 1000000
    if code[i - 1:i + 1] in S:
        memo[i + 1] += memo[i - 1]
        memo[i + 1] %= 1000000
print(memo[N])
