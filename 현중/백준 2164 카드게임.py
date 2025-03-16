# 백준 2164 카드게임

from collections import deque
N = int(input())
Queue = deque()

#입력받고
for i in range(1, N+1):
    Queue.append(i)

#카드가 한장 남을때 까지 반복(queue의 size가 1보다 클때)
while len(Queue) >1:
    #맨위의 카드를 버리고
    Queue.popleft()
    #맨위의 카드를 뽑아서 맨 아래로
    Queue.append(Queue.popleft())
    
print(Queue[0])