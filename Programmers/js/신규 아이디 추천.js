/*
https://programmers.co.kr/learn/courses/30/lessons/72410
21_07_09 create.
21_07_09 update: 함수 이름만 우선 작성.
21_07_10 update: 1, 2, 3 단계 작성.
*/

function toLower(str)
{
    // 1. 모든 대문자 -> 소문자.
    return str.toLowerCase();
}

function removeAt(str, start, end = -1)
{
    if(end === -1) end = start;
    return str.slice(0, start) + str.slice(end+1);
}

function eraseCharFromString(str)
{
    // 2. str 순회하면서 알파벳 숫자 - _ . 제외하고 삭제.
    let check_eng = /[a-z]/;
    let check_num = /[0-9]/;
    let check_spc = /[-_.]/;
    for(let i=0; i<str.length; ++i){
        if(!check_eng.test(str[i]) && 
           !check_num.test(str[i]) && 
           !check_spc.test(str[i])) {
            str = removeAt(str, i);
            --i;
        }
    }
    return str;
}

function eraseContinuousDotFromString(str)
{
    // 3. str 순회하면서 연속된 . 하나로 만들기.
    let start = -1, end = -1;
    for(let i=0; i<str.length; ++i){
        if(str[i] === "."){
            if(start === -1) start = i;
            else end = i;
        }
        else{
            if(end == -1) {
                start = end = -1;
                continue;
            }
            str = removeAt(str, start, end-1);
            start = end = -1;
        }
    }
    
    if(end != -1){
        str = removeAt(str, start, end-1);
    }
    
    return str;
}

function eraseFirstAndEndDotFromString(str)
{
    // 4. str 처음과 끝에 있는 . 삭제.
    if(str[0] === ".") str = removeAt(str, 0);
    if(str.length === 0) return str;
    if(str[str.length-1]) str = removeAt(str, str.length-1)
    return str;
}

function fillaIntoEmptyString(str)
{
    // 5. str이 비었을 경우 a하나 넣어주기.
    if(str === "") return "a";
    return str;
}

function erase15MoreFromString(str)
{
    // 6. 16자리 이상이면 16자리부터 자르기.
    if(str.length <= 15) return str;
    
}

function addCharFromString(str)
{
    // 7. 2자리 이하면 끝자리 문자를 추가로 넣어 3자리로 만들기.
    if(str.length > 2) return str;
}


function solution(new_id) {

    new_id = toLower(new_id);
    console.log(new_id);
    new_id = eraseCharFromString(new_id);
    console.log(new_id);
    new_id = eraseContinuousDotFromString(new_id);
    console.log(new_id);
    new_id = eraseFirstAndEndDotFromString(new_id);
    console.log(new_id);
    fillaIntoEmptyString(new_id);
    erase15MoreFromString(new_id);
    addCharFromString(new_id);
    
    console.log(new_id);
    
    return new_id;
}