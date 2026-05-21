class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        unordered_set wordSet=unordered_set<string>(wordDict.begin(), wordDict.end());
        vector<string> cur;
        backtrack(s, ans, wordSet, cur, 0);
        return ans;
    }

    void backtrack(const string& s, vector<string>& ans, unordered_set<string>& wordSet, vector<string>& cur, int i) {
        if(i==s.size()) {
            ans.push_back(join(cur));
            return;
        }

        for(int j=i;j<s.size();j++) {
            string w=s.substr(i, j-i+1);

            if(wordSet.count(w)) {
                cur.push_back(w);
                backtrack(s, ans, wordSet, cur, j+1);
                cur.pop_back();
            }
        }
    }

    string join(vector<string> arr) {
        string s="";
        int n=arr.size();
        for(int i=0;i<n-1;i++) {
            s+=arr[i]+" ";
        }
        s+=arr[n-1];
        return s;
    }

};