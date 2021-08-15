// 점수 -> 학점.
function getGrade(score)
{
    if(score >= 90) return 'A';
    else if(score >=80) return 'B';
    else if(score >= 70) return 'C';
    else if(score >= 50) return 'D';
    return 'F';
}

function solution(scores) {
    var answer = '';
    let numOfStudent = scores.length;
    
    // 배열 행, 열 반대로 새 배열에 넣기.
    let myScore = [];
    
    for(let j=0; j<numOfStudent; ++j){
        let tempScore = [];
        for(let i=0; i<numOfStudent; ++i){
            tempScore.push(scores[i][j]);
        }
        myScore.push(tempScore);
    }
    
    // 최고점, 최저점 찾기.
    for(let i=0; i<numOfStudent; ++i){
        let maxScore = Math.max(...myScore[i]);
        let minScore = Math.min(...myScore[i]);
        let exceptMe = 0; // 내가 최고점 or 최저점일때 제외됨.
        
        // 내가 유일한 최고점 or 최저점인지 확인.
        if(myScore[i][i] == maxScore
          && myScore[i].reduce((cnt, value) => cnt + (maxScore == value), 0) == 1) {
            myScore[i][i] = 0;
            exceptMe++;
        }
        else if(myScore[i][i] == minScore &&
          myScore[i].reduce((cnt, value) => cnt + (minScore == value), 0) == 1) {
             myScore[i][i] = 0;
            exceptMe++;
        }
        
        // 평균, 학점 구하기.
        let sum = myScore[i].reduce((sum, value) => sum + value, 0);
        answer += getGrade(sum / (numOfStudent - exceptMe));
    }
        
    return answer;
}
