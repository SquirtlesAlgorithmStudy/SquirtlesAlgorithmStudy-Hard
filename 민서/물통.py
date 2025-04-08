input = open(0).readline
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def solve(A, B, a, b):
    if 0 < a < A and 0 < b < B:
        return -1
    g = gcd(A, B)
    if a % g > 0 or b % g > 0:
        return -1
    A, B = A // g, B // g
    a, b = a // g, b // g
    if a == 0 and b == 0:
        return 0
    if a == 0 and b == B:
        return 1
    if a == A and b == 0:
        return 1
    if a == A and b == B:
        return 2
    if a == A:
        case = 0
        target = b
    elif a == 0:
        case = 1
        target = b
    elif b == 0:
        case = 2
        target = a
    elif b == B:
        case = 3
        target = a
    ans = 0
    n = B
    while n != target:
        ans += 4 if n < A else 2
        n = (n - A) % B
    ans += case
    return min(ans, B * 2 + A * 2 - 1 - ans)

A, B, a, b = map(int, input().split())
print(solve(A, B, a, b))
