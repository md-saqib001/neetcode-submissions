class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numCount;
        for(int n:nums) {
            numCount[n]++;
        }
        vector<pair<int, int>> arr;
        for(auto pair:numCount) {
            arr.emplace_back(pair.second, pair.first);
        }
        sort(arr.rbegin(), arr.rend());
        vector<int> ans;
        for(int i=0;i<k;i++) {
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};
