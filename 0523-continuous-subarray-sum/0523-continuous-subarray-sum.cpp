class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp; // rem, index;
        int sum=0;
        //edge case

        //lets learn a basic math
        /*
        
        let take a number 31 and modulo with 4 gives 3
        --> if we add the multiple of 4 and then modulo with 31 will always gives rem 3
        eg: --> 31+0%4=3, 31+8%4=3, 31+12%4=3 and so on it means we add a sum that is multiple 
        of modulo then it will always give the same remainder

        [23,2,4,6,7] --> 
        23+0%6 = 5
        23+2%6 = 1
        23+2+4%6 = 5

        as we have already seen 5 earlier that means that it is the multiple of 6 so we return
        true here.

        //edge case [1,2,3], k=6;
        here when we add them and we see 1+2+3=6 and modulo of this is 0 and we have 
        never seen 0 thats why we have to add 0 explicitly    

        
        */
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