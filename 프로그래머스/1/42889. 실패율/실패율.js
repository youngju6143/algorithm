function solution(N, stages) {
  var stageLength = stages.length;

  var challengeStages = new Array(N).fill(0);
  var notClearStages = new Array(N).fill(0);

  console.log(answer);
  for (let i = 1; i <= N; i++) {
    for (let j = 0; j < stageLength; j++) {
      if (stages[j] >= i) challengeStages[i - 1]++;
      if (stages[j] === i) notClearStages[i - 1]++;
    }
  }

  var failurePercents = [];
  for (let i = 0; i < N; i++) {
    failurePercents.push({
      index: i + 1,
      value: notClearStages[i] / challengeStages[i],
    });
  }

  failurePercents.sort((a, b) => b.value - a.value);
  var answer = new Array(N).fill(0).map((_, i) => failurePercents[i].index);

  return answer;
}

