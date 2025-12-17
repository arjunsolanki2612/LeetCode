class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int pref=0;
        for(auto x:nums){
            pref += x;
            maxi = max(pref,maxi);
            if(pref<0){
                pref = 0;
            }
        }

        return maxi;
    }
};