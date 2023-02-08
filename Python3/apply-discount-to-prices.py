class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        words = sentence.split()
        result = []
        pct = (100 - discount) / 100
        for word in words:
            if re.match('^\$\d+$', word):
                value = float(word[1:]) * pct
                result.append('$%.2f' % (value))
            else:
                result.append(word)
        return ' '.join(result)