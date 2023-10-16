#include <iostream>

using namespace std;

const int SIZE = 8; // 8x8

// BOARDSQR-----------------------
class BoardSqr
{
private:
  /* data */
public:
  BoardSqr(/* args */);
  ~BoardSqr();
};

BoardSqr::BoardSqr(/* args */)
{
}

BoardSqr::~BoardSqr()
{
}
// BOARDSQR-----------------------

// BOARD--------------------------
class Board
{

public:
  Board();
  ~Board();
  void fill();

private:
  BoardSqr **ptr_board;
};

Board::Board()
{
  ptr_board = new BoardSqr *[SIZE];
  for (int i = 0; i < SIZE; i++)
  {
    ptr_board[i] = new BoardSqr[SIZE];
  }
}

Board::~Board()
{
  for (int i = 0; i < SIZE; i++)
  {
    delete[] ptr_board[i];
    ptr_board[i] = nullptr;
  }
  delete[] ptr_board;
}

void Board::fill()
{
  for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            // Check if the sum of row and column indices is even (0-based)
            if ((row + col) % 2 == 0) {
                ptr_board[row][col] = 0;  // White square
            } else {
                ptr_board[row][col] = 1;  // Black square
            }
        }
    }
}
// BOARD--------------------------

int main()
{
  Board chessBoard;
  chessBoard.fill();
  return 0;
} // main