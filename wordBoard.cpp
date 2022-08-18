class Board {
public:
    
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
};
