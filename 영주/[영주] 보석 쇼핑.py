def solution(gems):
    answer = []
    gem_set_len = len(set(gems))
    gem_dict = {}

    start = 0
    end = 0
    sect = len(gems)+1

    while end < len(gems):
        if gems[end] not in gem_dict:
            gem_dict[gems[end]] = 1
        else:
            gem_dict[gems[end]] += 1

        end += 1

        if len(gem_dict) == gem_set_len:
            #print("19:",start+1, end)
            while start < end:
                start += 1
                if gem_dict[gems[start-1]] > 1:
                    gem_dict[gems[start-1]] -= 1
                else:
                    del gem_dict[gems[start-1]]
                    break
            if end-start<sect:
                sect= end-start
                answer = [start,end]
            #print("30:",start, end)
                
    return answer
