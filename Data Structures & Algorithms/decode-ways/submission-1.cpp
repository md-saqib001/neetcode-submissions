class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();

        if(s[0]=='0' || n==0) return 0;

        vector<int> dp(n+1, 0);

        dp[n]=1; // 1 for an empty string  

        for(int i=n-1;i>=0;i--) {
            if(s[i]!='0') {
                dp[i]=dp[i+1];
                if(i+1<n && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7'))) {
                    dp[i]+=dp[i+2];
                }
            }
        }

        return dp[0];
    }
};
