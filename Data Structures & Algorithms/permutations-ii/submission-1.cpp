class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        recurse(nums, 0, ans);
        return ans;
    }

    void recurse(vector<int>& nums, int index, vector<vector<int>>& ans) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used; // track duplicates at this level
        for (int i = index; i < (int)nums.size(); ++i) {
            if (used.count(nums[i])) continue; // skip duplicate choice
            used.insert(nums[i]);

            swap(nums[index], nums[i]);         // 🔁 choose
            recurse(nums, index + 1, ans);    // 🔍 explore
            swap(nums[index], nums[i]);         // ↩️ backtrack
        }
    }
};