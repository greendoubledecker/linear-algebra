#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> mulMatrix(vector<vector<long long>> matrix1, vector<vector<long long>> matrix2, int size){
	vector<vector<long long>> output(size, vector<long long>(size));
	for(int row = 0; row < size; ++row){
		for(int col = 0; col < size; ++col){
			vector<long long> tgtRow = matrix1[row];
			long long sum = 0;
			for(int i = 0; i < size; ++i){
				long long inCol = matrix2[i][col];
				long long inRow = tgtRow[i];
				sum += inCol * inRow;
			}
			output[row][col] = sum;
		}
	}
	return output;
}

int main(){
	int size;
	cout << "Input the size of your matrix." << endl;
	cin >> size;
	cout << "Now input the matrix itself." << endl;
	vector<vector<long long>> matrix(size, vector<long long>(size));
	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size; ++j){
			cin >> matrix[i][j];
		}
	}
	int pow = 0;
	cout << "Input the power you want the matrix raised to." << endl;
	cin >> pow;
	if(pow == 0){
		cout << "The 0th power is the identity matrix, or" << endl;
		for(int i = 0; i < size; ++i){
			for(int j = 0; j < size; ++j){
				if(i == j){
					cout << 1;
				}else{
					cout << 0;
				}
			}
			cout << endl;
		}
		return 0;
	}
	if(pow < 0){
		cout << "MathError: Please do not input a negative power." << endl;
		return 0;
	}
	vector<vector<long long>> result = matrix;
	for(int i = 1; i < pow; ++i){
		result = mulMatrix(matrix, result, size);
	}
	cout << "The " << pow << "th power of the matrix is" << endl;
	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size; ++j){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
