class Solution {
public:
    int n, m;
    string minWindow(string s, string t) {
        n = s.size();
        m = t.size();
        if(m > n) return "";

        vector<int> mpp(256, 0);
        for(auto it : t){
            mpp[it]++;
        }

        int l = 0;
        int r = 0;
        int startIndex = -1;
        int minLen = INT_MAX;
        int cnt = 0;

        while(r < n){
            if(mpp[s[r]] > 0) cnt++; //if a +ve occurs count increase
            mpp[s[r]]--;

            while(cnt == m){ //we need the smallest so shrink the window
                if(r - l + 1 < minLen){ //agar you find a smaller ans, update!
                    minLen = r - l + 1;
                    startIndex = l;
                }

                mpp[s[l]]++; //remove the element (in this ques we do ++ on removal and -- on adding in the window)
                if(mpp[s[l]] > 0) cnt--; 
                l++;
            }
            r++;
        }
        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};