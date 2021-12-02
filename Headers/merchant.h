#ifndef _MERCHANT_H_
#define _MERCHANT_H_

#include "character.h"

class Merchant : public Character
{
public:
    Merchant();
    ~Merchant() = default;
    char draw();
private:
    static const int DEFAULT_HP = 30;
    static const int DEFAULT_ATK = 70;
    static const int DEFAULT_DEF = 5;
};

#endif // _MERCHANT_H_
