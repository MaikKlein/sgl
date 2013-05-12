#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <fstream>
class FileReader {
        std::string input;
        std::ifstream file;
    public:
        FileReader(std::string path);
        ~FileReader() {
            file.close();
        }
        std::string get();
};

#endif // FILEREADER_H
