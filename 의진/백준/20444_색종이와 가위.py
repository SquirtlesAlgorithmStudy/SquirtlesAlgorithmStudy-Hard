import sys
import math as m


def quadratic_formula(cut, rect):
    poly = cut**2 + 4 * cut - 4 * rect + 4
    # cut == n
    # rect == k

    if poly < 0:
        print("NO")
        return
    # 1.1   1 != 1.1
    if int(poly) != poly:
        print("NO")
        return

    if int((poly ** (1 / 2))) ** 2 != poly:
        print("NO")
        return

    result1 = (cut + 2 + (poly ** (1 / 2))) / 2
    result2 = (cut + 2 - (poly ** (1 / 2))) / 2

    if int(result1) != result1 or int(result2) != result2:
        print("NO")
        return

    if (result1 > 0) and (result2 > 0):
        print("YES")
        return
    else:
        print("NO")
        return


n, k = map(int, sys.stdin.readline().split())
quadratic_formula(n, k)
