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
                char curr_char = pattern.charAt(i);  //to get the current character of pattern
                String token = tokens[i];

                // Check the one-one mapping
                if (!map.containsKey(curr_char) && !inverseMap.containsKey(token))//if it does'nt contain anything the char or word
                {
                   map.put(curr_char, token);//simply put it in map
                    inverseMap.put(token, curr_char);
                } else if (map.containsKey(curr_char) && inverseMap.containsKey(token)) {
                    String tokenToCheck = map.get(curr_char);
                    char charToCheck = inverseMap.get(token);

         //checking if mapping of curr_char is equal to curr_word or not
               if (!tokenToCheck.equals(token) || curr_char != charToCheck) 
               {
                        return false;  //it has to be equal so we returned false      
                }
                } else
                { 
                    return false;
                }
            }

            return true;
        }
    }
