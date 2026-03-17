function solution(id_list, report, k) {
  var answer = [];
  var userTable = {};
  var reportedTable = {};

  for (let user of id_list) {
    userTable[user] = 0;
    reportedTable[user] = 0;
  }

  var reports = new Set(report);

  for (let r of reports) {
    let user = r.split(" ");
    reportedTable[user[1]]++;
  }

  for (let r of reports) {
    let user = r.split(" ");
    if (reportedTable[user[1]] >= k) userTable[user[0]]++;
  }

  id_list.map((user) => {
    answer.push(userTable[user]);
  });

  return answer;
}