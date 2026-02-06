#include <iostream>
#include <fstream>

void printHex(const char* str) {
    if (!str) return;

    int i = 0;
    // Loop until we find the null terminator
    // The loop body runs one extra time for the null terminator itself
    while (true) {
        unsigned char c = static_cast<unsigned char>(str[i]);

        // std::hex says cout hey it is hex values.
        // setw makes width 2 for every variable after that.
        // setfill makes it so it puts 0 before paddings. so with that 4 becomes 04
        // putting space for readabilty for every hex value.
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)c << " ";

        // Break after printing the null terminator (00)
        if (str[i] == '\0') {
            break;
        }
        i++;
    }
    std::cout << std::dec << std::endl; // Reset to decimal for future prints
}

std::string readFile(std::string filePath)
{
    std::ifstream is(filePath);     // open file
    char c;
    std::string test;
    while (is.get(c))          // loop getting single characters
    {
        // std::cout << c;      // for debugging
        test.push_back(c);
    }
    // printHex(test.c_str()); // for debugging
    return test;
}