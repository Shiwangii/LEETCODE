class Solution {
    public boolean checkPrime(int n){
        if(n<2)return false;
        for(int i=2; i*i<=n; i++){
            if(n%i==0)return false;

        }
        return true;
    }
    public int[] closestPrimes(int left, int right) {
        ArrayList<Integer> num=new ArrayList<>();
        for(int i=left;i<=right; i++){
            if(checkPrime(i))num.add(i);
        }
        if(num.size()<2)return new int[]{-1, -1};
        int ans[]={-1, -1};
        int min=Integer.MAX_VALUE;
        for(int i=1; i<num.size(); i++){
            int diff=num.get(i)-num.get(i-1);
            if(diff<min){
                min=diff;
                ans[1]=num.get(i);
                ans[0]=num.get(i-1);
            }
        }
        return ans;
    }
}