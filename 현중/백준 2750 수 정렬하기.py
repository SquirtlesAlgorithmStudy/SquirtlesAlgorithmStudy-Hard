# 백준 2750 수 정렬하기

# sort()를 사용해도 되지만 버블정렬로 쌩 구현해보기 -> 시간 범위가 1,000으로 작기에 n^2로도 구현할 수 있다.

N = int(input())
A = [0] * N

# 정렬되지 않은 A값을 받아와
for i in range(N):
    A[i] = int(input())

# 버블정렬
for i in range(N-1):
    for j in range(N-1-i): # loop가 돌수록 fix값이 생기므로 N-1 -> N-1-i... 번 돌게 됌
        if A[j] > A[j+1]:  # 앞에 있는 수가 크면 swap? => 버블정렬
            #swap
            temp = A[j]
            A[j] = A[j+1]
            A[j+1] = temp

for i in range(N):
    print(A[i]) # A배열을 그대로 출력하면 되지!
                # 결국 버벌정렬의 swap이 한번도 일어나지 않은 루프가 언제?