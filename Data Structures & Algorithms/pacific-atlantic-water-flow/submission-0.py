class Solution:
    def trav(self, heights: List[List[int]], vis: List[List[bool]], queue: deque):
        
        m, n = len(heights), len(heights[0])
        directions = [(0, 1), (0, -1), (-1, 0), (1, 0)]  # right, left, up, down
        
        while queue:
            row, col = queue.popleft()  # More efficient than pop(0)
            
            for dr, dc in directions:
                new_row, new_col = row + dr, col + dc
                
                # Check bounds and conditions
                if (0 <= new_row < m and 0 <= new_col < n and 
                    not vis[new_row][new_col] and 
                    heights[new_row][new_col] >= heights[row][col]):  # Water flows to equal/lower
                    
                    vis[new_row][new_col] = True
                    queue.append((new_row, new_col))

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        
        if not heights or not heights[0]:
            return []
        
        m, n = len(heights), len(heights[0])
        
        # Use boolean matrices for better memory efficiency
        pacific_reachable = [[False] * n for _ in range(m)]
        atlantic_reachable = [[False] * n for _ in range(m)]
        
        # Use deque for better performance
        pacific_queue = deque()
        atlantic_queue = deque()
        
        # Initialize Pacific (top and left edges) and Atlantic (bottom and right edges)
        for i in range(m):
            # Left edge -> Pacific, Right edge -> Atlantic
            pacific_queue.append((i, 0))
            atlantic_queue.append((i, n - 1))
            pacific_reachable[i][0] = True
            atlantic_reachable[i][n - 1] = True
        
        for j in range(n):
            # Top edge -> Pacific, Bottom edge -> Atlantic
            pacific_queue.append((0, j))
            atlantic_queue.append((m - 1, j))
            pacific_reachable[0][j] = True
            atlantic_reachable[m - 1][j] = True
        
        # Perform BFS from both oceans
        self.trav(heights, pacific_reachable, pacific_queue)
        self.trav(heights, atlantic_reachable, atlantic_queue)
        
        # Find cells reachable by both oceans
        result = []
        for i in range(m):
            for j in range(n):
                if pacific_reachable[i][j] and atlantic_reachable[i][j]:
                    result.append([i, j])
        
        return result

        