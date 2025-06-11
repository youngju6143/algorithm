const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

rl.on("line", function (line) {
  input = [line];
}).on("close", function () {
  var answer = "";
  for (let s of input[0]) {
    if (s >= "A" && s <= "Z") answer += s.toLowerCase();
    else answer += s.toUpperCase();
  }
  console.log(answer);
});
