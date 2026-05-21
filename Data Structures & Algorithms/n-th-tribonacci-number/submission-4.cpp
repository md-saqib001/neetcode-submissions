class Solution {
public:
    int tribonacci(int n) {

        vector<int> dp(n+1, -1);

        dp[0]=0;
        dp[1]=1;
        dp[2]=1;

        return solve(dp, n);
    }

    int solve(vector<int>& dp, int n) {
        if(n<=2) {
            return n==0 ? 0 : 1;
        }

        if(dp[n]!=-1) {
            return dp[n];
        }

        return dp[n]=solve(dp, n-1)+solve(dp, n-2)+solve(dp, n-3);
    }
};