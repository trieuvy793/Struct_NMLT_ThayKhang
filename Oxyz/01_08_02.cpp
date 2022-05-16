#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Bai 048
struct diemkhonggian
{
	float x;
	float y;
	float z;
};
typedef struct diemkhonggian DIEMKHONGGIAN;

void Nhap(DIEMKHONGGIAN&);						//Bai 049
void Xuat(DIEMKHONGGIAN);						//Bai 050
float KhoangCach(DIEMKHONGGIAN, DIEMKHONGGIAN);	//Bai 051
float KhoangCachX(DIEMKHONGGIAN, DIEMKHONGGIAN);//Bai 052
float KhoangCachY(DIEMKHONGGIAN, DIEMKHONGGIAN);//Bai 053
float KhoangCachZ(DIEMKHONGGIAN, DIEMKHONGGIAN);//Bai 054
float KhoangCachGoc(DIEMKHONGGIAN);				//Bai 055
DIEMKHONGGIAN DoiXungGoc(DIEMKHONGGIAN);		//Bai 056
DIEMKHONGGIAN DoiXungOxy(DIEMKHONGGIAN);        //Bai 057
DIEMKHONGGIAN DoiXungOxz(DIEMKHONGGIAN);		//Bai 058
DIEMKHONGGIAN DoiXungOyz(DIEMKHONGGIAN);		//Bai 059
int ktTrung(DIEMKHONGGIAN, DIEMKHONGGIAN);		//Bai 060

int main() 
{
	DIEMKHONGGIAN A, B;
	cout << "Nhap toa do diem A: ";
	Nhap(A);
	cout << "Nhap toa do diem B: ";
	Nhap(B);
	cout << "\nToa do diem A: ";
	Xuat(A);
	cout << "Toa do diem B: ";
	Xuat(B);

	float kq = KhoangCach(A, B);
	float kq2 = KhoangCachX(A, B), kq3 = KhoangCachY(A, B), kq4 = KhoangCachZ(A, B);
	float kq5 = KhoangCachGoc(A), kq6 = KhoangCachGoc(B);
	DIEMKHONGGIAN kq7 = DoiXungGoc(A), kq8 = DoiXungGoc(B);
	DIEMKHONGGIAN kq9 = DoiXungOxy(A), kq10 = DoiXungOxy(B), kq11 = DoiXungOxz(A), kq12 = DoiXungOxz(B), kq13 = DoiXungOyz(A), kq14 = DoiXungOyz(B);
	int kq15 = ktTrung(A, B);

	cout << "\nKhoang cach giua 2 diem la: " << kq;
	cout << "\nKhoang cach giua 2 diem theo phuong x la: " << kq2;
	cout << "\nKhoang cach giua 2 diem theo phuong y la: " << kq3;
	cout << "\nKhoang cach giua 2 diem theo phuong z la: " << kq4;
	cout << "\nKhoang cach tu goc A den goc toa do la: " << kq5;
	cout << "\nKhoang cach tu goc B den goc toa do la: " << kq6;
	cout << "\nToa do diem A va B lan luot doi xung qua goc toa do la:\n";
	Xuat(kq7);
	Xuat(kq8);
	cout << "\nToa do diem A va B lan luot doi xung qua mat phang Oxy la:\n";
	Xuat(kq9);
	Xuat(kq10);
	cout << "\nToa do diem A va B lan luot doi xung qua mat phang Oxz la:\n";
	Xuat(kq11);
	Xuat(kq12);
	cout << "\nToa do diem A va B lan luot doi xung qua mat phang Oyz la:\n";
	Xuat(kq13);
	Xuat(kq14);
	(kq15) ? cout << "\n2 diem trung nhau\n" : cout << "\n2 diem khong trung nhau\n";

	return 0;
}

void Nhap(DIEMKHONGGIAN& P)
{
	cout << "\nNhap x: ";
	cin >> P.x;
	cout << "Nhap y: ";
	cin >> P.y;
	cout << "Nhap z: ";
	cin >> P.z;
}

void Xuat(DIEMKHONGGIAN P)
{
	cout << setprecision(3);
	cout << "(" << P.x << ", " << P.y << ", " << P.z << ")\n";
}

float KhoangCach(DIEMKHONGGIAN P, DIEMKHONGGIAN Q)
{
	return sqrt((P.x - Q.x) * (P.x - Q.x) +
		(P.y - Q.y) * (P.y - Q.y) +
		(P.z - Q.z) * (P.z - Q.z));
}

float KhoangCachX(DIEMKHONGGIAN P, DIEMKHONGGIAN Q)
{
	return abs(Q.x - P.x);
}

float KhoangCachY(DIEMKHONGGIAN P, DIEMKHONGGIAN Q)
{
	return abs(Q.y - P.y);
}

float KhoangCachZ(DIEMKHONGGIAN P, DIEMKHONGGIAN Q)
{
	return abs(Q.z - P.z);
}

float KhoangCachGoc(DIEMKHONGGIAN P)
{
	return sqrt(P.x*P.x + P.y*P.y + P.z*P.z);
}

DIEMKHONGGIAN DoiXungGoc(DIEMKHONGGIAN P)
{
	DIEMKHONGGIAN temp;
	temp.x = -P.x;
	temp.y = -P.y;
	temp.z = -P.z;
	return temp;
}

DIEMKHONGGIAN DoiXungOxy(DIEMKHONGGIAN P)
{
	DIEMKHONGGIAN temp;
	temp.x = P.x;
	temp.y = P.y;
	temp.z = -P.z;
	return temp;
}

DIEMKHONGGIAN DoiXungOxz(DIEMKHONGGIAN P)
{
	DIEMKHONGGIAN temp;
	temp.x = P.x;
	temp.y = -P.y;
	temp.z = P.z;
	return temp;
}

DIEMKHONGGIAN DoiXungOyz(DIEMKHONGGIAN P)
{
	DIEMKHONGGIAN temp;
	temp.x = -P.x;
	temp.y = P.y;
	temp.z = P.z;
	return temp;
}

int ktTrung(DIEMKHONGGIAN P, DIEMKHONGGIAN Q)
{
	if (P.x == Q.x && P.y == Q.y && P.z == Q.z)
		return 1;
	return 0;
}