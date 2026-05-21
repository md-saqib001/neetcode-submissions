class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1) {
            return nums[0];
        }

        return max(helper(vector<int>(nums.begin(), nums.end()-1)), helper(vector<int>(nums.begin()+1, nums.end())));
    }

    int helper(vector<int> nums) {
        int n=nums.size();

        int prevRob=0, maxRob=0;

        for(int i=0;i<n;i++) {
            int temp=max(maxRob, prevRob+nums[i]);
            prevRob=maxRob;
            maxRob=temp;
        }

        return maxRob;
    }
};
