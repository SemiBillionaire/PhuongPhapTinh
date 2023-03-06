#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using namespace std;

bool vosonghiem = false;
bool vonghiem = false;

double** MaTranA ( int n )
{
    cout << "Nhap ma tran A : \n";
    double** a;
    a = (double**)malloc(sizeof(double*)*n);
    for ( int i = 0; i < n; i++ )
    {
        a[i] = (double*)malloc(sizeof(double)*n);
    }
    for ( int i = 0 ;i < n; i++ )
    {
        for ( int j = 0; j < n; j++ )
            cin >> a[i][j];
    }
    return a;
}

double* MaTranB (int n)
{
    cout << "Nhap ma tran b : \n";
    double* b = new double [n];
    for ( int i = 0; i < n; i++ )
    {
        cin >> b[i];
    }
    return b;
}

double* GiaiHeTamGiacTren (double**a, double* b, int n)
{
    double* x = new double [n];
    for ( int i = 0; i < n; i++ ) x[i] = 0;
    for ( int i = n-1; i >= 0; i-- )
    {
        double s = 0;
        for ( int j = n-1; j > i; j-- )
        {
            s += a[i][j]*x[j];
        }
        if ( a[i][i] == 0 )
        {
            if (b[i] - s ==0)
            {
                vosonghiem = true;
            } else
            {
                vonghiem = true;
            }
            return x;
        }
        else
        {
            x[i] = (b[i] - (1.0)*s)/a[i][i];
        }
    }
    return x;
}

int main ()
{
    cout << "     ===== Giai he phuong trinh Ax=b =====\n";
    cout << "Nhap so an : "; int n; cin >> n;
    double* x = new double [n];
    double** a = MaTranA(n);
    double* b = MaTranB(n);
    for ( int k = 0; k < n-1; k++ )
    {
        if ( a[k][k] == 0 )
        {
            int tmp;
            for ( int i = 0; i < n; i++ )
            {
                if ( a[i][k] != 0 )
                {
                    tmp = i; i = n;
                }
            }
            for ( int j = 0; j < n; j++ )
            {
                swap(a[k][j], a[tmp][j]);
            }
            swap(b[k], b[tmp]);
        }
        for ( int i = k+1; i < n; i++ )
        {
            double q = (1.0)*a[i][k]/a[k][k];
            for ( int j = k; j < n; j++ )
            {
                a[i][j] -= (1.0)*a[k][j]*q;
            }
            b[i] -= (1.0)*b[k]*q;
        }
    }
    x = GiaiHeTamGiacTren(a,b,n);
    system("cls");
    if ( vonghiem ) cout << "He phuong trinh vo nghiem!";
    else if ( vosonghiem ) cout << "He phuong trinh vo so nghiem!";
    else
    {
        cout << "He phuong trinh co nghiem duy nhat :\n";
        for ( int i = 0; i < n; i++ )
        {
            cout << "x" << i+1 << " = " << setprecision(3) << fixed << setw(7) << x[i] << endl;
        }
    }
    return 0;
}




