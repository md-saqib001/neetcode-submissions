class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        return solve(nums, 0, false, n);
    }
    int solve(vector<int>& nums, int i, bool startedFirst, int n) {
        if(i>=n) {
            return 0;
        }

        if(i==n-1) {
            if(startedFirst) {
                return 0;
            }
        }
        
        int notPick=solve(nums, i+1, startedFirst, n);

        int pick=nums[i];

        if(i==0) {
            pick+=solve(nums, i+2, true, n);
        }
        else {
            pick+=solve(nums, i+2, startedFirst, n);
        }

        return max(pick, notPick);
    }
};
