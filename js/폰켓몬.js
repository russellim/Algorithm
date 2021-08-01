/*
https://programmers.co.kr/learn/courses/30/lessons/1845
21_07_07 create.
21_07_08 update: Set, forEach 사용.
21_07_08 update: forEach 주석처리하고 바로 넣어줌.
21_07_08 solved!
*/

function solution(nums) {
    const numsSize = nums.length / 2;

//     let set = new Set();
//     // 반복문!
//     nums.forEach(function(item) {
//         set.add(item);
//     });
    
    // 반복문 사용 안하고 바로 넣기.
    let set = new Set(nums);

    var setSize = set.size;
    return ((setSize >= numsSize) ? numsSize : setSize);
}