# [한양대 HCPC 2023] Phi Squared

import sys
from collections import deque


#1. 초기화
N = int(input().strip())
bug = list(map(int, input().split()))

def eatbug(n, bug):
    bug.sort() #2. 오름차순으로 정렬
    final_size = bug[0]
    for i in range(1, n):
        final_size += bug[i] #3. 왼쪽부터 차례대로 흡수 연산
        
    initial_size = bug[-1]
    
    print(final_size)
    print(initial_size)
    

#4. 마지막 남은 미생물의 크기, 초기크기 반환
eatbug(N, bug)