#include <iostream>
#include <stack> //스택 라이브러리

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int n, x;
    stack<int> s; //스택 s 선언
    string cmd;

    cin >> n;
    while(n--) {
        cin >> cmd;
        if(cmd == "push") {
            cin >> x;
            s.push(x); //스택에 값 push
        }
        else if(cmd == "pop") {
            if(s.empty()) { //스택이 비어 있을 시 1 리턴
                cout << -1 << '\n';
            }
            else {
                cout << s.top() << '\n'; // 스택 top 값 삭제 없이 리턴
                s.pop(); // 스택 top 값 삭제(리턴값 없음)
            }
        }
        else if(cmd == "size") {
            cout << s.size() << '\n'; //스택 크기 리턴
        }
        else if(cmd == "empty") {
            cout << s.empty() << '\n';
        }
        else if(cmd == "top") {
            if(s.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << s.top() << '\n';
            }
        }
    }
    return 0;
}
