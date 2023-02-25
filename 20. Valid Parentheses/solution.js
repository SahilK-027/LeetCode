/*
73 ms
42.2 MB

TC: O(N)
SC: O(N)

@author: SahilK-027
@brief: Stack

*/
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let n = s.length;
    const stack = [];
    for(let i = 0 ; i < n ; i++){
        let ch = s[i];
        switch(ch){
            case '(':
                stack.push(')');
                break;
            case '[':
                stack.push(']');
                break;
            case '{':
                stack.push('}');
                break;
            default:
                if(ch != stack.pop()){
                    return false;
                }
        } 
    }
    return (stack.length == 0) ;
};
