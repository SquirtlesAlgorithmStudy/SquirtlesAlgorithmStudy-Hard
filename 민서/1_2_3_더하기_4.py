input = open(0).readline
def main():
    memo = [0] * 10001
    memo[0] = 1
    memo[1] = 1
    memo[2] = 2
    for i in range(3, 10001):
        memo[i] = memo[i - 3] + i//2 + 1
    T = int(input())
    for _ in range(T):
        print(memo[int(input())])
main()
#=====================================================
input = open(0).readline
def main():
    T = int(input())
    for _ in range(T):
        n = int(input())
        ans = n//6 * (n//6*3 + n%3)
        ans += (n//2 + 1) if n%6 < 3 else n
        print(ans)
main()
