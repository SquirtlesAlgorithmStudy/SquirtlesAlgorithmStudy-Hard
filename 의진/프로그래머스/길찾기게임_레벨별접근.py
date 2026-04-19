from collections import deque, defaultdict
import sys

sys.setrecursionlimit(10**9)


class Node:
    def __init__(self, idx):
        self.idx = idx
        self.left = None
        self.right = None


def solution(nodeinfo):
    # 노드 정보에 인덱스 추가 (인덱스는 1부터 시작)
    indexed_nodeinfo = [(i + 1, x, y) for i, (x, y) in enumerate(nodeinfo)]

    # 노드 객체 생성
    nodes = [Node(i) for i in range(len(nodeinfo) + 1)]

    # y좌표 내림차순으로 정렬 (같은 y값은 x좌표 오름차순)
    indexed_nodeinfo.sort(key=lambda x: (-x[2], x[1]))

    # 루트 노드 찾기 (y좌표가 가장 큰 노드)
    root_idx = indexed_nodeinfo[0][0]

    # 레벨별로 노드 분류
    level_dict = defaultdict(list)
    current_level = 0
    current_y = indexed_nodeinfo[0][2]

    for idx, x, y in indexed_nodeinfo:
        if y == current_y:
            level_dict[current_level].append((idx, x))
        else:
            current_level += 1
            current_y = y
            level_dict[current_level].append((idx, x))

    # 각 노드의 영역 정의 (각 노드는 자신의 x좌표를 중심으로 왼쪽과 오른쪽 경계를 가짐)
    # 초기에는 루트 노드가 전체 영역을 차지
    regions = {}  # (left_bound, right_bound) 형태로 각 노드의 영역 저장
    regions[root_idx] = (float("-inf"), float("inf"))

    # 레벨별로 노드 연결
    for level in range(current_level):
        current_nodes = level_dict[level]
        next_nodes = level_dict[level + 1]

        for next_idx, next_x in next_nodes:
            # 다음 레벨의 각 노드에 대해 적절한 부모 찾기
            for parent_idx, parent_x in current_nodes:
                left_bound, right_bound = regions[parent_idx]

                # 노드가 부모의 영역 내에 있는지 확인
                if left_bound < next_x < right_bound:
                    # 노드가 부모의 왼쪽에 있는 경우
                    if next_x < parent_x:
                        nodes[parent_idx].left = nodes[next_idx]
                        # 왼쪽 자식의 영역 설정
                        regions[next_idx] = (left_bound, parent_x)
                    # 노드가 부모의 오른쪽에 있는 경우
                    else:
                        nodes[parent_idx].right = nodes[next_idx]
                        # 오른쪽 자식의 영역 설정
                        regions[next_idx] = (parent_x, right_bound)
                    break

    # 전위 순회와 후위 순회
    preorder = []
    postorder = []

    def dfs(node_idx):
        if node_idx == 0:
            return

        preorder.append(node_idx)

        if nodes[node_idx].left:
            dfs(nodes[node_idx].left.idx)

        if nodes[node_idx].right:
            dfs(nodes[node_idx].right.idx)

        postorder.append(node_idx)

    dfs(root_idx)

    return [preorder, postorder]
