def solution(n):
    arr = [0] * n
    arr[0] = 1
    for i in range(n - 1):
        for j in range(i):
            arr[j + 1] += arr[j]
        arr[i + 1] = arr[i]
    return sum(arr)
