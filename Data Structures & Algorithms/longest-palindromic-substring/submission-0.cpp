class Solution {
public:

    bool isPalindrome(string s, int l, int r) {
        if(l>=r) return true;

        return s[l]==s[r] && isPalindrome(s, l+1, r-1);
    }

    string longestPalindrome(string s) {
        int n=s.size();

        int resLen=0;

        string res="";

        for(int i=0;i<n;i++) {
            string t="";
            for(int j=i;j<n;j++) {
                t+=s[j];

                if(isPalindrome(t, 0, j-i)) {
                    if(resLen<(j-i+1)) {
                        res=s.substr(i, j-i+1);
                        resLen=j-i+1;
                    }
                }
            }
        }

        return res;
    }
};
