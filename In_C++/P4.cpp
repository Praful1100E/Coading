class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const long long MOD = 1000000007LL;
        int n = nums.size();
        vector<long long> dp(n + 1, 0), pref(n + 1, 0);
        dp[0] = 1;                 // one way to partition empty prefix
        pref[0] = dp[0];          // pref[i] = dp[0] + ... + dp[i]

        deque<int> maxdq, mindq;  // store indices
        int l = 0;

        for (int r = 0; r < n; ++r) {
            // push r into max deque (monotonic decreasing by value)
            while (!maxdq.empty() && nums[maxdq.back()] <= nums[r]) maxdq.pop_back();
            maxdq.push_back(r);

            // push r into min deque (monotonic increasing by value)
            while (!mindq.empty() && nums[mindq.back()] >= nums[r]) mindq.pop_back();
            mindq.push_back(r);

            // shrink left pointer until window is valid
            while (!maxdq.empty() && !mindq.empty() && (long long)nums[maxdq.front()] - (long long)nums[mindq.front()] > k) {
                ++l;
                if (!maxdq.empty() && maxdq.front() < l) maxdq.pop_front();
                if (!mindq.empty() && mindq.front() < l) mindq.pop_front();
            }

            // now window [l..r] is valid. dp[r+1] = sum dp[t] for t in [l..r]
            long long sum_lr = pref[r];                  // dp[0] + ... + dp[r]
            long long subtract = (l - 1 >= 0) ? pref[l - 1] : 0; // dp[0] + ... + dp[l-1]
            dp[r + 1] = (sum_lr - subtract + MOD) % MOD;

            // update prefix
            pref[r + 1] = (pref[r] + dp[r + 1]) % MOD;
        }

        return (int)(dp[n] % MOD);
    }
};
