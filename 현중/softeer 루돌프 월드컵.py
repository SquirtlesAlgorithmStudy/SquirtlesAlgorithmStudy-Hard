#softeer 루돌프 월드컵

import sys
import itertools

#1. 루돌프 힘 입력
F = list(map(int, input().split()))
prob = [[(0,0,0)]*4 for _ in range(4)]

#2. W,D,L 확률 계산
def match_probable(Fi, Fj):
    win_i = (4 * Fi) / (5*(Fi +Fj))
    win_j = (4 * Fj) / (5*(Fi +Fj))
    draw = (Fi + Fj) / (5*(Fi +Fj))
    return win_i, win_j, draw
    
def compute_score(results):
    scores = [0, 0, 0, 0]
    matches = [(0, 1), (0, 2), (0, 3), (1, 2), (1, 3), (2, 3)]  # 6경기
    probability = 1.0

    for idx, result in enumerate(results):
        a, b = matches[idx]
        if result == 0:  # a 승리
            scores[a] += 3
            probability *= prob[a][b][0]
        elif result == 1:  # b 승리
            scores[b] += 3
            probability *= prob[a][b][1]
        else:  # 무승부
            scores[a] += 1
            scores[b] += 1
            probability *= prob[a][b][2]

    return scores, probability

#3. 완전탐색하여 모든 결과 조합 탐색(1,2 == 2,1)
for i in range(4):
    for j in range(i + 1, 4):
        prob[i][j] = match_prob(F[i], F[j])
        prob[j][i] = (prob[i][j][1], prob[i][j][0], prob[i][j][2])  # 반대 방향도 저장

total_probability = 0

#4. 최종 순위 결정
for results in itertools.product(range(3), repeat=6):
    scores, prob_val = compute_score(results)
    
#5. 1번 루돌프가 상위2마리 안에 들어갈 확률 계산
    sorted_scores = sorted([(score, -idx) for idx, score in enumerate(scores)], reverse=True)
    if sorted_scores[0][1] == -0 or sorted_scores[1][1] == -0:
        total_probability += prob_val
        
#6. 최종확률을 소숫점 3째짜리 까지 반올림
print(f"{total_probability * 100:.3f}")