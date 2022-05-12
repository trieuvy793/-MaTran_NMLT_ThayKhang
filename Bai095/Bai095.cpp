#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
int DemChuSo(int);
int DemCot(int[][500], int, int, int);
int DemLonNhat(int[][500], int, int);
void LietKe(int[][500], int, int);
int main()
{
	int a[500][500];
	int n, m;
	cout << "Moi nhap so hang: ";
	cin >> n;
	cout << "Moi nhap so cot: ";
	cin >> m;
	Nhap(a, n, m);
	cout << "Ma tran sau khi nhap la: \n";
	Xuat(a, n, m);

	cout << endl;
	cout << "Cot co nhieu chu so nhat la: ";
	LietKe(a, n, m);

	return 0;
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

int DemChuSo(int k)
{
	if (k == 0)
		return 1;
	int dem = 0;
	for (int t = k; t != 0; t = t / 10)
		dem++;
	return dem;
}

int DemCot(int a[][500], int m, int n, int c)
{
	int s = 0;
	int d = 0;
	for (int i = 0; i < m; i++)
	{
		s = DemChuSo(a[i][c]);
		d += s;
	}
	return d;
}

int DemLonNhat(int a[][500], int n, int m)
{
	int lc = DemCot(a, n, m, 0);
	for (int j = 0; j < m; j++)
		if (DemCot(a, n, m, j) > lc)
			lc = DemCot(a, n, m, j);
	return lc;
}

void LietKe(int a[][500], int n, int m)
{
	int lc = DemLonNhat(a, n, m);
	for (int j = 0; j < m; j++)
		if (DemCot(a, n, m, j) == lc)
			cout << j << " ";
}