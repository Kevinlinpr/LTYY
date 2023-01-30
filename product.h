#ifndef LTYY_PRODUCT_H_
#define LTYY_PRODUCT_H_

#include <string>
#include <vector>

namespace product {

// ID、品牌名称、产品名称、产品型号、有效期、产品图片、产品类别、单价、消费总金额、上次成功卖出时间、总进货数、当前库存、信息录入时间

using Id = std::string;
using BrandName = std::string;
using Name = std::string;
using Model = std::string;
using ExpiredTime = std::string;

using ImagePath = std::string;
using Images = std::vector<ImagePath>;
using Category = std::string;

using Price = float;
using TotalConsumption = float;
using LastSuccessSellTime = std::string;
using TotalPurchaseQuantity = int; // TODO 是否存在小数
using CurrentInStockQuantity = float;
using InfoRegistryTime = std::string;

struct Product {
    Id id;
    BrandName brand_name;
    Name name;
    Model model;
    ExpiredTime expired_time;
    Images images;
    Category category;
    Price price;
    TotalConsumption total_consumption;
    LastSuccessSellTime last_success_sell_time;
    TotalPurchaseQuantity total_purchase_quantity;
    CurrentInStockQuantity current_in_stock_quantity;
    InfoRegistryTime info_registry_time;
};

} // namespace product


#endif // LTYY_PRODUCT_H_