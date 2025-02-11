def rotate(key_coord_case, key):
    return [(len(key) - 1 - item[1], item[0]) for item in key_coord_case]


def inspect(key_coord_case, lock_ok, lock_no):
    cnt = len(lock_ok)
    for k in key_coord_case:
        if k in lock_no:
            return False
        if k in lock_ok:
            cnt -= 1
    if cnt == 0:
        return True
    else:
        return False


def solution(key, lock):
    lock_ok = set()
    lock_no = set()
    key_coord = []

    for i in range(len(lock)):
        for j in range(len(lock[0])):
            if lock[i][j] == 1:
                lock_no.add((i, j))
            else:
                lock_ok.add((i, j))

    for i in range(len(key)):
        for j in range(len(key[0])):
            if key[i][j] == 1:
                key_coord.append((i, j))

    key_coord_90 = rotate(key_coord, key)
    key_coord_180 = rotate(key_coord_90, key)
    key_coord_270 = rotate(key_coord_180, key)

    for i in range((-len(lock) + 1), len(lock)):
        for j in range((-len(lock) + 1), len(lock)):
            key_coord_case = [(item[0] + i, item[1] + j) for item in key_coord]
            # print(key_coord_case)
            if inspect(key_coord_case, lock_ok, lock_no):
                return True
            key_coord_case = [(item[0] + i, item[1] + j) for item in key_coord_90]
            # print(key_coord_case)
            if inspect(key_coord_case, lock_ok, lock_no):
                return True
            key_coord_case = [(item[0] + i, item[1] + j) for item in key_coord_180]
            # print(key_coord_case)
            if inspect(key_coord_case, lock_ok, lock_no):
                return True
            key_coord_case = [(item[0] + i, item[1] + j) for item in key_coord_270]
            # print(key_coord_case)
            if inspect(key_coord_case, lock_ok, lock_no):
                return True

    return False
