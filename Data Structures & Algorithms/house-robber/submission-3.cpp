class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        int maxRob=0, prevRob=0;
        
        
        for(int i=0;i<n;i++) {
            int temp=max(maxRob, prevRob+nums[i]);
            prevRob=maxRob;
            maxRob=temp;
        }

        return maxRob;
    }
};
