class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) {
            return 1;
        }

        int result=climbStairs(n-1)+climbStairs(n-2);

        return result;
    }
};
