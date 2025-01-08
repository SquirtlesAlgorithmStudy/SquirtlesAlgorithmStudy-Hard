def solution(arr, k):
    for i in range(len(arr) - k % len(arr)):
        arr[i], arr[i + k % len(arr)] = arr[i + k % len(arr)], arr[i]

    return arr


print(solution([1, 2, 3, 4, 5, 6], 7))
