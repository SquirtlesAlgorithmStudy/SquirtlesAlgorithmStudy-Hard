# 백준 1427 내림차순으로 자릿수 정렬하기

import sys
print = sys.stdout.write
A = list(input())

#선택정렬 알고리즘
for i in range(len(A)): #총 길이만큼 반복해야 하니까
    Max = i                      #맨 앞이 최댓값이다라고 선언!
    for j in range(i+1, len(A)): # 두번째 부터 돌면서 찾아!
        # 최댓값을 찾으면 맨앞으로!
        if A[j] > A[Max]:    #현재 차례 > 최대값으로 지정해 둔것
            Max = j
    #2번째 부터 나머지 영역에서 최댓값 찾으면 swap
    if A[i] < A[Max]:
        temp = A[i]
        A[i] = A[Max]
        A[Max] = temp
        
for i in range(len(A)): # A배열을 출력
    print(A[i])