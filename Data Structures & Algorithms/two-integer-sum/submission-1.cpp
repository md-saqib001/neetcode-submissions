class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int sum=nums[i]+nums[j];
                if(target==sum) {
                    return {i, j};
                }
            }
        }

        return {-1, -1};
    }
};
