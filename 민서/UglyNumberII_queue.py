from collections import deque
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        if n == 1:
            return 1
        n -= 1
        ans = 1
        flag = set([1])
        n_2, n_3, n_5 = deque([1]), deque([1]), deque([1])
        while n:
            mn = min(n_2[0] * 2, n_3[0] * 3, n_5[0] * 5)
            if mn == n_2[0] * 2:
                n_2.popleft()
            elif mn == n_3[0] * 3:
                n_3.popleft()
            else:
                n_5.popleft()
            if mn not in flag:
                n -= 1
                flag.add(mn)
                n_2.append(mn)
                n_3.append(mn)
                n_5.append(mn)
        return n_2[-1]
