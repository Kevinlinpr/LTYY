#ifndef LTYY_BEAUTICIAN_BEAUTICIAN_H_
#define LTYY_BEAUTICIAN_BEAUTICIAN_H_

#include <string>

#include "person.h"

// ID、姓名、性别、照片、联系方式、员工级别、入职时间、薪资、提成、服务项目总数、服务消费总金额、上次服务时间、信息录入时间、热门项目

namespace beautician {

using person::Id;
using person::Name;
using person::Gender;
using social::PhoneNumber;

using AvatarPath = std::string;

enum class Level {
    NORMAL,
    MANAGER,
    ADMAIN
};

using EntryTime = std::string;
// TODO 提成
using ServiceProjectTotalQuantity = int;
using ServiceTotalConsumption = float;
using LastServiceCustomerTime = std::string;
using InfoRegistryTime = std::string;
// TODO 热门项目

struct Beautician {
    Id id;
    Name name;
    Gender gender;
    AvatarPath avatar_path;
    PhoneNumber phone_number;
    Level level;
    EntryTime entry_time;
    ServiceProjectTotalQuantity service_project_total_quantity;
    ServiceTotalConsumption service_total_consumption;
    LastServiceCustomerTime last_service_customer_time;
    InfoRegistryTime info_registry_time;
};

} // namespace beautician

#endif // LTYY_BEAUTICIAN_BEAUTICIAN_H_