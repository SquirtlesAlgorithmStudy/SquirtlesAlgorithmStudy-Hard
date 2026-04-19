input = open(0).readline
N = int(input())
H = [*map(int, input().split())]
arr = []
for i in range(N):
    for j in range(i + 1, N):
        arr.append((H[i] + H[j], i, j))
arr = sorted(arr)
mn = 1<<30
L = len(arr)
for i in range(L):
    j = i + 1
    while j < L and (
        arr[i][1] == arr[j][1] or
        arr[i][1] == arr[j][2] or
        arr[i][2] == arr[j][1] or
        arr[i][2] == arr[j][2]
    ):
        j += 1
    if j == L:
        continue
    diff = abs(arr[i][0] - arr[j][0])
    if diff < mn:
        mn = diff
print(mn)
