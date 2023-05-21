/*
61 ms
42.4 MB
*/

/**
 * @author : SahilK-027
 * @brief : JavaScript
*/

/**
 * @return {Function}
 */
var createHelloWorld = function() {
    return function(...args) {
        return "Hello World";
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */