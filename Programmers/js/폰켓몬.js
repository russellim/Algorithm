/*
21_07_07 create.
21_07_08 update Set, forEach 사용.
*/

function solution(nums) {
    const numsSize = nums.length / 2;
    let set = new Set();
    
    // 반복문!
    nums.forEach(function(item) {
        set.add(item);
    });

    var setSize = set.size;
    return ((setSize >= numsSize) ? numsSize : setSize);
}