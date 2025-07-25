function solution(progresses, speeds) {
  const MAX_INT = 100;
  var answer = [];

  var count = 0;

  while (1) {
    if (progresses.length == 0) break;

    for (let i = 0; i < speeds.length; i++) {
      if (progresses[i] < MAX_INT) progresses[i] += speeds[i];
    }
    while (1) {
      if (progresses[0] < MAX_INT || progresses.length === 0) {
        if (count !== 0) answer.push(count);
        count = 0;
        break;
      }

      progresses.shift();
      speeds.shift();
      count++;
    }
  }
  return answer;
}
