#ifndef LTYY_ACTIVITY_H_
#define LTYY_ACTIVITY_H_

#include "project.h"
#include <utility>
#include <string>
#include <vector>

namespace activity {
    
enum class LifeCircleType {
    TIME,
    FREQUENCY,
    VOUCHER
};

using product::Product;
using ActivityItemLifeCirleValue = std::string;
using ActivityItemLifeCircle = std::pair<LifeCircleType,ActivityItemLifeCirleValue>;
using ActivityItem = std::pair<ActivityItemLifeCircle,Product>;
using Activity = std::vector<ActivityItem>;

} // namespace activity

#endif // LTYY_ACTIVITY_H_