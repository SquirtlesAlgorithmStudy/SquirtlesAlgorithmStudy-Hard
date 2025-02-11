class Solution:
    def dfs(self, v):
        self.visited[v] = 1
        for n in self.graph[v]:
            if self.visited[n]:
                return False
            if not self.finish[n]:
                if not self.dfs(n):
                    return False
        self.visited[v] = 0
        self.finish[v] = 1
        return True

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        self.graph = [[] for _ in range(numCourses)]
        self.visited = [0] * numCourses
        self.finish = [0] * numCourses
        for a, b in prerequisites:
            self.graph[a].append(b)
        for i in range(numCourses):
            if not self.dfs(i):
                return False
        return True
            
