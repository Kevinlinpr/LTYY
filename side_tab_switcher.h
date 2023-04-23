#ifndef LTYY_SIDE_TAB_SWITCHER_H_
#define LTYY_SIDE_TAB_SWITCHER_H_


class SideTabSwitcher {
public:
    SideTabSwitcher(const SideTabSwitcher&) = delete;
    SideTabSwitcher& operator=(const SideTabSwitcher&) = delete;

    SideTabSwitcher();
    ~SideTabSwitcher() = default;

    enum class Section {
        CUSTOMER,
        BEAUTICIAN,
        PRODUCT,
        PROJECT,
        ACTIVITY,
        ORDER,
        LOG
    };

    Section GetSection() { return section_; }
    void SetSection(Section section) { section_ = section; } 
    
private:
    Section section_;
};

#endif // LTYY_SIDE_TAB_SWITCHER_H_