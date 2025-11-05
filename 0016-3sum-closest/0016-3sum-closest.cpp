class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()==3){
            return nums[0]+nums[1]+nums[2];
        }
        sort(nums.begin(),nums.end());
        int prevDis = INT_MAX;
        int closestSum = 0;
        for(int i=0;i<nums.size()-2;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int ele = nums[i];
            int j = i+1;
            int k = nums.size()-1;

            while(j<k){
                int sum = ele+nums[j]+nums[k];
                if(sum==target){
                    
                    return sum;

                }else if(sum<target){
                    int distance = abs(target-sum);
                    if(distance<prevDis){
                        prevDis = distance;
                        closestSum = sum;
                    }
                    j++;
                }else{
                    int distance = abs(target-sum);
                    if(distance<prevDis){
                        prevDis = distance;
                        closestSum = sum;
                    }
                    k--;
                }
            }
        }

        return closestSum;


    }
};