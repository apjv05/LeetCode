string simplifyPath(string path) {
    vector<string> stack;
    string cur;

    for (char c : path + "/") {
        //we build a path and once we find a
        // '/' we add or remove a path
        if (c == '/') {
            if (cur == "..") {
                if (!stack.empty()) stack.pop_back();
            }
            //we build our path name then push it into the stack
            // and each index seperates the files which we will add
            // later
            else if (!cur.empty() && cur != ".") stack.push_back(cur);
            cur.clear();
        }
        else cur += c;
    }

    string result = "/";
    for (int i = 0; i < stack.size(); i++) {
        if (i > 0) result += "/";
        result += stack[i];
    }
    return result;
}