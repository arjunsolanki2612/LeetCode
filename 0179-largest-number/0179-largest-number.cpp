class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        sort(begin(nums),end(nums),[](int &a, int &b){
            string s1 = to_string(a);
            string s2 = to_string(b);

            return s1+s2 > s2+s1;
        });

        if(nums[0]==0){
            return "0";
        }

        string result = "";
        for(auto x: nums){
            result += to_string(x);
        }

        return result;
    }
};