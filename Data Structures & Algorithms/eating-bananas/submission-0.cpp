class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxHr = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxHr;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (calHr(piles, mid) <= h) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return low;
    }

    int calHr(vector<int>& piles, int k) {
        int reqHr = 0;
        for (int i : piles) {
            reqHr += (i + k - 1) / k;
        }
        return reqHr;
    }
};
