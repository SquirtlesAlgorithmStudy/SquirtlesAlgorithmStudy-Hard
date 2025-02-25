class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        now_gas = 0
        now_gas_list = []
        for idx, (g, c) in enumerate(zip(gas, cost)):
            now_gas_list.append((now_gas, idx))
            now_gas += g
            now_gas -= c

        if now_gas < now_gas_list[0][0]:
            return -1

        return min(now_gas_list)[1]
