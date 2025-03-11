class Solution:
    def nthUglyNumber(self, n: int) -> int:
        if n == 1:
            return 1
        n -= 1
        ans = 1
        flag = set([1])
        n_2, n_3, n_5 = [1], [1], [1]
        i, j, k = 0, 0, 0
        while n:
            mn = min(n_2[i] * 2, n_3[j] * 3, n_5[k] * 5)
            if mn == n_2[i] * 2:
                i += 1
            elif mn == n_3[j] * 3:
                j += 1
            else:
                k += 1
            if mn not in flag:
                n -= 1
                flag.add(mn)
                n_2.append(mn)
                n_3.append(mn)
                n_5.append(mn)
        return n_2[-1]
