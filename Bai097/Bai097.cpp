#include <iostream>
#include<time.h>
#include<iomanip>
using namespace std;

float LonNhatDong(float[][500], int, int, int);
float NhoNhatDong(float[][500], int, int, int);
float LonNhatCot(float[][500], int, int, int);
float NhoNhatCot(float[][500], int, int, int);
int ktYenNgua(float[][500], int, int, int, int);
int DemYenNgua(float[][500], int, int);
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

	int kq = DemYenNgua(arr, n, m);
	cout << "So luong yen ngua co trong mang la: " <<  kq;

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

float NhoNhatDong(float a[][500], int n, int m, int d) {
	float lc = a[d][0];
	for (int j = 0; j < m; j++) {
		if (a[d][j] < lc)
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

float NhoNhatCot(float a[][500], int n, int m, int c) {
	float lc = a[0][c];
	for (int i = 0; i < n; i++) {
		if (a[i][c] < lc)
			lc = a[i][c];
	}
	return lc;
}

int ktYenNgua(float a[][500], int n, int m, int d, int c) {
	float lnd = LonNhatDong(a, n, m, d);
	float nnc = NhoNhatCot(a, n, m, c);
	float lnc = LonNhatCot(a, n, m, c);
	float nnd = NhoNhatDong(a, n, m, d);

	if ((a[d][c] == lnd && a[d][c] == nnc) || (a[d][c] == lnc && a[d][c] == nnd))
		return 1;
	return 0;
}

int DemYenNgua(float a[][500], int n, int m) {
	int dem = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (ktYenNgua(a, n, m, i, j) == 1)
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