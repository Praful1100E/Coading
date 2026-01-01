class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int directions[5] = {0, 1, 0, -1, 0};

        auto canCross = [&](int day) -> bool {
            vector<vector<int>> grid(row, vector<int>(col, 0));

            for (int i = 0; i < day; ++i) {
                grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
            }

            queue<pair<int, int>> bfsQueue;

            for (int j = 0; j < col; ++j) {
                if (grid[0][j] == 0) {
                    bfsQueue.emplace(0, j);
                    grid[0][j] = 1;
                }
            }

            while (!bfsQueue.empty()) {
                auto [currentRow, currentCol] = bfsQueue.front();
                bfsQueue.pop();

                if (currentRow == row - 1) {
                    return true;
                }

                for (int i = 0; i < 4; ++i) {
                    int nextRow = currentRow + directions[i];
                    int nextCol = currentCol + directions[i + 1];

                    if (nextRow >= 0 && nextRow < row &&
                        nextCol >= 0 && nextCol < col &&
                        grid[nextRow][nextCol] == 0) {
                        bfsQueue.emplace(nextRow, nextCol);
                        grid[nextRow][nextCol] = 1;
                    }
                }
            }

            return false;
        };

        auto feasible = [&](int day) -> bool {
            return !canCross(day);
        };

        // Binary search for first day where crossing becomes impossible
        int left = 1;
        int right = cells.size();
        int firstTrueIndex = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (feasible(mid)) {
                firstTrueIndex = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // Return last day where crossing was still possible
        return firstTrueIndex - 1;
    }
};
