#include <iostream>
#include <string>
#include <vector>

std::vector<int> split(const std::string& string) {
    std::vector<int> values;
    values.reserve((string.length() + 1) / 2);

    std::string buffer;
    for (int i = 0; i < string.length(); i++) {
        bool inside_number = true;
        if (string[i] == ' ') {
            values.push_back(stoi(buffer));
            buffer.clear();
            inside_number = false;
        }
        else if (inside_number)
            buffer.push_back(string[i]);
    }
    return values;
}

int main() {
    std::string input;
    std::cin >> input;

    std::vector<int> values = split(input);

    for (int i = 1; i < values[0]; i++) {
        std::cout << values[i] << std::endl;
    }

    return 0;
}