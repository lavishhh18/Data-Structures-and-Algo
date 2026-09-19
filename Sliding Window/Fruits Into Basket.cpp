class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> trees;

        int l = 0;
        int r = 0;
        int maxLen = 0;

        while(r < n){
            trees[nums[r]]++;

            while(trees.size() > 2){
                trees[nums[l]]--;
                if(trees[nums[l]] == 0) trees.erase(nums[l]);
                l++;
            }

            if(trees.size() <= 2){
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};