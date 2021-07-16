/*
https://programmers.co.kr/learn/courses/30/lessons/72411
21_07_14 create.
21_07_16 update: 조합과 map 사용해서 만들어보자.
*/

var map = new Map();
var setMenu = "";

function makeSetMenu(count = 0, maximum = 0, index = 0, order = "")
{
    if(count === maximum)
    {
        map[setMenu]++;
        console.log(map[setMenu]);
        return;
    }

    for(let i=index; i<order.length; ++i)
    {
        setMenu += order[i];
        makeSetMenu(count+1, maximum, index+1, order);
        setMenu = setMenu.substr(0, setMenu.length-1);
    }
}

function solution(orders, course) 
{
    var answer = [];

    for(let len in course)
    {
        for(let order in orders)
        {
            if(order.length < course[len]) continue;
            makeSetMenu(0, course[len], 0, order);
        }

        for(let [key, value] of map)
        {
            console.log(`${key} = ${value}`);
        }
        map.clear();
    }

    return answer;
}

console.log(solution(["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"], [2,3,4]));
console.log(solution(["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"], [2,3,5]));
console.log(solution(["XYZ", "XWY", "WXA"], [2,3,4]));

console.log("qwe");
