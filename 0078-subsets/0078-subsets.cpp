class Solution {
public:

    vector<vector<int>>result;
    int N;
    vector<int>temp;

    void solve(int i, vector<int>& nums){
        if(i==N){
            result.push_back(temp);
            return;
        }

        //take
        temp.push_back(nums[i]);
        solve(i+1,nums);

        //not take
        temp.pop_back();
        solve(i+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
         N = nums.size();
        solve(0,nums);
        return result;

    }
};