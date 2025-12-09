class Solution {
public:

    int func(vector<int>&nums, int k){
        if(k<0){
            return 0;
        }

        unordered_map<int,int>mp;
        int n=nums.size(),r=0,l=0;
        int count = 0;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }

                l++;
            }

            count = count + (r-l+1);
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return func(nums,k) - func(nums,k-1);
    }
};