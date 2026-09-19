#include <bits/stdc++.h>
#include<iostream>
using namespace std;

using ll = long long;
int mod = 1e9 + 7;

ll dp[2][11][20][2];

ll solve(bool tight, ll prev, ll i, bool lz, string& s){
    if(i == s.size()) return 1;

    if(dp[tight][prev][i][lz] != -1) return dp[tight][prev][i][lz];

    ll lb = 0; //lower bound 
    ll ub = (tight == 1) ? (s[i] - '0') : 9; //uppper bound

    ll ans = 0;

    for(ll digit = lb; digit <= ub; digit++){
        //case-1 : invalid -> adjacent same!
        if(digit == prev && !lz) continue;

        //case-2 : valid
        bool t = (tight && digit == ub) ? 1 : 0; //agar abhi tak tight violate nahi hua hai and curr digit is also equal to upper bound
        bool leadingZero = (lz && digit == 0) ? 1 : 0; //agar leading zero abhi tak violate nahi hua hai and curr digit is also a 0
        ans += solve(t, digit, i + 1, leadingZero, s);
    }

    return dp[tight][prev][i][lz] = ans;
}

ll countNumbers(ll num){
    if(num < 0) return 0;

    string s = to_string(num);

    memset(dp, -1, sizeof(dp));

    return solve(1, 10, 0, 1, s);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll a, b;
    cin >> a >> b;

    ll l = countNumbers(a - 1);
    ll r = countNumbers(b);

    cout << r - l;

    return 0;
}