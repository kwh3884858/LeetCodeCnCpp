class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m_row = matrix.size();
        m_column = matrix[0].size();
        m_sum.resize(m_row + 1);
        for(int i = 0; i < m_row + 1 ; i++){
            m_sum[i].resize(m_column + 1, 0);
        }

        for(int row = 1; row <= m_row; row++)
        {
            for(int column = 1; column <= m_column; column++)
            {
                m_sum[row][column] = m_sum[row][column - 1] + m_sum[row - 1][column] + matrix[row - 1][column -1] - m_sum[row - 1][column - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 < 0 || row1 >= m_row || row2 < 0 || row2 >= m_row || row2 < row1) return 0;
        if(col1 < 0 || col1 >= m_column || col2 < 0 || col2 >= m_column || col2 < col1) return 0;
        return m_sum[row2 + 1][ col2 + 1] - m_sum[row1][col2 + 1] - m_sum[row2 + 1][col1] + m_sum[row1][col1];
    }

    int m_row = 0;
    int m_column = 0;
    
    vector< vector<int> > m_sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */