#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


//Bai 031
struct diem
{
	float x;
	float y;
};
typedef struct diem DIEM;

void Nhap(DIEM&);				//Bai 032
void Xuat(DIEM);				//Bai 033
float KhoangCach(DIEM, DIEM);	//Bai 034
float KhoangCachX(DIEM, DIEM);  //Bai 035
float KhoangCachY(DIEM, DIEM);  //Bai 036
float KhoangCachGoc(DIEM);      //Bai 037

DIEM DoiXungGoc(DIEM);			//Bai 038
DIEM DoiXungHoanh(DIEM);		//Bai 039
DIEM DoiXungTung(DIEM);			//Bai 040
DIEM DoiXungPhanGiac1(DIEM);    //Bai 041
DIEM DoiXungPhanGiac2(DIEM);    //Bai 042

int ktTrung(DIEM, DIEM);		//Bai 043
int ktThuoc1(DIEM);				//Bai 044
int ktThuoc2(DIEM);				//Bai 045
int ktThuoc3(DIEM);				//Bai 046
int ktThuoc4(DIEM);				//Bai 047

int main() {
	DIEM A, B;
	cout << "Nhap toa do diem P: ";
	Nhap(A);
	cout << "Nhap toa do diem Q: ";
	Nhap(B);
	cout << "\nToa do diem P: ";
	Xuat(A);
	cout << "\nToa do diem Q: ";
	Xuat(B);

	float kq = KhoangCach(A, B);
	float kq2 = KhoangCachX(A, B), kq3 = KhoangCachY(A, B);
	float kq4 = KhoangCachGoc(A), kq5 = KhoangCachGoc(B);
	DIEM kq6 = DoiXungGoc(A), kq7 = DoiXungGoc(B);
	DIEM kq8 = DoiXungHoanh(A), kq9 = DoiXungTung(B), kq10 = DoiXungHoanh(B), kq11 = DoiXungTung(A);
	DIEM kq12 = DoiXungPhanGiac1(A), kq13 = DoiXungPhanGiac1(B), kq14 = DoiXungPhanGiac2(A), kq15 = DoiXungPhanGiac2(B);
	int kq16 = ktTrung(A, B), kq17 = ktThuoc1(A), kq18 = ktThuoc1(B), kq19 = ktThuoc2(A), kq20 = ktThuoc2(B), kq21 = ktThuoc3(A), kq22 = ktThuoc3(B), kq23 = ktThuoc4(A), kq24 = ktThuoc4(B);

	cout << setprecision(3) << "\nKhoang cach hai diem: " << kq;
	cout << setprecision(3) << "\nKhoang cach hai diem theo phuong Ox: " << kq2;
	cout << setprecision(3) << "\nKhoang cach hai diem theo phuong Oy: " << kq3;
	cout << setprecision(3) << "\nKhoang cach diem P den goc toa do la: " << kq4;
	cout << setprecision(3) << "\nKhoang cach diem Q den goc toa do la: " << kq5;
	cout << "\nDiem P va Q lan luot doi xung goc toa do la:\n";
	Xuat(kq6);
	Xuat(kq7);
	cout << "\nDoi xung qua truc hoanh va truc tung cua diem P lan luot la:\n";
	Xuat(kq8);
	Xuat(kq11);
	cout << "\nDoi xung qua truc hoanh va truc tung cua diem P lan luot la:\n";
	Xuat(kq9);
	Xuat(kq10);
	cout << "\nDiem doi xung qua duong phan giac 1 cua P va Q lan luot la:\n";
	Xuat(kq12);
	Xuat(kq13);
	cout << "\nDiem doi xung qua duong phan giac 2 cua P va Q lan luot la:\n";
	Xuat(kq14);
	Xuat(kq15);

	(kq16) ? cout << "2 toa do trung nhau" : cout << "2 toa do khong trung nhau";
	(kq17) ? cout << "\nDiem P thuoc goc phan tu thu I" : cout << "\nDiem P khong thuoc goc phan tu thu I";
	(kq18) ? cout << "\nDiem Q thuoc goc phan tu thu I" : cout << "\nDiem Q khong thuoc goc phan tu thu I";
	(kq19) ? cout << "\nDiem P thuoc goc phan tu thu II" : cout << "\nDiem P khong thuoc goc phan tu thu II";
	(kq20) ? cout << "\nDiem Q thuoc goc phan tu thu II" : cout << "\nDiem Q khong thuoc goc phan tu thu II";
	(kq21) ? cout << "\nDiem P thuoc goc phan tu thu III" : cout << "\nDiem P khong thuoc goc phan tu thu III";
	(kq22) ? cout << "\nDiem Q thuoc goc phan tu thu III" : cout << "\nDiem Q khong thuoc goc phan tu thu III";
	(kq23) ? cout << "\nDiem P thuoc goc phan tu thu IV" : cout << "\nDiem P khong thuoc goc phan tu thu IV";
	(kq24) ? cout << "\nDiem Q thuoc goc phan tu thu IV" : cout << "\nDiem Q khong thuoc goc phan tu thu IV";

	return 0;
}

void Nhap(DIEM& P)
{
	cout << "\nNhap x: ";
	cin >> P.x;
	cout << "Nhap y: ";
	cin >> P.y;
}

void Xuat(DIEM P)
{
	cout << setprecision(3);
	cout << "(" << P.x << ", " << P.y << ")\n";
}

float KhoangCach(DIEM P, DIEM Q)
{
	return sqrt((Q.x - P.x)*(Q.x - P.x) + (Q.y - P.y)*(Q.y - P.y));
}

float KhoangCachX(DIEM P, DIEM Q)
{
	return abs(Q.x - P.x);
}

float KhoangCachY(DIEM P, DIEM Q)
{
	return abs(Q.y - P.y);
}

float KhoangCachGoc(DIEM P)
{
	return sqrt(P.x*P.x + P.y*P.y);
}

DIEM DoiXungGoc(DIEM P)
{
	DIEM temp;
	temp.x = -P.x;
	temp.y = -P.y;
	return temp;
}

DIEM DoiXungHoanh(DIEM P)
{
	DIEM temp;
	temp.x = P.x;
	temp.y = -P.y;
	return temp;
}

DIEM DoiXungTung(DIEM P)
{
	DIEM temp;
	temp.x = -P.x;
	temp.y = P.y;
	return temp;
}

DIEM DoiXungPhanGiac1(DIEM P)
{
	DIEM temp;
	temp.x = P.y;
	temp.y = P.x;
	return temp;
}

DIEM DoiXungPhanGiac2(DIEM P)
{
	DIEM temp;
	temp.x = -P.y;
	temp.y = -P.x;
	return temp;
}

int ktTrung(DIEM P, DIEM Q)
{
	if (P.x == Q.x && P.y == Q.y)
		return 1;
	return 0;
}

int ktThuoc1(DIEM P)
{
	if (P.x > 0 && P.y > 0)
		return 1;
	return 0;
}

int ktThuoc2(DIEM P)
{
	if (P.x < 0 && P.y > 0)
		return 1;
	return 0;
}

int ktThuoc3(DIEM P)
{
	if (P.x < 0 && P.y < 0)
		return 1;
	return 0;
}

int ktThuoc4(DIEM P)
{
	if (P.x > 0 && P.y < 0)
		return 1;
	return 0;
}