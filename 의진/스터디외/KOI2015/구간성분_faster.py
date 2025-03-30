import sys

input = sys.stdin.readline

a = input().strip()
b = input().strip()
n = len(a)
m = len(b)

st = set()

for i in range(n):
    cnt = [0] * 26
    for j in range(i, n):
        cnt[ord(a[j]) - ord("a")] += 1
        st.add(tuple(cnt))

ans = 0

for i in range(m):
    cnt = [0] * 26
    for j in range(i, m):
        cnt[ord(b[j]) - ord("a")] += 1
        if tuple(cnt) in st:
            ans = max(ans, j - i + 1)
print(ans)
