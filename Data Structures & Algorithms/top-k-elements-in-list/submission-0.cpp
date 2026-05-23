class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numCount;
        for(int n:nums) {
            numCount[n]++;
        }
        vector<int> ans;
        for(auto pair:numCount) {
            if(pair.second>=k) {
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};
