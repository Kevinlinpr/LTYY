#include "preference.h"
#include <iostream>
#include <string>

Preference& Preference::Get(){
    static Preference preference;
    return preference;
}

Preference::Preference() {
    std::filebuf fbuf;
    if(fbuf.open("/Users/kevinlinpr/LTYY/Preference",std::ios::in) == nullptr){
        std::cout<< "[❌❌❌ LTTY ERROR ❌❌❌]Preference::Preference - ERROR OPEN FILE"<<std::endl;
        fbuf.close();
    }
    std::istream is(&fbuf);
    ReadFromDB(is);
    fbuf.close();
}

Preference::~Preference() {}


void Preference::ReadFromDB(std::istream& is){
    std::string flag{};
    int default_size_width {800};
    int default_size_height {600};
    is >> flag;
    if(flag == DEFAULT_SIZE_WIDTH) {
        std::string value{};
        is >> value;
        default_size_width = std::atoi(value.c_str());
    }
    is >> flag;
    if(flag == DEFAULT_SIZE_HEIGHT) {
        std::string value{};
        is >> value;
        default_size_height = std::atoi(value.c_str());
    }
    DefaultSize size;
    size.width = default_size_width;
    size.height = default_size_height;
    size_ = size;
}

DefaultSize Preference::GetSize(){
    return size_;
}
