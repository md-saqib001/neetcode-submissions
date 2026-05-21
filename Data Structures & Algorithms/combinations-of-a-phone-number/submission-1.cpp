class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) {
            return res;
        }
        vector<string> mapletters={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtrack(mapletters, "", digits, res, 0);
        return res;
    }

    void backtrack(vector<string>& mapletters, string curStr, string digits, vector<string>& res, int i) {
        if(i==digits.size()) {
            res.push_back(curStr);
            return ;
        }

        for(int j=0;j<mapletters[digits[i]-'0'].size();j++) {
            backtrack(mapletters, curStr+mapletters[digits[i]-'0'][j], digits, res, i+1);
        }
    }
};
