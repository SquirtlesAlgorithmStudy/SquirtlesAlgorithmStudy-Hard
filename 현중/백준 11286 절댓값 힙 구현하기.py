# 백준 11286 절댓값 힙 구현하기

from queue import PriorityQueue
import sys
print = sys.stdout.write
input = sys.stdin.readline

N = int(input())
Queue = PriorityQueue()

# 1. 절댓값이 작은 데이터 우선
# 2. 절댓값이 같은 경우 음수 먼저
for i in range(N):
    request = int(input())
    # 1. request입력값이 0인경우
    if request ==0:
        if Queue.empty(): # heap이 비어있다면 0출력
            print('0\n')    
        else:             # priority data를 가져오고
            temp = Queue.get()         # (abs_value, original_value)
            print(str(temp[1]) + '\n') # original_value을 출력
    # 2. request입력값이 0이 아닌경우
    else:
        Queue.put((abs(request), request)) #절댓값을 기준으로 힙에 추가
