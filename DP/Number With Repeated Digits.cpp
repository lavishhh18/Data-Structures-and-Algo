//Leetcode-1012
class Solution {
public:
    int n;
    int dp[11][2][2][1023][2];

    int solve(string& s, int i, bool tight, bool repetition, int mask, bool lz){
        if(i == n) return repetition ? 1 : 0; //if the formed number has repetition add it to the ans

        if(dp[i][tight][repetition][mask][lz] != -1) return dp[i][tight][repetition][mask][lz];

        int ub = tight ? (s[i] - '0') : 9;

        int cnt = 0;
        for(int digit = 0; digit <= ub; digit++){
            bool newTight = tight && digit == ub;

            if(lz && digit == 0){ // agar leading zeroes hai toh repetition count nahi karenge!
                cnt += solve(s, i + 1, newTight, 0, 0, 1);
            }

            else {
                bool isDigitUsed = 1 & (mask >> digit); //if this digit was previously seen or not
                //either repetition is already present or this digit was prev seen so ab repeat ho gayi
                bool newRep = repetition || isDigitUsed; 
                int newMask = mask | (1 << digit);

                cnt += solve(s, i + 1, newTight, newRep, newMask, 0);
            }
        }

        return dp[i][tight][repetition][mask][lz] = cnt;
    }

    int numDupDigitsAtMostN(int num) {
        string s = to_string(num);
        n = s.size();

        memset(dp, -1, sizeof(dp));

        return solve(s, 0, 1, 0, 0, 1);
    }
};