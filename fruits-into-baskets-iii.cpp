class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> tree(4 * n);
        vector<int> basketCopy = baskets; // Copy to maintain original input
        
        // Build the segment tree
        auto build = [&](auto&& self, int node, int start, int end) -> void {
            if (start == end) {
                tree[node] = basketCopy[start];
            } else {
                int mid = (start + end) / 2;
                self(self, 2 * node + 1, start, mid);
                self(self, 2 * node + 2, mid + 1, end);
                tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
            }
        };
        
        auto query = [&](auto&& self, int node, int start, int end, int val) -> int {
            if (start == end) {
                return (tree[node] >= val) ? start : -1;
            }
            int mid = (start + end) / 2;
            if (tree[2 * node + 1] >= val) {
                return self(self, 2 * node + 1, start, mid, val);
            }
            return self(self, 2 * node + 2, mid + 1, end, val);
        };
        
        auto update = [&](auto&& self, int node, int start, int end, int idx) -> void {
            if (start == end) {
                tree[node] = -1;
            } else {
                int mid = (start + end) / 2;
                if (idx <= mid) {
                    self(self, 2 * node + 1, start, mid, idx);
                } else {
                    self(self, 2 * node + 2, mid + 1, end, idx);
                }
                tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
            }
        };
        
        build(build, 0, 0, n - 1);
        
        int unplacedFruits = 0;
        for (int fruit : fruits) {
            int idx = query(query, 0, 0, n - 1, fruit);
            if (idx == -1) {
                unplacedFruits++;
            } else {
                update(update, 0, 0, n - 1, idx);
            }
        }
        
        return unplacedFruits;
    }
};