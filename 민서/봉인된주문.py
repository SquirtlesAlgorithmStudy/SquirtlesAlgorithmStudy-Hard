def s2n(string):
    n = 0
    b = 1
    for _ in string:
        n += b
        b *= 26
    b = 1
    for c in reversed(string):
        n += b * (ord(c) - ord('a'))
        b *= 26
    return n
def n2s(n):
    digits = 1
    b = 26
    while n > b:
        n -= b
        b *= 26
        digits += 1
    n -= 1
    string = []
    while n:
        string.append(chr(ord('a') + n % 26))
        n //= 26
    return 'a' * (digits - len(string)) + ''.join(string[::-1])
def solution(n, bans):
    bans = [s2n(b) for b in bans]
    bans = sorted(bans)
    i = 0
    while i < len(bans) and n >= bans[i]:
        i += 1
        n += 1
    return n2s(n)
