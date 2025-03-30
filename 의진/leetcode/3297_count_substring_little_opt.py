from collections import Counter


class Solution:
    def validSubstringCount(self, word1: str, word2: str) -> int:
        desired_state = Counter(list(word2))
        current_state = Counter(word1[0])
        matched = 1 if current_state[word1[0]] >= desired_state[word1[0]] else 0
        desired_matched = len(desired_state)
        ret = 0

        start_idx = 0
        end_idx = 0

        while end_idx < len(word1):
            if matched == desired_matched:
                ret += len(word1) - end_idx
                current_state[word1[start_idx]] -= 1
                if current_state[word1[start_idx]] < desired_state[word1[start_idx]]:
                    matched -= 1
                start_idx += 1

            else:
                end_idx += 1
                if end_idx != len(word1):
                    current_state[word1[end_idx]] += 1
                    if current_state[word1[end_idx]] == desired_state[word1[end_idx]]:
                        matched += 1
        return ret
