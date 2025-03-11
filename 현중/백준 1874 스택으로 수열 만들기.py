# 백준 1874 스택으로 수열 만들기

N = int(input()) # 수열 갯수
A = [0] * N      # 수열 list

# 입력받아
for i in range(N):
    A[i] = int(input())
    
    
stack = []
num = 1         # 1~N까지의 숫자
result = True   # 수열을 만들 수 있는지 여부
answer = []     # + - 기록   


for i in range(N):
    target = A[i]     #배열에 있는 값을 하나 가져오고
    if target >= num:
        while target >= num:
            stack.append(num)
            num +=1
            answer.append('+')
        stack.pop()
        answer.append('-')
    else : # target < num
        n = stack.pop()
        if n >target: #오름차순이기에 stack에서는 큰수가 먼저 빠지게되어있음
            print("no")
            result = False
            break
        else:
            answer.append('-')

if result:
    for i in answer:
        print(i)