class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int left = 0, right = n - 1;

        // Skip all leading 'L'
        while (left < n && directions[left] == 'L')
            left++;

        // Skip all trailing 'R'
        while (right >= 0 && directions[right] == 'R')
            right--;

        int collisions = 0;

        // Count collisions in the remaining part
        for (int i = left; i <= right; i++) {
            if (directions[i] == 'L' || directions[i] == 'R')
                collisions++;
        }

        return collisions;
    }
};
