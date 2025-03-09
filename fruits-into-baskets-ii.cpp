class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n, false); // To mark used baskets
        int unplaced = 0;
        
        for (int i = 0; i < n; i++) {
            bool placed = false;
            for (int j = 0; j < n; j++) {
                if (!used[j] && baskets[j] >= fruits[i]) { // If basket is not used and has enough capacity
                    used[j] = true; // Mark basket as used
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                unplaced++; // If fruit is not placed, increment unplaced count
            }
        }
        return unplaced;
    }
};