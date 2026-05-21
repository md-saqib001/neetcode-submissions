class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int total=0;
        for(int i=0;i<matchsticks.size();i++) {
            total+=matchsticks[i];
        }
        if(total%4!=0 || matchsticks.empty()) {
            return false;
        }
        int target=total/4;
        vector<int> sides(4, 0);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return backtrack(matchsticks, 0, target, sides);
    }

    bool backtrack(vector<int>& matchsticks, int index, int target, vector<int>& sides) {
        if(index==matchsticks.size()) {
            return sides[0]==target && sides[1]==target && sides[2]==target && sides[3]==target;
        }

        for(int i=0;i<4;i++) {
            if(sides[i]+matchsticks[index]>target) continue;
            sides[i]+=matchsticks[index];
            if(backtrack(matchsticks, index+1, target, sides)) return true;
            sides[i]-=matchsticks[index];
        }
        return false;
    }

};