def alpha_to_num(alpha):
    res = 0
    for char in alpha:
        res *= 26
        res += ord(char) - ord("a") + 1
    return res


def num_to_alpha(num):
    rev_res = []
    while True:
        remainer = num % 26
        if remainer == 0:
            remainer = 26
        rev_res.append(chr(ord("a") + remainer - 1))
        if num <= 26:
            break
        if remainer == 26:
            num -= 26

        num //= 26
    return "".join(reversed(rev_res))


def solution(n, bans):
    answer = n
    bans = [alpha_to_num(ban) for ban in bans]
    for ban in sorted(bans):
        if ban <= answer:
            answer += 1

    return num_to_alpha(answer)
