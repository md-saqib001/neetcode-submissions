class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        getSubsets(nums, subset, ans, 0, nums.size(), target);
        return ans;
    }
    void getSubsets(vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans, int i, int n, int target) {
        if(target==0) {
            ans.push_back(subset);
            return ;
        }

        if(target<0 || i>=n) {
            return ;
        }
        

        subset.push_back(nums[i]);
        getSubsets(nums, subset, ans, i, n, target-nums[i]);
        subset.pop_back();
        getSubsets(nums, subset, ans, i+1, n, target);
        
    }
};
