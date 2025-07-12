input = open(0).readline
input()
input()
arr = sorted(map(int, input().split()), reverse=True)
ans = 0
for n in arr:
    ans += n
    print(ans)
