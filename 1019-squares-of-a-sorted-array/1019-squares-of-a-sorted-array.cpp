class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0, h = nums.size()-1;
        int pos = nums.size()-1;
        vector<int> ans(nums.size());
        while(l<=h){
            if(abs(nums[l])>abs(nums[h])){
                ans[pos--] = nums[l]*nums[l];
                l++;
            }else{
               ans[pos--] = nums[h]*nums[h];
               h--; 
            }
        }

        return ans;
    }
};