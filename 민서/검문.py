import sys;sys.setrecursionlimit(1<<30)
input = open(0).readline
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)
arr = [int(input()) for _ in range(int(input()))]
arr = sorted(arr)
arr = [n - arr[0] for n in arr[1:]]
ans = arr[0]
for n in arr[1:]:
    ans = gcd(ans, n)
arr = []
i = 2
while i * i < ans:
    if ans % i == 0:
        arr.append(i)
    i += 1
if i * i == ans:
    arr = arr + [i] + [ans // n for n in reversed(arr)] + [ans]
else:
    arr = arr + [ans // n for n in reversed(arr)] + [ans]
print(*arr)
