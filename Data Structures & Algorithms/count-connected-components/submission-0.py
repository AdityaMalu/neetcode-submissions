class Solution:
    def trav(self,node,adjList,vis):
        que = deque()
        que.append(node)

        while que:
            curr = que.popleft()
            for it in adjList[curr]:
                if not vis[it]:
                    vis[it] = True
                    que.append(it)
                    

    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adjList = {i : [] for i in range(n)}
        vis = [False]*n

        for i,j in edges:
            adjList[i].append(j)
            adjList[j].append(i)
        
        ans = 0
        for i in range(n):
            if not vis[i] :
                ans+=1
                self.trav(i,adjList,vis)

        return ans
        