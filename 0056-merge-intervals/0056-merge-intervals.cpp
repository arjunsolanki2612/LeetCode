class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergeInterval;

        sort(intervals.begin(),intervals.end(),[](const vector<int>&a, const vector<int>&b){
            return a[0]<b[0];
        });

        mergeInterval.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            auto &last = mergeInterval.back();
            if(intervals[i][0]<=last[1]){
                last[1] = max(last[1],intervals[i][1]);
            }else{
                mergeInterval.push_back(intervals[i]);
            }
        }

        return mergeInterval;
        
    }
};