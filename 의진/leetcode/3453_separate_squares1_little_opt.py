# 819 ms
class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        start = 0
        max_height_square = max(squares, key=lambda item: item[1] + item[2])
        end = max_height_square[1] + max_height_square[2]
        self.total = sum(sq[2] * sq[2] for sq in squares)
        while start <= end:
            mid = (start + end) // 2
            if self._do_test(mid, squares):
                start = mid + 1
            else:
                end = mid - 1

        small_upper, big_lower = self._get_all_square_area(start, squares)
        big_upper, _ = self._get_all_square_area(end, squares)
        middle = (small_upper + big_lower) / 2

        return end + ((big_upper - middle) / (big_upper - small_upper))

    def _get_all_square_area(self, mid, squares):
        upper = 0
        lower = 0
        for sq in squares:
            if sq[1] <= mid <= sq[1] + sq[2]:
                upper += sq[2] * (sq[1] + sq[2] - mid)
                continue

            if sq[1] > mid:
                upper += sq[2] * sq[2]

        return upper, self.total - upper

    def _do_test(self, mid, squares):
        upper, lower = self._get_all_square_area(mid, squares)
        return upper > lower


"""
. 제곱 (Exponentiation)
비용: 매우 높음
이유: 제곱 연산(예: 
𝑎
𝑏
a 
b
 )은 일반적으로 반복적인 곱셈이나 로그/지수 함수를 통해 구현되며, 정수 제곱이라도 여러 단계의 곱셈이 필요합니다. CPU에 전용 명령어가 없으므로 소프트웨어적으로 계산되는 경우가 많아 비용이 큽니다.
예상 사이클: 단순 
𝑛
2
n 
2
 의 경우 최소 곱셈 1회 이상, 더 높은 차수는 훨씬 더 많은 연산 필요.
2. 나눗셈 (Division)
비용: 높음
이유: 나눗셈은 덧셈이나 곱셈에 비해 하드웨어에서 더 복잡한 알고리즘(예: Long Division 또는 Newton-Raphson 방법)을 사용합니다. 특히 부동소수점 나눗셈은 정밀도 계산 때문에 추가 시간이 걸립니다.
예상 사이클: 10~40 사이클 (정수/부동소수점 및 CPU에 따라 다름).
3. 곱셈 (Multiplication)
비용: 중간
이유: 곱셈은 현대 CPU에서 전용 회로로 최적화되어 있지만, 덧셈/뺄셈보다 복잡한 비트 연산을 요구합니다. 부동소수점 곱셈은 정수 곱셈보다 약간 더 비용이 높습니다.
예상 사이클: 15 사이클 (정수), 310 사이클 (부동소수점).
4. 조건문 (Conditional Statements)
비용: 낮음 ~ 중간
이유: 조건문 자체(예: 비교 연산)는 매우 빠르게 실행되지만, 분기 예측(branch prediction) 실패로 인한 파이프라인 스톨(pipeline stall)이 발생하면 비용이 증가할 수 있습니다. 순수 비교 연산은 덧셈 수준이지만, 분기 오버헤드가 변수입니다.
예상 사이클: 1~3 사이클 (성공적 예측), 10+ 사이클 (예측 실패 시).
5. 덧셈 (Addition)
비용: 매우 낮음
이유: 덧셈은 CPU에서 가장 기본적이고 최적화된 연산으로, 단일 사이클 내에서 완료됩니다. 정수와 부동소수점 모두 빠르게 처리됩니다.
예상 사이클: 1 사이클.
6. 뺄셈 (Subtraction)
비용: 매우 낮음
이유: 뺄셈은 덧셈과 거의 동일한 수준의 비용을 가지며, 내부적으로 2의 보수 연산으로 덧셈처럼 처리됩니다. 하드웨어적으로 차이가 거의 없습니다.
예상 사이클: 1 사이클.
최종 순서 (비용 큰 순 → 작은 순)
제곱
나눗셈
곱셈
조건문 (상황에 따라 변동 가능)
덧셈
뺄셈
"""
