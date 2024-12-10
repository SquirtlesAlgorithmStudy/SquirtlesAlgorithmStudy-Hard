def solution(grid):
    parse = {"S": 0, "L": -1, "R": 1}
    grid = [[parse[c] for c in s] for s in grid]
    grid_3d = [[[None] * 4 for _ in range(len(grid[0]))] for _ in range(len(grid))]
    check_3d = [[[False] * 4 for _ in range(len(grid[0]))] for _ in range(len(grid))]
    mapping = [(1, 0), (0, -1), (-1, 0), (0, 1)]
    N, M = len(grid), len(grid[0])
    for r in range(N):
        for c in range(M):
            for i in range(4):
                way = (i + grid[r][c]) % 4
                dr, dc = mapping[way]
                grid_3d[r][c][i] = ((r + dr) % N, (c + dc) % M, way)
    ans = []
    for r in range(N):
        for c in range(M):
            for i in range(4):
                cnt = 0
                while not check_3d[r][c][i]:
                    check_3d[r][c][i] = True
                    r, c, i = grid_3d[r][c][i]
                    cnt += 1
                if cnt > 0:
                    ans.append(cnt)
    return sorted(ans)
