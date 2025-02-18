import sys

sys.setrecursionlimit(10**9)

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
connections = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    left, right = map(int, input().split())
    connections[left].append(right)
    connections[right].append(left)

q = int(input())
queries = [tuple(map(int, input().split())) for _ in range(q)]

routes = [() for _ in range(n + 1)]


def scan(root):
    routes[root] = tuple([root])
    visited = [0] * (n + 1)
    visited[root] = 1

    def dfs(node, route):
        for next_node in connections[node]:
            if visited[next_node] == 0:
                route.append(next_node)
                routes[next_node] = tuple(route)
                visited[next_node] = 1
                dfs(next_node, route)
                route.pop()

    dfs(root, [root])


for i, item in enumerate(a):
    if item != 0:
        root = i + 1
        break

scan(root)
# print(routes)

sys.exit()

must_go_nodes = set()
for i, item in enumerate(a):
    if item != 0:
        must_go_nodes = must_go_nodes.union(set(routes[i + 1]))

print(2 * (len(must_go_nodes) - 1))

for query in queries:
    must_go_nodes = must_go_nodes.union(set(routes[query[0]]))
    must_go_nodes = must_go_nodes.union(set(routes[query[1]]))
    print(2 * (len(must_go_nodes) - 1))
