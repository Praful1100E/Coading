class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
      
        // dp[i][j] represents the maximum dot product of subsequences 
        // from nums1[0...i-1] and nums2[0...j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MIN));
      
        // Iterate through all pairs of elements
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // Calculate the product of current pair
                int currentProduct = nums1[i - 1] * nums2[j - 1];
              
                // Option 1: Skip element from nums1 (take dp[i-1][j])
                dp[i][j] = dp[i - 1][j];
              
                // Option 2: Skip element from nums2 (take dp[i][j-1])
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
              
                // Option 3: Include current pair
                // Either start new subsequence with current pair only,
                // or extend previous subsequence dp[i-1][j-1] with current pair
                dp[i][j] = max(dp[i][j], max(0, dp[i - 1][j - 1]) + currentProduct);
            }
        }
      
        return dp[m][n];
    }
};