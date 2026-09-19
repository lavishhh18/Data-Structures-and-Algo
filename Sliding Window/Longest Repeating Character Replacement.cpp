class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxLen = 0;
        int maxF = 0;
        vector<int> freq(26, 0);

        while(r < n){
            int c = s[r] - 'A';
            freq[c]++;
            maxF = max(maxF, freq[c]);

            if(r - l + 1 - maxF > k){
                freq[s[l] - 'A']--;
                l++;
            }

            if(r - l + 1 - maxF <= k){
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};