import sys
import bisect

input = sys.stdin.readline


N, Q = map(int, input().split())
pos_dict = {}
x_dict = {}
y_dict = {}
ps_x_dict = {}
ps_y_dict = {}
for _ in range(N):
    x, y, w = map(int, input().split())
    if x_dict.get(x) is not None:
        x_dict[x].append((y, w))
    else:
        x_dict[x] = [(y, w)]

    if y_dict.get(y) is not None:
        y_dict[y].append((x, w))
    else:
        y_dict[y] = [(x, w)]

for k in x_dict.keys():
    x_dict[k].sort()
    temp = [0]
    for i, item in enumerate(x_dict[k]):
        temp.append(temp[i] + item[1])
    ps_x_dict[k] = temp


for k in y_dict.keys():
    y_dict[k].sort()
    temp = [0]
    for i, item in enumerate(y_dict[k]):
        temp.append(temp[i] + item[1])
    ps_y_dict[k] = temp

current = [1, 1]

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
answer = 0


def bisect_tuple_left(a, x):
    lo, hi = 0, len(a)
    while lo < hi:
        mid = (lo + hi) // 2
        if a[mid][0] < x:  # 튜플의 첫 번째 요소 기준
            lo = mid + 1
        else:
            hi = mid
    return lo


def bisect_tuple_right(a, x):
    lo, hi = 0, len(a)
    while lo < hi:
        mid = (lo + hi) // 2
        if a[mid][0] <= x:  # 튜플의 첫 번째 요소 기준
            lo = mid + 1
        else:
            hi = mid
    return lo


for _ in range(Q):
    d, v = map(int, input().split())
    start_x = current[0]
    start_y = current[1]
    end_x = current[0] + dx[d] * v
    end_y = current[1] + dy[d] * v

    if d == 0:
        if y_dict.get(end_y) is not None:
            left_idx = bisect_tuple_right(y_dict[end_y], start_x)
            right_idx = bisect_tuple_right(y_dict[end_y], end_x)

            answer += ps_y_dict[end_y][right_idx] - ps_y_dict[end_y][left_idx]
    elif d == 1:
        if x_dict.get(end_x) is not None:
            left_idx = bisect_tuple_right(x_dict[end_x], start_y)
            right_idx = bisect_tuple_right(x_dict[end_x], end_y)

            answer += ps_x_dict[end_x][right_idx] - ps_x_dict[end_x][left_idx]
    elif d == 2:
        if y_dict.get(end_y) is not None:
            left_idx = bisect_tuple_left(y_dict[end_y], end_x)
            right_idx = bisect_tuple_left(y_dict[end_y], start_x)

            answer += ps_y_dict[end_y][right_idx] - ps_y_dict[end_y][left_idx]
    elif d == 3:
        if x_dict.get(end_x) is not None:
            left_idx = bisect_tuple_left(x_dict[end_x], end_y)
            right_idx = bisect_tuple_left(x_dict[end_x], start_y)

            answer += ps_x_dict[end_x][right_idx] - ps_x_dict[end_x][left_idx]

    # print(current)
    current[0] += dx[d] * v
    current[1] += dy[d] * v
    # print(current)
    # print(answer)

print(answer)
