class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total=0;
        for(int i=0;i<nums.size();i++) {
            total+=nums[i];
        }
        if(total%k!=0) return false;
        vector<int> parts(k, 0);
        sort(nums.begin(), nums.end(), greater<int>());
        return backtrack(nums, total/k, parts, 0);
    }

    bool backtrack(vector<int>& nums, int target, vector<int> parts, int index) {
        if(index==nums.size()) {
            for(int i=0;i<parts.size();i++) {
                if(parts[i]!=target) {
                    return false;
                }
            }
            return true;
        }

        for(int i=0;i<parts.size();i++) {
            if(parts[i]+nums[index]>target) continue;
            parts[i]+=nums[index];
            if(backtrack(nums, target, parts, index+1)) return true;
            parts[i]-=nums[index];

            if(parts[0]==0) break;
        }
        return false;

    } 

};