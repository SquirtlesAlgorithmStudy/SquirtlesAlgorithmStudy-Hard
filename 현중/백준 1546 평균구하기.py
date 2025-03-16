# 백준 1546 평균구하기

n = input()
mylist = list(map(int, input().split()))

m = max(mylist)
sum = sum(mylist)

print(sum *100 / m / int(n))