N = int(input().strip())
numbers= []

# 1. 정수부와 소수부로 분리
for _ in range(N):
    number = input().strip()
    int_part, left_part = "", ""
    now_in_int = True # 현재 처리 중인 부분이 정수부인지 소수부인지 나타냄
    
    for char in number:
        if char == '.':
            now_in_int = False
            continue
        if now_in_int:
            int_part += char   # 정수부 추가
        else:
            left_part += char  # 소수부 추가
    # 정수부와 소수부를 정수형으로 변환        
    integer = int(int_part)
    decimal = int(left_part) if left_part else -1
    # 정수부와 소수부를 튜플로 배열에 추가    
    numbers.append((integer, decimal))
        
# 2. 정렬
numbers.sort() #첫 번째 요소 → 두 번째 요소 순으로 정렬

# 3. 출력
for integer, decimal in numbers:
    if decimal == -1: # 소수부가 없는 경우
        print(integer)
    else:             # 소수부가 있는 경우
        print(f"{integer}.{decimal}")