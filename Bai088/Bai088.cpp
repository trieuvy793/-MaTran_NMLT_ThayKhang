#include <iostream>
#include<time.h>
#include<iomanip>
using namespace std;

float TongDong(float[][500], int, int, int);
float TongLonNhat(float[][500], int, int);
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

	float tong = TongLonNhat(arr, n, m);
	cout << "Tong dong lon nhat trong mang la: " << tong;

	return 0;
}

float TongDong(float a[][500], int n, int m, int d) {
	float s = 0;
	for (int j = 0; j < m; j++)
		s = s + a[d][j];
	return s;
}

float TongLonNhat(float a[][500], int n, int m) {
	float lc = TongDong(a, n, m, 0);
	for (int i = 0; i < n; i++)
		if (TongDong(a, n, m, i) > lc)
			lc = TongDong(a, n, m, i);
	return lc;
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