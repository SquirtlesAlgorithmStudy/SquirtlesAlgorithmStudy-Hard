from collections import Counter

a = [1, 3, 3, 4]

a.sort(reverse=True)
count_dict = {}

for item in a:
    if count_dict.get(item) is None:
        count_dict[item] = 1
    else:
        count_dict[item] += 1

for i in range(5):
    if count_dict.get(i) is None:
        count_dict[i] = 1
    else:
        continue


for k, v in count_dict.items():
    count_dict[2] = 1
