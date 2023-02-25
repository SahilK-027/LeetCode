/*
99 ms
47.5 MB

TC: O(n)
SC: O(1)

* @author: SahilK-027
* @brief: Linked list traversal
*/


/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let carry = 0;
    // Node to keep track of prev node
    let head = new ListNode(0);
    let ans = head;
    while(l1 || l2 || carry){
        let val1 = 0;
        let val2 = 0;
        // If l1 not empty
        if(l1){
            val1 = l1.val;
            l1 = l1.next;
        }
        // If l2 not empty
        if(l2){
            val2 = l2.val;
            l2 = l2.next;
        }
        // Find sum , last_digit and carry
        let sum = val1 + val2 + carry;
        let last_digit = sum % 10;
        // Get carry as integer
        carry = parseInt(sum / 10);
        // Store answer ion current node
        const currNode = new ListNode(last_digit);
        // Attach current node to head
        head.next = currNode;
        // Make current node as head
        head = currNode;
    }
    return ans.next;
};
