#삼성기출2024상반기(오전)1번

K, M = map(int, input().split()) # K번 반복, 유물조각 개수M
arr = [list(map(int, input().split())) for _ in range(5)]
list = list(map(int, input().split()))
answer = [] # 각 턴마다 유물 가치 총합list

#1-1. 90도 rotate구현
def rotate(arr, si, sj):
    new_arr = [x[:] for x in arr]
    for i in range(3):
        for j in range(3):
            new_arr[si+i][sj+j] = arr[si+3-j-1][sj+i]
    return new_arr

#2-2 bfs구현
def bfs(arr, visited, si, sj, clear):
    queue = []
    cnt =0
    sset = set()
    
    queue.append((si,sj))
    visited[si][sj] =1 
    sset.add((si, sj))
    cnt +=1

    while queue:
        ci, cj = queue.pop(0)
        #4방향, 범위내, 미방문, 같은값이면
        for di,dj in ((-1,0),(1,0),(0,-1),(0,1)):
            ni, nj = ci+di, cj+dj
            if 0<=ni<5 and 0<=nj<5 and visited[ni][nj] ==0 and arr[ci][cj] == arr[ni][nj]:
                queue.append((ni,nj))
                visited[ni][nj] =1
                sset.add((ni, nj))
                cnt +=1

    if cnt >=3: #유물이면 cnt return + clear ==1이면 0으로 clear
        if clear ==1:
            for i,j in sset:
                arr[i][j] =0
                
        return cnt
    return 0 # cnt가 0,1,2 이라면

#2-1. count_clear구현 -> tmp갯수를 return
def count_clear(arr, clear): #clear ==1인 경우 3개 이상값들을 bfs를 이용하여 0으로 clear
    visited = [[0]*5 for _ in range(5)] # 5x5
    cnt = 0
    for i in range(5): #미방문인 경우 같은 값이면 fill 
        for j in range(5):
            if visited[i][j] ==0:
                tmp = bfs(arr, visited, i, j, clear) # 같은 값이면 , 3개 이상인 경우 return, clear
                cnt += tmp
    return cnt

#1. K턴만큼 진행(유물이 없으면 중지), 회전하며 탐사진행
for _ in range(K):
    max_cnt = 0 #탐사를 진행할 위치
    for rot in range(1, 4): # 90, 180, 270 -> 회전 중심 좌표의 열이 가장 작은 구간 -> 회전 중심 좌표의 행이 가장 작은 구간
        for sj in range(3) :
            for si in range(3):
                # rot 횟수만큼 90도 시계방향 회전 -> new_awrr에 저장
                new_arr = [x[:] for x in arr]
                for _ in range(rot):
                    new_arr = rotate(new_arr, si, sj)

                #2. list에서 숫자(유물) 획득
                tmp = count_clear(new_arr, 0) # 0: clear안함
                if max_cnt < tmp:
                    max_cnt = tmp
                    max_arr = new_arr 
    if max_cnt ==0: #유물이 없으면 중지
        break
    
    # 3. 유물 연쇄 획득
    cnt=0
    arr = max_arr
    while True:
        tmp = count_clear(arr, 1)
        if tmp ==0:
            break # 연쇄 획득 종료 -> 다음 턴
        
        #획득한 유물 갯수 누적
        cnt += tmp

        #arr에서 0인 부분을 list에서 순서대로 추가
        for j in range(5):
            for i in range(4, -1, -1): # 4 -> 0까지 열이 가장 작은 구간
                if arr[i][j] ==0:
                    arr[i][j] = list.pop(0)
                    

    answer.append(cnt) # 이번턴의 연쇄획득한 갯수 추가
    
print(*answer)