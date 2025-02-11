import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N = int(input())
    ans = [0, 0, 0, 0, 0]
    ans[0] += N // 60
    N %= 60
    if N <= 35:
        if N % 10 <= 5:
            ans[1] += N // 10
            ans[3] += N % 10
        else:
            ans[1] += (N // 10) + 1
            ans[4] += 10 - (N % 10)
    else:
        ans[0] += 1
        if N % 10 < 5:
            ans[2] += 6 - (N // 10)
            ans[3] += N % 10
        else:
            ans[2] += 5 - (N // 10)
            ans[4] += 10 - (N % 10)

    print(*ans)
