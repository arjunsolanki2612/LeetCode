class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;
        //-->right
        for(auto x:right){
            result = max(result,n-x);
        }
        //<----left
        for(auto x:left){
            result = max(result,x);
        }

        return result;
    }
};