import sys

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    query = input().rstrip()
    reverse = str(query[::-1])

    result = 0

    q_i = 0
    r_i = 0

    while True:
        if query[q_i] != reverse[r_i]:
            result += 1
            if q_i + 1 == len(query):
                result += 1
                break

            if (
                query[:q_i] + query[q_i + 1 :]
                == reverse[: len(reverse) - 1 - r_i] + reverse[len(reverse) - r_i :]
            ):
                break

            if (
                reverse[:r_i] + reverse[r_i + 1 :]
                == query[: len(query) - 1 - q_i] + query[len(query) - q_i :]
            ):
                break

            result += 1
            break

        q_i += 1
        r_i += 1
        if q_i == len(query):
            break

    print(result)
