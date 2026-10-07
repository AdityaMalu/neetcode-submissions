class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int start = 0, ans = 0;
        for(int i = 0; i < prices.size() ; i++){
            if(prices[i] <= prices[start]){
                start = i;
            }
            else{
                ans = max(ans, prices[i] - prices[start]);
            }
        }
        return ans;
    }
};
