#include<iostream>
#include<vector>
using namespace std;
int index_of(vector<vector<int>> v2d,int index1d){//find which row
    for(int i = 0;i < v2d.size();i++){
        for(int j = 0;j < v2d[i].size();j++){
            if(index1d - 1 == (v2d.size() * i) + j){
                return i;//row that has index1d
            }
        }
    }
    return -1;
}
template<typename T>
vector<vector<T>> creatMatrix(int row,int column){
    vector<vector<T>> v2d;
    for(int i = 0;i < row;i++){
        vector<T> temp;
        for(int j = 0;j < column;j++){
            temp.push_back(0);
        }
        v2d.push_back(temp);
    }
    return v2d;
}
template<typename T>
void print_matrix(vector<vector<T>> v2d){
    for(int i = 0;i < v2d.size();i++){
        for(int j = 0;j < v2d[i].size();j++){
            cout << v2d[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}
void adjacentGame(std::vector<int> move)
{
    // vector<vector<bool>> matrix {
    //     {0,0,0,0,0},//row 0
    //     {0,0,0,0,0},//row 1
    //     {0,0,0,0,0},//row 2
    //     {0,0,0,0,0},//row 3
    //     {0,0,0,0,0}//row 4
    // };
    vector<vector<int>> matrix = creatMatrix<int>(5,5);//rows x columns
    for(const auto& i : move){
        int index = i;
        int row = index_of(matrix,index);
        cout << "row:" << row << endl;
        int column = 0;
        column = matrix.size() - ((matrix.size() * (row + 1)) - (index - 1));
        matrix[row][column] =  !matrix[row][column];//self change
        if(row - 1 < 0){
            matrix[row + 1][column] = !matrix[row + 1][column];//opposite change
        }
        if(row + 1 > matrix.size() - 1){
            matrix[row - 1][column] = !matrix[row - 1][column];//opposite change
        }
        if(row - 1 >= 0 && row + 1 < matrix.size()){//opposite change
            matrix[row - 1][column] = !matrix[row - 1][column];
            matrix[row + 1][column] = !matrix[row + 1][column];
        }
        if(column - 1 < 0){
            matrix[row][column + 1] = !matrix[row][column + 1];//opposite change
        }
        if(column + 1 > matrix.size() - 1){
            matrix[row][column - 1] = !matrix[row][column - 1];//opposite change
        }
        if(column - 1 >= 0 && column + 1 < matrix.size()){//opposite change
            matrix[row][column - 1] = !matrix[row][column - 1];
            matrix[row][column + 1] = !matrix[row][column + 1];
        }
        print_matrix<int>(matrix);
    }

}
int main(){
    vector<int> move {13};//middle
    adjacentGame(move);//print out the matrix each time move increases
    return 0;
}