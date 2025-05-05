from collections import deque


def get_possible_indice(now_worker, start_idx, diff):
    results = set()
    current_idx = start_idx
    while True:
        if diff[current_idx] > now_worker:
            return results

        results.add(current_idx)
        now_worker -= diff[current_idx]
        current_idx = (current_idx + 1) % len(diff)


def circular_merge(possible_indice, start_idx, diff):
    sum_result = 0
    new_diff = list(diff)
    calculate_indice = set()
    if len(possible_indice) == 0:
        calculate_indice.add(start_idx)
        calculate_indice.add((start_idx + 1) % len(diff))
    else:
        for i in range(len(diff)):
            if i in possible_indice:
                calculate_indice.add(i)
                calculate_indice.add((i - 1) % len(diff))
                calculate_indice.add((i + 1) % len(diff))

    for i in range(len(diff)):
        if i in calculate_indice:
            sum_result += diff[i]
            new_diff[i] = 0
    new_diff[start_idx] = sum_result
    for i, d in enumerate(new_diff):
        if d == 0:
            del new_diff[i]
    return new_diff


def solution(n, weak, dist):
    diff = [weak[i + 1] - weak[i] for i in range(len(weak) - 1)]
    diff.append(n - weak[-1] + weak[0])
    dist.sort(reverse=True)
    queue = deque()
    queue.append((0, tuple(diff)))

    while queue:
        item = queue.popleft()
        # print(item)

        for start_idx in range(len(item[1])):
            if item[0] >= len(dist):
                continue
            now_worker = dist[item[0]]
            possible_indice = get_possible_indice(now_worker, start_idx, item[1])
            if len(possible_indice) >= len(item[1]) - 1:
                return item[0] + 1
            new_diff = circular_merge(possible_indice, start_idx, item[1])
            queue.append((item[0] + 1, tuple(new_diff)))

    return -1
