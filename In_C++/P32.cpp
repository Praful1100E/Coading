class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // Iterate through digits from right to left (least significant to most significant)
        for (int i = digits.size() - 1; i >= 0; --i) {
            // Add 1 to the current digit
            ++digits[i];
          
            // Handle carry by taking modulo 10
            // If digit becomes 10, it will be set to 0
            digits[i] %= 10;
          
            // If the digit is not 0, there's no carry to propagate
            // We can return the result immediately
            if (digits[i] != 0) {
                return digits;
            }
          
            // If digit is 0, continue to next iteration to handle carry
        }
      
        // If we exit the loop, all digits were 9 (e.g., 999 -> 1000)
        // Insert 1 at the beginning of the array
        digits.insert(digits.begin(), 1);
      
        return digits;
    }
};