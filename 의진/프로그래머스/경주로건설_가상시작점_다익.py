import heapq
from pprint import pprint


def solution(board):
    INF = float("inf")
    N = len(board)
    dr = [1, -1, 0, 0]
    dc = [0, 0, 1, -1]
    answer = INF

    dp = [[[INF] * N for _ in range(N)] for _ in range(2)]
    dp[0][0][0] = 0
    dp[1][0][0] = 0
    heap = []
    heapq.heappush(heap, (0, (0, 0, 0)))
    heapq.heappush(heap, (0, (1, 0, 0)))
    visited = [[[False] * N for _ in range(N)] for _ in range(2)]
    visited[0][0][0] = True
    visited[1][0][0] = True

    while heap:
        item = heapq.heappop(heap)
        if item[0] > dp[item[1][0]][item[1][1]][item[1][2]]:
            continue

        visited[item[1][0]][item[1][1]][item[1][2]] = True
        r = item[1][1]
        c = item[1][2]

        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]

            if nr < 0 or nr >= N or nc < 0 or nc >= N:
                continue

            if board[nr][nc] == 1:
                continue

            if item[1][0] == 0:
                if i == 2 or i == 3:
                    if visited[0][nr][nc]:
                        continue
                    dp[0][nr][nc] = min(dp[0][nr][nc], dp[0][r][c] + 100)
                    heapq.heappush(heap, (dp[0][nr][nc], (0, nr, nc)))
                else:
                    if visited[1][nr][nc]:
                        continue
                    dp[1][nr][nc] = min(dp[1][nr][nc], dp[0][r][c] + 600)
                    heapq.heappush(heap, (dp[1][nr][nc], (1, nr, nc)))
            else:
                if i == 2 or i == 3:
                    if visited[0][nr][nc]:
                        continue
                    dp[0][nr][nc] = min(dp[0][nr][nc], dp[1][r][c] + 600)
                    heapq.heappush(heap, (dp[0][nr][nc], (0, nr, nc)))
                else:
                    if visited[1][nr][nc]:
                        continue
                    dp[1][nr][nc] = min(dp[1][nr][nc], dp[1][r][c] + 100)
                    heapq.heappush(heap, (dp[1][nr][nc], (1, nr, nc)))

        answer = min(dp[0][-1][-1], dp[1][-1][-1], answer)
        # pprint(dp)
        # answer = 0

    return answer
