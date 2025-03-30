import sys

input = sys.stdin.readline

K = int(input())
C = int(input())
queries = [tuple(map(int, input().split())) for _ in range(C)]

for query in queries:
    if query[0] == query[1]:
        print(1)
        continue

    if query[0] > query[1]:
        remain = K - query[1]
        score = query[0] - query[1]

        if score > (remain // 2) + 1:
            print(0)
        else:
            print(1)

    else:
        remain = K - query[0]
        score = query[1] - query[0]

        if score > (remain // 2 + remain % 2):
            print(0)
        else:
            print(1)
