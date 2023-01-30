#ifndef LTYY_PREFERENCE_H_
#define LTYY_PREFERENCE_H_

#include <fstream>
#include <string>

const std::string DEFAULT_SIZE_WIDTH = "DEFAULT_SIZE_WIDTH";
const std::string DEFAULT_SIZE_HEIGHT = "DEFAULT_SIZE_HEIGHT";

struct DefaultSize {
    int width;
    int height;
};

class Preference {
public:
    Preference(const Preference&) = delete;
    Preference& operator=(const Preference&) = delete;
    
    static Preference& Get();

    ~Preference();

    DefaultSize GetSize();

private:
    Preference();
    void ReadFromDB(std::istream& is);

    DefaultSize size_;
};

#endif // LTYY_PREFERENCE_H_