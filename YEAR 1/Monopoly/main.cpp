#include <iostream>
#include <cassert>

using namespace std;

void printBoard()
{
    
}//printBoard


void Game()
{

}//Game

int main()
{
    int players;
    cout << "Players (2-6):" << endl << "> ";
    cin >> players;
    assert(players >= 2 && players <=6);

    return 0;
}//main