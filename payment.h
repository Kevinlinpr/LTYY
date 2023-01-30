#ifndef LTYY_PAYMENT_H_
#define LTYY_PAYMENT_H_

namespace payment {

enum class Payment {
    WECHAT,
    ALIPAY,
    BANKCARD,
    OVERDRAFT,
    VIPCARD,
    CASH
};

} // namespace payment

#endif // LTYY_PAYMENT_H_