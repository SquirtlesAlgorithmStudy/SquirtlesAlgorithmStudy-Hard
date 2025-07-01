import io, os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
def main():
    N, K = map(int, input().split())
    arr = [*map(int, input().split())]
    ans = arr[N - 1] - arr[0]
    if K == 1:
        print(ans)
        return
    arr = sorted(arr[i + 1] - arr[i] for i in range(N - 1))
    print(ans - sum(arr[1 - K:]))
main()
