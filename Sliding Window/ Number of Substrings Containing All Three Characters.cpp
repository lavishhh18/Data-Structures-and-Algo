class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> posi(3, -1);
        int r = 0;
        int cnt = 0;
        
        while(r < n){
            posi[s[r] - 'a'] = r;
            int last = min(posi[0], min(posi[1], posi[2]));
            if(last != -1){
                cnt += last + 1;
            }
            r++;
        }
        return cnt;

    }
};