input = open(0).readline
def game(a, b, matrix):
    if matrix[a - 1][b - 1] == 2:
        return True
    return False
N, K = map(int, input().split())
matrix = [[*map(int, input().split())] for _ in range(N)]
B_que = [*map(int, input().split())]
C_que = [*map(int, input().split())]
A_use = [False] * (N + 1)
win = [0, 0, 0]
def bruteforce(A_use, bidx, cidx, turn, win):
    if win[0] == K:
        return True
    if win[1] == K or win[2] == K:
        return False
    if turn == 0:
        for i in range(1, N + 1):
            if A_use[i]:
                continue
            result = game(i, B_que[bidx], matrix)
            win[0 if result else 1] += 1
            A_use[i] = True
            if bruteforce([*A_use], bidx + 1, cidx, 1 if result else 2, [*win]):
                return True
            win[0 if result else 1] -= 1
            A_use[i] = False
        return False
    elif turn == 1:
        for i in range(1, N + 1):
            if A_use[i]:
                continue
            result = game(i, C_que[cidx], matrix)
            win[0 if result else 2] += 1
            A_use[i] = True
            if bruteforce([*A_use], bidx, cidx + 1, 0 if result else 2, [*win]):
                return True
            win[0 if result else 2] -= 1
            A_use[i] = False
        return False
    else:
        result = game(B_que[bidx], C_que[cidx], matrix)
        win[1 if result else 2] += 1
        if bruteforce(A_use, bidx + 1, cidx + 1, 0 if result else 1, win):
            return True
        return False
ans = bruteforce(A_use, 0, 0, 0, win)
print(int(ans))
