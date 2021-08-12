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

    // 배열 최대, 최소 인덱스가 본인이면 0으로 변경
    // 세로로 점수 더해주고 평균값.
    
    
    // 잘못이해한 코드 ㅎㅎ;
    /*
        let scoreSum = scores[i].reduce((sum, value) => {
            return sum + value; 
        });

        let myScore = scores[i][i];
        scores[i].sort(function(a, b){
            return a - b;
        });
    
        if(scores[0] == myScore || scores[numOfStudent-1] == myScore) 
            scoreSum -= myScore;
        
        console.log(scoreSum + " " + scoreSum/numOfStudent);
    
        answer += getGrade(scoreSum / numOfStudent);
    */
    
    return answer;
}