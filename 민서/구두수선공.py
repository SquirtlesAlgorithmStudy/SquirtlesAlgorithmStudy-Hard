input = open(0).readline
N = int(input())
arr = []
for i in range(1, N + 1):
    t, s = map(int, input().split())
    arr.append((t/s, i))
arr = sorted(arr)
arr = [i for _, i in arr]
print(*arr)
