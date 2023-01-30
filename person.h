#ifndef LTYY_PERSON_H_
#define LTYY_PERSON_H_

namespace person {

using Id = std::string;
using Name = std::string;
using Birthday = std::string;

enum class Gender {
    MALE,
    FEMALE
};

} // namespace person

#endif // LTYY_PERSON_H_