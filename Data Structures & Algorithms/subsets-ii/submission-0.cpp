class Solution {
    vector<vector<int>> ans;
public:

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        recursion(nums, 0, subset);
        return ans;
    }

    void recursion(vector<int>& nums, int ind, vector<int>& subset) {
        ans.push_back(subset);
        for(int i=ind;i<nums.size();i++) {
            if(i>ind && nums[i]==nums[i-1]) {
                continue;
            }
            subset.push_back(nums[i]);
            recursion(nums, i+1, subset);
            subset.pop_back();
        }

    }

};
