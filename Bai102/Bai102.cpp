#include <iostream>
#include<cmath>
#include<time.h>
#include<iomanip>
using namespace std;

int TonTaiLe(int[][500], int, int);
void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);

int main() {
	int arr[500][500];
	int m, n;
	cout << "Moi nhap so hang: ";
	cin >> n;
	cout << "Moi nhap so cot: ";
	cin >> m;
	Nhap(arr, n, m);
	cout << "Ma tran sau khi nhap la: \n";
	Xuat(arr, n, m);

	cout << "Kiem tra ma tran co ton tai so le hay khong: " << TonTaiLe(arr, n, m);

	return 0;
}

int TonTaiLe(int a[][500], int n, int m) {
	int flag = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] % 2 != 0)
				flag = 1;
	return flag;
}

void Nhap(int a[][500], int& n, int& m)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = -100 + (rand() / (RAND_MAX / (100 - (-100))));
}

void Xuat(int a[][500], int n, int m)
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