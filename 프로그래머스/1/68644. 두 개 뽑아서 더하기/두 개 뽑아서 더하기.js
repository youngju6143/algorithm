function solution(numbers) {
  var newArr = [];
  for (let i = 0; i < numbers.length; i++) {
    for (let j = i + 1; j < numbers.length; j++) {
      i != j && newArr.push(numbers[i] + numbers[j]);
    }
  }
  var answer = [...new Set(newArr)];
  answer.sort((a, b) => a - b);

  return answer;
}