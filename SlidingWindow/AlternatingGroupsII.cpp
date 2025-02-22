class Solution {
    public:
        int numberOfAlternatingGroups(std::vector<int>& colors, int k) {
            int n = colors.size();
            // if (n == 0 || k > n) return 0;
            for (int i = 0; i < n; i++) {
                colors.push_back(colors[i]);
            }
    
            int start = 0, end = 0;
            int count1 = 0, count2 = 0;
    
            while (end < 2 * n) {
                if (end > 0 && colors[end] == colors[end - 1]) {
                    start = end; 
                }
                if (end - start + 1 >= k) {
                    count2++;
                    start++; 
                }
                if (end == n - 1) {
                    count1 = count2;
                }
    
                end++;
            }
    
            return count2 - count1; 
        }
    };
    