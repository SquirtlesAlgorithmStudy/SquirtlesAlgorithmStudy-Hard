from collections import defaultdict
import sys

sys.setrecursionlimit(10**9)


class Node:
    def __init__(self, idx):
        self.idx = idx
        self.left = None
        self.right = None


def solution(nodeinfo):
    # 노드 정보에 인덱스 추가
    nodes_with_idx = [(i + 1, x, y) for i, (x, y) in enumerate(nodeinfo)]

    # 노드 객체 생성
    nodes = [Node(i) for i in range(len(nodeinfo) + 1)]

    def find_root(node_list):
        return max(node_list, key=lambda x: x[2])

    def divide_nodes(node_list, root_x):
        left_nodes = [node for node in node_list if node[1] < root_x]
        right_nodes = [node for node in node_list if node[1] > root_x]
        return left_nodes, right_nodes

    def build_tree(node_list):
        if not node_list:
            return None

        root = find_root(node_list)
        root_idx, root_x, root_y = root

        # 루트 제거 후 나머지 노드 분리
        remaining = [node for node in node_list if node != root]
        left_nodes, right_nodes = divide_nodes(remaining, root_x)

        # 재귀적으로 왼쪽, 오른쪽 서브트리 구성
        if left_nodes:
            left_root = build_tree(left_nodes)
            nodes[root_idx].left = nodes[left_root]

        if right_nodes:
            right_root = build_tree(right_nodes)
            nodes[root_idx].right = nodes[right_root]

        return root_idx

    # 트리 구성
    root_idx = build_tree(nodes_with_idx)

    # 전위 순회와 후위 순회
    preorder = []
    postorder = []

    def traverse(node_idx):
        if node_idx == 0:
            return

        preorder.append(node_idx)

        if nodes[node_idx].left:
            traverse(nodes[node_idx].left.idx)

        if nodes[node_idx].right:
            traverse(nodes[node_idx].right.idx)

        postorder.append(node_idx)

    traverse(root_idx)

    return [preorder, postorder]
