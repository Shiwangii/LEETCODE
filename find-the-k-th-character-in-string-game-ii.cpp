class Solution {
    public char kthCharacter(long k, int[] operations) {
        long length = 1;

        for (int operation : operations) {
            if (operation == 0) {
                length *= 2;
            } else if (operation == 1) {
                length *= 2;
            }
        }

        for (int i = operations.length - 1; i >= 0; i--) {
            int operation = operations[i];

            if (operation == 0) {
                if (k > length / 2) {
                    k -= length / 2;
                }
                length /= 2;
            } else if (operation == 1) {
                if (k > length / 2) {
                    k -= length / 2;
                }
                length /= 2;
            }
        }
        return 'b';
    }
}
