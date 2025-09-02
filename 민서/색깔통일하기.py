input = open(0).readline
def main():
    N, C = map(int, input().split())
    arr = [*map(int, input().split())]
    left = [0] * N
    right = [0] * N
    for i in range(1, N):
        left[i] = left[i - 1] + (arr[i - 1] - arr[i]) % C
    for i in range(N - 2, -1, -1):
        right[i] = right[i + 1] + (arr[i + 1] - arr[i]) % C
    mn = right[0]
    idx = 0
    for i in range(1, N):
        if max(left[i], right[i]) < mn:
            idx = i
            mn = max(left[i], right[i])
    print(idx + 1)
    print(mn)
main()
