push_element = [1, 2, 3]
pop_element = []


def main(push_element, pop_element):
    if len(pop_element) == 0:
        return True
    is_push_finished = False
    push_idx = 0
    pop_idx = 0
    stack = []
    while True:
        if not is_push_finished:
            stack.append(push_element[push_idx])
            if push_idx + 1 == len(push_element):
                is_push_finished = True
            else:
                push_idx += 1

        if stack and (stack[-1] == pop_element[pop_idx]):
            stack.pop()
            if pop_idx + 1 == len(pop_element):
                return True
            pop_idx += 1

        else:
            if is_push_finished:
                return False


print(main(push_element, pop_element))
