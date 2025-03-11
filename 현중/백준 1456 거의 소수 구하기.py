#백준 1456 거의 소수 구하기
import math

#1. 초기화, list생성, idx값으로 초기화
MIN, MAX = map(int, input().split())
LIST = [0] * (10000001)

for i in range(2, len(LIST)):
    LIST[i] = i

#2. rootN 까지 소수가 아니면 버리고, 소수의 배수값 버리고
for i in range(2, int(math.sqrt(len(LIST)))+1):
    if LIST[i] ==0:
        continue
    for j in range(i+i, len(LIST), i):
        LIST[j] =0
        
#3. 소수를 N제곱한 값이 B보다 커질때 까지 반복(long의 표현범위를 넘어가면 음수가 나오기에 이항정리)
count =0

for i in range(2, 10000001):
    if LIST[i] !=0:
        temp = LIST[i] #일단 값을 하나 넣어 7^9 <= MAX    -> 7<= MAX/7^8
        while LIST[i] <= MAX/temp:
            if LIST[i] >=MIN/temp:
                count +=1
            temp = temp * LIST[i]
print(count)