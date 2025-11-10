/*
Intuition & Approach:
We need to sort an array of 0s, 1s, and 2s in a single pass without extra space.
Use the Dutch National Flag Algorithm with three pointers: low, mid, and high.
Step 1: Initialize low = 0, mid = 0, high = n - 1.
Step 2: Traverse while mid <= high:
- If nums[mid] == 0 → swap with nums[low], increment both low and mid.
- If nums[mid] == 1 → increment mid.
- If nums[mid] == 2 → swap with nums[high], decrement high.
Step 3: Continue until all 0s are at front, 1s in middle, 2s at end.
This greedy, in-place algorithm runs in O(n) time and uses O(1) space.*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid++],nums[low++]);
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid],nums[high--]);
            }
        }
    }
};