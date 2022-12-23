class Solution {
public:
    int maxProfit(vector<int>& w) {
        int n = w.size();
        vector<vector<int>> f(2, vector<int>(3, 0));    
        // state: f[i][0] = not hold, f[i][1] = hold ,f[i][2] = cooldown
        f[0][1] = -1e9;

        for (int i = 1; i <= n; i ++ ) {
            f[i % 2][0] = max(f[i - 1 & 1][0], f[i - 1 & 1][2]);        
            f[i % 2][1] = max(f[i - 1 & 1][1], f[i - 1 & 1][0] - w[i - 1]);
            f[i % 2][2] = f[i - 1 & 1][1] + w[i - 1];
        }

        return max(f[n & 1][2], f[n & 1][0]);
        // solutions are either in cooldown or not holding
    }
};
