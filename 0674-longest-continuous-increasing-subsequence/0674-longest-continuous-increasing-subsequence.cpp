class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 1;
        int maxLen = INT_MIN;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                count++;

                maxLen = max(count,maxLen);
                
            }else{
                maxLen = max(count,maxLen);
                count=1;

            }
        }

        return maxLen==INT_MIN?1:maxLen;
    }
};