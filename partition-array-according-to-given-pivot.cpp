class Solution {
    public int[] pivotArray(int[] arr, int pivot) {
        int n=arr.length;
        int[] ans=new int[n];
        int p=0, count=0;
        for(int num: arr){
            if(num<pivot)ans[p++]=num;
            else if(num==pivot)count++;
        }
        int q=p;
        while(count-->0)ans[q++]=pivot;
        for(int num: arr){
            if(num>pivot)ans[q++]=num;
        }
        return ans;
    }
}