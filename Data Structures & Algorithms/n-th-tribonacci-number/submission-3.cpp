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

        return dp[n]=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};