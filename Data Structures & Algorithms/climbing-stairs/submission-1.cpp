class Solution {
public:
    int solve(int memo[], int n) {
        if(n<=1) {
            return 1;
        }

        if(memo[n]!=0) {
            return memo[n];
        }

        int result=solve(memo, n-1)+solve(memo, n-2);

        return memo[n]=result;
    }
    int climbStairs(int n) {
        int memo[n+1] = {0};

        return solve(memo, n);
    }
};
