class Solution {
public:
    int findMin(vector<int> &nums) {
        int min = 0, max = nums.size()-1;
        while(min < max){
            int mid = min + (max-min)/2;
            if(nums[mid] < nums[max]){
                max = mid;
            }
            else{
                min = mid+1;
            }
        }
        return nums[min];
    }
};

