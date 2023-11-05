class Solution {
public:
    int getWinner(vector<int>& arr, int k) {

        if(k>=arr.size()){
            return *max_element(begin(arr),end(arr));
        }

       int maxEle = *max_element(begin(arr),end(arr));
       int winner = arr[0];
       int streak = 0;

       for(int i=1;i<arr.size();i++){
           if(arr[i]>winner){
               winner=arr[i];
               streak=1;
           }else{
               streak++;
           }

           if(streak==k || winner==maxEle){
               return winner;
           }
       }
       return winner;
        
    }
};