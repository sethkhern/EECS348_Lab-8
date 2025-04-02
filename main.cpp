#include <stdio.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void read_matrix(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2) {
    string filename;
    cout << "Enter name of Matrix file: ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cout <<"Cannot open the file!\n";
        exit(0);
    } else {
        int matrix_size = 0;
        file >> matrix_size;

        if (matrix_size <= 0) {
            cout <<"Invalid matrix size!\n";
            exit(0);
        }

        matrix1 = vector<vector<int>>(matrix_size, vector<int>(matrix_size));
        matrix2 = vector<vector<int>>(matrix_size, vector<int>(matrix_size));

        for (int i = 0; i < matrix_size; ++i) {
            for (int j = 0; j < matrix_size; ++j) {
                file >> matrix1[i][j];
            }
        }

        for (int i = 0; i < matrix_size; ++i) {
            for (int j = 0; j < matrix_size; ++j) {
                file >> matrix2[i][j];
            }
        }
    }
}

void print_matrix(const vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            printf("%3d ", matrix[i][j]);
        }

        cout <<endl;
    }
}

vector<vector<int>> add_matrix_up(const vector<vector<int>> &matrix1, const vector<vector<int>> &matrix2) {
    vector<vector<int>> sresult(matrix1);
    for (int i = 0; i < matrix1.size(); ++i) {
        for (int j = 0; j < matrix1[0].size(); ++j) {
            sresult[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return sresult;
}

vector<vector<int>> product_matrix(const vector<vector<int>> &matrix1, const vector<vector<int>> &matrix2) {
    vector<vector<int>> presult(matrix1.size(), vector<int>(matrix1.size()));
    for (int i = 0; i < matrix1.size(); ++i) {
        for (int j = 0; j < matrix1.size(); ++j) {
            for (int x = 0; x < matrix1.size(); ++x) {
                presult[i][j] += (matrix1[i][x] * matrix2[x][j]);
            }
        }
    }
    return presult;
}

void diagonal_sum_matrix(const vector<vector<int>> &matrix) {
    int main_diagonal = 0, second_diagonal = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        main_diagonal += matrix[i][i];
        second_diagonal += matrix[i][matrix.size() - 1 - i];
    }

    cout <<"Result of main diagonal " <<main_diagonal <<endl;
    cout <<"Result of second diagonal " <<second_diagonal <<endl;
}

void row_swap_matrix(vector<vector<int>> matrix, int row1, int row2) {
    if(0 <= row1 && row1 < matrix.size() && 0 <= row2 && row2 < matrix.size()) {
        swap(matrix[row1], matrix[row2]);
        print_matrix(matrix);
    } else {
        cout <<"Invalid index!" <<endl;
        exit(1);
    }
}

void column_swap_matrix(vector<vector<int>> matrix, int col1, int col2) {
    if (0 <= col1 && col1 < matrix.size() && 0 <= col2 < matrix.size()) {
        for (int i = 0; i < matrix.size(); ++i) {
            swap(matrix[i][col1], matrix[i][col2]);
        }
        print_matrix(matrix);
    } else {
        cout <<"Invalid index!" <<endl;
    }
}

vector<vector<int>> update_matrix(vector<vector<int>> matrix, const int row, const int col, const int newval) {
    if (0 <= row && row < matrix.size() && 0 <= col && col < matrix.size()) {
        matrix[row][col] = newval;
        return matrix;
    } else {
        cout <<"Invalid index!" <<endl;
    }
}

int main(int argc, char *argv[]) {
    vector<vector<int>> matrix1, matrix2;
    read_matrix(matrix1, matrix2);
    cout <<"The value of the first matrix" <<endl;
    print_matrix(matrix1);
    cout <<"The value of the second matrix" <<endl;
    print_matrix(matrix2);

    auto sresult = add_matrix_up(matrix1, matrix2);
    cout <<"The result of the sum of matrices" <<endl;
    print_matrix(sresult);

    auto presult = product_matrix(matrix1, matrix2);
    cout <<"The result of the product of matrices" <<endl;
    print_matrix(presult);

    cout <<"The result of the product of the main diagonals and secondary diagonals of matrices" <<endl;
    diagonal_sum_matrix(matrix1);

    cout <<"The result of the rows swapped in matrix" <<endl;
    row_swap_matrix(matrix1, 0, 1);

    cout <<"The result of the columns swapped in matrix" <<endl;
    column_swap_matrix(matrix1, 0, 1);

    auto uresult = update_matrix(matrix1, 2, 3, 80);
    cout <<"The result of the updated matrix" <<endl;
    print_matrix(uresult);

    return 0;
}
