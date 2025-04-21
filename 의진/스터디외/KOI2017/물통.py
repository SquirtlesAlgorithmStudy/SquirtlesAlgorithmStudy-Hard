import sys

sys.setrecursionlimit(10**6)
a, b, c, d = map(int, input().split())
path_set = set()
INF = 2 << 31


def dfs(node, state):
    global path_set
    global a, b, c, d
    if node == (0, 0):
        return len(path_set) - 1

    if node == (0, b):
        return len(path_set)

    if node == (a, 0):
        return len(path_set)

    if node == (a, b):
        return len(path_set) + 1

    new_node = list(node)
    if state == 0:
        result = INF
        flag = False
        if node[0] == 0:
            new_node[0] = a
            flag = True
        elif node[0] == a:
            new_node[0] = 0
            flag = True

        if flag and tuple(new_node) not in path_set and node[0] <= a:
            path_set.add(tuple(new_node))
            result = min(dfs(tuple(new_node), 1), result)
            path_set.remove(tuple(new_node))

        flag = False

        if node[1] == 0:
            new_node[1] = b
            flag = True
        elif node[1] == b:
            new_node[1] = 0
            flag = True

        if flag and tuple(new_node) not in path_set and node[1] <= b:
            path_set.add(tuple(new_node))
            result = min(result, dfs(tuple(new_node), 1))
            path_set.remove(tuple(new_node))

        return result

    else:
        result = INF
        node_sum = node[0] + node[1]
        for i in range(node_sum + 1):
            if not check(i, node_sum - i):
                continue
            if (i, node_sum - i) in path_set:
                continue
            path_set.add((i, node_sum - i))
            result = min(result, dfs((i, node_sum - i), 0))
            path_set.remove((i, node_sum - i))
        return result


def check(p, q):
    global a, b
    if p == 0 and q < b:
        return True
    if q == 0 and p < a:
        return True
    if p == a:
        return True
    if q == b:
        return True
    return False


if not check(c, d):
    print(-1)
else:
    path_set.add((c, d))
    ans = min(dfs((c, d), 0), dfs((c, d), 1))
    if ans == INF:
        print(-1)
    else:
        print(ans)
