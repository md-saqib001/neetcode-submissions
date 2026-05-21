class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> perm;
        vector<bool> pick(nums.size(), false);
        recurse(nums, perm, pick, ans);
        return ans;
    }

    void recurse(vector<int>& nums, vector<int>& perm, vector<bool>& pick, vector<vector<int>>& ans) {
        if(perm.size()==nums.size()) {
            ans.push_back(perm);
            return ;
        }

        for(int i=0;i<nums.size();i++) {
            if(pick[i] || (i>0 && nums[i]==nums[i-1] && !pick[i-1])){
                continue;
            }
            pick[i]=true;
            perm.push_back(nums[i]);
            recurse(nums, perm, pick, ans);
            pick[i]=false;
            perm.pop_back();
        }
    }
};