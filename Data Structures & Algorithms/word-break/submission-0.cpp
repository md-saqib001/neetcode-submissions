class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return check(s, wordDict, 0);
    }

    bool check(string s, vector<string>& wordDict, int i) {
        if(i>=s.length()) return true;

        for(string& word:wordDict) {
            if(i+word.length()<=s.length() && s.substr(i, word.length())==word) {
                if(check(s, wordDict, i+word.length())) {
                    return true;
                }
            }
        }
        return false;
    }
};
