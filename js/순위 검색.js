/*
https://programmers.co.kr/learn/courses/30/lessons/72412
참고: https://programmers.co.kr/questions/15601
21_07_18 create.
21_07_19 ~ 21_07_24 update: 문자열 자르기 추가. str.split(' ') -> array 반환, foreach, 쿼리 검색 매치,  Number() 사용, 제출했는데 시간 초과
21_07_25 update: Map 써서 새로운 방법으로 해보자
21_07_31 update: 시간초과

*/

var infoMap = new Map();
var infoTempArr;

function arrayToString(arr)
{
    let str = "";
    for(let i=0; i<=3; ++i){
        str += arr[i];
    }
    return str;
}

function makeInfoString(oneInfoArr, totalBarCount, useBarCount, index){
    if(totalBarCount == useBarCount){
        let infoStr = arrayToString(infoTempArr);
        //infoMap.push([oneInfoArr[4], infoStr]);
        //infoMap[infoStr].push(oneInfoArr[4]);
        return;
    }

    for(let i=index; i<4; ++i){
        if (totalBarCount - useBarCount > 4 - i) return;
        infoTempArr[i] = "-";
        makeInfoString(oneInfoArr, totalBarCount, useBarCount+1, i+1);
        infoTempArr[i] = oneInfoArr[i];
    }   
}

function solution(info, query){
    var answer = [];
    var infoArr = [];
    var searchArr = [];
    info.forEach(value =>{
        infoArr.push(value.split(' '));
    });
    
    infoArr.forEach(oneInfoArr =>{
        infoTempArr = oneInfoArr.slice();
        for(let barCount=0; barCount<=4; ++barCount){
            makeInfoString(oneInfoArr, barCount, 0, 0);
        }
    });

    //infoMap.sort((a, b) => b[0] - a[0]);
    
    let count = 0;
    query.forEach(value =>{
         searchArr.push(value.split(' and '));
    });
    for(let i=0; i<searchArr.length; ++i){
        let temp = searchArr[i][3];
        let splitTemp = temp.split(' ');
        searchArr[i].pop();
        searchArr[i].push(splitTemp[0]);
        
        let searchStr = arrayToString(searchArr[i]);
        let searchScore = splitTemp[1];
        
    }

    return answer;
}

const SCORE_INDEX = 4;
function solution_legacy(info, query) {
    var answer = [];
    var infoDB = [];
    var searchDB = [];

    info.forEach(element => {
        infoDB.push(element.split(' '));
    });

    query.forEach(element => {
        searchDB.push(element.split(' and '));
    });
    for(let i=0; i<searchDB.length; ++i){
        let temp = searchDB[i][3];
        let splitTemp = temp.split(' ');
        searchDB[i].pop();
        splitTemp.forEach(value =>{
            searchDB[i].push(value);
        });
        
    }
    
    
    searchDB.forEach(search_query => {
        let selectTemp = [];
        for(let i=0; i<info.length; ++i){
        selectTemp.push(1);
        }
        
        search_query.forEach((search_data, search_index) => {
            if(search_data == '-') return;
            
            infoDB.forEach((info_data, info_index) => {
                if(selectTemp[info_index] === 0) return;
                if(search_index === SCORE_INDEX){
                    if(Number(info_data[search_index]) < Number(search_data))
                         selectTemp[info_index] = 0;         
                }
                else {
                    if(info_data[search_index] != search_data)
                        selectTemp[info_index] = 0;
                }
            });
        });
        
        let count = selectTemp.filter(element => 1 === element).length;
        answer.push(count);
    });
    
    return answer;
}

console.log(solution(["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"],
["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]));
