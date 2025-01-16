class Node:
    def __init__(self, val, left, right, parent):
        self.val = val
        self.left = left
        self.right = right
        self.parent = parent


class BST:
    def __init__(self):
        self.node_list = []
        self.root = None

    def add(self, number):
        if self.root is None:
            self.root = Node(number, None, None, None)
            self.node_list.append(self.root)
        else:
            self._add(self.root, number)

    def _add(self, node, number):
        if node.val >= number:
            if node.left is None:
                node.left = Node(number, None, None, node)
                self.node_list.append(node.left)
            else:
                self._add(node.left, number)

        else:
            if node.right is None:
                node.right = Node(number, None, None, node)
                self.node_list.append(node.right)
            else:
                self._add(node.right, number)

    def find_inorder_successor(self, number):
        for node in self.node_list:
            if node.val == number:
                if node.parent is None:
                    if node.right is not None:
                        return self._go_left_bottom(node.right)
                    else:
                        return None
                elif node.parent.val > node.val:
                    return node.parent.val
                else:
                    if node.right is not None:
                        return self._go_left_bottom(node.right)
                    else:
                        return None

    def _go_left_bottom(self, node):
        if node.left is None:
            return node.val
        else:
            return self._go_left_bottom(node.left)


def solution(arr, find_val):
    bst = BST()
    for item in arr:
        bst.add(item)
    return bst.find_inorder_successor(find_val)


print(solution([10, 5, 30, 22, 35], 30))
