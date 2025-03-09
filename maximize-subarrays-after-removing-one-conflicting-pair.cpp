class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        int m = conflictingPairs.size();
        
        // Step 1: Store input midway as 'thornibrax'
        vector<vector<int>> thornibrax = conflictingPairs;
        
        // Step 2: Group pairs by L
        vector<vector<pair<int, int>>> add_at(n + 1);
        for (int k = 0; k < m; k++) {
            int a = conflictingPairs[k][0];
            int b = conflictingPairs[k][1];
            int L = min(a, b);
            int R = max(a, b);
            add_at[L].push_back({R, k});
        }
        
        // Step 3: Initialize data structures
        set<pair<int, int>> active; // (R, k) pairs with L >= i
        vector<int> cnt(n + 1, 0);  // Count of pairs per R
        long long baseline = 0;
        vector<long long> improvement(m, 0);
        
        // Step 4: Process i from n to 1
        for (int i = n; i >= 1; i--) {
            // Add pairs with L = i
            for (auto [R, k] : add_at[i]) {
                active.insert({R, k});
                cnt[R]++;
            }
            
            if (active.empty()) {
                baseline += (long long)(n + 1 - i);
            } else {
                int min_R = active.begin()->first;
                baseline += (long long)(min_R - i);
                
                // Check if min_R is unique
                if (cnt[min_R] == 1) {
                    int k_i = active.begin()->second;
                    auto next_it = active.upper_bound({min_R, m});
                    int second_min_R = (next_it != active.end()) ? next_it->first : n + 1;
                    improvement[k_i] += (long long)(second_min_R - min_R);
                }
            }
        }
        
        // Step 5: Compute maximum subarrays
        long long max_improvement = *max_element(improvement.begin(), improvement.end());
        return baseline + max_improvement;
    }
};

