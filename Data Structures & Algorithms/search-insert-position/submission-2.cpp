class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int min  = 0 , max = nums.size()-1;
        int mid = 0;
        while(min<=max){
            mid = min + (max-min)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                max = mid-1;
            }
            else{
                min = mid+1;
            }
        }

        if(nums[mid] > target){
            if(mid > 0) return mid;
            return 0;
        }
        else{
            return mid+1;
             
        }
    }
};