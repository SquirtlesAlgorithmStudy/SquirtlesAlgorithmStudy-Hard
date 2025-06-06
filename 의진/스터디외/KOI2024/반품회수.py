import sys

input = sys.stdin.readline

N = int(input())
X = list(map(int, input().split()))
T = list(map(int, input().split()))
not_finished = set([i for i in range(len(X))])
current = 0
current_time = 0
ans = 0
while not_finished:
    next_move = (float("inf"), -1)
    for nf in not_finished:
        cost = max(max(T[nf] - current_time, 0), abs(current - X[nf]))
        if next_move[0] > cost:
            next_move = (cost, nf)
    ans += next_move[0]
    current = X[next_move[1]]
    current_time += cost
    not_finished.remove(next_move[1])
    

print(ans)
