# 백준 11003 최솟값 찾기1

import sys
from collections import deque

input = sys.stdin.readline

N, L = map(int, input().split())
Deque = deque()

#현재 sample이 있는 data
now = list(map(int, input().split()))

for i in range(N):
    # 삭제조건1: 제일 끝(오른쪽)에 있는 now보다 큰 데이터 pop
    while Deque and Deque[-1][0] > now[i]:         #<idx, data>
        Deque.pop()
    # 마지막 위치에 append로 현재 값 저장
    Deque.append((now[i], i))
    
    # 삭제조건2: 제일 앞(왼쪽부터) old_idx <= new_idx - sliding_window ?
    if Deque[0][1] <= i-L:
        Deque.popleft() #앞에서 뺄때는 popleft
    
    # 맨 앞에 있는 값이 결국 가장 작은 값이므로 [0][0]출력하면 됌
    print(Deque[0][0], end = ' ')