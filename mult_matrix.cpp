#include <iostream>
#include <vector>

using namespace std;

int main(){
	int rows1, cols1, rows2, cols2;
	cin >> rows1 >> cols1 >> rows2 >> cols2;
	if(cols1 != rows2) {
		cout << "MathError: the number of columns in the first matrix must be the same as the number of rows in the second.";
		return 0;
	}
	vector<vector<int>> m1(rows1, vector<int>(cols1)), m2(rows2, vector<int>(cols2));
	cout << "Enter the first matrix." << endl;
	for(int i = 0; i < rows1; ++i){
		for(int j = 0; j < cols1; ++j){
			cin >> m1[i][j];
		}
	}
	cout << "Now enter the second." << endl;
	for(int i = 0; i < rows2; ++i){
		for(int j = 0; j < cols2; ++j){
			cin >> m2[i][j];
		}
	}
	cout << "The product is" << endl;
	for(int row = 0; row < rows1; ++row){
		for(int col = 0; col < cols2; ++col){
			vector<int> tgtRow = m1[row];
			int sum = 0;
			for(int i = 0; i < rows2; ++i){
				int inCol = m2[i][col];
				int inRow = tgtRow[i];
				sum += inCol * inRow;
			}
			cout << sum << " ";
		}
		cout << endl;
	}
	return 0;
}
