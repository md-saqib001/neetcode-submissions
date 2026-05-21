class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) {
            return "";
        }
        int l=0, r=0, n=s.length();
        pair<int, int> res={-1, -1};
        unordered_map<char, int> countS;
        unordered_map<char, int> countT;

        for(char ch:t) {
            countT[ch]++;
        }

        int resLen=INT_MAX, have=0, need=countT.size();

        while(r<n) {
            char c=s[r];
            countS[c]++;

            if(countT[c]!=0 && countS[c]==countT[c]) {
                have++;
            }

            while(have==need) {
                if(r-l+1<resLen) {
                    resLen=r-l+1;
                    res={l, r};
                }
                countS[s[l]]--;

                if(countT[s[l]]!=0 && countS[s[l]]<countT[s[l]]) {
                    have--;
                }
                l++;
            }

            r++;
        }
        return resLen==INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
