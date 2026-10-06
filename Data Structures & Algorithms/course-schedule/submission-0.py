class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj_map = {i: [] for i in range(numCourses)} 
        inorder = [0 for _ in range(numCourses)]

        for course, preq in prerequisites:
            adj_map[preq].append(course)
            inorder[course] += 1

        que = deque()
        for i in range(numCourses):
            if inorder[i] == 0:
                que.append(i) 

        ans = 0
        while que:
            curr = que.popleft()
            ans += 1
            for neighbor in adj_map[curr]: 
                inorder[neighbor] -= 1
                if inorder[neighbor] == 0:
                    que.append(neighbor)

        return ans == numCourses