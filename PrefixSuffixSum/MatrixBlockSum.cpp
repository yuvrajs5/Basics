class Solution {
    public:
        vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = mat[i - 1][j - 1] + prefix[i - 1][j]+ prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int r1 = max(0, i - k);
                int c1 = max(0, j - k);
                int r2 = min(m - 1, i + k);
                int c2 = min(n - 1, j + k);
                r1++; c1++; r2++; c2++;
                ans[i][j] = prefix[r2][c2]- prefix[r1 - 1][c2]- prefix[r2][c1 - 1]+ prefix[r1 - 1][c1 - 1];
            }
        }
        
        return ans;
    }
    
    };