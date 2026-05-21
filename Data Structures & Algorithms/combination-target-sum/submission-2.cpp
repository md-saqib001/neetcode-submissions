class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        getSubsets(nums, subset, ans, 0, nums.size(), target);
        return ans;
    }
    void getSubsets(vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans, int i, int n, int target) {
        if(target==0) {
            ans.push_back(subset);
            return ;
        }

        for(int j=i;j<n;j++) {
            if(target-nums[j]<0) {
                return ;
            }

            subset.push_back(nums[j]);
            getSubsets(nums, subset, ans, j, n, target-nums[j]);
            subset.pop_back();
        }
    }
};
