class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;
    int lower, upper;
    ll dp[23][2][401];

    ll solve(string& s, int i, int tight, int sum){
        if(i == s.size()){
            if(sum <= upper && sum >= lower) return 1;
            return 0;
        }

        if(dp[i][tight][sum] != -1) return dp[i][tight][sum];

        int ub = tight ? s[i] - '0' : 9;
        ll cnt = 0;

        for(int digit = 0; digit <= ub; digit++){
            bool newTight = tight && digit == ub;

            cnt = (cnt + solve(s, i + 1, newTight, sum + digit)) % mod;
        }

        return dp[i][tight][sum] = cnt;
    }

    string subtractOne(string s) {
        int i = s.size() - 1;

        while (i >= 0 && s[i] == '0') {
            s[i] = '9';
            i--;
        }

        if (i >= 0) s[i]--;

        if (s.size() > 1 && s[0] == '0') s.erase(0, 1);
        return s;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        lower = min_sum;
        upper = max_sum;

        string num1minusOne = subtractOne(num1);

        memset(dp, -1, sizeof(dp));
        ll r = solve(num2, 0, 1, 0);

        memset(dp, -1, sizeof(dp));
        ll l = solve(num1minusOne, 0, 1, 0);

        int ans = (r - l + mod) % mod;

        return ans;
    }
};