class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans=recurse(coins, amount);
        return ans==INT_MAX ? -1 : ans;
    }

    int recurse(vector<int>& coins, int target) {

        if(target==0) return 0;

        int res=INT_MAX;

        for(int coin:coins) {
            if(target-coin>=0) {
                int sol=recurse(coins, target-coin);
                if(sol!=INT_MAX) {
                    res=min(res, sol+1);
                }
            }
        }
        return res;
    }
};
