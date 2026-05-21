class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return max(solve(nums, 0, false, n, dp), solve(nums, 0, true, n, dp));
    }
    int solve(vector<int>& nums, int i, bool startedFirst, int n, vector<vector<int>>& dp) {
        if(i>=n) {
            return 0;
        }

        if(i==n-1) {
            if(startedFirst) {
                return 0;
            }
        }

        if(dp[i][startedFirst]!=-1) {
            return dp[i][startedFirst];
        }
        
        int notPick=solve(nums, i+1, startedFirst, n, dp);

        int pick=nums[i]+solve(nums, i+2, i==0 ? true : startedFirst, n, dp);

        return dp[i][startedFirst]=max(pick, notPick);
    }
};
