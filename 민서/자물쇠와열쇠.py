from itertools import chain
def slide_check(key, lock, N, M):
    for i in range(-M + 1, N):
        for j in range(-M + 1, N):
            nlock = lock[:]
            for r in range(max(i, 0), min(i + M, N)):
                for c in range(max(j, 0), min(j + M, N)):
                    nlock[r*N + c] ^= key[r - i][c - j]
            if sum(nlock) == N * N:
                return True
    return False

def rotate(key, M):
    nkey = [[0] * M for _ in range(M)]
    for i in range(M):
        for j in range(M):
            nkey[i][j] = key[j][M - 1 - i]
    return nkey

def solution(key, lock):
    M, N = len(key), len(lock)
    lock = [*chain.from_iterable(lock)]
    if slide_check(key, lock, N, M):
        return True
    for _ in range(3):
        key = rotate(key, M)
        if slide_check(key, lock, N, M):
            return True
    return False
