class Solution {
public:

    void fillCount(string &str, int count[26]){
        for(int i=0;i<str.size();i++){
            count[str[i]-'a']++;
        }
    }
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        int count[26] = {0};

        fillCount(words[0],count);

        for(int i=1;i<words.size();i++){
            int temp[26]={0};
            fillCount(words[i],temp);

            for(int j=0;j<26;j++){
                count[j]=min(count[j],temp[j]);
            }
        }

        for(int i=0;i<26;i++){
            int c = count[i];
            while(c--){
                ans.push_back(string(1,i+'a'));
            }
        }
        return ans;

    }
};