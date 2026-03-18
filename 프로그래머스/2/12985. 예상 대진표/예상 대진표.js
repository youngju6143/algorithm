function solution(n, a, b) {
  var answer = 0;

  while (1) {
    answer++;
    let first = a % 2 == 0 ? parseInt(a / 2) : parseInt(a / 2) + 1;
    let second = b % 2 == 0 ? parseInt(b / 2) : parseInt(b / 2) + 1;

    if (first === second) return answer;
    a = a % 2 == 0 ? parseInt(a / 2) : parseInt(a / 2) + 1;
    b = b % 2 == 0 ? parseInt(b / 2) : parseInt(b / 2) + 1;
  }

  return answer;
}

console.log(solution(8, 4, 7));
console.log(solution(16, 7, 10));
