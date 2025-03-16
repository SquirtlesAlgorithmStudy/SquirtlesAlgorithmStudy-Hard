#백준 2018 연속된 자연수의 합 구하기

n = int(input())
count =1 # 1개의 숫자를 이용하여 N을 만들 수 있으므로

start_idx =1
end_idx =1
sum =1

while end_idx != n:
    if sum == n: #정답이면
        count +=1
        end_idx +=1
        sum += end_idx
    elif sum >n:
        sum =+ start_idx
        start_idx +=1
    else:
        end_idx +=1
        sum += end_idx

print(count)
    