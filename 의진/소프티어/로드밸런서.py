import sys
from collections import deque

input = sys.stdin.readline

N, K = map(int, input().split())
nodes = [-1] + [list(map(int, input().split())) for _ in range(N)]


def topo_sort(nodes):
    queue = deque()
    indegrees = [0] * len(nodes)
    for node in nodes[1:]:
        for conn in node[1:]:
            indegrees[conn] += 1

    for i, ind in enumerate(indegrees[1:]):
        if ind == 0:
            queue.append(i + 1)
    result = []
    while queue:
        now = queue.popleft()
        now_node = nodes[now]
        for conn in now_node[1:]:
            indegrees[conn] -= 1
            if indegrees[conn] == 0:
                queue.append(conn)
        result.append(now)

    return result


seq = topo_sort(nodes)
result = [0] * N
result[0] = K

for s in seq:
    traffic = result[s - 1]
    if nodes[s][0] == 0:
        continue
    distributed = traffic // nodes[s][0]
    remainer = traffic % nodes[s][0]

    for conn in nodes[s][1:]:
        result[conn - 1] += distributed
        if remainer > 0:
            result[conn - 1] += 1
            remainer -= 1


print(" ".join(map(str, result)))
