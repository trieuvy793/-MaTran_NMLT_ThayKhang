#include <iostream>
#include<time.h>
#include<iomanip>
using namespace std;

int DemDong(int[][500], int, int, int);
int DemLonNhat(int[][500], int, int);
void LietKe(int[][500], int, int);
bool ktNguyenTo(int);
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

	cout << "Dong co nhieu so nguyen to nhat trong mang la: ";
	LietKe(arr, n, m);

	return 0;
}

bool ktNguyenTo(int m){
	int dem = 0;
	for (int i = 1; i <= m; i++)
		if (m%i == 0)
			dem++;
	if (dem == 2)
		return true;
	return false;
}

int DemDong(int a[][500], int n, int m, int d) {
	int dem = 0;
	for (int j = 0; j < m; j++)
		if (ktNguyenTo(a[d][j]))
			dem++;
	return dem;
}

int DemLonNhat(int a[][500], int n, int m) {
	int lc = DemDong(a, n, m, 0);
	for (int i = 0; i < n; i++)
		if (DemDong(a, n, m, i) > lc)
			lc = DemDong(a, n, m, i);
	return lc;
}

void LietKe(int a[][500], int n, int m) {
	int lc = DemLonNhat(a, n, m);
	for (int i = 0; i < n; i++)
		if (DemDong(a, n, m, i) == lc)
			cout << i << " ";
}

void Nhap(int  a[][500], int& n, int& m)
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