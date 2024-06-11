// Approach 1 : Counting sort
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

//Approach 2 : Custom sort using Lambda function
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;

        for(int i=0;i<arr2.size();i++){
            mp[arr2[i]]=i;
        }

        for(auto &num :arr1){
            if(!mp.count(num)){
                mp[num]=1e9;
            }
        }

        auto lambda = [&](int &num1, int &num2){
            if(mp[num1]==mp[num2]){
                return num1<num2;
            }

            return mp[num1]<mp[num2];
        };

        sort(begin(arr1),end(arr1),lambda);
        return arr1;
    }
};
