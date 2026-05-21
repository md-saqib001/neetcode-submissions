class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1) {
            return nums[0];
        }

        return max(helper(vector<int>(nums.begin(), nums.end()-1)), helper(vector<int>(nums.begin()+1, nums.end())));
    }

    int helper(vector<int> nums) {
        int n=nums.size();

        vector<int> dp(n, -1);

        dp[0]=nums[0];

        for(int i=1;i<n;i++) {
            int taken=nums[i];

            if(i>=2) {
                taken+=dp[i-2];
            }

            dp[i]=max(dp[i-1], taken);
        }

        return dp[n-1];
    }
};
