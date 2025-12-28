class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        // Set to store all unique bitwise OR results from all subarrays
        unordered_set<int> allResults;
      
        // Set to store bitwise OR results ending at the previous position
        unordered_set<int> previousEndingResults;
      
        // Iterate through each element in the array
        for (int currentElement : arr) {
            // Set to store bitwise OR results ending at current position
            unordered_set<int> currentEndingResults;
          
            // For each result that ended at the previous position,
            // compute OR with current element to extend those subarrays
            for (int previousResult : previousEndingResults) {
                currentEndingResults.insert(currentElement | previousResult);
            }
          
            // Include the subarray containing only the current element
            currentEndingResults.insert(currentElement);
          
            // Add all results ending at current position to the final answer set
            allResults.insert(currentEndingResults.begin(), currentEndingResults.end());
          
            // Update previous ending results for next iteration
            previousEndingResults = move(currentEndingResults);
        }
      
        // Return the count of unique bitwise OR values
        return allResults.size();
    }
};