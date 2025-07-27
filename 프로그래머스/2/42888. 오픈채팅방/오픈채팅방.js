function solution(record) {
  var nameTable = {};
  var orderTable = {
    Enter: "님이 들어왔습니다.",
    Leave: "님이 나갔습니다.",
  };

  var temp = [];

  for (let i = 0; i < record.length; i++) {
    var array = record[i].split(" ");
    if (array[0] == "Enter") {
      nameTable[array[1]] = array[2];
      temp.push({ id: array[1], order: orderTable["Enter"] });
    } else if (array[0] == "Leave")
      temp.push({ id: array[1], order: orderTable["Leave"] });
    else nameTable[array[1]] = array[2];
  }

  var answer = [];
  for (let i = 0; i < temp.length; i++)
    answer.push(`${nameTable[temp[i].id]}${temp[i].order}`);

  return answer;
}