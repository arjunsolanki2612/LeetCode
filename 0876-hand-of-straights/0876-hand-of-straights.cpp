class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int g) {
        int n=hand.size();

        if(n%g!=0){
            return false;
        }
        
        map<int,int>mp;
        int i=0;
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }

        while(!mp.empty()){
            int curr = mp.begin()->first;

            for(int i=0;i<g;i++){
                if(mp[curr+i]==0){
                    return false;
                }

                mp[curr+i]--;
                if(mp[curr+i]<1){
                    mp.erase(curr+i);
                }
            }
        }

    return true;

    }
};