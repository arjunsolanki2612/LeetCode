class Solution {
    public int longestOnes(int[] nums, int k) {
        int l=0,r=0,len=0,n=nums.length;
        int zeroes = 0;
        while(r<n){
            if(nums[r]==0){
                zeroes++;
            }

            if(zeroes>k){
                if(nums[l]==0){
                    zeroes--;
                }
                l=l+1;
            }else{

            len = Math.max(len,r-l+1);
            
            }
            r++;

        }

        return len;
    }
}