type Fn = (...params: number[]) => number

function memoize(fn: Fn): Fn {
    var cache = new Map();

    return function(...args) {
        let key = JSON.stringify(args);
        if (cache.has(key)) 
            return cache.get(key);
        cache.set(key, fn(...args));
        return cache.get(key);
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */