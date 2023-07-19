#include <iostream>

using namespace std;

int cars(int &wheel, int &carb, int &fig)
{
    bool possible = true;
    int result = 0;
    while(possible)
    {

        if(wheel >= 4 && carb >= 1 && fig >= 2)
        {
            wheel = wheel - 4;
            carb--;
            fig--;
            fig--;
            result++;
        }
        else
        {
            possible = false;
        }
        
    }

    return result;
}//cars

int main()
{
    cout << "Enter:" << endl << "Wheels: ";
    int wheel;
    cin >> wheel;
    cout  << "Car bodies: ";
    int carb;
    cin >> carb;
    cout << "Figures: ";
    int fig;
    cin >> fig;

    cout << "Parts: " << wheel << " " << carb << " " << fig << endl;

    int nr = cars(wheel, carb, fig);
    cout << "Cars made: " << nr << endl;

    cout << "Parts left: " << wheel << " " << carb << " " << fig << endl;
    return 0;
}//main
