class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = INT_MIN, res = 0;

        for(int i=0;i<nums.size();i++){
            if(i<k){
                res+=nums[i];
            }else{
                avg = max(avg,res);
                res = res + nums[i]-nums[i-k];
            }
        }

        //if only one element is present
        avg = max(res,avg);
        return avg/k;
    }
};