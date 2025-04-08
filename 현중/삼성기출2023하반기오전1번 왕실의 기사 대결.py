# 삼성기출2023하반기(오전)1번 왕실의 기사 대결

import sys
input = sys.stdin.readline

di = [-1, 0, 1, 0] #상우하좌
dj = [0, 1, 0, -1]

#1. 입력받기
N,M,Q = map(int, input().split()) #L(N*M), N개 기사 정보, Q왕의 명령
arr = [[2]*(N+2)] + [[2]+list(map(int, input().split()))+[2] for _ in range(N)]+ [[2]*(N+2)]

units = {}              #dictionary로 {1:(12215), 2:(21211) ~}
init_k = [0] * (M+1)    # unit들의 체력
for m in range(1, M+1):
    si,sj,h,w,k = map(int, input().split())
    units[m] = [si,sj,h,w,k]
    init_k[m] = k
    # for i in range(si,si+h):    # 디버그용(제출시 삭제 가능)
    #     v[i][sj:sj+w]=[m]*w
    
def push_unit(start, dr): #start를 밀고 연쇄처리
    q = []                #밀 기사 순차적으로 넣고
    pushset = set()       #visited같은거(밀릴 기사번호 저장)
    damage = [0] * (M+1)
    
    q.append(start)
    pushset.add(start) 
    
    # 조건
    while q:
        current_i = q.pop(0)
        ci,cj,h,w,k = units[current_i]
        
        # 명령받은 방향진행, 벽이아니면, 겹치는 다른조각이면 => 큐에 삽입
        ni,nj = ci + di[dr], cj + dj[dr]
        for i in range(ni, ni+h):
            for j in range(nj, nj+w):
                if arr[i][j] ==2:
                    return 
                if arr[i][j] ==1:
                    damage[current_i] +=1   # 함정인 경우 데미지 누적
    
        # 벽이 없다면 겹치는 unit이 있을 경우 queue에 추가
        for idx in units:
            if idx in pushset : continue 
            
            ti, tj, th, tw, tk = units[idx]
            if ni<=ti+th-1 and ni+h-1 >=ti and nj+w-1>=tj and nj <=tj+tw-1:
                q.append(idx)
                pushset.add(idx)

    #명령받은 기사는 damage없음
    damage[start] =0
        
    #데미지가 체력이상이면 삭제처리, 명령받은 기사가 다른 기사를이동
    for idx in pushset:
        si, sj, h, w, k = units[idx]
        if k <= damage[idx]:
            units.pop(idx)
        else:
            ni, nj = si + di[dr], sj + dj[dr]
            units[idx] = [ni,nj,h,w,k-damage[idx]]

for _ in range(Q):
    idx, dr = map(int, input().split())
    if idx in units:
        push_unit(idx, dr) #3. 기사들 계속 밀기 함수 만들기


#2. 정답처리
ans =0
for idx in units:
    ans += init_k[idx] - units[idx][4] #총 받은 데미지들의 합을 answer에 누적
print(ans)