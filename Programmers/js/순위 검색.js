/*
https://programmers.co.kr/learn/courses/30/lessons/72412
21_07_18 create.
21_07_19 update: 문자열 자르기 추가. str.split(' ') -> array 반환.
21_07_20 update: for추가
21_07_21 update: for->foreach
*/

const SCORE_INDEX = 4

function solution(info, query) {
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
    
    let temp = [];
    for(let i=0; i<info.length; ++i){
        temp.push(1);
    }

    searchDB.forEach(search_query => {
        search_query.forEach(search_data_, indexNum => {
            if(search_query === "-") continue;

            infoDB.forEach(data => {
                if(indexNum === SCORE_INDEX) {

                }
                else {
                    if(data[indexNum] === data){

                    }
                }
            })
        });
    });

    
    console.log(infoDB);
    console.log(searchDB);

    return answer;
}

console.log(solution(["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"],
["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]));