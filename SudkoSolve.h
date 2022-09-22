class SudokuSolve {
public:
    void solveSudoku(vector<vector<char>>&);

private:
    typedef vector<vector<bool>> vec2D;
    vector<pair<int, int>> empt;

    bool Backtrack(vector<vector<char>>&, vec2D&, vec2D&, vec2D&, int);
};


void SudokuSolve::solveSudoku(vector<vector<char>>& board) {
    empt.clear();

    vec2D row(9, vector<bool>(9, false));
    vec2D col(9, vector<bool>(9, false));
    vec2D subbox(9, vector<bool>(9, false));
    short dig;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (isdigit(board[i][j]))
            {
                dig = board[i][j] - '0';
                row[i][dig - 1] = true;
                col[j][dig - 1] = true;
                subbox[(i / 3) * 3 + (j / 3)][dig - 1] = true;
            }

            else
                empt.push_back(make_pair(i, j));
        }
    }

    Backtrack(board, row, col, subbox, 0);
}

bool SudokuSolve::Backtrack(vector<vector<char>>& board, vec2D& row, vec2D& col, vec2D& subbox, int index)
{
    if (index == empt.size())
        return true;

    int curr_r = empt[index].first;
    int curr_c = empt[index].second;

    for (int i = 0; i < 9; i++)
    {
        if (row[curr_r][i] == false && col[curr_c][i] == false && subbox[(curr_r / 3) * 3 + (curr_c / 3)][i] == false)
        {
            row[curr_r][i] = true;
            col[curr_c][i] = true;
            subbox[(curr_r / 3) * 3 + (curr_c / 3)][i] = true;

            board[curr_r][curr_c] = (i + 1) + '0';

            if (Backtrack(board, row, col, subbox, index + 1) == true)
                return true;

            row[curr_r][i] = false;
            col[curr_c][i] = false;
            subbox[(curr_r / 3) * 3 + (curr_c / 3)][i] = false;

            board[curr_r][curr_c] = '.';
        }
    }

    return false;
}
