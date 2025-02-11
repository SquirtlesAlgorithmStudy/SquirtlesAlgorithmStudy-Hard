from collections import deque


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        self.in_degree = [0 for _ in range(numCourses)]
        self.queue = deque()
        self.connections = [[] for _ in range(numCourses)]

        for pre in prerequisites:
            self.in_degree[pre[0]] += 1
            self.connections[pre[1]].append(pre[0])

        for idx, ent in enumerate(self.in_degree):
            if ent == 0:
                self.queue.append(idx)

        for _ in range(numCourses):
            if not self.queue:
                return False
            item = self.queue.popleft()
            for conn in self.connections[item]:
                self.in_degree[conn] -= 1
                if self.in_degree[conn] == 0:
                    self.queue.append(conn)

        return True
