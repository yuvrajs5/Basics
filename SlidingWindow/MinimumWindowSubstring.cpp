class Solution {
    public:
        string minWindow(string s, string t) {
            int start = 0;
            int end = 0;
            int minLength = s.size()+1;
            int startIndex = -1;
            int endIndex = -1;
            int unique =0;
            vector<int> frequencyS(128);
            vector<int> frequencyT(128);
              for (char c : t) {
                frequencyT[c]++;
            }
            for (int count : frequencyT) {
                if (count > 0) {
                    unique++;
                }
            }
            while (end < s.length()) {
                char c = s[end];
                frequencyS[c]++;
    
                if (frequencyT[c] > 0 && frequencyS[c] == frequencyT[c]) {
                    unique--;
                }
    
                while (unique == 0) {
                    if (end - start + 1 < minLength) {
                        minLength = end - start + 1;
                        startIndex = start;
                    }
    
                    char ch = s[start];
                    frequencyS[ch]--;
    
                    if (frequencyT[ch] > 0 && frequencyS[ch] < frequencyT[ch]) {
                        unique++;
                    }
                    start++;
                }
    
                end++;
            }
    
            return startIndex == -1 ? "" : s.substr(startIndex, minLength);
        }
    };