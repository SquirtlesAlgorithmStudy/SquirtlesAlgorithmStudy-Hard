import sys

sys.setrecursionlimit(int(10e9))


def find(start, parents, answer):
    if parents.get(start) is None:
        answer.append(start)
        parents[start] = start + 1
        return start + 1
    else:
        parent = find(parents[start], parents, answer)
        parents[start] = parent
        return parent


def solution(k, room_number):
    parents = {}
    answer = []
    for room in room_number:
        find(room, parents, answer)

    return answer
