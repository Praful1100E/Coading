class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long maxArea = 0;
        int n = bottomLeft.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Find the boundaries of the intersection
                long long minX = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long maxX = min(topRight[i][0], topRight[j][0]);
                long long minY = max(bottomLeft[i][1], bottomLeft[j][1]);
                long long maxY = min(topRight[i][1], topRight[j][1]);

                // Check if an intersection exists
                if (minX < maxX && minY < maxY) {
                    long long side = min(maxX - minX, maxY - minY);
                    maxArea = max(maxArea, side * side);
                }
            }
        }
        return maxArea;
    }
};