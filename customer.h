#ifndef LTYY_CUSTOMER_CUSTOMER_H_
#define LTYY_CUSTOMER_CUSTOMER_H_

#include <string>

#include "person.h"
#include "social.h"

namespace customer {

// ID、姓名 、性别、生日、联系电话、顾客级别、项目总数、消费总金额、上次到店时间、信息录入时间
using person::Id;
using person::Name;
using person::Birthday;
using person::Gender;
using social::PhoneNumber;

using LastTimeBeServed = std::string;
using InfoRegistryTime = std::string;

using ProjectTotalQuantity = int;
using TotalConsumption = float;

enum class Level {
    NEW,
    OG
};

struct Customer {
    Id id;
    Name name;
    Gender gender;
    Birthday birthday;
    PhoneNumber phone_number;
    Level level;
    ProjectTotalQuantity project_total_quantity;
    TotalConsumption total_consumption;
    LastTimeBeServed last_time_be_served;
    InfoRegistryTime info_registry_time;
};

} // namespace customer

#endif // LTYY_CUSTOMER_CUSTOMER_H_