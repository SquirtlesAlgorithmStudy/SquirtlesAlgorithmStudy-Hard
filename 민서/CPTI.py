input = open(0).readline
N, M = map(int, input().split())
codes = [int(input().rstrip(), 2) for _ in range(N)]
codes_map = {codes[0]: 1}
adjs = [0]
for i in range(M):
    adjs.append(1 << i)
    for j in range(i + 1, M):
        adjs.append((1 << i) + (1 << j))
ans = 0
for c in codes[1:]:
    for adj in adjs:
        if codes_map.get(c ^ adj) is not None:
            ans += codes_map[c ^ adj]
    if codes_map.get(c) is not None:
        codes_map[c] += 1
    else:
        codes_map[c] = 1
print(ans)
