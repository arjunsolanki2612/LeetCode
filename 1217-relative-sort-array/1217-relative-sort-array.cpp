class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        vector<int>ans;
        for(auto &num:arr1){
            mp[num]++;
        }

        for(int i=0;i<arr2.size();i++){
            if(mp.find(arr2[i])!=mp.end()){
                int freq = mp[arr2[i]];
                for(int j=0;j<freq;j++){
                    ans.push_back(arr2[i]);
                }
                mp[arr2[i]]=0;
            }
        }
        for(auto &x:mp){
            if(x.second>0){
                int freq = x.second;
                for(int i=0;i<freq;i++){
                    ans.push_back(x.first);
                }
            }
        }
        return ans;
    }
};