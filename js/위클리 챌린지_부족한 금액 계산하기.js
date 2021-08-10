// 등차수열의 합
function solution(price, money, count) {
  //var answer = count * ( 2*price + (count-1) * price) * 0.5;
  var answer = count * (price + (price*count)) *0.5;
  answer -= money;
  
  answer = (answer>0) ? answer:0;
  
  return answer;
}
