class Solution {
    public int compress(char[] chars) {
        int index=0, count=1;
        char curr_char=chars[0];
        List<Character> arr=new ArrayList<>();
        for(int i=1; i<chars.length; i++){
            if(curr_char==chars[i]){
                count++;
                // arr.add(curr_char);

            }
            else{
                arr.add(curr_char);
                if(count>1){
                    for(char c: Integer.toString(count).toCharArray()){
                        arr.add(c);
                    }
                }

                curr_char=chars[i];
                count=1;
                
            }

        }
        arr.add(curr_char);
        if(count>1){
            for(char c: Integer.toString(count).toCharArray()){
                arr.add(c);
            }
        }
        for(int i=0; i<arr.size(); i++){
            chars[i]=arr.get(i);
        }
        
        return arr.size();
        
    }
}