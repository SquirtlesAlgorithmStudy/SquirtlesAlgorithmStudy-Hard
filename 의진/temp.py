import time

# a = [1] * 100_000_000
a = {i: 1 for i in range(100_000_000)}
start_time = time.time()
for i in range(100_000_000):
    b = a[i]
print(time.time() - start_time)
