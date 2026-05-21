class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> subset;
        vector<vector<int>> ans;
        recurse(subset, ans, n, k, 1);
        return ans;
    }

    void recurse(vector<int>& subset, vector<vector<int>>& ans, int n, int k, int i) {
        if(subset.size()==k) {
            ans.push_back(subset);
        }

        for(int j=i;j<=n;j++) {
            subset.push_back(j);
            recurse(subset, ans, n, k, j+1);
            subset.pop_back();
        }
    }
};