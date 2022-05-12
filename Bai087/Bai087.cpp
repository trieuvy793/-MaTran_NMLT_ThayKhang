#include <iostream>
#include<time.h>
#include<iomanip>
using namespace std;

int TanSuat(float[][500], int, int, float);
float TimGiaTri(float[][500], int, int);
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

	float giatri = TimGiaTri(arr, n, m);
	cout << "Gia tri xuat hien nhieu nhat trong mang la: " << giatri;

	return 0;
}

int TanSuat(float a[][500], int n, int m, float x) {
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (a[i][j] == x)
				dem++;
	}
	return dem;
}

float TimGiaTri(float a[][500], int n, int m) {
	float lc = a[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (TanSuat(a, n, m, a[i][j]) > TanSuat(a, n, m, lc))
				lc = a[i][j];
	}
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