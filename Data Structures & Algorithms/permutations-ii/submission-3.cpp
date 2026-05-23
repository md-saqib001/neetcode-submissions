class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        recurse(nums, 0, ans);
        return ans;
    }

    void recurse(vector<int>& nums, int i, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int j=i;j<nums.size();j++) {
            if(j>i && nums[j]==nums[i]) continue;
            swap(nums[j], nums[i]);
            recurse(nums, j + 1, ans);
            swap(nums[j], nums[i]); 
        }
    }
};