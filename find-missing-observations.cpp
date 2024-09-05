class Solution {
    public static int[] getmissingelements(int rolls[], int n, int diff){
        int ans[]=new int[n];
        int nd=diff;
        int md=diff/n;
        for(int i=0; i<n; i++){
            ans[i]=md;
            nd-=md;
        }
        for(int i=0; i<nd; i++){
            ans[i%n]++;
        }
        return ans;
    }
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int m=rolls.length;
        
        int sum=0, tsum=mean*(n+m), diff=0;
       
        for(int i=0; i<rolls.length; i++){
            sum+=rolls[i];
        }
        diff=tsum-sum;
        if(diff<n || diff>6*n){
            return new int[0];
        }
        return getmissingelements(rolls,n, diff);
    }
}