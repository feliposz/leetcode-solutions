class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        for n in range(k):
            max_g = 0
            for i in range(len(gifts)):
                if gifts[i] > gifts[max_g]:
                    max_g = i
            gifts[max_g] = int(gifts[max_g] ** 0.5)
        return sum(gifts)