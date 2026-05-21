class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> hashset(nums.begin(), nums.end());
        int maxi=0;
        for(int i=0;i<n;i++) {
            int num=nums[i], cnt=0;
            while(hashset.find(num)!=hashset.end()) {
                cnt++;
                num++;
            }
            maxi=max(maxi, cnt);
        }
        return maxi;
    }
};
