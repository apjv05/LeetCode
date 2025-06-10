int calPoints(vector<string>& operations) {
    vector<int> Stack;

    for(int i = 0; i < operations.size(); i++) {
        if(operations[i] == "+") {
            int Top = Stack.back();
            Stack.pop_back();
            int NewTop = Stack.back() + Top;
            Stack.push_back(Top);
            Stack.push_back(NewTop);
        }
        else if(operations[i] == "D") Stack.push_back(Stack.back() * 2);
        else if(operations[i] == "C") Stack.pop_back();
        else {
            int StrNum = stoi(operations[i]);
            Stack.push_back(StrNum);
        }
    }

    int Sum = 0;
    for(int i = 0; i < Stack.size(); i++) {
        Sum += Stack[i];
    }
    return Sum;
}