//works by push opening brackets on the stack. 
//When you see a closing bracket, you check if it 
//matches the top of the stack. If not, return false.
bool isValid(string s) {
    stack<char> Stack;

    for(int i = 0; i < s.length(); i++) {
        //adds open parentheses to the stack
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') Stack.push(s[i]);

        //if its a closed parentheses
        //check if each the top of the stack matches each respective
        // closing parentheses
        else {
            if (Stack.empty()) return false;
            if(s[i] == ')' && Stack.top() != '(') return false;
            else if(s[i] == ']' && Stack.top() != '[') return false;
            else if(s[i] == '}' && Stack.top() != '{') return false;

            //if the closing matches the opening, pop because we know its a valid pair
            else Stack.pop();
        }
    }
    //if the stack still has elements then we know that there are more
    //openings than closings and its not valid
    return Stack.empty();
}