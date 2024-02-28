#include <iostream>

using namespace std;

class test
{
public:
    test();
    test(int);

    void setInput(const int input);
    int getInput();

    void read();
    void write() const;
private:
    int input;
};


test::test()
{
    input = 0;
}

test::test(int input)
{
    this->input = input;
}

void test::setInput(const int input)
{
    this->input = input;
}

int test::getInput()
{
    return input;
}

void test::read()
{
    cout << "Enter integer: " << endl << "> ";
    cin >> input;
}//read

void test::write() const
{
    cout << "Input: " << input << endl;
}

int main()
{
    test tt;
    tt.read();
    tt.write();
    //tt.setInput(10);
    tt.write();
    return 0;
}//main