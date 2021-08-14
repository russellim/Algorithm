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
    
    let myScore = [];
    
    for(let j=0; j<numOfStudent; ++j){
        let tempScore = [];
        for(let i=0; i<numOfStudent; ++i){
            tempScore.push(scores[i][j]);
        }
        myScore.push(tempScore);
    }
    
    for(let i=0; i<numOfStudent; ++i){
        let maxScore = Math.max(...myScore[i]);
        let minScore = Math.min(...myScore[i]);
        
        if(myScore[i][i] == maxScore
          && myScore[i].reduce((cnt, value) => cnt + (maxScore == value), 0) == 1) {
            myScore[i][i] = 0;
        }
        else if(myScore[i][i] == minScore &&
          myScore[i].reduce((cnt, value) => cnt + (minScore == value), 0) == 1) {
             myScore[i][i] = 0;
        }
    }
    
    answer += getGrade(myScore[i].reduce((sum, value) => cnt + value) / numOfStudent);
        
    return answer;
}
