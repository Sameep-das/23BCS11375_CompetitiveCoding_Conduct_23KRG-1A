"use strict";
function matChainMul(arr, i, j) {
    if (i == j)
        return 0;
    let res = Number.MAX_VALUE;
    for (let k = i; k < j; ++k) {
        let steps = arr[i - 1] * arr[k] * arr[j] + matChainMul(arr, i, k) + matChainMul(arr, k + 1, j);
        res = Math.min(steps, res);
    }
    return res;
}
let arr = [10, 20, 30, 40];
console.log(matChainMul(arr, 1, arr.length - 1));
