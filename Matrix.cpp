#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
class matrix
{
public:
    vector<vector<int>> cell = {{}};
    int row = cell.size();
    int col = cell[0].size();
    // Constructor and Destructor
    matrix();
    matrix(int row, int col);
    matrix(int sqr);
    matrix(string value);
    // Function
    friend ostream &operator<<(ostream &os, const matrix &matrix);
    int det();
    matrix sub(int srow, int scol, int erow, int ecol);
    matrix substr(int row, int col);
    void insert(int srow, int scol, matrix matrix);
};

// constructor
matrix::matrix(int row, int col)
{
    this->row = row;
    this->col = col;
    for (int i = 0; i < row; i++)
    {
        this->cell.push_back({});
        for (int j = 0; j < col; j++)
            this->cell[i].push_back(0);
    }
}

matrix::matrix(int sqr)
{
    this->row = sqr;
    this->col = sqr;
    for (int i = 0; i < sqr; i++)
    {
        this->cell.push_back({});
        for (int j = 0; j < sqr; j++)
            this->cell[i].push_back(0);
    }
}

matrix::matrix(string value)
{
    int row = 0;
    int tmp = 0;
    for (int i = 0; i < value.length(); i++)
    {
        if ((int)value[i] >= 48 && (int)value[i] <= 57)
        {
            tmp = tmp * 10 + ((int)value[i] - 48);
        }
        else
        {
            if (value[i] == ' ' && (this->cell[row].size() <= this->cell[0].size()))
            {
                this->cell[row].push_back(tmp);
                tmp = 0;
            }
            else
            {
                this->cell[row].push_back(tmp);
                tmp = 0;
                this->cell.push_back({});
                row++;
            }
        }
    }
    this->cell[row][this->cell[0].size() - 1] = tmp;
    this->col = cell[0].size();
    this->row = cell.size();
    for (int i = 0; i < row; i++)
    {
        if (this->cell[i].size() != this->col)
        {
            for (int j = this->cell[i].size(); j < this->col; j++)
            {
                this->cell[i].push_back(0);
            }
        }
    }
}

// friend function
ostream &operator<<(ostream &os, const matrix &matrix)
{
    int max = 0;
    for (int i = 0; i < matrix.row; i++)
        for (int j = 0; j < matrix.col; j++)
        {
            if (matrix.cell[i][j] > max)
                max = matrix.cell[i][j];
        }
    if (max != 0)
        max = log10(max);
    for (int i = 0; i < matrix.row; i++)
    {
        for (int j = 0; j < matrix.col; j++)
        {
            if (max != 0)
                if (matrix.cell[i][j] == 0)
                {
                    for (int k = 0; k < max; k++)
                        os << ' ';
                }
                else
                    for (int k = 0; k < ((max - log10(matrix.cell[i][j]))); k++)
                    {
                        os << ' ';
                    }
            os << matrix.cell[i][j];
            if (j != matrix.cell[0].size() - 1)
                os << ' ';
        }
        os << '\n';
    }
    return os;
}

matrix matrix::sub(int srow, int scol, int erow, int ecol)
{
    if (srow < 0 || scol < 0 || erow >= this->row || ecol >= this->col)
    {
        cerr << "Overload Matrix";
        return -1;
    }
    matrix result(erow - srow + 1, ecol - scol + 1);

    for (int i = 0; i < erow - srow + 1; i++)
    {
        for (int j = 0; j < ecol - scol + 1; j++)
        {
            result.cell[i][j] = this->cell[i + srow][j + scol];
        }
    }
    return result;
}

matrix matrix::substr(int row, int col){
    if (row < 0 || col < 0 || row >= this->row || col >= this->col)
    {
        cerr << "Overload Matrix";
        return -1;
    }
    else{
        matrix result(this->row - 1, this->col - 1);
        bool addr = 0, addc = 0;
        for (int i = 0; i < this->row; i++)
        {
            addc = 0;
            if(i != row)
        for (int j = 0; j < this->col; j++)
        {
            if(j != col)
            result.cell[i - (int)addr][j - (int)addc] = this->cell[i][j];
            else addc = 1;
        }else addr = 1;
        }
        return result;
    }
}

void matrix::insert(int srow, int scol, matrix matrix)
{
    if (matrix.row + srow - this->row > 0 || matrix.col + scol - this->col > 0)
    {
        cerr << "Overload Matrix";
    }
    else
    {
        for (int i = srow; i < this->row; i++)
            for (int j = scol; j < this->col; j++)
            {
                this->cell[i][j] = matrix.cell[i - srow][j - scol];
            }
    }
}

int matrix::det()
{
    if (col != row)
    {
        cerr << "Not Square Matrix ";
        return -1;
    }
    else
    {
    }
    return 0;
}

int main()
{
    matrix s("2 1 5 8 9/45 5 5 4/ 4 5 8 7 5");
    // cout << s.cell[2][3] << endl;
    cout << s.col;
    cout << s.row << endl;
    cout << s << endl;
    cout << s.substr(1, 1);
    return 0;
}
