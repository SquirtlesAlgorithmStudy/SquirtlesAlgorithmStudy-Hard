# 백준 1931 회의실 배정하기

#1. 입력받고, 종료시간 기준으로 정렬
N = int(input())
A = [[0]*2 for _ in range(N)] #N 수만큼 [[0,0], [0,0], ... ]

for i in range(N):
    S,E = map(int, input().split())
    A[i][0] = E
    A[i][1] = S
    
A.sort()

#2. 종료시간이 같을 땐, 시작시간 기준으로 다시 정렬  (생각안해도 sort에서 해결)
#3. 시작시간을 기준으로 겹치지 않는 부분 count

count =0
end = -1 #회의가 시작하기 전이기에 음수

for i in range(N):
    if A[i][1] >= end:
        end = A[i][0]
        count +=1
        
print(count)