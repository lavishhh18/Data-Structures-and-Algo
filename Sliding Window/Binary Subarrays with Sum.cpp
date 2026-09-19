class Solution {
public:
    int n;
    int solve(vector<int>& nums, int k){
        if(k < 0) return 0;
        int l = 0;
        int r = 0;
        int cnt = 0;
        int sum = 0;

        while(r < n){
            sum += nums[r];
            while(sum > k){
                sum -= nums[l];
                l++;
            }
            if(sum <= k){
                cnt += r - l + 1;
            }
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        n = nums.size();
        
        int x = solve(nums, goal);
        int y = solve(nums, goal - 1);

        return x - y;
    }
};