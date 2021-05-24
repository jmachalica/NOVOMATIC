#include <iostream>
#include "StringCompression.h"

int main() {


    std::string input("gggghhhhhhzzz");
    std::cout << "String Compression" << std::endl<<std::endl;

    std::cout << "Before compression: "<<input << std::endl;
    std::cout <<  "After compression: "<<compress(input) << std::endl;
    std::cout << "After decompression: "<<decompress(compress(input)) << std::endl<< std::endl;

    input="a10b20c1";
    std::cout << "Before decompression: "<<input << std::endl;
    std::cout << "After decompression: "<<decompress(input) << std::endl<< std::endl;

    input="c";

    std::cout << "Before compression: "<<input << std::endl;
    std::cout <<  "After compression: "<<compress(input) << std::endl;
    std::cout << "After decompression: "<<decompress(compress(input)) << std::endl<< std::endl;

    input="";
    std::cout << "Before compression: "<<input << std::endl;
    std::cout <<  "After compression: "<<compress(input) << std::endl;
    std::cout << "After decompression: "<<decompress(compress(input)) << std::endl<< std::endl;

    return 0;
}
