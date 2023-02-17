/*
106 ms
46.9 MB
*/
/**
 * TC: O(n log n)
 * SC: O(n)
*/
/**
 * @author : SahilK-027
 * @brief : Heap
 */

/**
 * @param {number[]} gifts
 * @param {number} k
 * @return {number}
 */
var pickGifts = function(gifts, k) {
    const pq = new MaxPriorityQueue();
    // gifts.forEach((element, index)=>{
    //     pq.enqueue(element);
    // })

    for (let i of gifts) {
        pq.enqueue(i);
    }
    // for(let i = 0 ; i < gifts.length ; i++){
    //     pq.enqueue(gifts[i]);
    // }
    while(k--){
        let top = pq.dequeue().element;
        let rem =  Math.floor(Math.sqrt(top));
        pq.enqueue(rem);
    }

    let ans = 0;
    while (!pq.isEmpty()) {
        ans += pq.dequeue().element;
    }

    return ans;
};