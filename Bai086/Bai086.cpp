#include <iostream>
using namespace std;

int ChanDau(int[][500], int, int);
int ChanNhoNhat(int[][500], int, int);
int DemChanNhoNhat(int[][500], int, int);
void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);

int main() {
	int arr[500][500], m, n;
	cout << "Moi nhap so hang: ";
	cin >> n;
	cout << "Moi nhap so cot: ";
	cin >> m;
	Nhap(arr, n, m);
	cout << "Ma tran sau khi nhap la: \n";
	Xuat(arr, n, m);

	int count = DemChanNhoNhat(arr, n, m);
	cout << "So luong gia tri chan nho nhat trong ma tran la: " << count;

	return 0;
}

int ChanDau(int a[][500], int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] % 2 == 0)
				return a[i][j];
	return -1;
}

int ChanNhoNhat(int a[][500], int n, int m) {
	int lc = ChanDau(a, n, m);
	if (lc == -1)
		return -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] % 2 == 0 && a[i][j] < lc)
				lc = a[i][j];
	return lc;
}

int DemChanNhoNhat(int a[][500], int n, int m) {
	int dem = 0;
	int lc = ChanNhoNhat(a, n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] % 2 == 0 && a[i][j] == lc)
				dem++;
		}
	}
	return dem;
}

void Nhap(int a[][500], int& n, int& m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
}

void Xuat(int a[][500], int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
}