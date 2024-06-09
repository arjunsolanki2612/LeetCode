class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        int rem=0;
        int result=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            rem = sum%k;
            if(rem<0){
                rem = rem+k;
            }

            if(mp.find(rem)!=mp.end()){
                result = result+mp[rem];
            }
            mp[rem]++;
        }
        return result;
    }
};