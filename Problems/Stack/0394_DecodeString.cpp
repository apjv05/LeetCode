string decodeString(string s) {
    stack<string> stringst;
    stack<int> countst;
    string Cur = "", CurNum;

    for(char c : s) {
        if(isdigit(c)) {
            CurNum.push_back(c);
        }
        else if(c == '[') {
            stringst.push(Cur);
            int num = stoi(CurNum);
            countst.push(num);
            Cur = "";
            CurNum = "";
        }
        else if(c == ']') {
            string temp = Cur;
            Cur = stringst.top();
            stringst.pop();
            int count = countst.top();
            countst.pop();
            for(int i = 0; i < count; i++) Cur += temp;
        }
        else Cur += c;
    }
    return Cur;
}