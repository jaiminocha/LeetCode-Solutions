/**
 * @param {number[]} nums
 * @return {number}
 */
'use strict';
var pivotIndex = function(nums) {
    // var left[n], right = [];
    // var n = nums.length, sum = 0;
    // for (let i = 0; i < n; i++){
    //     left[i] = sum;
    //     sum += nums[i];
    // }
    // sum = 0;
    // for (let i = n - 1; i >= 0; i--){
    //     right[i] = sum;
    //     sum += nums[i];
    // }
    // for (let i = 0; i < n; i++){
    //     if (left[i] == right[i]) return i;
    // }
    // return -1;
    
    var totalSum = 0, sum = 0;
    var n = nums.length;
    
    nums.forEach((num)=>{
        totalSum += num;
    });
    
    for (let i = 0; i < n; i++){
        totalSum -= nums[i];
        if (sum == totalSum){
            return i;
        }
        sum += nums[i];
    }
    return -1;
};