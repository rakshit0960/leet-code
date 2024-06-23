type Fn = (accum: number, curr: number) => number

function reduce(nums: number[], fn: Fn, init: number): number {
    let res: number = init;
    for (let num of nums) {
        res = fn(res, num);
    }
    return res;
};