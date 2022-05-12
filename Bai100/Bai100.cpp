#include <iostream>
#include<cmath>
#include<time.h>
#include<iomanip>
using namespace std;

int ViTriDuongDau(int[], int);
int ViTriDuongNhoNhat(int[], int);
int TimChuSo(int[][500], int, int);
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

	cout << "Chu so xuat hien it nhat trong mang la: " << TimChuSo(arr, n, m);

	return 0;
}

int ViTriDuongDau(int a[], int n) {
	for (int i = 0; i <= n - 1; i++)
		if (a[i] > 0)
			return i;
	return -1;
}

int ViTriDuongNhoNhat(int a[], int n) {
	int lc = ViTriDuongDau(a, n);
	if (lc == -1)
		return -1;
	for (int i = 0; i <= n - 1; i++)
		if (a[i] > 0 && a[i] < a[lc])
			lc = i;
	return lc;
}

int TimChuSo(int a[][500], int n, int m) {
	int dem[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0)
				dem[0]++;
			int t = abs(a[i][j]);
			while (t != 0)
			{
				int dv = t % 10;
				dem[dv]++;
				t /= 10;
			}
		}
	return ViTriDuongNhoNhat(dem, 10);
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