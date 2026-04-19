import sys
import heapq
from collections import defaultdict

input = sys.stdin.readline


def dijkstra_farthest(adj_list, start, n, interview_positions):
    distances = [float("inf")] * (n + 1)
    distances[start] = 0

    heap = [(0, start)]
    visited = set()

    while heap:
        current_dist, current_node = heapq.heappop(heap)

        if current_node in visited:
            continue

        visited.add(current_node)

        for neighbor, weight in adj_list[current_node]:
            if neighbor not in visited:
                new_dist = current_dist + weight

                if new_dist < distances[neighbor]:
                    distances[neighbor] = new_dist
                    heapq.heappush(heap, (new_dist, neighbor))

    max_dist = -1
    farthest_node = start
    interview_set = set(interview_positions)

    for i in range(1, n + 1):
        if (
            i not in interview_set
            and distances[i] != float("inf")
            and distances[i] > max_dist
        ):
            max_dist = distances[i]
            farthest_node = i

    return farthest_node, max_dist


def main():
    N, M, K = map(int, input().split())
    connections = defaultdict(list)

    for _ in range(M):
        u, v, c = map(int, input().split())
        connections[v].append((u, c))

    interview_positions = list(map(int, input().split()))
    for pos in interview_positions:
        connections[0].append((pos, 0))

    return dijkstra_farthest(connections, 0, N, interview_positions)


result = main()
print(result[0])
print(result[1])
