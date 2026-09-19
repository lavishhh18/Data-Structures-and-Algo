class Solution {
public:
    using ll = long long;
    ll dp[17][2];
    int limit;

    ll solve(string& s, int i , bool tight){
        if(i == s.size()) return 1;

        if(dp[i][tight] != -1) return dp[i][tight];

        int ub = tight ? min(s[i] - '0', limit) : limit;
        ll cnt = 0;

        for(int digit = 0; digit <= ub; digit++){
            bool newTight = tight && (digit == s[i] - '0');
            cnt += solve(s, i + 1, newTight);
        }

        return dp[i][tight] = cnt;
    }

    ll middleMan(long long n, ll suffix, string& s) {
        if(n < suffix) return 0;

        ll p10 = 1;

        for(int i = 0; i < s.size(); i++) p10 *= 10;

        ll prefix = (n - suffix) / p10;
        string p = to_string(prefix);

        memset(dp, -1, sizeof(dp));
        return solve(p, 0, 1);
    }
    
    long long numberOfPowerfulInt(long long start, long long finish, int l, string s) {
        ll suff = stoll(s);
        limit = l;
        
        ll right = middleMan(finish, suff, s);
        ll left = middleMan(start - 1, suff, s);

        return right - left;
    }
};