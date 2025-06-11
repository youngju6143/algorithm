function solution(answers) {
  const patterns = [
    [1, 2, 3, 4, 5],
    [2, 1, 2, 3, 2, 4, 2, 5],
    [3, 3, 1, 1, 2, 2, 4, 4, 5, 5],
  ];

  const scores = patterns.map((pattern) =>
    answers.reduce(
      (score, answer, idx) =>
        score + (pattern[idx % pattern.length] === answer ? 1 : 0),
      0
    )
  );

  const maxScore = Math.max(...scores);
  const result = [];
  for (let i = 0; i < scores.length; i++) {
    if (scores[i] === maxScore) result.push(i + 1);
  }
  return result;
}
