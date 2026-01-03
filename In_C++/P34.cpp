using ll = long long;

class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
      
        // Initial state: patterns for the first row
        // patternABA: count of patterns where adjacent cells have different colors (e.g., Red-Yellow-Red)
        // patternABC: count of patterns where all three cells have different colors (e.g., Red-Yellow-Green)
        ll patternABA = 6;  // 6 ways to color in ABA pattern
        ll patternABC = 6;  // 6 ways to color in ABC pattern
      
        // Process each subsequent row
        while (--n) {
            // Calculate patterns for the next row based on transition rules
            // From ABA pattern: can transition to 3 ABA patterns + 2 ABC patterns
            // From ABC pattern: can transition to 2 ABA patterns + 2 ABC patterns
            ll nextPatternABA = (patternABA * 3 + patternABC * 2) % MOD;
            ll nextPatternABC = (patternABA * 2 + patternABC * 2) % MOD;
          
            // Update current patterns for the next iteration
            patternABA = nextPatternABA;
            patternABC = nextPatternABC;
        }
      
        // Return total number of ways (sum of both pattern types)
        return static_cast<int>((patternABA + patternABC) % MOD);
    }
};