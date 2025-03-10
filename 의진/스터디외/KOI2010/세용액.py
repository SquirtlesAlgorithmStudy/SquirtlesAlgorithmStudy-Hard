import sys


def main():
    input = sys.stdin.readline
    N = int(input())
    seq = list(map(int, input().split()))
    seq.sort()
    opt = float("inf")
    res = None
    for most_left in range(N - 2):
        anchor = seq[most_left]
        start = most_left + 1
        end = N - 1

        while start < end:
            left_liq = seq[start]
            right_liq = seq[end]
            sum_val = left_liq + right_liq + anchor
            if opt > abs(sum_val):
                opt = abs(sum_val)
                res = anchor, left_liq, right_liq

            if sum_val == 0:
                print(res[0], res[1], res[2])
                return

            elif sum_val < 0:
                start += 1
            else:
                end -= 1

    print(res[0], res[1], res[2])


if __name__ == "__main__":
    main()
