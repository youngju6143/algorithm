function solution(my_string, overwrite_string, s) {
  const answer = my_string.split("");
  answer.splice(s, overwrite_string.length, overwrite_string);
  return answer.join("");
}

console.log(solution("He11oWor1d", "lloWorl", 2));
console.log(solution("Program29b8UYP", "merS123", 7));
