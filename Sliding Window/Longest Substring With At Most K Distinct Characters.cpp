class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        
        int l = 0;
        int r = 0;
        unordered_map<char, int> hash;
        int ans = INT_MIN;
        
        while(r < n){
            hash[s[r]]++;
            
            if(hash.size() > k){
                hash[s[l]]--;
                if(hash[s[l]] == 0) hash.erase(s[l]);
                l++;
            }
            
            if(hash.size() == k){
                ans = max(ans, r - l + 1);
            }
            r++;
        }
        return ans == INT_MIN ? -1 : ans;
    }
};