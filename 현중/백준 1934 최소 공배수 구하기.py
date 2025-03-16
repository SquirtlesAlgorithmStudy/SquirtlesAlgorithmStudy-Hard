#백준 1934 최소 공배수 구하기


#2.초기화에서 최대공약수를 MOD로 계산, 재귀로(앞계산에서 작았던 애가 큰애가 되고 MOD가 작은애), 작은 값이 0이 나오면 최대공약수라하고 return
def gcd(a,b):
    if b ==0:
        return a
    else:
        return gcd(b, a%b) #이과정을 통해 자연스럽게 a가 더 커지게 됌

#1. 초기화
t = int(input())
for i in range(t):
    a,b = map(int, input().split())
    result = a*b/ gcd(a,b)
    print(int(result))