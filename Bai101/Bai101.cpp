#include <iostream>
#include<cmath>
#include<time.h>
#include<iomanip>
using namespace std;

int TonTaiLe(float[][500], int, int);
void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);

int main() {
	float arr[500][500];
	int m, n;
	cout << "Moi nhap so hang: ";
	cin >> n;
	cout << "Moi nhap so cot: ";
	cin >> m;
	Nhap(arr, n, m);
	cout << "Ma tran sau khi nhap la: \n";
	Xuat(arr, n, m);

	cout << "Kiem tra ma tran co ton tai so duong hay khong: " << TonTaiLe(arr, n, m);

	return 0;
}

int TonTaiLe(float a[][500], int n, int m) {
	int flag = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] > 0)
				flag = 1;
	return flag;
}

void Nhap(float  a[][500], int& n, int& m)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = -100.0 + (rand() / (RAND_MAX / (100.0 - (-100.0))));
}

void Xuat(float a[][500], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(8);
			cout << setprecision(3);
			cout << a[i][j];
		}
		cout << "\n";
	}
}