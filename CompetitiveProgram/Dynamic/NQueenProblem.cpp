#include <iostream>
using namespace std;
// have to be improved and updated!
int N = 4;
int board[4][4] = {0};

bool canBePlaced(int i, int j)
{
    for (int k = 0; k < N; ++k) {
        if(board[i][k] == 1 || board[k][j] == 1)
            return false;
    }
    for (int k = 0; k < N; ++k) {
        for (int l = 0; l < N; ++l) {
            if(k+l == i+j || k - l == i - j )
                if(board[k][l] == 1)
                    return false;
        }
    }
    return true;
}

int PlaceQueen(int c)
{

    if(c == 0)
        return 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(canBePlaced(i,j) && board[i][j] != 1)
            {
                board[i][j] = 1;

                if(PlaceQueen(c-1) == 1)
                    return 1;

                board[i][j] = 0;

            }
        }
    }
    return 0;

}

int main()
{
    PlaceQueen(N);

    for (auto i : board) {
        for (int j = 0; j < 4; ++j) {
            cout << i[j] << " ";
        }
        cout << endl;

    }



}