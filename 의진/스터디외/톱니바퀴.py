import sys

input = sys.stdin.readline

topni = [input().strip() for _ in range(4)]
k = int(input())
commands = [tuple(map(int, input().split())) for _ in range(k)]


def get_intersection(topni):
    intersection = []
    for i in range(3):
        left = topni[i]
        right = topni[i + 1]

        intersection.append(left[2] != right[6])
    return intersection


def make_topni_to_state(topni):
    state = {}
    state["topni"] = topni
    state["intersection"] = get_intersection(topni)
    return state


def make_plan(state, command):
    plan = [command]
    # 왼쪽으로 간다.
    now = command[0]
    direction = command[1]
    while True:
        if now == 1:
            break

        if state["intersection"][now - 2]:
            plan.append((now - 1, -direction))
            now -= 1
            direction = -direction
        else:
            break

    # 오른쪽으로 간다.

    now = command[0]
    direction = command[1]
    while True:
        if now == 4:
            break

        if state["intersection"][now - 1]:
            plan.append((now + 1, -direction))
            now += 1
            direction = -direction
        else:
            break
    return plan


def rotate_gear(state, p):
    a = state["topni"][p[0] - 1]
    if p[1] == 1:
        a = a[-1] + a[:-1]
    else:
        a = a[1:] + a[0]
    state["topni"][p[0] - 1] = a

    return state


def operate(state, command):
    plan = make_plan(state, command)
    for p in plan:
        rotate_gear(state, p)
    state["intersection"] = get_intersection(state["topni"])


def get_score(state):
    score = 0
    for i, topni in enumerate(state["topni"]):
        score += int(topni[0]) * (2 ** (i))

    return score


state = make_topni_to_state(topni)


for command in commands:
    operate(state, command)


print(get_score(state))
