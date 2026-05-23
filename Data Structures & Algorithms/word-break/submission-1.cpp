class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> dp;
        dp[s.length()]=true;
        return check(s, wordDict, 0, dp);
    }

    bool check(string s, vector<string>& wordDict, int i, unordered_map<int, bool>& dp) {
        if(dp.find(i)!=dp.end()) return dp[i];

        for(string& word:wordDict) {
            if(i+word.length()<=s.length() && s.substr(i, word.length())==word) {
                if(check(s, wordDict, i+word.length(), dp)) {
                    return dp[i]=true;
                }
            }
        }
        return dp[i]=false;
    }
};
