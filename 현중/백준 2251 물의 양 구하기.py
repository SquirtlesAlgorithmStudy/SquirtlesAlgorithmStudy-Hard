from collections import deque

# A → B, A → C, B → A, B → C, C → A, C → B (총 6가지 이동)
Sender = [0, 0, 1, 1, 2, 2]
Receiver = [1, 2, 0, 2, 0, 1]

# 입력 받기
now = list(map(int, input().split()))  # [A, B, C] 물통 크기
visited = [[False for _ in range(201)] for _ in range(201)]  # 방문 여부
answer = [False] * 201  # 가능한 C의 물의 양 기록

def BFS():
    queue = deque()
    queue.append((0, 0))  # 초기 상태: A=0, B=0, C=now[2] (자동 결정)
    visited[0][0] = True
    answer[now[2]] = True  # 처음 C가 가득 찬 상태 저장

    while queue:
        now_A, now_B = queue.popleft()
        now_C = now[2] - now_A - now_B  # C 물통의 양은 자동 결정

        for k in range(6):  # 6가지 이동 방식 탐색
            next = [now_A, now_B, now_C]  # 현재 물통 상태 복사
            send, receive = Sender[k], Receiver[k]  # 이동할 물통 쌍 지정

            # 물 옮기기
            next[receive] += next[send]  # 받는 물통에 물 추가
            next[send] = 0  # 보낸 물통을 0으로 만들기

            # 초과하는 경우 조정 (넘치는 만큼 되돌려 넣기)
            if next[receive] > now[receive]:  
                next[send] = next[receive] - now[receive]  # 넘친 만큼 되돌려 넣기
                next[receive] = now[receive]  # 최대치로 채우기

            # 방문하지 않은 상태라면 BFS 큐에 추가
            if not visited[next[0]][next[1]]:
                visited[next[0]][next[1]] = True
                queue.append((next[0], next[1]))

                # A가 0일 때 C의 값을 기록
                if next[0] == 0:
                    answer[next[2]] = True

BFS()

# 가능한 C의 물 양을 정렬하여 출력
for i in range(len(answer)):
    if answer[i]:
        print(i, end=" ")
