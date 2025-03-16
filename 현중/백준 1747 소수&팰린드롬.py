#백준 1747 소수&팰린드롬
# 1. N보다 크고 2. 소수이며 3. 우영우인거
import math

#1. 초기화, list생성, idx값으로 초기화
N = int(input())
LIST = [0] * (10000001)

for i in range(2, len(LIST)):
    LIST[i] = i

#2. rootN 까지 소수가 아니면 버리고, 소수의 배수값 버리고
for i in range(2, int(math.sqrt(len(LIST)))):
    if LIST[i] ==0:
        continue
    for j in range(i+i, len(LIST), i):
        LIST[j] =0
        
#3. 각 소수의 숫자를 list로 만들고 시작과 끝이 다르면 false
def uyoungu(number):
    temp = list(str(number))
    s= 0
    e = len(temp)-1
    while (s<e):
        if temp[s] != temp[e]:
            return False
        s +=1
        e -=1
    return True

#4. 우영우세면서 제일 작은거
i = N
while True:
    if LIST[i] !=0:
        MIN = LIST[i]
        if (uyoungu(MIN)):
            print(MIN)
            break
    i +=1