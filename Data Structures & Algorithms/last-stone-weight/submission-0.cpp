class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> q;

        for(int i : stones){
            q.push(i);
        }


        while(!q.empty() && q.size() > 1){
            int one = q.top();
            q.pop();
            int two = q.top();
            q.pop();

            if(one != two) q.push(one-two);
        }

        if(!q.empty()){
            return q.top();
        }
        return 0;
    }
};
