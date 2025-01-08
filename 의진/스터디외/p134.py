class SparseArray:
    def __init__(self, arr, size):
        self.size = size
        self.sparse_arr = {i: val for i, val in enumerate(arr) if val != 0}

    def set(self, i, val):
        if i >= self.size:
            raise IndexError()
        self.sparse_arr[i] = val

    def get(self, i):
        if i >= self.size:
            raise IndexError()
        if self.sparse_arr.get(i) is None:
            return 0
        else:
            return self.sparse_arr[i]


sa = SparseArray([0, 0, 0, 1, 0, 0], 6)
print(sa.get(2))
print(sa.set(2, 2))
print(sa.get(2))
print(sa.get(3))
print(sa.get(10))
