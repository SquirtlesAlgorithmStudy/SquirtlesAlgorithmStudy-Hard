import time

st = time.time()
for i in range(10**7):
    a = st**2

et = time.time()

print(et - st)
