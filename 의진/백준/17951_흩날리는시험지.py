import sys

input = sys.stdin.readline

N, K = map(int, input().split())


nums = list(map(int, input().split()))


def do_test(mid):
    count = K
    v = 0

    for i, num in enumerate(nums):
        if count == 1:
            if sum(nums[i:]) >= mid:
                return True
            else:
                return False
        v += num
        if v >= mid:
            v = 0
            count -= 1
    return False


if K == 1:
    print(sum(nums))
else:
    start = 0
    end = sum(nums)

    while start <= end:
        mid = (start + end) // 2
        if do_test(mid):
            start = mid + 1

        else:
            end = mid - 1

    print(end)
