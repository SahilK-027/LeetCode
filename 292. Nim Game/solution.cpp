/*
Runtime : 3 ms
Memory : 5.9 MB

TC : O(1)
SC : O(1)
*/

/**
 * @author : Shashank Bhosagi
 * @brief : Math
 */

class Solution
{
public:
    bool canWinNim(int n)
    {

        // Check if the number of stones remaining is divisible by 4
        if (n % 4 == 0)
        {
            // If it is, then the current player cannot win because
            // no matter how many stones they remove (1, 2, or 3),
            // the other player can always remove enough stones to leave a
            // multiple of 4 stones remaining, and thus force the current player to lose.

            // Therefore, return false
            return false;
        }
        else
        {
            // If the number of stones remaining is not divisible by 4,
            // then the current player can remove enough stones to leave a multiple of 4
            // stones remaining, and force the other player into the losing position.

            // Therefore, return true
            return true;
        }
    }
};
