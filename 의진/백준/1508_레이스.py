import sys

input = sys.stdin.readline

N, M, K = map(int, input().split())
pos = list(map(int, input().split()))

start = 0
end = N


def do_test(mid):
    result = [1] + [0] * (len(pos) - 1)
    cnt = M - 1
    # print(f"=============={mid}=============")
    dist = 0
    for i in range(len(pos) - 1):
        if dist + pos[i + 1] - pos[i] >= mid:
            result[i + 1] = 1
            cnt -= 1
            dist = 0

            if cnt == 0:
                return True, "".join(map(str, result))
        else:
            dist += pos[i + 1] - pos[i]
    return False, None


while start <= end:
    mid = (start + end) // 2
    if do_test(mid)[0]:
        start = mid + 1
    else:
        end = mid - 1


print(do_test(end)[1])
