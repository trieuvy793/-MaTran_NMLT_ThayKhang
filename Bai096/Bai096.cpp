#include <iostream>
#include<cmath>
#include<time.h>
#include<iomanip>
using namespace std;

float LonNhat(float[][500], int, int);
float NhoNhat(float[][500], int, int);
float LonNhi(float[][500], int, int); 
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

	cout << "So lon thu nhi trong mang la: " << LonNhi(arr, n, m);

	return 0;
}

float LonNhat(float a[][500], int n, int m)
{
	float lc = a[0][0];
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
		if (a[i][j] > lc)
			lc = a[i][j];
	return lc;
}

float NhoNhat(float a[][500], int n, int m)
{
	float lc = a[0][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] < lc)
				lc = a[i][j];
	return lc;
}


float LonNhi(float a[][500], int n, int m) {
	float Max = LonNhat(a, n, m);
	float Max2 = a[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (Max2 < Max && a[i][j] != Max && Max2 < a[i][j])
			{
				Max2 = a[i][j];
			}
		}
	}
	return Max2;
}

void Nhap(float a[][500], int& n, int& m)
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