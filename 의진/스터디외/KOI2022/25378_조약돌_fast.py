n = int(input())
a = list(map(int, input().split()))

left = 0
cnt = 0
for i in range(1, n):
    temp = a[i]
    for j in range(i, left, -1):
        temp = a[j - 1] - temp

        if temp == 0:
            cnt += 1
            left = i + 1
            break
        elif temp < 0:
            break

print(n - cnt)
