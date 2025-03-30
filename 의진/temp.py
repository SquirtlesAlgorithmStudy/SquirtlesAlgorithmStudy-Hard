import time

print("Hello" * 1000000, end="")  # 버퍼에 저장되고 즉시 출력되지 않음
time.sleep(2)  # 2초 대기
print("World!")  # 이제 출력됨
