import sys

input = sys.stdin.readline

n = int(input())
seq = list(map(int, input().split()))

if n == 3:
    print(seq[0] + seq[2])
    sys.exit()


def sub_problem(offset, seq):
    dp = [-float("inf")] * len(seq)
    dp[0] = seq[0]
    division = set()

    for i in range(1, len(seq)):
        if dp[i - 1] + seq[i] > seq[i]:
            dp[i] = dp[i - 1] + seq[i]

        else:
            dp[i] = seq[i]
            division.add(i - 1)

    result = max(((i, item) for i, item in enumerate(dp)), key=lambda x: x[1])

    idx_list = []
    idx_list.append(offset + result[0])
    i = result[0]
    i -= 1

    while i >= 0:
        if i in division:
            break
        else:
            idx_list.append(offset + i)
            i -= 1

    return result[1], idx_list


val1, idx_list1 = sub_problem(0, seq[:-2])
val2, idx_list2 = sub_problem(2, seq[2:])


val = -float("inf")

if idx_list1[-1] > 1:
    val = max(sub_problem(0, seq[: idx_list1[-1] - 1])[0], val)

if idx_list1[0] < len(seq) - 2:
    val = max(sub_problem(idx_list1[0] + 2, seq[idx_list1[0] + 2 :])[0], val)

val1 += val

val = -float("inf")

if idx_list2[-1] > 1:
    val = max(sub_problem(0, seq[: idx_list2[-1] - 1])[0], val)

if idx_list2[0] < len(seq) - 2:
    val = max(sub_problem(idx_list2[0] + 2, seq[idx_list2[0] + 2 :])[0], val)

val2 += val

ans = max(val1, val2)

print(ans)
