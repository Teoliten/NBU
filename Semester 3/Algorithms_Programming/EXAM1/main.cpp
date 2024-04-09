#include <iostream>
#include <vector>

using namespace std;

void AMCAP(vector<vector<int>> &exams, int H) // as much credits as possible (list of exams, hours before session)
{
    int n = exams.size();
    vector<vector<int>> result(n + 1, vector<int>(H + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= H; ++j)
        {
            if (exams[i - 1][1] <= j) // we have time to study exam nr i - 1
            {
                result[i][j] = max(result[i - 1][j], result[i - 1][j - exams[i - 1][1]] + exams[i - 1][0]);
            }
            else // we dont have time for current exam
            {
                result[i][j] = result[i - 1][j];
            }
        }
    }

    int Hleft = H;  // study hours left
    int totalC = 0; // total credit earned

    cout << '\n'
         << "Exams to study:" << endl;
    for (int i = n; i > 0 && Hleft > 0; --i)
    {
        if (result[i][Hleft] != result[i - 1][Hleft])
        {
            cout << "Exam " << i << ": Credits = " << exams[i - 1][0] << ", Hours = " << exams[i - 1][1] << endl;

            totalC += exams[i - 1][0];
            Hleft -= exams[i - 1][1];
        }
    }

    cout << '\n'
         << "Resulting in " << totalC << " total credits." << endl;
    cout << "For " << H - Hleft << " hours worth of studying." << '\n'
         << endl;
} // as much credits as possible (AMCAP)

int main()
{
    cout << "Number of exams: ";
    int n; // EXAMS
    cin >> n;

    cout << "Hours before exam session: ";
    int H; // HOURS BEFORE EXAM SESSION
    cin >> H;

    vector<vector<int>> exams(n, vector<int>(2));
    cout << "Credit / Hours to study for each exam." << endl;
    for (int i = 0; i < n; i++)
    {
        cout << '\n'
             << "Exam #" << i + 1 << endl
             << "Credits: ";
        cin >> exams[i][0];
        cout << "Hours to study: ";
        cin >> exams[i][1];
    }

    AMCAP(exams, H);

    return 0;
} // main