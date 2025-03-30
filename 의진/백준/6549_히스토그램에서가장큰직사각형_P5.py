import sys

input = sys.stdin.readline


def get_answer(start_idx, end_idx):
    if end_idx == start_idx:
        return histogram[start_idx]
    elif end_idx - start_idx == 1:
        if histogram[end_idx] < histogram[start_idx]:
            return max(2 * histogram[end_idx], histogram[start_idx])
        else:
            return max(2 * histogram[start_idx], histogram[end_idx])

    else:
        divide_idx = (start_idx + end_idx) // 2
        left = get_answer(start_idx, divide_idx)
        right = get_answer(divide_idx + 1, end_idx)

        ptr_l = divide_idx - 1
        ptr_r = divide_idx + 1
        height = histogram[divide_idx]
        width = 1
        mid = height

        while start_idx <= ptr_l and ptr_r <= end_idx:
            if histogram[ptr_l] < histogram[ptr_r]:
                if histogram[ptr_r] < height:
                    height = histogram[ptr_r]
                width += 1
                mid = max(mid, width * height)
                ptr_r += 1
            else:
                if histogram[ptr_l] < height:
                    height = histogram[ptr_l]
                width += 1
                mid = max(mid, width * height)
                ptr_l -= 1

        while start_idx <= ptr_l:
            if histogram[ptr_l] < height:
                height = histogram[ptr_l]
            width += 1
            mid = max(mid, width * height)
            ptr_l -= 1

        while ptr_r <= end_idx:
            if histogram[ptr_r] < height:
                height = histogram[ptr_r]
            width += 1
            mid = max(mid, width * height)
            ptr_r += 1

        return max(left, right, mid)


while True:
    test_case = list(map(int, input().split()))
    if test_case[0] == 0:
        break
    histogram = test_case[1:]
    answer = get_answer(0, len(histogram) - 1)

    print(answer)
