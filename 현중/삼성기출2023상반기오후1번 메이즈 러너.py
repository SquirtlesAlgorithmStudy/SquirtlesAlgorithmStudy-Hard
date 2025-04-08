#삼성기출2023상반기(오후)1번 메이즈 러너

# N,M,K #판, 사람, K초, 출구를 -11로 놓고 사람을 -11<사람<0으로 두기
# 움직임: 
#     동시에 움직임: 복사, arr에 지우고 narr에 만들어서 적용
#     출구에 가깝게 움직임(|현재위치-출구| - |(ni,nj)-출구|)
#     네방향, 미방문x, 조건(벽x, 출구에 가깝게)
#         주의!! 비상구(-11): narr[i][j] -= arr[i][j](이동거리)
#                빈공간: narr[i][j] += arr[i][j](들어온 인원 추가)
# 회전: 참가자+출구, 시계 90도 회전, 내구도 -1
#     탐색: 비상구와 사람사이 가로세로 최단거리 or 반경1짜리 2짜리 증가해가며 슬라이딩 윈도우 형식으로 판 탐색
#           L = min(max(abs(ei-i), abs(ej-j)))
# K초후 or 모두 탈출: 이동거리합, 출구좌표

N,M,K = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
# 사람
for _ in range(M):
    #lambda 매개변수: 반환값 = map() 안에서 간단한 계산을 할때 쓰임
    i,j = map(lambda x:int(x)-1, input().split()) # 상단이 1,1부터 시작하기에
    arr[i][j] -=1 #사람을 -1로 표시해주는데 0에서 1씩빼주는 방식으로 표현

#비상구
ei,ej = map(lambda x: int(x)-1, input().split())
arr[ei][ej]= -11
#3. find_exit
def find_exit(arr):
    for i in range(N):
        for j in range(N):
            if arr[i][j] == -11:                   # 비상구 -11
                return i,j 

# 4. find_square
def find_square(arr):
    # [1] 비상구와 모든 사람간의 가장짧은 가로 또는 세로거리 구하기 => L
    mn = N
    for i in range(N):
        for j in range(N):
            if -11<arr[i][j]<0:
                mn = min(mn, max(abs(ei-i), abs(ej-j)))
    # [2] (0,0)부터 순회하면서 길이 L인 정사각형에 비상구와 사람있는지 체크 => 리턴 L+1
    for si in range(N-mn):                       # 가능한 모든 시작위치
        for sj in range(N-mn):
            # 1. 비상구, 
            if si<=ei<=si+mn and sj<=ej<=sj+mn:  # 비상구가 포함된 사각형!
                # 2. 사람,
                for i in range(si, si+mn+1):      
                    for j in range(sj, sj+mn+1):  
                        if -11< arr[i][j] <0:     # 사람인 경우 리턴!
                            return si,sj,mn+1

#1. K턴을 모두 돌거나, 모두탈출 까지 모든 사람의 이동거리 누적, 종료
ans =0
cnt = M
for _ in range(K):
    #[1] 모든 참가자 (동시에)한 칸 이동(출구 최단거리 방향으로, 상하먼저)
    # -11에 도달하면 탈출
    narr = [x[:] for x in arr]
    for i in range(N):
        for j in range(N):
            if -11 < arr[i][j] < 0:
                dist = abs(ei-i) + abs(ej-j)
                # 네방향, 범위내, 조건(벽아니고(<=0), 최단거리면())
                for di,dj in ((-1,0), (1,0), (0,-1), (0,1)):
                    ni, nj = i +di, j +dj
                    if 0<=ni<N and 0<=nj<N and arr[ni][nj] <=0 and dist>(abs(ei-ni)+abs(ej-nj)):
                        ans += arr[i][j]      # 현재 인원수가 이동하는 것이니 이동거리에 누적
                        narr[i][j]-=arr[i][j] # 이동처리
                        if arr[ni][nj] ==-11: # 비상구인 경우
                            cnt +=arr[i][j]   # 탈출!
                        else:                 # 일반빈칸 또는 사람있는자리
                            narr[ni][nj] += arr[i][j]
                        break
    arr = narr
    if cnt ==0:
        break 
    #[2] 미로회전(출구, 사람 포함해서 가장 작은 사각형), 시계방향 90도
    si, sj, L = find_square(arr)

    narr = [x[:] for x in arr]
    for i in range(L):
        for j in range(L):
            narr[si+i][sj+j] = arr[si+L-1-j][sj+i]
            #돌리고나서 내구도 감소
            if narr[si+i][sj+j] >0:
                narr[si+i][sj+j] -=1

    arr = narr
    ei,ej = find_exit(arr) # 회전으로 달라졌으므로... 비상구 위치 저장

print(-ans)
print(ei+1, ej+1)