import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> stringMatching(String[] words) {
        List<String> match = new ArrayList<>();
        
        for (int c = 0; c < words.length; c++) {
            for (int o = 0; o < words.length; o++) {
                if (c != o && words[o].contains(words[c])) {
                    if (!match.contains(words[c])) {
                        match.add(words[c]);
                    }
                    break; // No need to check further for this word
                }
            }
        }
        
        return match;
    }
}
