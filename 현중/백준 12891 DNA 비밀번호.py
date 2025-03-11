# 백준 12891 DNA 비밀번호

List = [0] * 4 # A C G T
checkList = [0] * 4
checkSecret =0

#1. list에 새로 들어오는 문자열을 처리
def add(c):
    global checkList, List, checkSecret
    # 1. List[] == checkList[]면 checkSecret증가
    if c== 'A':
        List[0] +=1
        if List[0] == checkList[0]:
            checkSecret +=1
    elif c== 'C':
        List[1] +=1
        if List[1] == checkList[1]:
            checkSecret +=1
    elif c== 'G':
        List[2] +=1
        if List[2] == checkList[2]:
            checkSecret +=1
    elif c== 'T':
        List[3] +=1
        if List[3] == checkList[3]:
            checkSecret +=1

#2. sliding window 후 list에 빠지는 문자열을 처리
def remove(c):
    global checkList, List, checkSecret
    # 1. List[] == checkList[]면 checkSecret감소
    if c== 'A':
        if List[0] == checkList[0]:
            checkSecret -=1
        List[0] -=1
    elif c== 'C':
        if List[1] == checkList[1]:
            checkSecret -=1
        List[1] -=1
    elif c== 'G':
        if List[2] == checkList[2]:
            checkSecret -=1
        List[2] -=1
    elif c== 'T':
        if List[3] == checkList[3]:
            checkSecret -=1
        List[3] -=1
            
S, P = map(int, input().split()) #문자열 크기, 부분 문자열 크기
result = 0
A = list(input())
checkList = list(map(int, input().split()))

#3. DNA 조건 초기화, checklist에 0인것이 있으면 이미 조건을 만족시켰으므로 checkSecret update
for i in range(4):
    if checkList[i] == 0:
        checkSecret +=1

#4. 첫번째윈도우 부분문자열을 처리 -> 6
for i in range(P):
    add(A[i])   # 각 문자열을 받으며 checklist
    
#5.checkSecret 배열이 1111이면 result update
if checkSecret ==4:
    result +=1

#6. main : 두번째윈도우 부터 시작
for i in range(P,S): # 주의 범위는 작은거 부터 큰거이기에 S,P하면 틀림!
    j = i-P # 빠지는 것 : 더하는 것 - 슬라이딩 윈도우 크기P
    add(A[i])
    remove(A[j])
    if checkSecret ==4:
        result +=1
        
print(result)