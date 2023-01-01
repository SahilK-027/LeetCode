/*
1 ms
40.3 MB

TC : O(N)
SC : O(n)
*/

/**
 * @author : yashlondhe90960
 * @brief : hashmap
*/ 
public class Solution {
        public boolean wordPattern(String pattern, String str) {
            if (pattern == null || pattern.length() == 0 || str == null || str.length() == 0) {
                return false;
            }

            String[] tokens = str.split(" ");

            if (pattern.length() != tokens.length) {
                return false;
            }
    //making 2 hashmaps
            Map<String, Character> inverseMap = new HashMap<>();
            Map<Character, String> map = new HashMap<>();

            for (int i = 0; i < pattern.length(); i++) {
                char c = pattern.charAt(i);
                String token = tokens[i];

                // Check the one-one mapping
                if (!map.containsKey(c) && !inverseMap.containsKey(token)) {
                    map.put(c, token);
                    inverseMap.put(token, c);
                } else if (map.containsKey(c) && inverseMap.containsKey(token)) {
                    String tokenToCheck = map.get(c);
                    char charToCheck = inverseMap.get(token);

                    if (!tokenToCheck.equals(token) || c != charToCheck) {
                        return false;
                    }
                } else { 
                    return false;
                }
            }

            return true;
        }
    }
