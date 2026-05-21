class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        getAllSubsets(nums, 0, subset, nums.size(), ans);
        return ans;
    }
    void getAllSubsets(const vector<int>& nums, int i, vector<int>& subset, int n, vector<vector<int>>& ans){
        if(i>=n) {
            ans.push_back(subset);
            return ;
        }

        subset.push_back(nums[i]);
        getAllSubsets(nums, i+1, subset, n, ans);
        subset.pop_back();
        getAllSubsets(nums, i+1, subset, n, ans);

    }
};
