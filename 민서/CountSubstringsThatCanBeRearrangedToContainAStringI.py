class Solution:
    def valid_dic(self, dic):
        for v in dic.values():
            if v < 0:
                return False
        return True
    def validSubstringCount(self, word1: str, word2: str) -> int:
        answer = 0
        dic = {}
        for c in word2:
            if dic.get(c) is not None:
                dic[c] -= 1
            else:
                dic[c] = -1
        i, j = 0, 0
        while j < len(word1):
            while j < len(word1) and not self.valid_dic(dic):
                if dic.get(word1[j]) is not None:
                    dic[word1[j]] += 1
                j += 1
            while i < j and self.valid_dic(dic):
                answer += len(word1) - j + 1
                if dic.get(word1[i]) is not None:
                    dic[word1[i]] -= 1
                i += 1
        return answer
