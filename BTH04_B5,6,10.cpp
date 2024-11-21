//Bai 5+6+10
#include <iostream>

using namespace std;

void nhapDulieu(int &n) {
	do {
		cout << "Nhap n: ";
		cin >> n;
		if (n <= 0)
			cout << "Nhap sai roi, n phai lon hon 0, nhap lai di!!\n";
	} while (n <= 0);
}

bool isNguyento(int n) {
	bool flag = true;
	if (n < 2)
		flag = false;
	else{
		for (int i = 2; i <= sqrt(n);i++){
			if (n%i == 0) {
				flag = false;
					break;
			}
		}
	}
	return flag;
}

	int tinhSDN(int n) {
		int tam = n, soDaonguoc = 0;

		while (tam != 0) {
			soDaonguoc = soDaonguoc * 10 + tam % 10;
			tam = tam / 10;
		}
		return soDaonguoc;
	}

int main() {
	int chon, n, soDaonguoc = 0;
	int SoCuaBan;
	int tam = 0;

	do {

		cout << ("====================\n");
		cout << ("1.SoDaoNguoc\n");
		cout << ("2.SoNguyenTo\n");
		cout << ("3.ThuaSoNguyenTo\n");
		cout << ("4.SoDoiXung\n");
		cout << ("0.Thoat chuong trinh\n");

		cout << ("====================\n");
		cout << ("Nhap de bai ban mong muon: \n");

		cin >> chon;
		system("cls");
		switch (chon)
		{//So Dao Nguoc
		case 1: cout << "==========SoDaoNguoc==========\n";
			nhapDulieu(n);

			soDaonguoc = tinhSDN(n);

			cout << "So dao nguoc la " << soDaonguoc << endl;
			break;

		case 2://So Nguyen To
		{
			cout << "==========So Nguyen To==========\n" << endl;
			//Vong lap nhap vao so nguyen to (neu sai)
			nhapDulieu(n);
			bool flag = isNguyento(n);
			{
				if (flag == true)
					cout << n << " la so nguyen to";
				else
					cout << n << " khong phai so nguyen to";
			}
			break;
		}
		case 3:// Thua so nguyen to
		{
			cout << "==========Thua so nguyen to==========\n";
			nhapDulieu(n);

			for (int i = 2; i <= n; i++) {
				bool flag = isNguyento(i);
				if (flag == true) {
					while (n%i == 0) {
						cout << i << " ";
						n = n / i;
					}
				}
			}
		}
		break;
		case 4://So doi xung
		{
			cout << "==========So doi xung==========\n";
			nhapDulieu(n);

			soDaonguoc = tinhSDN(n);

			if (soDaonguoc == n)
				cout << n << " la so doi xung!\n";
			else
				cout << n << " khong la so doi xung!\n";
		}
		break;
		case 0:
			cout << "Cam on da su dung dich vu!\n";
			break;
		default:
			cout << "Chuc nang chua phat trien!\n";
			break;
		}

	} while (chon != 0);

	system("pause");
	return 0;
}