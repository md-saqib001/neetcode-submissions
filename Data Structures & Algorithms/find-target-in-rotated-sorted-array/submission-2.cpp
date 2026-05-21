class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while(l<=r) {
            int mid=(r+l)/2;
            if(nums[mid]==target) {
                return mid;
            }
            while(nums[l]==nums[mid] && nums[mid]==nums[r]) {
                l++;
                r--;
                continue;
            }
            if(nums[l]<=nums[mid]) {
                if(target>=nums[l] && target<nums[mid]) {
                    r=mid-1;
                }
                else {
                    l=mid+1;
                }
            }
            else {
                if(target<=nums[r] && target>nums[mid]) {
                    l=mid+1;
                }
                else {
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};
