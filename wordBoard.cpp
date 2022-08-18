
bool dfs(vector<vector<char>>& board, string word, int i, int j, int len)
{
    if(len == word.size())
        return true;
    
    if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[len])
        return false;
    
    char temp = board[i][j];
    
    board[i][j] = '1';
    
    bool found = dfs(board, word, i - 1, j, len + 1) ||  
                    dfs(board, word, i + 1, j, len + 1) ||  
                    dfs(board, word, i, j - 1, len + 1) ||  
                    dfs(board, word, i, j + 1, len + 1);    
    
    board[i][j] = temp;

    return found;
}

bool exist(vector<vector<char>>& board, string word)
{
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[i].size(); j++)
        {

            if(board[i][j] == word[0] && dfs(board, word, i, j, 0))
                return true;
        }
    }
    
    return false;
}
    char board[12][2]
    board[0][0] = "A";
    board[0][1] = "B";
    board[0][2] = "C";
    board[0][3] = "E";
    board[1][0] = "S";
    board[1][1] = "F";
    board[1][2] = "C";
    board[1][3] = "S";
    board[2][0] = "A";
    board[2][1] = "D";
    board[2][2] = "E";
    board[2][3] = "E";
    char word[] = "ABCCED";
    cout<<exist(board, word);

    return 0;
