class Solution {
    public int countServers(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        int total_ser=0;
        int row_count[]=new int[m];
        int col_count[]=new int[n];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    row_count[i]++;
                    col_count[j]++;
                    total_ser++;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 &&(row_count[i]==1 && col_count[j]==1))total_ser--;
            }
        }
        return total_ser;
    }
}