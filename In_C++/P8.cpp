class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();

        // Since nums[i] <= 100000, max double = 200000
        vector<long long> leftFreq(200001, 0);
        vector<long long> rightFreq(200001, 0);

        // Fill right frequency initially with all elements
        for (int x : nums) rightFreq[x]++;

        long long ans = 0;

        for (int j = 0; j < n; j++) {
            int mid = nums[j];

            // remove current from right side
            rightFreq[mid]--;

            long long need = mid * 2LL;
            if (need <= 200000) {
                long long leftCount = leftFreq[need];
                long long rightCount = rightFreq[need];

                ans = (ans + (leftCount * rightCount) % MOD) % MOD;
            }

            // add current to left side
            leftFreq[mid]++;
        }

        return ans % MOD;
    }
};
