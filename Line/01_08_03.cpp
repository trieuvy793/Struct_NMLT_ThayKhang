#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct duongthang
{
	float a;
	float b;
	float c;
};
typedef struct duongthang DUONGTHANG;

struct diem
{
	float x;
	float y;
};
typedef struct diem DIEM;

void Nhap(DUONGTHANG&);					//Bai 062
void Xuat(DUONGTHANG);					//Bai 063
float KhoangCach(DUONGTHANG, DIEM);		//Bai 064
int ktThuoc(DUONGTHANG, DIEM);			//Bai 065
int ktTrung(DUONGTHANG, DUONGTHANG);	//Bai 066
int ktSongSong(DUONGTHANG, DUONGTHANG); //Bai 067
int ktCat(DUONGTHANG, DUONGTHANG);		//Bai 068
DIEM GiaoDiem(DUONGTHANG, DUONGTHANG);  //Bai 069
int ktVuongGoc(DUONGTHANG, DUONGTHANG); //Bai 070

void NhapDiem(DIEM&);				
void XuatDiem(DIEM);

int main()
{
	DUONGTHANG A, B;
	cout << "Nhap duong thang A: ";
	Nhap(A);
	cout << "Nhap duong thang B: ";
	Nhap(B);
	cout << "\nDuong thang A: ";
	Xuat(A);
	cout << "\nDuong thang B: ";
	Xuat(B);

	DIEM P;
	cout << "\nNhap toa do diem P: ";
	NhapDiem(P);
	cout << "\nToa do diem P: ";
	XuatDiem(P);

	float kq = KhoangCach(A, P), kq1 = KhoangCach(B, P);
	int kq2 = ktThuoc(A, P), kq3 = ktThuoc(B, P);
	int kq4 = ktTrung(A, B), kq5 = ktSongSong(A, B), kq6 = ktCat(A, B);
	DIEM kq7 = GiaoDiem(A, B);
	int kq8 = ktVuongGoc(A, B);

	cout << "\nKhoang cach tu duong thang A va B lan luot toi diem P la: " << kq << "\t" << kq1;
	(kq2) ? cout << "\nDiem P thuoc duong thang A" : cout << "\nDiem P khong thuoc duong thang A";
	(kq3) ? cout << "\nDiem P thuoc duong thang B" : cout << "\nDiem P khong thuoc duong thang B";
	(kq4) ? cout << "\n2 duong thang trung nhau" : cout << "\n2 duong thang khong trung nhau";
	(kq5) ? cout << "\n2 duong thang song song nhau" : cout << "\n2 duong thang khong song song nhau";
	(kq8) ? cout << "\n2 duong thang vuong goc nhau" : cout << "\n2 duong thang khong vuong goc nhau";

	if (kq6)
	{
		cout << "\n2 duong thang cat nhau voi toa do: ";
		XuatDiem(kq7);
	}
	else
		cout << "\n2 duong thang khong cat nhau";

	return 0;
}

void Nhap(DUONGTHANG& d)
{
	cout << "\nNhap a: ";
	cin >> d.a;
	cout << "Nhap b: ";
	cin >> d.b;
	cout << "Nhap c: ";
	cin >> d.c;
}

void Xuat(DUONGTHANG d)
{
	cout << setprecision(3);
	cout << d.a << "x + " << d.b << "y + " << d.c << " = 0\n";
}

float KhoangCach(DUONGTHANG d, DIEM P)
{
	float tu = abs(d.a*P.x + d.b*P.y + d.c);
	float mau = sqrt(d.a*d.a + d.b*d.b);
	return tu / mau;
}

int ktThuoc(DUONGTHANG d, DIEM P)
{
	if ((d.a*P.x + d.b*P.y + d.c) == 0)
		return 1;
	return 0;
}

int ktTrung(DUONGTHANG d1, DUONGTHANG d2)
{
	float D = d1.a*d2.b - d2.a*d1.b;
	float Dx = -d1.c*d2.b + d2.c*d1.b;
	if (D == 0 && Dx == 0)
		return 1;
	return 0;
}

int ktSongSong(DUONGTHANG d1, DUONGTHANG d2)
{
	float D = d1.a*d2.b - d2.a*d1.b;
	float Dx = -d1.c*d2.b + d2.c*d1.b;
	if (D == 0 && Dx != 0)
		return 1;
	return 0;
}

int ktCat(DUONGTHANG d1, DUONGTHANG d2)
{
	float D = d1.a*d2.b - d2.a*d1.b;
	if (D != 0)
		return 1;
	return 0;
}

DIEM GiaoDiem(DUONGTHANG d1, DUONGTHANG d2)
{
	float D = d1.a*d2.b - d2.a*d1.b;
	float Dx = -d1.c*d2.b + d2.c*d1.b;
	float Dy = -d1.a*d2.c + d2.a*d1.c;

	DIEM temp;
	temp.x = Dx / D;
	temp.y = Dy / D;
	return temp;
}

int ktVuongGoc(DUONGTHANG d1, DUONGTHANG d2)
{
	if ((d1.a*d2.a + d1.b*d2.b) == 0)
		return 1;
	return 0;
}

void NhapDiem(DIEM& P)
{
	cout << "\nNhap x: ";
	cin >> P.x;
	cout << "Nhap y: ";
	cin >> P.y;
}

void XuatDiem(DIEM P)
{
	cout << setprecision(3);
	cout << "(" << P.x << ", " << P.y << ")\n";
}

