public class Solution {
    public int[] twoSum(int[] numbers, int target) {

        //creating new hashmap
        Map<Integer,Integer> map = new HashMap<>();

        //running a for loop
        for(int i=0;i< numbers.length;i++){

            //making the complement of the numbers in the array
            int compl=target-numbers[i];

            //findiing a num whether it exits in hashmap
            if (map.containsKey(compl)){
                return new int[]{map.get(compl),i};
                
            }
            //if we dont find the complement, so just put the index in hashmap
            map.put(numbers[i],i);
            
        }
        return null;
        
    }
}
/*
1 ms
42.7 MB

TC : O(n)
*/

/**
 * @author : yashlondhe90960
 * @brief : Hashing
*/
