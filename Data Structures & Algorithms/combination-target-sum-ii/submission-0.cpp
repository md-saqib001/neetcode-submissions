class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> subset;
        combineSum(candidates, target, subset, 0, ans);
        return ans;
    }

    void combineSum(vector<int>& nums, int target, vector<int>& subset, int ind, vector<vector<int>>& ans) {
        if(target<0) {
            return ;
        }
        else if(target==0) {
            ans.push_back(subset);
            return ;
        }
        else {
            for(int i=ind;i<nums.size();i++) {
                if(i>ind && nums[i]==nums[i-1]) continue;

                if(nums[i]>target) {
                    break;
                }

                subset.push_back(nums[i]);
                combineSum(nums, target-nums[i], subset, i+1, ans);
                subset.pop_back();
            }
        }
    }
};
