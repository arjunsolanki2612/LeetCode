class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int power = 0;
        int n=dist.size();
        vector<int>time(n);
        for(int i=0;i<n;i++){
           time[i]= ceil((float)dist[i]/speed[i]);
           
        }
        sort(begin(time),end(time));
        int t=1;
        int died=1;
        for(int i=1;i<n;i++){
            if(time[i]-t<=0){
               return died;
            }else{
               t++;
               died++;
            }
        }
        return died;
    }
};