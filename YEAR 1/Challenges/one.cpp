


#include <iostream>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int len;
    cin >> len;
    int arr[len];
    string inp;
    cin.ignore();
    getline(cin, inp);
    //cout << inp;
    int j = 0;
    for(int i = 0; i < len; i++)
    {
        //cout << "arr: " << i << endl;
        //cout << "inp: " << inp[j] << endl;
        arr[i] = inp[j];
        j = j + 2;
    }
    
    for(int i = len - 1; i >= 0; i--)
    {
        cout << arr[i] - 48 << " ";
    }
    //cout << endl;y
    

    return 0;
}
