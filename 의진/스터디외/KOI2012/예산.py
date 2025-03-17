import sys

input = sys.stdin.readline

N = int(input())
requests = list(map(int, input().split()))
limit = int(input())

start = 0
end = limit


def do_test(mid):
    global limit
    return sum(min(r, mid) for r in requests) <= limit


while start <= end:
    mid = (start + end) // 2
    if do_test(mid):
        start = mid + 1
    else:
        end = mid - 1

print(min(max(requests, key=lambda x: min(x, end)), end))
