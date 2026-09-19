class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, int sum, vector<int>& stones, int target){
        if(i == n) return sum;

        if(dp[i][sum] != -1) return dp[i][sum];

        int notTake = solve(i + 1, sum, stones, target);
        int take = 0;

        if(sum + stones[i] <= target){
            take = solve(i + 1, sum + stones[i], stones, target);
        }

        return dp[i][sum] = max(take, notTake);
    }

    int lastStoneWeightII(vector<int>& stones) {
        n = stones.size();

        int sum = 0;
        for(auto it : stones) sum += it;
        int target = sum / 2;

        dp.assign(n, vector<int>(target + 1, -1));

        int best = solve(0, 0, stones, target);
        return sum - (2*best);
    }
};