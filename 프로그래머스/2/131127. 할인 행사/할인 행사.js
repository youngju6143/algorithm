function solution(want, number, discount) {
  var table = {};
  var answer = 0;

  for (let i = 0; i < want.length; i++) table[want[i]] = number[i];

  var day = 0;
  for (let i = 0; i < discount.length; i++) {
    if (discount.length - i < 10) continue;
    for (let j = 0; j < want.length; j++) table[want[j]] = number[j];

    for (let j = i; j <= i + 9; j++) {
      if (table[discount[j]] == undefined || table[discount[j]] <= 0) {
        day = 0;
        continue;
      } else {
        table[discount[j]]--;
        day++;
      }
    }

    if (day == 10) answer++;

    day = 0;
  }
  return answer;
}