class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> countLetters(26, 0);
        for(char ch:s) {
            countLetters[ch-'a']++;
        }
        for(char ch:t) {
            countLetters[ch-'a']--;
        }
        for(int count:countLetters) {
            if(count!=0) {
                return false;
            }
        }
        return true;
    }
};
