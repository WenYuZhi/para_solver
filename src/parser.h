#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <iostream>

// 命令行参数解析类
struct Parser 
{    
    Parser(int argc, char* argv[]) {
        if (argc < 2) {
            std::cout << "Error: At least one MPS file must be provided." << std::endl;
            exit(0); 
        }
        
    // Extract file paths from command-line
        for (int i = 1; i < argc; ++i) {
            input_path.push_back(std::string(argv[i]));
        }
    }
    std::vector<std::string> input_path; 
};

#endif // PARSER_H
