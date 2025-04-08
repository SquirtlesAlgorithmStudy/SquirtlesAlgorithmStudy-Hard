def myprint(arr):
    for lst in arr:
        print(*lst)
    print()

# route = find_route(si,sj,ei,ej)
from collections import deque
def find_route(si,sj,ei,ej):
    q = deque()
    v = [[0]*N for _ in range(N)]

    q.append((si,sj))
    v[si][sj]=((si,sj))          # 직전위치를 저장

    while q:
        ci,cj = q.popleft()

        if (ci,cj)==(ei,ej):        # 목적지 도착! 경로 저장
            route = []
            ci,cj = v[ci][cj]
            while (ci,cj)!=(si,sj): # 출발지가 아니라면 저장
                route.append((ci,cj))
                ci,cj = v[ci][cj]
            return route[::-1]      # 역순(메두사 이동순서대로) 리턴

        # 네방향(상하좌우!), 범위내, 미방문, 조건(==0)
        for di,dj in ((-1,0),(1,0),(0,-1),(0,1)):
            ni,nj = ci+di, cj+dj
            if 0<=ni<N and 0<=nj<N and v[ni][nj]==0 and arr[ni][nj]==0:
                q.append((ni,nj))
                v[ni][nj]=(ci,cj)

    # 이곳까지 왔다는 얘기는?? 목적지 못찾음
    return -1

#     상,우상, 우,우하, 하,좌하, 좌,좌상
#      0,  1,  2,  3,  4,  5,  6,  7
di = [-1, -1, 0, 1, 1, 1, 0, -1]
dj = [0, 1, 1, 1, 0, -1, -1, -1]

def mark_line(v, ci, cj, dr):
    while 0 <= ci < N and 0 <= cj < N:
        v[ci][cj]=2                     # 시각적 구분위해 2로표시
        ci,cj = ci+di[dr],cj+dj[dr]     # 해당 방향으로 한 칸 이동

def mark_safe(v, si, sj, dr, org_dr):
    # [1] 직선방향 표시
    ci,cj = si+di[dr], sj+dj[dr]
    mark_line(v, ci, cj, dr)        # v에 dr방향으로 이동가능지역 표시

    # [2] 바라보는 방향으로 한줄씩 표시
    ci,cj = si+di[org_dr],sj+dj[org_dr]
    while 0<=ci<N and 0<=cj<N:          # 범위내라면 계속 진행
        mark_line(v, ci, cj, dr)        # v에 dr방향으로 이동가능지역 표시
        ci,cj = ci+di[org_dr],cj+dj[org_dr]

#             tv, tstone = make_stone(marr,mi,mj,dr)
def make_stone(marr, mi, mj, dr):
    v = [[0]*N for _ in range(N)]
    cnt = 0

    # [1] dr 방향으로 >0 만날때까지 1표시, 이후좌표 2표시
    ni,nj = mi+di[dr],mj+dj[dr]
    while 0<=ni<N and 0<=nj<N:          # 범위내라면 계속 진행
        v[ni][nj]=1
        if marr[ni][nj] > 0:
            cnt+=marr[ni][nj]
            ni, nj = ni + di[dr], nj + dj[dr]
            mark_line(v, ni, nj, dr)    # v에 dr방향으로 이동가능지역 표시
            break
        ni,nj = ni+di[dr], nj+dj[dr]

    # [2] dr-1, dr+1 방향으로 동일처리, 대각선 원점잡고 dr방향 처리
    for org_dr in ((dr-1)%8, (dr+1)%8):
        si,sj = mi+di[org_dr], mj+dj[org_dr]        # 첫 대각선 위치부터 체크
        while 0<=si<N and 0<=sj<N:                  # 대각선 방향으로 초기위치 탐색후 직선단위 처리
            if v[si][sj] == 0 and marr[si][sj] > 0: # 전사 만나면 전사가 바라보는 방향 처리
                v[si][sj]=1
                cnt +=marr[si][sj]                  # 돌로만든 전사수 누적
                mark_safe(v, si, sj, dr, org_dr)    # v에 dr방향으로 이동가능지역 표시
                break

            ci,cj = si,sj                           # 첫 위치가 전사가 아닌 경우는 직선으로 내려오며 탐색
            while 0<=ci<N and 0<=cj<N:              # 범위내라면 계속 진행
                if v[ci][cj]==0:                    # 처음 방문
                    v[ci][cj] = 1
                    if marr[ci][cj] > 0:            # 전사로 막혔으면
                        cnt +=marr[ci][cj]
                        mark_safe(v,ci,cj,dr,org_dr)    # v에 dr방향으로 이동가능지역 표시
                        break
                else:
                    break
                ci,cj = ci+di[dr], cj+dj[dr]

            si,sj = si+di[org_dr], sj+dj[org_dr]

    return v, cnt

# move_cnt, attk_cnt = move_men(v, mi, mj)
def move_men(v,mi,mj):
    # (상하좌우), (좌우상하) 메두사 시야가 아니면 (!=1)
    move, attk = 0, 0

    for dirs in (((-1,0),(1,0),(0,-1),(0,1)), ((0,-1),(0,1),(-1,0),(1,0))):
        for idx in range(len(men)-1,-1,-1):
            ci,cj = men[idx]
            if v[ci][cj]==1:                # 메두사 시야면 얼음!
                continue

            dist = abs(mi-ci)+abs(mj-cj)    # 현재거리
            for di,dj in dirs:
                ni,nj = ci+di, cj+dj
                # 범위내 메두사시야 아니고 현재보다 줄어드는 방향이면 (상하좌우 우선순위로 이동)
                if 0<=ni<N and 0<=nj<N and v[ni][nj]!=1 and dist>abs(mi-ni)+abs(mj-nj):
                    if (ni,nj)==(mi,mj):
                        attk+=1             #
                        men.pop(idx)
                    else:
                        men[idx]=[ni,nj]
                    move+=1
                    break
    return move, attk


#######################################
#######################################

N, M = map(int, input().split())
si,sj,ei,ej = map(int, input().split())
tlst = list(map(int, input().split()))

men = []
for i in range(0,M*2,2):
    men.append([tlst[i],tlst[i+1]])
arr = [list(map(int, input().split())) for _ in range(N)]

# [0] BFS로 메두사 최단경로: 도로따라 공원까지(여러 개면 상하좌우 순) 없으면 -1
route = find_route(si,sj,ei,ej)
# print(route)
if route==-1:
    print(-1)
else:
    for mi,mj in route:
        move_cnt, attk_cnt = 0, 0

        # [1] 메두사의 이동: 지정된 최단거리로 한 칸 이동 (전사 마주치면 삭제)
        for i in range(len(men)-1, -1, -1):     # 삭제시 역순으로 접근
            if men[i]==[mi,mj]:                 # 같은좌료
                men.pop(i)

        # [2] 메두사의 시선: 상하좌우 네 방향 가장 많이 돌로 만들 수 있는 방향찾기
        # => v[]에 표시해서 이동시 참조(메두사시선 == 1, 전사에 가려진 곳 == 2, 빈 땅==0)
        # marr[][]: 지도에 있는 전사수 표시
        marr = [[0]*N for _ in range(N)]
        for ti,tj in men:
            marr[ti][tj]+=1

        mx_stone = -1
        v = []
        for dr in (0, 4, 6, 2):     # 상하좌우 순서로 처리!
            tv, tstone = make_stone(marr,mi,mj,dr)
            if mx_stone<tstone:
                mx_stone=tstone
                v = tv
        # print(mx_stone)
        # myprint(v)
        # myprint(marr)

        # [3] 전사들의 이동(한 칸씩 두번): 메두사 있는 경우 공격
        move_cnt, attk_cnt = move_men(v, mi, mj)

        print(move_cnt, mx_stone, attk_cnt)
    print(0)