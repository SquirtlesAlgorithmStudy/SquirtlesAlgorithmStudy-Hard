import sys

input = sys.stdin.readline

N = int(input())
M = int(input())
relations = [tuple(map(int, input().split())) for _ in range(M)]

dp = [[-1] * (N + 1) for _ in range(N + 1)]

middle_dict = {}
basic_set = set(range(1, N + 1))

for rel in relations:
    if middle_dict.get(rel[0]) is None:
        middle_dict[rel[0]] = {rel[1]: rel[2]}
        basic_set.remove(rel[0])
    else:
        middle_dict[rel[0]][rel[1]] = rel[2]


def get_num(target):
    result = [0] * (N + 1)
    result[target] = 1
    for material in range(1, N + 1):
        if dp[material][target] != -1:
            result[material] = dp[material][target]
        else:
            if (
                middle_dict.get(target) is not None
                and middle_dict[target].get(material) is not None
            ):

                for i, item in enumerate(get_num(material)[1:]):
                    result[i + 1] += item * middle_dict[target][material]

    for i, res in enumerate(result):
        dp[i][target] = res

    return result


result = get_num(N)

for i, value in enumerate(result[1:]):
    if i + 1 in basic_set:
        print(i + 1, value)
