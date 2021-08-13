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
    
    for(let i=0; i<numOfStudent; ++i){
        
        let maxIndex = scores[i].indexOf(Math.max(...scores[i]));
        let minIndex = scores[i].indexOf(Math.min(...scores[i]));
        
        if(maxIndex == i || minIndex == i) scores[i][i] = 0;
    }
    
    for(let j=0; j<numOfStudent; ++j){
        let sum = 0;
        let num = numOfStudent;
        for(let i=0; i<numOfStudent; ++i){
            sum += scores[i][j];
            if(scores[i][j] == 0) num--;
        }
        answer += getGrade(sum / num);
    }
        
    return answer;
}