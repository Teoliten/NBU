#include <iostream>
#include <string>

using namespace std;

//__________________________________PIXEL
class Pixel
{
public:
    Pixel();
    Pixel(int x, int y, bool isOn);
    void print() const;
    
protected:
    int x;//coordinates of pixel
    int y;
    bool isOn;
};//Pixel

Pixel::Pixel()
{
    x = 555;
    y = 1080;
    isOn = 1;
}

Pixel::Pixel(int x, int y, bool isOn)
{
    this->x = x;
    this->y = y;
    this->isOn = isOn;
}

void Pixel::print() const
{
    cout << "x-coodinate: " << x << endl;
    cout << "y-coodinate: " << y << endl;
    cout << "Pixel on: " << isOn << endl;
}
//__________________________________PIXEL

//__________________________________BINARY
class Binary : public Pixel
{
public: 
    Binary();
    Binary(int valueBin);

    virtual void print() const;
private:
    int valueBin;
};//Binary

Binary::Binary()
{
    valueBin = 1001001;
}

void Binary::print() const
{
    cout << "Pixel binary value: " << valueBin << endl;
}
//__________________________________BINARY

//__________________________________HSVColor
class HSVColor : public Pixel
{
public: 
    HSVColor();
    HSVColor(string valueBin);

    virtual void print() const;
private:
    string valueHSV;
};//HSVColor

HSVColor::HSVColor()
{
    valueHSV = "hsv(43, 41%, 90%)";
}

void HSVColor::print() const
{
    cout << "Pixel HSV value: " << valueHSV << endl;
}//HSVColor
//__________________________________HSVColor

//__________________________________RGBColor
class RGBColor : public Pixel
{
public: 
    RGBColor();
    RGBColor(string valueRGB);

    virtual void print() const;
private:
    string valueRGB;
};

RGBColor::RGBColor()
{
    valueRGB = "#A52A2A";
}

void RGBColor::print() const
{
    cout << "Pixel RGB value: " << valueRGB << endl;
}//RGBColor
//__________________________________RGBColor

//__________________________________Grayscale
class Grayscale : public Pixel
{
public: 
    Grayscale();
    Grayscale(int valueGray);

    virtual void print() const;
private:
    int valueGray;
};//Grayscale

Grayscale::Grayscale()
{
    valueGray = 349;
}

void Grayscale::print() const
{
    cout << "Pixel binary value: " << valueGray << endl;
}//Grayscale

//__________________________________Grayscale

int main()
{
    Pixel px;
    px.print();

    Binary bn;
    bn.print();

    HSVColor HSV;
    HSV.print();

    RGBColor RGB;
    RGB.print();

    Grayscale gs;
    gs.print();

    return 0;
}//main

//Base class PIXEL
//inherited classes: Binary, Grayscale, RGBColor, HSVColor.