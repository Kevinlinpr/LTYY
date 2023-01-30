#ifndef LTYY_PROJECT_H_
#define LTYY_PROJECT_H_

#include <string>
#include <utility>
#include <vector>

#include "product.h"

namespace project {

// ID、项目名称、项目类型、项目发布时间、单次产品消耗、消费总次数、上次服务时间、信息录入时间

using Id = std::string;
using Name = std::string;

enum class Category {
    NORMAL,
    SPECIAL
};

using ReleaseTime = std::string;
using ProductName = product::Name;
using ProductUseUpQuantity = float;
using ProductUseUp = std::pair<ProductName,ProductUseUpQuantity>;
using TotalProductUseUpEachTime = std::vector<ProductUseUp>;
using TotalConsumptionQuantity = float;
using LastBeUsedTime = std::string;
using InfoRegistryTime = std::string;

struct Project {
    Id id;
    Name name;
    Category category;
    ReleaseTime release_time;
    TotalProductUseUpEachTime total_product_useup_eachtime;
    TotalConsumptionQuantity total_consumption_quantity;
    LastBeUsedTime last_beused_time;
    InfoRegistryTime info_registry_time;
};

} // namespace project

#endif // LTYY_PROJECT_H_