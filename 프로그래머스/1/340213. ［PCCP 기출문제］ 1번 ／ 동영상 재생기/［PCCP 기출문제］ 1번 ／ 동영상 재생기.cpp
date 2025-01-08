#include <string>
#include <vector>

using namespace std;

// video_len : 동영상 길이
// 기능 수행 전 재생 위치 : pos
// 오프닝 시작 시각 문자열 : op_start
// 사용자의 입력 : 1차원 문자 배열 : commands
// 출력 : mm:ss
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    // 기능 : 10초 전으로 이동, 10초 후로 이동, 오프닝 건너뛰기
    // 10초 전으로 이동 : prev
    // 10초 후로 이동 : next
    // 오프닝 건너뛰기 : 오프닝 구간에 있을 경우, 오프닝이 끝나는 위치로 이동
    
    vector<pair<string, string>> s_vec;
    vector<int> second_times;
    
    pair<string, string> s_pair;
    int minute_to_second;
    
    string time_infos[4] = {video_len, pos, op_start, op_end};
    
    for (int i = 0; i < 4; i++) {
        string minutes = time_infos[i].substr(0, 2);
        string seconds = time_infos[i].substr(3, 2);
        int minute = stoi(minutes);
        int second = stoi(seconds);
        minute_to_second = minute * 60 + second;
        s_vec.push_back(make_pair(minutes, seconds));
        second_times.push_back(minute_to_second);
    }
  
//    for (int i = 0; i < s_vec.size(); i++) {
//        cout << s_vec[i].first << " " << s_vec[i].second << endl;
//        cout << "====================" << endl;
//    }
//    cout << second_times[0] << endl; // video_len
//    cout << second_times[1] << endl; // pos : 현재 위치
//    cout << second_times[2] << endl; // op_Start
//    cout << second_times[3] << endl; // op_end

    int video_len_i = second_times[0];
    int pos_i = second_times[1];
    int op_start_i = second_times[2];
    int op_end_i = second_times[3];
    
    for (int i = 0; i < commands.size(); i++) {
//        cout << "commands[i] : " << commands[i] << endl;
        if (op_start_i <= pos_i && pos_i <= op_end_i)
            pos_i = op_end_i;
        
        if (commands[i] == "prev") {
//            cout << "prev 실행" << endl;
            pos_i -= 10;
            if (pos_i < 0) {
                pos_i = 0;
            }
        } else {
//            cout << "next 실행" << endl;
            pos_i += 10;
            if (pos_i > video_len_i) {
                pos_i = video_len_i;
            }
        }
        if (op_start_i <= pos_i && pos_i <= op_end_i)
            pos_i = op_end_i;
        
        
//        cout << "pos_i : " << pos_i << endl;
//        cout << "------------------" << endl;
    }
    
    int result_minute_i = pos_i / 60;
    int result_second_i = pos_i % 60;
    
    string result_minute, result_second;
    
    if (result_minute_i < 10)
        result_minute = "0" + to_string(result_minute_i);
    else
        result_minute = to_string(result_minute_i);
        
    if (result_second_i < 10)
        result_second = "0" + to_string(result_second_i);
    else
        result_second = to_string(result_second_i);
    
    string answer = result_minute + ":" + result_second;
    return answer;
}