#include <iostream>
#include<time.h>
#include<iomanip>
using namespace std;

float TongCot(float[][500], int, int, int);
float TongNhoNhat(float[][500], int, int);
void LietKe(float[][500], int, int);
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

	cout << "Cac cot co tong nho nhat trong mang la: ";
	LietKe(arr, n, m);

	return 0;
}

float TongCot(float a[][500], int n, int m, int c) {
	float s = 0;
	for (int i = 0; i < n; i++)
		s = s + a[i][c];
	return s;
}

float TongNhoNhat(float a[][500], int n, int m) {
	float lc = TongCot(a, n, m, 0);
	for (int j = 0; j < m; j++)
		if (TongCot(a, n, m, j) < lc)
			lc = TongCot(a, n, m, j);
	return lc;
}

void LietKe(float a[][500], int n, int m) {
	float lc = TongNhoNhat(a, n, m);
	for (int i = 0; i < n; i++)
		if (TongCot(a, n, m, i) == lc)
			cout << i << " ";
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