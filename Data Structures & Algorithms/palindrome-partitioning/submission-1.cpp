class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        backtrack(s, res, 0, part);
        return res;
    }

    void backtrack(const string& s, vector<vector<string>>& ans, int start, vector<string>& part) {
        if(start==s.size()) {
            ans.push_back(part);
            return ;
        }

        for(int end=start;end<s.size();end++) {
            if(isPalindrome(s, start, end)) {
                part.push_back(s.substr(start, end-start+1));
                backtrack(s, ans, end+1, part);
                part.pop_back();
            }
        }

    }

    



    bool isPalindrome(string word, int left, int right) {
        while(left<right) {
            if(word[left++]!=word[right--]) {
                return false;
            }
        }
        return true;
    }
};
