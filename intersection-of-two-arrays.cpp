class Solution {
    
     public static int[] intersection(int arr1[], int arr2[]) {
        int n = arr1.length;
        int m = arr2.length;
    
        ArrayList<Integer> inter = Intersectionarray(arr1, arr2, n, m);
        int[] result=new int[inter.size()];
        for(int i=0; i< inter.size(); i++){
            result[i]=inter.get(i);
        }
        return result;
    }

    public static ArrayList<Integer> Intersectionarray(int arr1[], int arr2[], int n, int m) {
        HashSet<Integer> set1 = new HashSet<>();
        HashSet<Integer> set2 = new HashSet<>();
        
        for (int i : arr1) {
            set1.add(i);
        }
        for (int i : arr2) {
            set2.add(i);
        }
        
        ArrayList<Integer> list = new ArrayList<>();
        for (int i : set1) {
            if (set2.contains(i)) {
                list.add(i);
            }
        }
        return list;
    }
}