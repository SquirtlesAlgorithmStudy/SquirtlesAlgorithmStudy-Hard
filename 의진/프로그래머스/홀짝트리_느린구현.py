from collections import defaultdict, Counter
import sys


def dfs(start, visited_dict, node_dict):
    visited_dict[start] = 2
    ret = [start]
    for conn in node_dict[start]:
        if visited_dict[conn] == 1:
            ret.extend(dfs(conn, visited_dict, node_dict))
    return ret


def solution(nodes, edges):
    sys.setrecursionlimit(10**8)
    answer = [0, 0]
    node_dict = defaultdict(list)
    visited_dict = defaultdict(int)
    counter = Counter()
    for node in nodes:
        visited_dict[node] = 1
    for edge in edges:
        node_dict[edge[0]].append(edge[1])
        node_dict[edge[1]].append(edge[0])
        counter[edge[0]] += 1
        counter[edge[1]] += 1

    trees = []
    for k, v in visited_dict.items():
        if v == 1:
            trees.append(dfs(k, visited_dict, node_dict))

    for tree in trees:
        count_o = 0
        count_x = 0
        for node in tree:
            if node % 2 == counter[node] % 2:
                count_o += 1
            else:
                count_x += 1

        if count_o == 1:
            answer[0] += 1
        if count_x == 1:
            answer[1] += 1

    return answer
