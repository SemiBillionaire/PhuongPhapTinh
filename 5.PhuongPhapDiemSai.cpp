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

double* Derivative ( double* a, int Bac )
{
    double* b = new double [Bac];
    for ( int i = Bac; i >= 1; i-- )
    {
        b[i-1] = a[i]*i;
    }
    return b;
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
    cout << "Nhap 2 dau mut ban dau cua day cung : " << endl;
    double p0, p1;
    cout << "p0 : "; cin >> p0;
    cout << "p1 : "; cin >> p1;
    cout << "Nhap so lan lap : ";
    int t; cin >> t;
    cout << "Nhap dung sai : ";
    double k; cin >> k;
    system("cls");
    double p;
    double d = k+1;
    while (t>0 && d>k )
    {
        if (f(a,n,p1) - f(a,n,p0) == 0) break;
        p = p1 - (1.0)*(f(a,n,p1))*(p1-p0)/(f(a,n,p1)-f(a,n,p0));
        d = fabs(p-p1);
        if ( f(a,n,p)*f(a,n,p1) < 0 ) p0 = p1;
        p1 = p;
        t--;
    }
    if ( fabs(f(a,n,p)) > 0.1  || ( t>0 && d>k ) )
    {
        cout << "Da thuc "; InHam(a,n) ; cout << " khong co nghiem!";
    }
    else
    {
        cout << "Gia tri gan dung nghiem cua da thuc "; InHam(a,n); cout << " la : ";
        int m = log10(1.0/k);
        cout << setprecision(m) << fixed << p;
    }
    return 0;
}




