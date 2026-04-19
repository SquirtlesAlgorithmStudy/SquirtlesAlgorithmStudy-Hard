def main():
    s = open(0).readline().rstrip()
    r = s.count("R")
    i, j = 0, len(s) - 1
    ans = r
    k = 0
    while r:
        if s[i] == "R":
            i += 1
            r -= 1
            continue
        if s[j] == "R":
            j -= 1
            r -= 1
            continue
        i += 1
        j -= 1
        k += 2
        ans = max(r + k, ans)
    print(ans)
main()
