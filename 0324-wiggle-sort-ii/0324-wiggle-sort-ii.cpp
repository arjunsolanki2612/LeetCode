class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();

        vector<int>sorted = nums;
        sort(begin(sorted),end(sorted));

        int mid = (n+1)/2;
        int j = mid-1;
        int k = n-1;


        for(int i=0;i<n;i++){
            if(i%2==0){
                nums[i]=sorted[j--];
            }else{
                nums[i]=sorted[k--];
            }
        }
    }
};