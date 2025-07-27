function solution(cards1, cards2, goal) {
  var answer = "Yes";

  while (goal.length !== 0) {
    let front1 = cards1[0];
    let front2 = cards2[0];

    if (goal[0] === front1) {
      cards1.shift();
      goal.shift();
    } else if (goal[0] === front2) {
      cards2.shift();
      goal.shift();
    } else {
      answer = "No";
      break;
    }
  }

  return answer;
}