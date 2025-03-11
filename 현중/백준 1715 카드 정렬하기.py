# 백준 1715 카드 정렬하기

#1. 초기화
from queue import PriorityQueue
N =int(input())
pq =PriorityQueue()

for _ in range(N):
    data = int(input())
    pq.put(data)
    
#2. queue에 1값만 나올때 까지 업데이트
data1 =0
data2 =0
sum =0

while pq.qsize()>1:
    data1 = pq.get()
    data2 = pq.get()
    temp = data1 + data2
    
    pq.put(temp)
    sum = sum + temp #결과값을 출력할 때 사용
    
print(sum)