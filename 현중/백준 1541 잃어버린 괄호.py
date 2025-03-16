# 백준 1541 잃어버린 괄호

# 1. -를 기준으로 split
answer =0
A = list(map(str, input().split("-"))) # -를 기준으로 나눔 ["40+50+74","30+29","45+43+11"]

# 2. +를 기준으로 split
def Sum(i):
    sum =0
    temp = str(i).split("+") # i   0: 40 1: 50 2: 74
    for i in temp: # temp : ["40", "50", "74"]
        sum += int(i) #40 -> 90 -> 164
    return sum # 164 / 59 / 99

#3. 맨앞만 더해주고 나머지 다 빼
for i in range(len(A)): # 총 3개 그룹동안
    temp = Sum(A[i]) 
    if i ==0:
        answer += temp # 164
    else:
        answer -= temp

print(answer)    