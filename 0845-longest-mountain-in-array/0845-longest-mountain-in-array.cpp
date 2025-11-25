class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int i=1, n = arr.size();
        int ans = 0;

        while(i<n-1){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                int j=i;
                int count=1;

                while(j>0 && arr[j]>arr[j-1]){
                    count++;
                    j--;
                }

                while(i<n-1 and arr[i]>arr[i+1]){
                    count++;
                    i++;
                }

                ans = max(ans,count);
            }else{
                i++;
            }
        }

        return ans;

    }
};