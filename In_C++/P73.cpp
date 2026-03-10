class Solution {
public:
    /**
     * Check if all '1's in the binary string form a single contiguous segment.
     * 
     * The string contains a single segment of '1's if there are no '0's followed by '1's.
     * If pattern "01" exists, it means '1's are split into multiple segments.
     * 
     * @param s - Binary string containing only '0's and '1's
     * @return true if all '1's form a single contiguous segment, false otherwise
     */
    bool checkOnesSegment(string s) {
        // Check if pattern "01" exists in the string
        // If "01" is not found (returns string::npos), all '1's are contiguous
        return s.find("01") == string::npos;
    }
};