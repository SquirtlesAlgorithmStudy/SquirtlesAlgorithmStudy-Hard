import sys

input = sys.stdin.readline


N, M = map(int, input().split())
W = [-1] + list(map(int, input().split()))
connections = [[] for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, input().split())
    connections[b].append(a)
    connections[a].append(b)

W_idx = sorted([(i, v) for i, v in enumerate(W)], reverse=True)
state = [0] + [-1] * N

for idx, w in W_idx[:-1]:
    if state[idx] == -1:
        im_best_flag = True
        for conn in connections[idx]:
            if W[conn] > w:
                state[idx] = 0
                im_best_flag = False

            elif W[conn] == w:
                state[idx] = 0
                state[conn] = 0
                im_best_flag = False

            else:
                state[conn] = 0
        if im_best_flag:
            state[idx] = 1

print(sum(state))
