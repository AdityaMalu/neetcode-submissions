class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroPointer = 0, nextDigit=0;
        while(nextDigit < nums.size()){
            if(nums[nextDigit] == 0){
                nextDigit++;
            }
            else{
                while(zeroPointer < nextDigit && nums[zeroPointer] != 0){
                    zeroPointer++;
                }
                swap(nums[nextDigit], nums[zeroPointer]);
                nextDigit++;
            }
        }
    }
};