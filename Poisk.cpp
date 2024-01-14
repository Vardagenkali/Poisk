#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string occ(const string& input, const string& pattern) {
    string result;
    size_t pos = input.find(pattern);
    size_t lastPos = 0;

    while (pos != string::npos) {
        result += input.substr(lastPos, pos - lastPos) + "(" + pattern + ")";
        lastPos = pos + pattern.length();
        pos = input.find(pattern, lastPos);
    }

    result += input.substr(lastPos);
    
    return result;
}

string eval(const string& input) {
    string result;
    istringstream iss(input);

    while (!iss.eof()) {
        string token;
        iss >> token;

        if (token.find_first_of("+-") != string::npos) {
            size_t pos = token.find_first_of("+-");
            int num1 = stoi(token.substr(0, pos));
            int num2 = stoi(token.substr(pos + 1));

            result += to_string((token[pos] == '+') ? num1 + num2 : num1 - num2) + " ";
        }
        else {
            result += token + " ";
        }
    }

    return result;
}

int main() {
    string input1 = "abracadabra";
    string pattern1 = "ab";
    string result1 = occ(input1, pattern1);
    cout << result1 << endl;

    string input2 = "alpha 5+26 beta 72-35 gamma 32+45 etc";
    string result2 = eval(input2);
    cout << result2 << endl;

    return 0;
}
