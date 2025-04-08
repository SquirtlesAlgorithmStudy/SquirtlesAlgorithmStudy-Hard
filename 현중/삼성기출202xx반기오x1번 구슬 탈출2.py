# 삼성기출202xx반기오x1번 구슬 탈출2


# 1. 4방향이동 dfs(n번, ri,rj, bi,bj)
# 1-1 r_cnt = move(ri, rj, dr) / b_cnt = move(bi,bj,dr) / 모두 못움직이면 그만탐색(continue)
# 1-2. 이동은 nri = ri+di[dr]*r_cnt
# 1-3. 구멍처리: 빨강만, 둘다 안빠지면 dfs(n+1번, nri, nrj...)
# 2 공이동: def move(ci, cj, dr) 
# #: d방향으로 계속가면서 벽만나면 cnt-1만큼 이동
# O: return cnt
# 공 겹침: 만약 이동하면서 다른공 있으면 한칸 back = -1 cnt+back???



import sys

di = [-1, 1, 0, 0]
dj = [0, 0, -1, 1]

N,M = map(int, input().split())
arr = [list(input()) for _ in range(N)]
for i in range(N):
    for j in range(M):
        if arr[i][j] == 'R':
            ri, rj = i,j
        if arr[i][j] == 'B':
            bi, bj = i,j

def move(i, j, dr):
    back =-1
    for cnt in range(1,10): #끝까지 가서 벽을 만날 때
        ni,nj = i+di[dr]*cnt,j+dj[dr]*cnt
        if arr[ni][nj] =='#': return cnt + back            #1. 벽이면 back
        if arr[ni][nj] =='O': return cnt                   #2. 구멍
        if arr[ni][nj] =='B' or arr[ni][nj] =='R': back-=1 #3. 다른공을 지나간경우 벽을 마주친다면 back -1

def dfs(n,ri,rj,bi,bj):
    global ans
    
    #1. 종료조건 10보다 크면
    if n>10:
        return
    #2. 각 공의 이동거리 계산, 4방향 이동처리
    for dr in range(4):
        r_cnt = move(ri,rj,dr)
        b_cnt = move(bi,bj,dr)
        if r_cnt ==0 and b_cnt ==0: # 못움직이면 탐색x
            continue
        
        #2-1 각 공의 이동 반영
        nri, nrj = ri+di[dr]*r_cnt, rj+dj[dr]*r_cnt
        nbi, nbj = bi+di[dr]*b_cnt, bj+dj[dr]*b_cnt
        
        #2-2 빨강만이면 성공 나머지 실패
        if arr[nbi][nbj] == "O":      #파랑공이 빠지면 실패, 다음 방향으로
            continue
        else:
            if arr[nri][nrj] == "O":
                ans = min(ans, n)
                return
        
        #2-3 둘다 홀이 아닌경우 이동, 시도
        arr[ri][rj], arr[bi][bj]='.','.'        #현재위치를 빈칸으로, 다음위치에는 구슬 표시
        arr[nri][nrj], arr[nbi][nbj] = 'R','B'
        
        dfs(n+1, nri,nrj, nbi,nbj)
        
        arr[nri][nrj], arr[nbi][nbj]='.','.'        #원상복구!
        arr[ri][rj], arr[bi][bj] = 'R','B'



ans = 11 #10번 이하로 종료가 안될경우에는 -1출력
dfs(1, ri, rj, bi, bj)
if ans ==11:
    ans =-1
print(ans) 