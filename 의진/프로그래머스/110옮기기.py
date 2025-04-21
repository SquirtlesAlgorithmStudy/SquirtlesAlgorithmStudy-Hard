def solution(s):
    answer = []

    for item in s:

        stack = []
        counter = 0
        for i in range(len(item)):
            if item[i] == "1":
                stack.append("1")
            else:
                if len(stack) >= 2 and stack[-1] == "1" and stack[-2] == "1":
                    counter += 1
                    stack.pop()
                    stack.pop()
                else:
                    stack.append("0")
        item = "".join(stack)
        pivot_i = -1
        for i in range(len(item) - 1, -1, -1):
            if item[i] == "0":
                pivot_i = i
                break

        result = item[: pivot_i + 1] + "110" * counter + item[pivot_i + 1 :]
        answer.append(result)

    return answer


print(solution(["100111100"]))
