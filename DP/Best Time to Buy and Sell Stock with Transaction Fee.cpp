class Solution {
public:
    int n;
    int tax;
    vector<vector<int>> dp;

    int solve(int i, int buy, vector<int>& prices){
        if(i == n) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        if(buy){
            int notTake = solve(i + 1, buy, prices);
            int take = -prices[i] + solve(i + 1, 0, prices);

            return dp[i][buy] = max(take, notTake);
        }

        int sell = prices[i] - tax + solve(i + 1, 1, prices);
        int skip = solve(i + 1, 0, prices);

        return dp[i][buy] = max(sell, skip);
    }

    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        tax = fee;
        dp.assign(n, vector<int>(2, -1));

        //1 -> buy & 0 -> sell. 
        return solve(0, 1, prices);
    }
};