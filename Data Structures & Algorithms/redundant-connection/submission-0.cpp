class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> indegree(n+1 , 0);
        vector<vector<int>> adj(n+1);
        for(auto &edge: edges){
            int u = edge[0];
            int v= edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            indegree[u]++;
            indegree[v]++;
        }

        queue<int> q;

        for(int i = 1 ; i <= n ; i++){
            if(indegree[i] == 1) q.push(i);
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            indegree[curr]--;

            for(int i : adj[curr]){
                indegree[i]--;
                if(indegree[i] == 1) q.push(i);
            }
        }


        for(int i = edges.size() - 1 ; i >= 0; i--){
            int u = edges[i][0];
            int v = edges[i][1];

            if(indegree[u] == 2 && indegree[v]){
                return {u,v};
            }
        }

        return {};
    }
};
