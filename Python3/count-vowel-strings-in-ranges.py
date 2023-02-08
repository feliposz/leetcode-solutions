class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        tmp = []
        isV = []
        count = 0
        vowels = 'aeiouAEIOU'
        for word in words:
            isVowel =  word[0] in vowels and word[-1] in vowels
            if isVowel:
                count += 1
            isV.append(isVowel)
            tmp.append(count)
        tmp.append(count)
        result = []
        for q in queries:
            l, r = q
            if l == r:
                result.append(1 if isV[l] else 0)
            elif l > 0:
                result.append(tmp[r] - tmp[l-1])
            else:
                result.append(tmp[r])
        return result