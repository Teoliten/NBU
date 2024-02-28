#include <iostream>

using namespace std;

void drawOneTick(int tick_len, int tick_label = -1)
{
  for (int i = 0; i < tick_len; i++)
  {
    cout << '-';
  }
  if (tick_label > -1)
  {
    cout << tick_label;
  }
  cout << endl;
}

void drawTicks(int tick_len)
{
  if (tick_len > 0)
  {
    drawTicks(tick_len - 1);
    drawOneTick(tick_len);
    drawTicks(tick_len - 1);
  }
}

void drawRuler(int numb_inch, int major_len)
{
  drawOneTick(major_len, 0);
  for (int i = 1; i <= numb_inch; i++)
  {
    drawTicks(major_len - 1);
    drawOneTick(major_len, i);
  }
}

int main()
{
  drawRuler(10, 2);
  return 0;
} // main