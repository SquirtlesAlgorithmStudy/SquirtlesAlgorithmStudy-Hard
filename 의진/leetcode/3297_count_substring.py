from collections import Counter


class Solution:
    def validSubstringCount(self, word1: str, word2: str) -> int:
        desired_state = Counter(list(word2))
        current_state = Counter(word1[0])
        ret = 0

        start_idx = 0
        end_idx = 0

        while end_idx < len(word1):
            if all(current_state[k] >= desired_state[k] for k in desired_state.keys()):
                ret += len(word1) - end_idx
                current_state[word1[start_idx]] -= 1
                start_idx += 1

            else:
                end_idx += 1
                if end_idx != len(word1):
                    current_state[word1[end_idx]] += 1
        return ret
