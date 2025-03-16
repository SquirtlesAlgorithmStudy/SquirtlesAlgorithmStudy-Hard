#백준 1016 제곱이 아닌 수

import math
#1. 초기화
MIN, MAX = map(int, input().split())
POW = [False] * (MAX-MIN+1)

for i in range(2, int(math.sqrt(MAX))+1): #1~50일때 root50 = 7.07이므로 8까지
    pow = i*i
    start_idx = int(MIN / pow)
    if MIN%pow !=0:
        start_idx +=1
    # 2. 제곱수 확인
    for j in range(start_idx, int(MAX/pow)+1): # 50/4 = 12.5이므로 하나 더 확인
        POW[int((j*pow)-MIN)] =True

count =0
for i in range(0, MAX-MIN+1):
    if not POW[i]:
        count +=1
        
print(count)