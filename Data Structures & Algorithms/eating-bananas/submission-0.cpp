class Solution {
public:

    int giveHours(vector<int>& piles, int k) {
        int res=0;
        for(int p:piles) {
            res+=ceil(static_cast<double>(p)/k);
        }
        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=*max_element(piles.begin(), piles.end());
        int res=0;
        while(l<=r) {
            int mid=l+(r-l)/2;
            int hours=giveHours(piles, mid);
            if(hours<=h) {
                res=mid;
                r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        return res;
    }
};
