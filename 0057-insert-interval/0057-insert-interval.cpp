class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>>arrItval;
        bool isInsert = false;
        for(auto x: intervals){
            if(x[0]<newInterval[0]){
                arrItval.push_back(x);
            }else{
                if(isInsert==false){
                    arrItval.push_back(newInterval);
                    isInsert = true;
                }

                arrItval.push_back(x); 
            }
        }
        if(!isInsert){
            arrItval.push_back(newInterval);
        }
        vector<vector<int>>mergeInterval;
        mergeInterval.push_back(arrItval[0]);
        for(int i=1;i<arrItval.size();i++){
            auto &last = mergeInterval.back();
            if(arrItval[i][0]<=last[1]){
                last[1] = max(last[1],arrItval[i][1]);
            }else{
                mergeInterval.push_back(arrItval[i]);
            }
        }

        return mergeInterval;
    }
};