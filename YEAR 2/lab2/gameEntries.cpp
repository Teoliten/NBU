#include <iostream>

using namespace std;

//---------------------
class GameEntry
{
public:                                                  // no default constructor "GameEntry();""
  GameEntry(string name = "Player Name", int score = 0); // default parameters name ad score.
  string getName() const;
  int getScore() const;

private:
  string name;
  int score;
};

GameEntry::GameEntry(string name, int score)
{
  this->name = name;
  this->score = score;
} // GameEntry

string GameEntry::getName() const
{
  return name;
} // getName

int GameEntry::getScore() const
{
  return score;
} // getScore
//---------------------

//---------------------
class Scores
{
public:
  Scores(int max_entries);
  ~Scores();

  void add(const GameEntry &ent);
  void print() const;

private:
  static const int DEFAULT;

  int max_entries;
  int num_entries;
  GameEntry *ptr_arr;
};

const int Scores::DEFAULT = 10;
// default number of maximum entries

Scores::Scores(int max_entries = DEFAULT)
{
  this->max_entries = max_entries;
  num_entries = 0;
  ptr_arr = nullptr;
  ptr_arr = new GameEntry[this->max_entries];
} // constructor with parameters

Scores::~Scores()
{
  if (ptr_arr)
  {
    delete[] ptr_arr;
    ptr_arr = nullptr;
  }
} // destructor

void Scores::add(const GameEntry &ent)
{
  if (num_entries == max_entries)
  {
    if (ent.getScore() <= ptr_arr[max_entries - 1].getScore())
    {
      return; // ignore
    }
  }
  else
  {
    num_entries++;
  }
  int i = num_entries - 2;
  while (i >= 0 && ent.getScore() > ptr_arr[i].getScore())
  {
    ptr_arr[i + 1] = ptr_arr[i];
    i--;
  }
  ptr_arr[i + 1] = ent;

} // add a new entry in the array of scores

void Scores::print() const
{
  for (int i = 0; i < num_entries; i++)
  {
    cout << ptr_arr[i].getName() << ": " << ptr_arr[i].getScore() << endl;
  }
} // print array of scores
//---------------------

int main()
{
  /*
  GameEntry ge1("Rick", 1024);
  cout << ge1.getName() << ": " << ge1.getScore() << endl;
  */

  Scores sc;
  GameEntry ge1("Rick", 1024);
  sc.add(ge1);

  GameEntry ge2("Morty", 32);
  sc.add(ge2);

  GameEntry ge3("Summer", 64);
  sc.add(ge3);

  sc.print();
  return 0;
} // main