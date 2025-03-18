input = open(0).readline
N = int(input())
arr = [*map(int, input().split())]
s = sum(arr[1::2])
mx = s
for i in range(N // 2):
    s += arr[2 * i] - arr[2 * i + 1]
    if s > mx:
        mx = s
s = sum(arr[::2])
for i in reversed(range(1, N // 2)):
    s += arr[2 * i - 1] - arr[2 * i]
    if s > mx:
        mx = s
print(mx)
