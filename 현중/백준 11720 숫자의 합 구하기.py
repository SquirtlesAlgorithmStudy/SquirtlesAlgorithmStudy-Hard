# 백준 11720 숫자의 합 구하기

n = input() 
numbers = list(input())

sum = 0

for i in numbers:
    sum = sum + int(i) # 주의 i는 str형태이기 때문에 int로 변환
    
print(sum)

