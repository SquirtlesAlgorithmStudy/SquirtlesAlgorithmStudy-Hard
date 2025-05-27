import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**9)
set_db = set()
cache_dict = {}


def get_process(message):
    if len(message) == 0:
        return 1

    if message[0] == "0":
        return 0

    if cache_dict.get(message) is not None:
        return cache_dict[message]

    result = 0

    if len(message) >= 2 and (int(message[:2]) <= 26):
        result += get_process(message[2:])

    result += get_process(message[1:])

    cache_dict[message] = result
    return result


message = input().strip()


print(get_process(message) % 1000000)
