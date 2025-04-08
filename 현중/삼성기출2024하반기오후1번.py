# codetree 마법의 숲

#1. 초기화
R,C,K = map(int, input().split()) #좌표, k개 정령
unit = [list(map(int, input().split())) for _ in range(K)] #k개 정령의 출발열c, 방향d
arr = [[1] +[0]*C+ [1] for _ in range(R+3)] + [[1]*(C+2)] #bounding box 
exit_set = set()

#상우하좌
di = [-1,0,1,0]
dj = [0,1,0,-1]

def bfs(si,sj):
    queue = []
    visited = [[0] * (C+2) for _ in range(R+4)]
    max_i =0
    
    queue.append((si, sj))
    visited[si][sj] = 1
    
    while queue:
        ci, cj = queue.pop(0)
        max_i = max(max_i, ci)
        
        #4방향, 미방문, 조건: 같은숫자(범위) 또는 내가출구 상대방이 골름
        for di,dj in ((-1,0),(1,0),(0,-1),(0,1)):
            ni,nj = ci+di, cj+dj
            if visited[ni][nj] ==0 and (arr[ci][cj] == arr[ni][nj] or ((ci, cj) in exit_set and arr[ni][nj] >1)):
                queue.append((ni, nj))
                visited[ni][nj] =1
    return max_i -2
                

answer = 0
number =2 #(경계를 1로표시했기때문에)
#2. 골름이동(입력, 방향에 따라서 남으로 이동, 정령 최대좌표 누적계산)
for cj,dir in unit:
    ci = 1
    while True:
        # 남 -> 서 -> 동
        # 1. 남으로 최대한 이동
        if arr[ci+1][cj-1] + arr[ci+2][cj] + arr[ci+1][cj+1] ==0: #다음이동칸이 비어있으면
            ci +=1
        # 서쪽으로 회전하며 아래로 한칸
        elif (arr[ci-1][cj-1] + arr[ci][cj-2] + arr[ci+1][cj-1] +arr[ci+1][cj-2] + arr[ci+2][cj-1]==0):
            ci +=1
            cj -=1
            dir = (dir-1)%4
        # 동쪽으로 회전하며 아래로 한칸    
        elif (arr[ci-1][cj+1] + arr[ci][cj+2] + arr[ci+1][cj+1] +arr[ci+1][cj+2] + arr[ci+2][cj+1]==0):
            ci +=1
            cj +=1
            dir = (dir+1)%4
        else:
            break    

    #3. 골름표시2번부터
    if ci <4: #bounding box밖
        arr = [[1] +[0]*C+ [1] for _ in range(R+3)] + [[1]*(C+2)] #bounding box 
        exit_set = set()
        number =2
    else: 
        arr[ci+1][cj] = arr[ci-1][cj] = number #골름 세로줄
        arr[ci][cj-1 : cj+2] = [number] *3 #골름 가로줄
        number +=1

        #탈출경로 구현
        exit_set.add((ci + di[dir], cj+dj[dir])) 
        answer += bfs(ci, cj)

print(answer)

