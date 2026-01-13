class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totalTime = 0;
      
        // Iterate through consecutive pairs of points
        for (int i = 1; i < points.size(); ++i) {
            // Calculate the horizontal distance between current and previous point
            int horizontalDistance = abs(points[i][0] - points[i - 1][0]);
          
            // Calculate the vertical distance between current and previous point
            int verticalDistance = abs(points[i][1] - points[i - 1][1]);
          
            // The minimum time to travel between two points is the maximum of 
            // horizontal and vertical distances (due to diagonal movement capability)
            // We can move diagonally (1 unit in both x and y) or straight (1 unit in x or y)
            // So the time required is determined by the larger dimension
            totalTime += max(horizontalDistance, verticalDistance);
        }
      
        return totalTime;
    }
};