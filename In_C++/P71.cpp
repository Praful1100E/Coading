class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        // Encode each number by adding (bit count * 100000) to create a composite value
        // This allows sorting by bit count first, then by the original value
        for (int& value : arr) {
            int bitCount = __builtin_popcount(value);  // Count number of 1-bits
            value += bitCount * 100000;  // Encode: new_value = original + (bit_count * 100000)
        }
      
        // Sort the encoded values
        // Values with fewer bits will have smaller encoded values
        // Among values with same bit count, smaller original values come first
        sort(arr.begin(), arr.end());
      
        // Decode each number back to its original value using modulo operation
        for (int& value : arr) {
            value %= 100000;  // Extract original value by removing the bit count encoding
        }
      
        return arr;
    }
};