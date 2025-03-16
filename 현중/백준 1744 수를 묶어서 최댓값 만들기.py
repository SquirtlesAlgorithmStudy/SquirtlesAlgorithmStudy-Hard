# 백준 1744 수를 묶어서 최댓값 만들기

#1. 초기화
from queue import PriorityQueue
N = int(input())
pluspq = PriorityQueue()
minuspq = PriorityQueue()
zero_count =0
one_count =0

#2. 4개의 그룹으로 나누어서 저장하는데, 양수는 내림차순으로!
for i in range(N):
    data = int(input())
    if data >1:
        pluspq.put(data *-1)
    elif data ==1:
        one_count +=1
    elif data ==0:
        zero_count +=1
    else:
        minuspq.put(data)

sum =0
#3. 양수처리(queue가 1개 남을때 까지, 근데 홀수면 그냥 더함)
while pluspq.qsize()>1:
    first = pluspq.get() *-1
    second = pluspq.get() *-1
    sum = sum + first*second

if pluspq.qsize() > 0:
    sum += pluspq.get() * -1

#4. 음수처리(queue가 1개 남을때 까지, 근데 홀수, 0이 있다면 무시 / 0이 없으면 더해)
while minuspq.qsize()>1:
    first = minuspq.get() 
    second = minuspq.get() 
    sum = sum + first*second

if minuspq.qsize()>0:
    if zero_count ==0:
        sum += minuspq.get()
        
#5. 1의 갯수를 더해주는 건 결국 1을 더해그냥
sum += one_count

print(sum)