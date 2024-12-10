from collections import deque


def solution(stones, k):
    dq = deque()
    max_values = []

    # 덱은 반드시 인덱스는 증가하고, 값은 단조 감소한다.
    # 작업 순서
    # 1. 조건 맞을 때 까지 큐 비우기
    # 2. 그 위치에 원소 넣기
    # 3. 윈도우 벗어나는 queue 값 제거
    # 4. i > = k - 1일 때 부터 윈도우 완성이므로 이 때 부터 로직 처리
    for i in range(len(stones)):
        # 작은 i부터 작업하는데
        # dq가 빌 때, 혹은 바로 아래 값이 새로 들어오는 원소보다 크거나 같을 때 까지 원소를 뺀다.
        while dq and stones[dq[-1]] < stones[i]:
            dq.pop()
        # 이제 원소를 넣는다.
        dq.append(i)

        # i - k는 1씩 커지는데 dq[0] 이 i - k보다 작다는 건 현재 윈도우의 범위를 벗어난 것
        # 후보군에서 삭제한다. (i - k보다 작거나 같은 놈은 이 조건문 또는 위의 pop 과정에서 무조건 제거됨)
        if dq[0] <= i - k:
            dq.popleft()

        # i가 k-1 보다 커져야 드디어 윈도우 완성 -> 이때 로직 처리
        if i >= k - 1:
            max_values.append(stones[dq[0]])

        # 이런식으로 처리하면 큐에는 i - k + 1 ~ i 까지에 대해 단조 감소 덱이 만들어지게 된다.

    return min(max_values)
