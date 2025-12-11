class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int startProd = 1, endProd = 1, maxProd = INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            startProd *= nums[i];
            endProd *= nums[n-i-1];

            maxProd = max({maxProd,startProd,endProd});
            if(startProd==0) startProd = 1;
            if(endProd==0) endProd = 1;
        }

        return maxProd;
    }
};