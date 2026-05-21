class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();

        vector<int> dp(n, -1);
        
        return min(dfs(cost, 0, n, dp), dfs(cost, 1, n, dp));
    }

    int dfs(vector<int>& cost, int i, int n, vector<int>& dp) {
        if(i>=n) {
            return 0;
        }

        if(dp[i]!=-1) {
            return dp[i];
        }

        dp[i]=cost[i]+min(dfs(cost, i+1, n, dp), dfs(cost, i+2, n, dp));


        return dp[i];
    }
};
