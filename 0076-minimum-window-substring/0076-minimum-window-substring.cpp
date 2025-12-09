class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        if(t.size()>s.size()){
            return "";
        }

        unordered_map<char,int>mp;
        for(auto x:t){
            mp[x]++;
        }
        int minWindowLength = INT_MAX;
        int start_i = 0;
        int requiredCount = t.size();
        int r=0,l=0;
        while(r<n){
            if(mp[s[r]]>0){
                requiredCount--;
            }

             mp[s[r]]--;

            while(requiredCount==0){
                mp[s[l]]++;
                
                int currWindowLength = r-l+1;
                if(minWindowLength>currWindowLength){
                    minWindowLength = currWindowLength;
                    start_i = l;

                }

                if(mp[s[l]]>0){
                    requiredCount++;
                }
                l++;
            }

            r++;
            
        }

        return minWindowLength == INT_MAX ? "" : s.substr(start_i,minWindowLength);
    }
};