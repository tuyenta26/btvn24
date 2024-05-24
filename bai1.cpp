#include <iostream>
using namespace std;

int tong (int matrix[][100],int rows,int cols){
    int sum = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            sum += matrix[i][j];
        }
    }
    return sum;
}

int minMax (int matrix[][100], int rows, int cols, int &min, int &max){
    min = 0;
    max = 0;
    for (int i = 0; i < rows; i++){
        for ( int j = 0; j < cols; j++){
            if (matrix[i][j] < min) min = matrix[i][j];
            if (matrix[i][j] > max) max = matrix[i][j];
        }
    }
}

int sumColsVaRows (int matrix[][100], int rows, int cols){
    for (int i = 0; i < rows; i++){
        int sumRows = 0;
        for ( int j = 0; j < cols; j++){
            sumRows += matrix[i][j];
        }
        cout << "Tong hang " << i << " :" << sumRows << endl;
    }
    for (int j = 0; j < cols; j++){
        int sumCols = 0;
        for (int i = 0; i < rows; i++){
            sumCols += matrix[i][j];
        }
        cout << "Tong cot " << j << " :" << sumCols << endl;
    }
}

int maxRows ( int matrix[][100], int rows, int cols){
    for (int i = 0; i < rows; i++){
        int maxRow = 0;
        for (int j = 0; j < cols; j++){
            if (matrix[i][j] > maxRow)
            maxRow = matrix[i][j];
        }
        cout << "Max hang " << i << " :" << maxRows << endl;
    }
}

bool maTran (int matrix[][100],int rows, int cols){
    if ( rows != cols) return false;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (matrix[i][j] != matrix[j][i]) return false;
        }
    }
    return true;

}

int tongDuongCheo (int matrix[][100], int rows, int cols){
    int sum = 0;
    for (int i = 0; i <rows; i++){
        sum += matrix[i][i];
    }
    return sum;
}
bool isPrimes (int n){
    if (n < 2){
        return false;
    }
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int isPrimes (int matrix[][100], int rows, int cols){
    int sum = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (isPrimes(matrix[i][j]))
            sum += matrix[i][j];
        }
    }
    return sum;
}

int sortRows (int matrix[][100], int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols - 1; j++){
            for (int k = j +1; k < cols; k++){
                if(matrix[i][j] > matrix[i][k]){
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[i][k];
                    matrix[i][k] = temp;
                }
            }
        }
    }  
}

int main(){
    int matrix[100][100];
    int rows, cols;
    cout << "Nhap so dong:";
    cin >> rows;

    cout << "Nhap so cot:";
    cin >> cols;


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Nhap matrix[" << i << "][" << j << "]:";
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Tong cac phan tu cua mang la: " << tong(matrix, rows,cols) << endl;

    int min, max;
    minMax (matrix, rows, cols, min, max);
    cout << "Phan tu nho nhat: " << min << endl;
    cout << "Phan tu lon nhat: " << max << endl;

    sumColsVaRows (matrix, rows, cols);
    
    maxRows (matrix, rows, cols);

    if (maTran(matrix, rows, cols)){
        cout << "Ma tran doi xung" << endl;
    } else {
        cout << "Ma tran khong doi xung." << endl;
    }

    cout << "Tong duong cheo:"<< tongDuongCheo(matrix, rows, cols) << endl;

    cout << "Tong cac so nguyen to trong mang:" << isPrimes(matrix, rows, cols) << endl;

    
    cout << "Mang sau khi sap xep la:" << endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
             cout << matrix[i][j]<< " ";
        }
        cout << endl;
    }
 return 0;
}

