
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n - 1:
            return False
        
        adj_list = {i: [] for i in range(n)}
        for i, j in edges:
            adj_list[i].append(j)
            adj_list[j].append(i)
        
        visited = set()
        queue = deque([0])
        
        while queue:
            curr = queue.popleft()
            if curr in visited:
                continue
            visited.add(curr)
            for neighbor in adj_list[curr]:
                if neighbor not in visited:
                    queue.append(neighbor)
        
        return len(visited) == n