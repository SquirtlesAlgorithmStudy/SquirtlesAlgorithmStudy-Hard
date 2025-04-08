# 삼성기출2023하반기(오전)1번 고대 문명 유적 탐사

K,M = map(int, input().split())                           #K턴, 유물조각수M
arr = [list(map(int, input().split())) for _ in range(5)] #5개 줄에 arr
lst = list(map(int, input().split()))                     #M개의 유물조각list
answer = []                                               #각 턴마다 획득한 유물 가치의 총합

def bfs(arr, visited, si, sj, clr):
    q = []
    sset = set()
    #visited는 아래 있음
    cnt =0
    
    q.append((si,sj))
    visited[si][sj] =1
    sset.add((si,sj))
    cnt +=1
    
    while q:
        ci, cj = q.pop(0)
        #네방향, 범위내, 미방문, 조건: 같은 값이면
        for di, dj in ((-1,0),(1,0),(0,-1),(0,1)):
            ni,nj = ci+di, cj+dj
            if 0<=ni<5 and 0<=nj<5 and visited[ni][nj]==0 and arr[ci][cj] == arr[ni][nj]:
                q.append((ni,nj))
                visited[ni][nj] =1
                sset.add((ni,nj))
                cnt +=1
        
    #유물이 3개 이상이면 cnt return, clr==1이면 0으로 clr
    if cnt>=3:
        if clr ==1:
            for i,j in sset:
                arr[i][j] =0
        return cnt
    else: #3개 미만이면 clr하지 않음
        return 0
        

# 90도 시계방향 회전
def rotate(arr, si, sj):
    narr = [x[:] for x in arr]
    for i in range(3):
        for j in range(3):
            narr[si+i][sj+j] = arr[si+3-j-1][sj+i]
    return narr

#clr==1인 경우 3개이상값들을 0으로 clr/ 탐색을 하며 미방문값이면 bfs로 채워 / 갯수를 return  
def count_clear(arr, clr):
    visited = [[0]*5 for _ in range(5)]
    cnt =0
    for i in range(5):
        for j in range(5):
            tmp = bfs(arr, visited, i, j, clr) # 같은 값이 3개 이상인 경우
            cnt +=tmp
    return cnt

#K턴만큼
for _ in range(K):
    mx_cnt =0
    #1. 탐사를 진행(1차 유물 획득 가치 최대 -> 회전각도 작게 -> 열->행)
    for rot in range(1,4): #90 180 270
        #탐사를 진행할 기준위치 설정 (2,2) -> (2,3) -> (2,4)로 크기(3,3)네모 이동
        for sj in range(3): 
            for si in range(3):
                #90도 회전을 rot 횟수 만큼 -> narr(돌린)
                narr = [x[:] for x in arr]
                for _ in range(rot): #rot 횟수만큼 실제로 돌리고 다시 받아
                    narr = rotate(narr, si, sj)

                #유물의 갯수 count
                tmp = count_clear(narr, 0) #count_clear : 3개 이상값들을 0으로, 0은 clear안한다는 flag
                if mx_cnt < tmp: #최대 갯수 찾음!
                    mx_cnt = tmp
                    mx_arr = narr
    #유물이 없다면 즉시 턴 종료
    if mx_cnt ==0:
        break
    
    #2. 유물 연쇄 획득
    cnt =0
    arr = mx_arr
    while True:
        tmp = count_clear(arr, 1) #1: clear 한다
        if tmp ==0:
            break #연쇄획득 종료, 다음 turn
        cnt +=tmp # 발굴한 유물 갯수 누적
        
        #arr 0인 부분(좌에서 우로 -> 아래서 위로)에 유물lst값을 pop해서 arr에 순서대로 추가
        for j in range(5):
            for i in range(4, -1, -1):
                if arr[i][j] ==0:
                    arr[i][j] = lst.pop(0)
        
    answer.append(cnt) #이번턴 연쇄획득한 개수 추가

print(*answer)