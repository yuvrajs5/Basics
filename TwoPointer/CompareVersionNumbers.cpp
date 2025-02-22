class Solution {
    public:
        int compareVersion(string version1, string version2) {
        for (int i = 0, j = 0; (i < version1.size() || j < version2.size()); ) {
            int val1 = 0;
            int val2 = 0;
    
            while (i < version1.size() && version1[i] != '.') {
                val1 = val1 * 10 + (version1[i++] - '0');
            }
            if (i < version1.size() && version1[i] == '.') i++;
    
            while (j < version2.size() && version2[j] != '.') {
                val2 = val2 * 10 + (version2[j++] - '0');
            }
            if (j < version2.size() && version2[j] == '.') j++;
    
            if (val1 > val2) {
                return 1;
            } else if (val1 < val2) {
                return -1;
            }
        }
        return 0;
    }
    };