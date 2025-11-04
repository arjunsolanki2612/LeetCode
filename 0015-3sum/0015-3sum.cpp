#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        // set<vector<int>>st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int ele = nums[i];
            int j = i+1;
            int k = n-1;

            while(j<k){

                
                if(ele + nums[j]+nums[k]==0){
                    vector<int>temp = {ele, nums[j], nums[k]};
                    j++;
                    k--;
                    ans.push_back(temp);
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;

                   
                }else if(ele + nums[j]+nums[k]>0){
                    k--;
                }else{
                    j++;
                }
            }

            
        }

        return ans;
    }
};