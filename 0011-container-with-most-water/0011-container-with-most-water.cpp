class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxiArea = INT_MIN;

        int i=0, j=height.size()-1;

        while(i<j){

            int minBar = min(height[i],height[j]);
            int len = j-i;
            int area = minBar*len;
            maxiArea = max(maxiArea,area);

            if(height[i]<height[j]){
                i++;
            }else if(height[i]>height[j]){
                j--;
            }else{
                i++;
                j--;
            }
        }

        return maxiArea;
    }
};