function solution(id_list, report, k) {
  var table = {};
  var report_table = {};

  id_list.map((id) => {
    table[id] = [];
    report_table[id] = 0;
  });

  for (let i = 0; i < report.length; i++) {
    let ids = report[i].split(" ");

    table[ids[0]].push(ids[1]);
  }

  id_list.map((id) => {
    table[id] = [...new Set(table[id])];
  });

  id_list.map((id) => {
    for (let i = 0; i < table[id].length; i++) report_table[table[id][i]]++;
  });

  var answer = [];

  id_list.map((id) => {
    let count = 0;
    for (let i = 0; i < table[id].length; i++) {
      if (report_table[table[id][i]] >= k) {
        count++;
      }
    }
    answer.push(count);
  });

  return answer;
}