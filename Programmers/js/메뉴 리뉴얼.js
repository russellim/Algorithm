/*
https://programmers.co.kr/learn/courses/30/lessons/72411
21_07_14 create.
21_07_16 update: 조합과 map 사용해서 만들어보자.
21_07_17 update: map 삽입, 탐색 사용. sortString() 만듦.
21_07_17 solved!
*/
var map = new Map();
var setMenu = "";

// 세트 조합을 모두 찾는다.
// 찾은 조합의 카운트를 올려준다.
function makeSetMenu(count = 0, maximum = 0, index = 0, order = "")
{
    if(count === maximum)
    {
        if(map.has(setMenu)) map.set(setMenu, map.get(setMenu) + 1);
        else map.set(setMenu, 1);
        return;
    }

    for(let i=index; i<order.length; ++i)
    {
        setMenu += order[i];
        makeSetMenu(count+1, maximum, i+1, order);
        setMenu = setMenu.substr(0, setMenu.length-1);
    }
}

/// string을 sort한다.
/// ex> bca -> abc.
function sortString(str)
{
    let strArr = [];
    for(let i=0; i<str.length; ++i)
    {
        strArr.push(str[i]);
    }
    strArr.sort();
    str = "";
    for(let i=0; i<strArr.length; ++i)
    {
        str += strArr[i];
    }
    return str;
}

function solution(orders, course) 
{
    var answer = [];
    setMenu = "";

    for(let len in course)
    {
        for(let i in orders)
        {
            let order = sortString(orders[i]);
            if(order.length < course[len]) continue;
            makeSetMenu(0, course[len], 0, order);
        }

        // 이 course중 조합의 카운트가 가장 높은 것을 찾는다.
        let orderMaxCount = Math.max(...map.values());
        if(orderMaxCount > 1) // 2개 이상이여야 세트메뉴가 됨.
        {
            map.forEach((value, key) =>
            {
                if(value === orderMaxCount)
                {
                    answer.push(key);
                }
            })
        }
        map.clear();
    }

    answer.sort();
    console.log(answer);
    return answer;
}

console.log(solution(["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"], [2,3,4]));
console.log(solution(["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"], [2,3,5]));
console.log(solution(["XYZ", "XWY", "WXA"], [2,3,4]));