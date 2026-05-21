class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        for(int i=0;i<n;i++) {
            int leftMax=height[i], rightMax=height[i];
            for(int j=0;j<i;j++) {
                leftMax=max(leftMax, height[j]);
            }
            for(int j=i+1;j<n;j++) {
                rightMax=max(rightMax, height[j]);
            }
            ans+=min(leftMax, rightMax)-height[i];
        }
        return ans;
    }
};
