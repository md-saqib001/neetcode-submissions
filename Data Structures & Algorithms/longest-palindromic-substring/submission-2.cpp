class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();

        int resLen=0, resIdx=-1;

        vector<vector<int>> dp(n, vector<int>(n, false));

        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                if(s[i]==s[j] && (j-i<=2 || dp[i+1][j-1])) {
                    dp[i][j]=true;

                    if(resLen<j-i+1) {
                        resIdx=i;
                        resLen=j-i+1;
                    }
                }
            }
        }

        return s.substr(resIdx, resLen);
    }
};
