/**
 * @param {number[]} nums
 * @return {number[]}
 */
var runningSum = function(nums) {
    var sum = 0;
    var arr = [];
    nums.forEach((num)=>{
        sum += num;
        arr.push(sum);
    });
    return arr;
};