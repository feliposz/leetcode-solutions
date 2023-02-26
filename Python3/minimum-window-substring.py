class Solution:
    def minWindow(self, s: str, t: str) -> str:
        targetLetterCounts = collections.Counter(t)
        start = 0
        minWindow = ""
        targetLen = len(t)

        for end in range(len(s)):
            if targetLetterCounts[s[end]] > 0:
                targetLen -= 1
            targetLetterCounts[s[end]] -= 1

            while targetLen == 0:
                windowLen = end - start + 1
                if not minWindow or windowLen < len(minWindow):
                    minWindow = s[start : end + 1]
                targetLetterCounts[s[start]] += 1
                if targetLetterCounts[s[start]] > 0:
                    targetLen += 1
                start += 1

        return minWindow

