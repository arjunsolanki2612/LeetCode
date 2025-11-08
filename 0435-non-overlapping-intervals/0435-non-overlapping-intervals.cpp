class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int i =1;
        int count = 0;
        int n = intervals.size();
        sort(begin(intervals),end(intervals));
        vector<int>prev_interval = intervals[0];
        while(i<n){
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];

            int prev_end = prev_interval[1];

            if(curr_start>=prev_end){
                prev_interval = intervals[i];
            }else if(curr_end>=prev_end){
                count++;
            }else if(curr_end<prev_end){
                prev_interval = intervals[i];
                count++;
            }

            i++;
        }
        return count;
    }
};