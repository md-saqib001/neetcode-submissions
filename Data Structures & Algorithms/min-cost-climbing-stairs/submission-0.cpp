class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return min(dfs(cost, 0), dfs(cost, 1));
    }

    int dfs(vector<int>& cost, int n) {
        if(n>=cost.size()) {
            return 0;
        }

        return cost[n]+min(dfs(cost, n+1), dfs(cost, n+2));
    }
};
