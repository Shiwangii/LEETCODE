
// Computer Knowledge
// 31 minutes ago
// B.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = (int)nums1.size();
        vector<long long> ans(n, 0);

        vector<array<long long, 3>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {(long long)nums1[i], (long long)nums2[i], (long long)i};
        }

        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            return a[0] < b[0];
        });

        vector<array<long long, 2>> queries(n);
        for (int i = 0; i < n; i++) {
            queries[i] = {(long long)nums1[i], (long long)i};
        }

        sort(queries.begin(), queries.end(), [](auto &a, auto &b) {
            return a[0] < b[0];
        });

        multiset<long long> small, large;
        long long sumLarge = 0;

        auto balance = [&](long long val) {
            if (large.size() < k || val >= *large.begin()) {
                sumLarge += val;
                large.insert(val);
                if (large.size() > k) {
                    auto it = large.begin();
                    sumLarge -= *it;
                    small.insert(*it);
                    large.erase(it);
                }
            } else {
                small.insert(val);
            }
        };

        int p = 0;
        for (auto &q : queries) {
            long long val = q[0];
            long long idx = q[1];
            while (p < n && arr[p][0] < val) {
                balance(arr[p][1]);
                p++;
            }
            ans[idx] = sumLarge;
        }

        return ans;
    }
};