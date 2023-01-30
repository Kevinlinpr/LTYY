#ifndef LTYY_ORDER_H_
#define LTYY_ORDER_H_

#include <vector>

#include "project.h"
#include "product.h"
#include "beautician.h"
#include "payment.h"

namespace order {
// ID、创建时间、订单状态、项目、产品、美容师、顾客、支付方式、原价、优惠券减免、实际付款

using Id = std::string;
using CreateTime = std::string;

// 等待顾客到店、顾客已经到店、开始服务，暂停服务、完成服务、取消服务
enum class OrderStatus {
    WIATE_FOR_CUSTOMER_ARRIVE,
    CUSTOMER_ARRIVED,
    START_SERVICE,
    PAUSE_SERVICE,
    FINISHED_SERVICE,
    CANCEL_SERVICE
};

using project::Project;
using Projects = std::vector<Project>;
using product::Product;
using Products = std::vector<Product>;
using beautician::Beautician;
using payment::Payment;
using TotalPrice = float;
using Reduction = float;
using FinalPrice = float;


} // namespace order

#endif // LTYY_ORDER_H_