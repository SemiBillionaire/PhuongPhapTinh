#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using namespace std;

bool vosonghiem = false;
bool vonghiem = false;

double** TaoTamGiacTren (int n)
{
    double** u;
    u = (double**)malloc(sizeof(double*)*n);
    for ( int i = 0; i < n; i++ )
    {
        u[i] = (double*)malloc(sizeof(double)*n);
    }
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < n; j++ )
        {
            if (i > j) u[i][j] = 0;
            else u[i][j] = 1;
        }
    }
    return u;
}

double** TaoTamGiacDuoi (int n)
{
    double** l;
    l = (double**)malloc(sizeof(double*)*n);
    for ( int i = 0; i < n; i++ )
    {
        l[i] = (double*)malloc(sizeof(double)*n);
    }
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < n; j++ )
        {
            if (i < j) l[i][j] = 0;
            else l[i][j] = 1;
        }
    }
    return l;
}

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
        if ( a[i][i] == 0 )
        {
            if (b[i]==0)
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
            double s = 0;
            for ( int j = n-1; j > i; j-- )
            {
                s += a[i][j]*x[j];
            }
            x[i] = (b[i] - (1.0)*s)/a[i][i];
        }
    }
    return x;
}

double* GiaiHeTamGiacDuoi (double**a, double* b, int n)
{
    double* x = new double [n];
    for ( int i = 0; i < n; i++ ) x[i] = 0;
    for ( int i = 0; i < n; i++ )
    {
        double s = 0;
        for ( int j = 0; j < i; j++ )
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
    double* y = new double [n];
    double** a = MaTranA(n);
    double* b = MaTranB(n);
    double** l = TaoTamGiacDuoi(n);
    double** u = TaoTamGiacTren(n);
    for ( int i = 0;i < n; i++ )
    {
        for ( int j = 0; j <= i; j++ )
        {
            double s = 0;
            for ( int k = 0; k < j; k++ )
            {
                s += l[i][k]*u[k][j];
            }
            l[i][j] = a[i][j] - s;
        }
        for ( int j = i+1; j < n; j++ )
        {
            if ( l[i][i] != 0 )
            {
                double s = 0;
                for ( int k = 0; k < i; k++ )
                {
                    s += (1.0)*l[i][k]*u[k][j];
                }
                u[i][j] = ((1.0)*a[i][j]-s)/l[i][i];
            }
        }
    }
    y = GiaiHeTamGiacDuoi(l,b,n);
    if ( !vonghiem && !vosonghiem )
    {
        x = GiaiHeTamGiacTren(u,y,n);
    }
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




