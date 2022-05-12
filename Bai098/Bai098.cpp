#include <iostream>
#include<time.h>
#include<iomanip>
using namespace std;

float LonNhatDong(float[][500], int, int, int);
float LonNhatCot(float[][500], int, int, int);
float LonNhatCheo1(float[][500], int, int, int, int);
float LonNhatCheo2(float[][500], int, int, int, int);
int ktHoangHau(float[][500], int, int, int, int);
int DemHoangHau(float[][500], int, int);
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

	cout << "So luong gia tri hoang hau co trong mang la: " << DemHoangHau(arr, n, m);

	return 0;
}

float LonNhatDong(float a[][500], int n, int m, int d) {
	float lc = a[d][0];
	for (int j = 0; j < m; j++) {
		if (a[d][j] > lc)
			lc = a[d][j];
	}
	return lc;
}

float LonNhatCot(float a[][500], int n, int m, int c) {
	float lc = a[0][c];
	for (int i = 0; i < n; i++) {
		if (a[i][c] > lc)
			lc = a[i][c];
	}
	return lc;
}

float LonNhatCheo1(float a[][500], int n, int m, int d, int c) {
	float lc = a[d][c];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if ((i - j == d - c) && a[i][j] > lc)
				lc = a[i][j];
	return lc;
}

float LonNhatCheo2(float a[][500], int n, int m, int d, int c) {
	float lc = a[d][c];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if ((i + j == d + c) && a[i][j] > lc)
				lc = a[i][j];
	return lc;
}

int ktHoangHau(float a[][500], int n, int m, int d, int c) {
	float lnd = LonNhatDong(a, n, m, d);
	float lnc = LonNhatCot(a, n, m, c);
	float lnc1 = LonNhatCheo1(a, n, m, d, c);
	float lnc2 = LonNhatCheo2(a, n, m, d, c);

	if (a[d][c] == lnd && a[d][c] == lnc && a[d][c] == lnc1 && a[d][c] == lnc2)
		return 1;
	return 0;
}

int DemHoangHau(float a[][500], int n, int m) {
	int dem = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (ktHoangHau(a, n, m, i, j) == 1)
				dem++;
	return dem;
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