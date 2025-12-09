class Solution {
public:
        int func(vector<int>&nums, int k){
        if(k<0){
            return 0;
        }

        int l=0,r=0,n=nums.size();
        int sum = 0;
        int count = 0;
        while(r<n){
            sum = sum + nums[r];
            while(sum>k){
                sum = sum - nums[l];
                l++;
            }

            count = count + (r-l+1);
            r++;
        }

        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int k) {
                return func(nums,k) - func(nums,k-1);

    }
};