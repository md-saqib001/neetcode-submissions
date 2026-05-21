class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        for(const string& str:strs) {
            string sortedStr=str;
            sort(sortedStr.begin(), sortedStr.end());
            mpp[sortedStr].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto pair:mpp) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};
