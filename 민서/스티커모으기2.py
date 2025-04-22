def get_max(arr):
    memo = [[0, 0] for _ in range(len(arr) + 1)]
    for i, s in enumerate(arr):
        memo[i + 1][0] = memo[i][1] + s
        memo[i + 1][1] = max(memo[i])
    return max(memo[-1])
def solution(sticker):
    if len(sticker) > 1:
        return max(get_max(sticker[:-1]), get_max(sticker[1:]))
    else:
        return sticker[0]
