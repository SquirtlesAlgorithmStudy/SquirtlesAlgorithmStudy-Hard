import heapq

INF = int(10e20)


def get_min_cost(source, dest, graph):
    if source == dest:
        return 0
    dp = [INF] * len(graph)
    pq = [(0, source)]
    dp[source] = 0

    while pq:
        smallest = heapq.heappop(pq)
        if smallest[1] == dest:
            return smallest[0]
        if dp[smallest[1]] < smallest[0]:
            continue

        for connected in graph[smallest[1]]:
            if dp[connected[0]] > dp[smallest[1]] + connected[1]:
                dp[connected[0]] = dp[smallest[1]] + connected[1]
                heapq.heappush(pq, (dp[connected[0]], connected[0]))

    return dp[dest]


def solution(n, s, a, b, fares):
    # fare -> graph
    graph = [[] for _ in range(n + 1)]
    for fare in fares:
        graph[fare[0]].append((fare[1], fare[2]))
        graph[fare[1]].append((fare[0], fare[2]))

    answer = INF
    # get distance
    for node in range(1, len(graph)):
        candidate = (
            get_min_cost(s, node, graph)
            + get_min_cost(node, a, graph)
            + get_min_cost(node, b, graph)
        )

        answer = min(answer, candidate)

    return answer
