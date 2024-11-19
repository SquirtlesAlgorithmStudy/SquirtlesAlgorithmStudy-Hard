import sys


def dfs(parent_idx, info, visited, a, is_root):
    visited[parent_idx] = True
    if len(info[parent_idx]) == 1 and not is_root:
        return (abs(a[parent_idx]), a[parent_idx])

    dfs_0_acc = 0
    dfs_1_acc = 0
    for n_node in info[parent_idx]:
        if not visited[n_node]:
            result = dfs(n_node, info, visited, a, False)
            dfs_0_acc += result[0]
            dfs_1_acc += result[1]
    return (dfs_0_acc + abs(dfs_1_acc + a[parent_idx]), dfs_1_acc + a[parent_idx])


def solution(a, edges):
    sys.setrecursionlimit(10**9)
    acc = 0
    zero_flag = False
    for item in a:
        if item != 0:
            zero_flag = True
        acc += item

    if not zero_flag:
        return 0

    elif acc != 0:
        return -1

    info = [[] for _ in range(len(a))]
    for e in edges:
        info[e[0]].append(e[1])
        info[e[1]].append(e[0])

    for idx, item in enumerate(info):
        if len(item) == 1:
            leaf_idx = idx
            break
    visited = [False] * len(a)
    answer, _ = dfs(leaf_idx, info, visited, a, True)
    return answer
