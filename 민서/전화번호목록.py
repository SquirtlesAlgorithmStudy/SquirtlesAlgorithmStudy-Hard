input = open(0).readline
def solve(arr, N):
    for i in range(1, N):
        if len(arr[i - 1]) >= len(arr[i]):
            continue
        if arr[i][:len(arr[i - 1])] == arr[i - 1]:
            return False
    return True
def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        arr = [input().rstrip() for _ in range(N)]
        if solve(sorted(arr), N):
            print("YES")
        else:
            print("NO")
main()
