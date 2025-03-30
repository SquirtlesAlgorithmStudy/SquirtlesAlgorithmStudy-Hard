import sys

input = sys.stdin.readline

a = input().strip()
b = input().strip()

ans = 0

info_set = set()
code1 = [0 for _ in range(27)]
code2 = [0 for _ in range(27)]


def code2str(code):
    return "".join(map(lambda x: str(x).zfill(4), code))


def scan(s, code):
    left = 0
    right = 1
    phase = "toright"
    code[ord(s[0]) - ord("a")] += 1
    code[-1] += 1
    yield code2str(code)

    while True:
        if phase == "toright":
            right += 1
            code[ord(s[right - 1]) - ord("a")] += 1
            code[-1] += 1
            yield code2str(code)

            if right == len(s):
                phase = "toleft"
                left += 1
                code[ord(s[left - 1]) - ord("a")] -= 1
                code[-1] -= 1
                yield code2str(code)

        else:
            right -= 1
            code[ord(s[right]) - ord("a")] -= 1
            code[-1] -= 1
            yield code2str(code)

            if right == left + 1:
                left += 1
                right += 1
                code[ord(s[left - 1]) - ord("a")] -= 1
                code[ord(s[right - 1]) - ord("a")] += 1
                phase = "toright"
                yield code2str(code)

        if left + right == 2 * len(s) - 1:
            break


for res in scan(a, code1):
    info_set.add(res)

for res in scan(b, code2):
    if res in info_set:
        ans = max(ans, int(res[-4:]))

print(ans)
