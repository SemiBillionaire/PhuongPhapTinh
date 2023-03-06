#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

double* Chiso ( int Bac )
{
    cout << "Nhap chi so : " << endl;
    double* a = new double [Bac+1];
    for ( int i = Bac; i >= 0; i-- )
    {
        cout << 'a' << i << " : ";
        cin >> a[i];
    }
    return a;
}

void InHam ( double* a, int Bac )
{
    for ( int i = Bac; i >= 0; i-- )
    {
        if ( i != 0 ) cout << a[i] << "x^" << i << " + ";
        else cout << a[i];
    }
}

double f(double*a, int Bac, double x)
{
    double result = a[Bac];
    for ( int i = Bac-1; i >= 0; i-- )
    {
        result = result*x + a[i];
    }
    return result;
}

int main ()
{
    cout << "        ===== Tim nghiem cua da thuc =====\n";
    cout << "Nhap bac cua da thuc : ";
    int n; cin >> n;
    double* a = new double [n];
    a = Chiso(n);
    system("cls");
    cout << "Ham vua nhap co dang : ";
    InHam(a,n); cout << endl;
    cout << "Nhap diem bat dong du doan : ";
    double p0; cin >> p0;
    cout << "Nhap so lan lap : ";
    int t; cin >> t;
    cout << "Nhap dung sai : ";
    double k; cin >> k;
    system("cls");
    double p;
    double d = k+1;
    while (t>0 && d>k )
    {
        p = f(a,n,p0);
        d = fabs(p-p0);
        p0 = p;
        t--;
    }
    if ( fabs(p) > 1000000000000 )
    {
        cout << "Da thuc "; InHam(a,n) ; cout << " khong co diem bat dong tai lan can diem da du doan!";
    }
    else
    {
        cout << "Gia tri diem bat dong gan dung cua da thuc "; InHam(a,n); cout << " tai lan can diem da du doan la : ";
        int m = log10(1.0/k);
        cout << setprecision(m) << fixed << p;
    }
    return 0;
}



