class BT:
    def __init__(self, node_list):
        self.node_list = node_list
        self.size = len(node_list)
        self.path_list = []

    def traverse(self):
        self.path_list = []
        self._traverse(1, [self.node_list[1]])

    def _traverse(self, node_idx, path):
        is_leaf = True
        if 2 * node_idx < self.size and self.node_list[2 * node_idx] is not None:
            self._traverse(2 * node_idx, path + [self.node_list[2 * node_idx]])
            is_leaf = False
        if (
            2 * node_idx + 1 < self.size
            and self.node_list[2 * node_idx + 1] is not None
        ):
            self._traverse(2 * node_idx + 1, path + [self.node_list[2 * node_idx + 1]])
            is_leaf = False

        if is_leaf:
            self.path_list.append(path)

    def get_min_path_sum(self):
        self.traverse()
        min_val = float("inf")
        for path in self.path_list:
            print(path)
            min_val = min(min_val, sum(path))

        return min_val


bt = BT(
    [None, 10, 5, 5, None, 2, None, 1, None, None, None, None, None, None, -1, None]
)
print(bt.get_min_path_sum())
