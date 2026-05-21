class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0, n=s.length(), maxf=0, res=0;
        vector<int> count(26, 0);
        while(r<n) {
            count[s[r]-'A']++;
            maxf=max(maxf, count[s[r]-'A']);
            while((r-l+1)-maxf>k) {
                count[s[l++]-'A']--;
            }
            res=max(res, r-l+1);
            r++;
        }
        return res;
    }
};
