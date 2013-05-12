#include "filereader.h"

FileReader::FileReader(std::string path):file(path, std::ifstream::in){

  std::string content( (std::istreambuf_iterator<char>(file) ),
                       (std::istreambuf_iterator<char>()    ) );

                       input = content;
}
std::string FileReader::get(){
    return input;
}
