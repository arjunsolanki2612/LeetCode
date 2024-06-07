class Solution {
public:

    string findRoot(string &word, unordered_set<string>&st){
        for(int i=0;i<word.size();i++){
            string root = word.substr(0,i);
            if(st.count(root)){
                return root;
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream ss(sentence);
        string word; //tokenize and store every word in this word;
        unordered_set<string>st(begin(dictionary),end(dictionary));
        string result;

        while(getline(ss,word,' ')){
            result+=findRoot(word,st)+" ";
        }

        result.pop_back();
        return result;
    }
};