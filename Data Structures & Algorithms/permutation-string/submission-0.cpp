class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k=s1.length(), n=s2.length();
        if(k>n) {
            return false;
        }
        unordered_map<char, int> count1;
        unordered_map<char, int> count2;
        for (int i = 0; i < k; i++) {
            count1[s1[i]]++;
            count2[s2[i]]++;
        }
        int l=0, r=k-1;
        while(r<n) {
            bool found=true;
            for(auto const& [item, count]:count1) {
                if(count2[item]!=count) {
                    found=false;
                }
            }
            if(found) {
                return true;
            }
            count2[s2[l++]]--;
            count2[s2[++r]]++;
        }
        return false;
    }
};
