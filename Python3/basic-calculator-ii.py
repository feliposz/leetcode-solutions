class Solution:
    def calculate(self, s: str) -> int:
        def calc(i):
            def update(op, v):
                if op == '+':
                    stack.append(v)
                if op == '-':
                    stack.append(-v)
                if op == '*':
                    stack.append(stack.pop() * v)
                if op == '/':
                    stack.append(int(stack.pop() / v))

            num = 0
            stack = []
            sign = '+'

            while i < len(s):
                if s[i].isdigit():
                    num = num * 10 + int(s[i])
                elif s[i] in '+-*/':
                    update(sign, num)
                    num = 0
                    sign = s[i]
                elif s[i] == '(':
                    num, j = calc(i + 1)
                    i = j - 1
                elif s[i] == ')':
                    update(sign, num)
                    return sum(stack), i + 1
                i += 1
            update(sign, num)
            return sum(stack)

        return calc(0)