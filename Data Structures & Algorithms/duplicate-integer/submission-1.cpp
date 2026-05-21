class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> hashset;
        for(int num:nums) {
            if(hashset.find(num)!=hashset.end()) {
                return true;
            }
            hashset.insert(num);
        }
        return false;
    }
};
