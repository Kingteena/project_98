#ifndef SUPERANNUATION_H
#define SUPERANNUATION_H

#include "Adjustment.h"
#include <string>

class SuperAnnuation : public Adjustment {
private:
    std::string provider;  // Super provider name

public:
    SuperAnnuation(float rate, const std::string &provider);

    virtual float calculateAdjustement(float income) override;   // Calculate superannuation adjustment
    float calculateCompanyContribution(float income);  // Company’s contribution based on income
    std::string getProvider() const;
};

#endif
