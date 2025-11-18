class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0,sum=0,n=nums.size();
        int len = INT_MAX;
        while(r<n){
            sum = sum+nums[r];

            while(sum>=target){
                len = min(len,r-l+1);
                sum = sum - nums[l];
                l++;
            }
            
            r++;
        }

        return len==INT_MAX?0:len;
    }
};