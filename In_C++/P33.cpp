class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        // Use a hash set to track elements we've seen
        unordered_set<int> seen;
      
        // Iterate through the array
        for (int i = 0; ; ++i) {
            // Check if current element has been seen before
            if (seen.count(nums[i])) {
                // If yes, this is the element that appears N times
                return nums[i];
            }
            // Add current element to the set of seen elements
            seen.insert(nums[i]);
        }
    }
};