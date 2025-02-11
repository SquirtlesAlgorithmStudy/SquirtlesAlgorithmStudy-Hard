# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def is_valid_node(node, valid_min, valid_max):
            if node is None:
                return True

            if node.left and not (valid_min < node.left.val < node.val):
                return False
            if node.right and not (node.val < node.right.val < valid_max):
                return False

            return is_valid_node(node.left, valid_min, node.val) and is_valid_node(
                node.right, node.val, valid_max
            )

        return is_valid_node(root, -float("inf"), float("inf"))
