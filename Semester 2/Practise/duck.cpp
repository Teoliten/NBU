#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printMaze(const int maze[], int size, int pos, int M)
{
    cout << endl
         << "Maze: " << endl;

    for (int i = 0; i < size; i++)
    {
        cout << maze[i] << " ";
        if ((i + 1) % M == 0) // make a line break at end of every row
        {
            cout << endl;
        }
    }
    cout << endl;
}

int main()
{
    cout << "Rows: (2-10)"
         << "\n>";
    int N;
    cin >> N;

    cout << "Columns: (2-10)"
         << "\n>";
    int M;
    cin >> M;

    int num = N * M; // size of maze
    int maze[num];   // maze
    int input = 0;   // reading input
    int pos = 0;     // position in maze
    int coins = 0;   // coins picked up

    for (int i = 0; i < num; i++)
    {
        cin >> input;//
        maze[i] = input;
        if (input == 0)
        {
            pos = i; // set position to where the 0 is given
        }
    }

    int moves = 0;
    int left = 0, right = 0, up = 0, down = 0;
    do
    {
        printMaze(maze, num, pos, M);
        cout << "POS: " << pos << endl;
        left = 0, right = 0, up = 0, down = 0, moves = 0;

        // find values of all possible moves
        if (!(pos % M == 0))
        {
            left = maze[pos - 1];
            moves++;
        }

        if (!(pos % M == M - 1))
        {
            right = maze[pos + 1];
            moves++;
        }

        if (!(pos < M))
        {
            up = maze[pos - M];
            moves++;
        }

        if (!(pos >= (num - M)))
        {
            down = maze[pos + M];
            moves++;
        }

        cout << "left: " << left << ". right: " << right << ". up: " << up << ". down: " << down << endl;

        // decrease pos value
        if (maze[pos] != 0)
        {
            maze[pos] = (maze[pos] - 1);
        }

        // moves == 1 / 4
        // find biggest number
        int largest = max({left, right, up, down}, [](int x, int y) { return x < y; });
        cout << "LARGEST: " << largest << endl;
        if(largest == 0)
        {
            cout << "END" << endl;
            break;
        }
        // if multiple biggest, rule: left, right, up, down
        // move to next number
        if(left == largest)
        {
            pos--;
            cout << "LEFT" << endl;
        }
        else if(right == largest)
        {
            pos++;
            cout << "RIGHT" << endl;
        }
        else if(up == largest)
        {
            pos -= M;
            cout << "UP" << endl;
        }
        else if(down == largest)
        {
            pos += M;
            cout << "DOWN" << endl;
        }
        coins++;
        cout << "POS: " << pos << endl;
            
        // int break = 0;
        // cin >> break;

    } while (true);
    cout << "COINS: " << coins << endl;

    printMaze(maze, num, 0, M);

    return 0;
} // main