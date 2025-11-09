class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        if(firstList.empty() || secondList.empty()){
            return {};
        }

        vector<vector<int>>finalList;
        int i=0,j=0;
        int n=firstList.size(), m=secondList.size();
        while(i<n && j<m){
            int start = max(firstList[i][0],secondList[j][0]);
            int end = min(firstList[i][1],secondList[j][1]);

            //if overlaps
            if(start<=end){
                finalList.push_back({start,end});
            }

            //move pointer that ends first
            if(firstList[i][1]<secondList[j][1]){
                i++;
            }else{
                j++;
            }
        }

        return finalList;
    }
};