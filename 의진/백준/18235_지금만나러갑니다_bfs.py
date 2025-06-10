import sys
import math
from collections import deque

input = sys.stdin.readline


def solution():
    N, A, B = map(int, input().split())

    if abs(A - B) % 2 == 1:
        return -1

    i = 1
    queue = deque()
    queue.append((A, 0, 0))
    queue.append((B, 1, 0))
    visited = [set([(A, 0)]), set([B, 0])]

    while queue:
        agent_pos, agent_kind, count = queue.popleft()

        if (agent_pos, count) in visited[1 - agent_kind]:
            return count

        move = 2**count

        if (
            agent_pos - move > 0
            and (agent_pos - move, count + 1) not in visited[agent_kind]
        ):
            queue.append((agent_pos - move, agent_kind, count + 1))
            visited[agent_kind].add((agent_pos - move, count + 1))

        if (
            agent_pos + move <= N
            and (agent_pos + move, count + 1) not in visited[agent_kind]
        ):
            queue.append((agent_pos + move, agent_kind, count + 1))
            visited[agent_kind].add((agent_pos + move, count + 1))

    return -1


print(solution())
