class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k<=1){
            return 0;
        }
        int prod = 1,l=0,r=0,n=nums.size(),count=0;
        while(r<n){
            prod *= nums[r];
            while(prod>=k){
                prod = prod/nums[l];
                l++;
            }

            count = count + r-l+1;
            r++;
        }

        return count;
    }
};