class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size(), i=0,j=1, count=0;

        sort(begin(intervals),end(intervals));
        while(j<n){
            vector<int>curr_interval = intervals[i];
            vector<int>next_interval = intervals[j];

            int curr_start = curr_interval[0];
            int curr_end = curr_interval[1];

            int next_start = next_interval[0];
            int next_end = next_interval[1];

            if(curr_end<=next_start){ //non overlapping
                i=j;
                j++;
            }else if(curr_end <= next_end){ //overlapping
                j++;
                count++;
            }else if(curr_end > next_end){
                i=j;
                j++;
                count++;
            }
        }

        return count;
    }
};