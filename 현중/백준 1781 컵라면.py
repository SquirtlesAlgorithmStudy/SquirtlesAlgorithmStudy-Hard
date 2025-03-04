#백준 1781 컵라면

#1. 입력받기
import sys
import heapq

read = sys.stdin.readline
N = int(read().strip())

problems = []
for _ in range(N):
    d,r = map(int, read().strip()) #deadline, raman
    problems.append((d,r))

#2. deadline을 오름차순정렬
problems.sort()

#3. 우선순위queue를 사용하여 만약 heap에 들어간 갯수가 데드라인을 초과하면 가장 작은 컵라면 개수 제거
min_heap = []
for d,r in problems:
    heapq.heappush(min_heap, r) #현재 문제를 선택
    if len(min_heap) > d:
        heapq.heappop(min_heap)
        
#4. 최소힙에 남은 컵라면 수 모두 더하기
print(sum(min_heap))
