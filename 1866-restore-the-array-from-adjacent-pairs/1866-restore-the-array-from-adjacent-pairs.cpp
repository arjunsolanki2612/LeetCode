class Solution {
public:

    vector<int>res;
    void dfs(int u, int prev, unordered_map<int,vector<int>>&mp){
        res.push_back(u);
        for(auto &v:mp[u]){
            if(v!=prev){
                dfs(v,u,mp);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>mp;
        for(vector<int> vec: adjacentPairs){
            int u = vec[0];
            int v = vec[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        int startPoint=-1;
        for(auto &it:mp){
            if(it.second.size()==1){
                startPoint = it.first;
                break;
            }
        }

        dfs(startPoint,INT_MIN,mp); //(startPoint, prev);
        return res;
    }
};
