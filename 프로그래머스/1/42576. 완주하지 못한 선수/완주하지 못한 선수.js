function solution(participant, completion) {
  var table = {};
  var answer = "";
  for (let i = 0; i < participant.length; i++) table[participant[i]] = 0;
  for (let i = 0; i < participant.length; i++) table[participant[i]]++;
  for (let i = 0; i < completion.length; i++) table[completion[i]]--;

  for (let i = 0; i < participant.length; i++)
    if (table[participant[i]] != 0) return participant[i];
}