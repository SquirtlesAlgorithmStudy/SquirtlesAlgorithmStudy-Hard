# 삼성기출2024하반기(오후)1번 메두사와 전사들
from collections import deque


def find_route(si, sj, ei, ej):  # 상하좌우
    q = deque()
    v = [[0] * N for _ in range(N)]

    q.append((si, sj))
    v[si][sj] = ((si, sj))  # 내가 어디서 왔는지를 저장(직전 위치)

    while q:
        ci, cj = q.popleft()

        # 언제끝나?
        if (ci, cj) == (ei, ej):  # 목적지에 도착했으면 경로를 꺼내
            route = []
            ci, cj = v[ci][cj]
            while (ci, cj) != (si, sj):  # 언제까지? 역으로 올라가며 출발지점 전까지
                route.append((ci, cj))
                ci, cj = v[ci][cj]
            return route[::-1]  # 끝점부터 올라가므로, 뒤집어!

        # 네방향(상하좌우), 범위내, 미방문, 조건(길:0 이면)
        for di, dj in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            ni, nj = ci + di, cj + dj
            if 0 <= ni < N and 0 <= nj < N and v[ni][nj] == 0 and arr[ni][nj] == 0:
                q.append((ni, nj))
                v[ni][nj] = (ci, cj)

                # 이곳까지 왔다는 얘기는?? 목적지 못찾음
    return -1


######################################
##             입,출력               ##
######################################

N, M = map(int, input().split())
si, sj, ei, ej = map(int, input().split())
wwhere = list(map(int, input().split()))

men = []
for i in range(0, M * 2, 2):  # 전사마다 x좌표 y좌표를 받음으로 idx를 2칸씩 증가하며 x,y짝 추출하여 전사좌표
    men.append([wwhere[i], wwhere[i + 1]])
arr = [list(map(int, input().split())) for _ in range(N)]

# [0] BFS로 메두사 최단경로: 도로따라 공원까지, 상하좌우
route = find_route(si, sj, ei, ej)
print(route)
# if route ==-1:
#     print(-1)
# else: #하나씩 꺼내면서
#     for mi,mj in route:
#     #[1]: 메두사 이동

#     #[2]: 메두사 시선(전사 가장 많은쪽으로) visited: 0: 빈땅/ 1: 메두사시선/ 2: 전사에 가려진 곳/ ==> 전사는 1이아니면 이동가능
#     #[3]: 전사 이동

# print()