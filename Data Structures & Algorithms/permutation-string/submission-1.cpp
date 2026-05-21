class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k=s1.length(), n=s2.length();
        if(k>n) {
            return false;
        }
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        for (int i = 0; i < k; i++) {
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
        }
        int l=0, r=k-1;
        while(r<n) {
            if(count1==count2) {
                return true;
            }
            count2[s2[l++]-'a']--;
            count2[s2[++r]-'a']++;
        }
        return count1==count2;
    }
};
