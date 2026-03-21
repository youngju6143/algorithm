function solution(n, words) {
  var answer = [];
  var [number, turn] = [0, 0];
  const map = {};

  var last = words[0][words[0].length - 1];
  map[words[0]] = 1;
  for (let i = 0; i < words.length; i++) {
    let word = words[i];
    number = (i + 1) % n == 0 ? n : (i + 1) % n;
    turn = (i + 1) % n == 0 ? parseInt((i + 1) / n) : parseInt((i + 1) / n) + 1;
    let first = word[0];
    if (i == 0) continue;
    if (map[word] !== undefined || first !== last) {
      answer = [number, turn];
      return answer;
    }
    map[word] = 1;
    last = word[word.length - 1];
  }
  answer = [0, 0];
  return answer;
}
