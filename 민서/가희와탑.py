def main():
    N, a, b = map(int, input().split())
    if a + b > N + 1:
        print("-1")
        return
    if a < b:
        arr = [*range(1, a)] + [*range(b, 0, -1)]
    else:
        arr = [*range(1, a + 1)] + [*range(b - 1, 0, -1)]
    print(arr[0], end=" ")
    print("1 " * (N - len(arr)), end="")
    print(*arr[1:])
main()
