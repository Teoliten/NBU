#include <iostream>

using namespace std;

class Pumpkin
{
public:
    Pumpkin();
    Pumpkin(int);

    void setP(int);
    void getP() const;

    void print() const;
private:
    int peach;
};//Pumpkin

Pumpkin::Pumpkin()
{
    peach = 0;
}//Pumpkin

Pumpkin::Pumpkin(int one)
{
    this->peach = peach;
}

Pumpkin::setP(const int one);
{
    this->peach = peach;
}

Pumpkin::getP() const;
{
    return peach;
}

int main()
{
    Pumpkin pk;

    return 0;
}//main