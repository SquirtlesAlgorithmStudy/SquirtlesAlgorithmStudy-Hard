import sys

input = sys.stdin.readline


def main():
    N, a, b = map(int, input().split())

    if a + b - 1 > N:
        return [-1]

    result = [1] * N

    if a == 1 or b == 1:
        if a == b:
            return result
        else:
            return [-1]

    if a <= b:
        for i in range(b):
            result[-i] = i
        cnt = a - 1
        for i in range(b, b + a - 2):
            result[-i] = cnt
            cnt -= 1

    else:
        cnt = 2
        for i in range(N - (a + b - 2), N - (a + b - 2) + (a)):
            result[i] = cnt
            cnt += 1

        cnt = 1
        for i in range(N - 1, 0, -1):
            if result[i] != 1:
                break
            result[i] = cnt
            cnt += 1

    return result


print(main())
print(" ".join(main()))
