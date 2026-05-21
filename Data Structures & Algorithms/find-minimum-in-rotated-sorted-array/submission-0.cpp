class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0, r=nums.size()-1, minNum=INT_MAX;
        while(l<=r) {
            int mid=l+(r-l)/2;
            if(nums[l]<=nums[mid]) {
                minNum=min(minNum, nums[l]);
                l=mid+1;
            }
            else {
                minNum=min(minNum, nums[mid]);
                r=mid-1;
            }
        }
        return minNum;
    }
};
