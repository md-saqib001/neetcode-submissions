class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans=recurse(coins, amount, 0, coins.size());
        return ans==INT_MAX ? -1 : ans;
    }

    int recurse(vector<int>& coins, int target, int ind, int n) {

        if(target==0) return 0;

        int res=INT_MAX;

        for(int i=ind;i<n;i++) {
            if(target-coins[i]>=0) {
                int sol=recurse(coins, target-coins[i], ind, n);
                if(sol!=INT_MAX) {
                    res=min(res, sol+1);
                }
            }
        }
        return res;
    }
};
