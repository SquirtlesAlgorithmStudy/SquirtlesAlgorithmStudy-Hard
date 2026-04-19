import sys
from collections import deque

input = sys.stdin.readline

S = input().rstrip()

A_queue = deque()
B_queue = deque()
C_queue = deque()

for i, s in enumerate(S):
    if s == "A":
        A_queue.append(i)
    elif s == "B":
        B_queue.append(i)
    else:
        C_queue.append(i)

ans = 0
while B_queue:
    item = B_queue.popleft()

    if C_queue and item < C_queue[0]:
        ans += 1
        C_queue.popleft()
        continue
    elif A_queue and A_queue[0] < item:
        ans += 1
        A_queue.popleft()
        continue

print(ans)
