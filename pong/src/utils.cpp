#include <iostream>
#include <fstream>
#include <filesystem>
#include "utils.h"

#ifdef PONGPONG_EMBED_SHADERS
#include "shaders.h"
#endif

void printHex(const char* str) {
    if (!str) return;

    int i = 0;
    while (true) {
        unsigned char c = static_cast<unsigned char>(str[i]);
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)c << " ";
        if (str[i] == '\0') {
            break;
        }
        i++;
    }
    std::cout << std::dec << std::endl;
}

std::string readFile(std::string filePath)
{
    std::ifstream is(filePath);
    char c;
    std::string test;
    while (is.get(c))
    {
        test.push_back(c);
    }
    is.close();
    return test;
}

std::string getShaderSource(const std::string& shaderName)
{
#ifdef PONGPONG_EMBED_SHADERS
    // Release mode: use embedded shaders
    if (shaderName == "vertex") {
        return std::string(VERT_SHADER);
    } else if (shaderName == "fragment") {
        return std::string(FRAG_SHADER);
    }
    return "";
#else
    // Debug mode: load from files relative to executable location
    // Get the directory where the executable is located
    std::filesystem::path exePath = std::filesystem::current_path();
    
    // Go up two directories: from build/debug/pong to pong/
    std::filesystem::path basePath = exePath.parent_path().parent_path();
    
    std::string fullPath;
    if (shaderName == "vertex") {
        fullPath = (basePath / "src" / "test.vert").string();
    } else if (shaderName == "fragment") {
        fullPath = (basePath / "src" / "test.frag").string();
    }
    
    return readFile(fullPath);
#endif
}
