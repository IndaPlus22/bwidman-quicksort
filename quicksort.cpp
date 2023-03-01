#include <iostream>
#include <string>
#include <vector>

// Splits string with space seperated numbers
// Doesn't work with multiple spaces in between numbers or space in beginning (i.e. application specific)
std::vector<int> split(const std::string& string) {
    std::vector<int> values;
    values.reserve((string.length() + 1) / 2);

    std::string buffer;
    for (int i = 0; i < string.length(); i++) {
        if (string[i] == ' ' || i == string.length() - 1) {
            if (i == string.length() - 1)
                buffer.push_back(string[i]);
            values.push_back(stoi(buffer));
            buffer.clear();
        }
        else
            buffer.push_back(string[i]);
    }
    return values;
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::vector<int> values = split(input);

    // Sort list of numbers
    

    // Print sorted list
    for (int i = 1; i < values.size(); i++) {
        std::cout << values[i] << std::endl;
    }

    return 0;
}