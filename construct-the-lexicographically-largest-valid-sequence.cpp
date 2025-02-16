class Solution {
    public int[] constructDistancedSequence(int n) {
        int[] arr = new int[n * 2 - 1];
        boolean[] used = new boolean[n + 1];
        backtrack(0, arr, used, n);
        return arr;
    }

    private boolean backtrack(int idx, int[] arr, boolean[] used, int n) {
        if (idx == arr.length) return true;
        if (arr[idx] != 0) return backtrack(idx + 1, arr, used, n);

        for (int num = n; num >= 1; num--) {
            if (used[num]) continue;
            used[num] = true;
            arr[idx] = num;
            
            if (num == 1 || (idx + num < arr.length && arr[idx + num] == 0)) {
                if (num > 1) arr[idx + num] = num;
                if (backtrack(idx + 1, arr, used, n)) return true;
                if (num > 1) arr[idx + num] = 0;
            }
            
            arr[idx] = 0;
            used[num] = false;
        }
        return false;
    }
}
