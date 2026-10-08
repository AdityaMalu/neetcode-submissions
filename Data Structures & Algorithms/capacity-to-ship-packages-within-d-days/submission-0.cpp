class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin() , weights.end());
        int r = accumulate(weights.begin() , weights.end(), 0);

        int res = r;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(canShip(weights, mid, days)){
                res = min(res, mid);
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return res;

    }

    bool canShip(vector<int> &weights , int cap, int days){
        int ship = 1, currCap = cap;
        for(int i : weights){
            if(currCap - i < 0){
                ship++;
                if(ship > days){
                    return false;
                }
                currCap = cap;
            }
            currCap-=i;
        }
        return true;
    }
};