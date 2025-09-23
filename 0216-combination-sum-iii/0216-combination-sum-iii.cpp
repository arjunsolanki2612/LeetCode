class Solution {
public:
    vector<vector<int>>res;
    vector<int>temp;

    void solve(int i, int k, int sum){
        if(k==0 && sum==0){
            res.push_back(temp);
            return;
        }

        if(i>9) return;
        if(sum<0 || k<0) return;

        //take
        temp.push_back(i);
        solve(i+1,k-1,sum-i);

        //not take
        temp.pop_back();
        solve(i+1,k,sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        solve(1,k,n);
        return res;
    }
};