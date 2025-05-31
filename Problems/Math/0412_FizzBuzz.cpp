vector<string> fizzBuzz(int n) {
    vector<string> Array;
    for(int i = 1; i <= n; i++) {
        if(i % 3 == 0 && i % 5 == 0) Array.push_back("FizzBuzz");
        else if(i % 3 == 0) Array.push_back("Fizz");
        else if(i % 5 == 0) Array.push_back("Buzz");
        else {
            string int_str = to_string(i);
            Array.push_back(int_str);
        }
    }
    return Array;
}