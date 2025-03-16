# 백준 1253 좋은 수 구하기2

#1. 초기화, 숫자 정렬
import sys
input = sys.stdin.readline

N = int(input()) #배열 A의 크기
good =0

A = list(map(int, input().split()))
A.sort()

#2. 투포인터를 양끝에 두고 양끝값의 합 < 원하는값 까지 j를 --, i ++
for k in range(N):
    find = A[k]
    i =0
    j =N-1
    while i<j:
        if A[i] + A[j] ==find:
            if i !=k and j !=k:
                good +=1
                break
            elif i ==k:
                i+=1
            elif j ==k:
                j -=1
        elif A[i] + A[j] < find:
            i +=1
        else :
            j -=1
print(good)