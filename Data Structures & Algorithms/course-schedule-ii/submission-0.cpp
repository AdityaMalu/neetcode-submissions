class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<int> courseAlreadyDone(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
        queue<int> q;

        for (vector<int> i : prerequisites) {
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
                courseAlreadyDone[i] = 1;
            }
        }


        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (indegree[curr] == 0){
                ans.push_back(curr);
            }
            for (int i : adj[curr]) {
                indegree[i]--;
                if (indegree[i] == 0 && courseAlreadyDone[i] == 0) {
                    courseAlreadyDone[i] = 1;
                    q.push(i);
                }
            }
        }

        for (int i : courseAlreadyDone) {
            if (i == 0) {
                return {};
            }
        }

        return ans;
    }
};
