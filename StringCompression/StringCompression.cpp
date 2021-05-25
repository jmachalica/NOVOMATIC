#include "StringCompression.h"

std::string compress(std::string to_compress) {

    size_t length = to_compress.length();
    std::string output;

    //if (!length)return output;

    // compressing empty string -> empty string
    for (int i = 0; i < length; i++) {

        unsigned int count = 1;
        char current = to_compress[i];

        while (i < length - 1 && current == to_compress[i + 1]) {
            count++;
            i++;
        }

        output.push_back(current);
        output.push_back(count + '0');

    }

    return output; // returns empty string if input string == empty
}


std::string decompress(std::string to_decompress) {

    size_t length = to_decompress.length();
    std::string output{};

    // decompressing empty string -> empty string
    for (int i = 0; i < length; i++) {

        char character = to_decompress[i];
        std::string count;
        while (i < length - 1 && isdigit(to_decompress[i + 1])) {
            count.push_back(to_decompress[i++ + 1]);
        }


        output.append(std::stoi(count), character);  //appends count of characters to output

    }

    return output;

}