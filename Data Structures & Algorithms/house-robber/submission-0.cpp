class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        return solve(0, n, nums);
    }
    int solve(int i, int n, vector<int>& nums) {
        if(i>=n) {
            return 0;
        }

        int notPick=solve(i+1, n, nums);

        int pick=nums[i]+solve(i+2, n, nums);

        return max(pick, notPick);
    }
};
