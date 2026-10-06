class Solution {
public:
    void sortColors(vector<int>& nums) {
        int min = 0, mid = 0, max = nums.size()-1;
        while(mid <= max){
            if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 0){
                swap(nums[min], nums[mid]);
                min++;
                mid++;
            }
            else{
                swap(nums[mid], nums[max]);
                max--;
            }
        }
    }
};