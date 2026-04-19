input = open(0).readline
def main():
    pairs = []
    for _ in range(int(input())):
        h, o = map(int, input().split())
        pairs.append((h, o) if h < o else (o, h))
    d = int(input())
    arr = []
    for l, r in pairs:
        if r - l > d:
            continue
        arr.append((l, 1))
        arr.append((r - d, -1))
    arr = sorted(arr)
    mx = 0
    cnt = 0
    for n, flag in arr:
        cnt -= flag
        if cnt > mx:
            mx = cnt
    print(mx)
main()
