class Solution {
public:
    static const long long MOD = 1000000007;

    int countTrapezoids(vector<vector<int>>& points) {

        unordered_map<long long, long long> mp;  
        mp.reserve(points.size() * 2);

        // Count points grouped by y-coordinate
        for (auto &p : points) {
            mp[(long long)p[1]]++;
        }

        // For each horizontal level with k points, segments = C(k,2)
        vector<long long> seg;
        seg.reserve(mp.size());

        for (auto &it : mp) {
            long long k = it.second;
            if (k >= 2) {
                seg.push_back((k * (k - 1) / 2) % MOD);
            }
        }

        long long S = 0, S2 = 0;

        for (long long x : seg) {
            S = (S + x) % MOD;              // sum of all segment counts
            S2 = (S2 + (x * x) % MOD) % MOD; // sum of squares
        }

        // Formula: sum over i<j = (S^2 - S2) / 2
        long long ans = (S * S) % MOD;
        ans = (ans - S2 + MOD) % MOD;

        long long inv2 = (MOD + 1) / 2; // modular inverse of 2
        ans = (ans * inv2) % MOD;

        return (int)ans;
    }
};
