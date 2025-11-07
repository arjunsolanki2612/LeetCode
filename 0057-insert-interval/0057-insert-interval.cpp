class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>>mergeInterval;
        int i = 0, n = intervals.size();
        //merge all inteval that come before newInterval
        while(i<n && intervals[i][1]<newInterval[0]){
            mergeInterval.push_back(intervals[i]);
            i++;
        }
        //merge intervals with newInterval that overlap
        //-- newInterval -->[4,8]
        //-- remaining elements in intervals --> [3,5],[6,7],[8,10],[12,16]
        //to check whether they will overlap, we see if intervals[i][0]<=newInterval[1]

        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }

        mergeInterval.push_back(newInterval);

        //now add all non overlapping intervals

        while(i<n){
            mergeInterval.push_back(intervals[i]);
            i++;
        }
        
        return mergeInterval;
    }
};