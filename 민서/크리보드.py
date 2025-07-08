N = int(input())
memo = [i for i in range(N + 1)]
for i in range(1, N + 1):
    for j in range(2, 6):
        if i + j + 1 < N + 1:
            memo[i + j + 1] = max(memo[i + j + 1], memo[i] * j)
print(memo[N])
