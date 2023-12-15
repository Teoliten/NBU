#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    for(int i = 0; i < argc; i++)
    {
        cout << argv[i] << endl;
    }
    //g++ -o arg arg.cpp && ./arg I am orange apple pear
    return 0;
}//main