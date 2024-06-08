class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp; // rem, index;
        int sum=0;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            sum = sum+nums[i];
            int rem = sum%k;
            if(mp.find(rem)==mp.end()){
                mp.insert({rem,i});
            }else if(mp.find(rem)!=mp.end()){
                int idx = mp[rem];
                if(i-idx>=2){
                    return true;
                }
            }
        }
        return false;
    }
};