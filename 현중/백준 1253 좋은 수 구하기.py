# 백준 1253 좋은 수 구하기

import sys
input = sys.stdin.readline

N = int(input())
good = 0;

A = list(map(int, input().split()))
A.sort()

for k in range(N):
    find = A[k]
    i = 0
    j = N-1
    while i<j:
        if A[i] + A[j] == find:
            if i !=k and j !=k:
                good +=1
                break
            elif i ==k:
                i+=1
            elif j ==k:
                j-=1
        elif A[i] + A[j] < find:
            i+= 1
        else :
            j-= 1
            
print(good)
