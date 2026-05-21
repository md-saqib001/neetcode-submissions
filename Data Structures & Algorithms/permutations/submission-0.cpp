class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(nums, 0, ans);
        return ans;
    }

    void backtrack(vector<int>& nums, int ind, vector<vector<int>>& ans) {
        if(ind==nums.size()) {
            ans.push_back(nums);
            return ;
        }

        for(int i=ind;i<nums.size();i++) {
            swap(nums[ind], nums[i]);
            backtrack(nums, ind+1, ans);
            swap(nums[i], nums[ind]);
        }
    }
};
