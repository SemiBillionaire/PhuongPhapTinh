#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using namespace std;

bool batthuong = false;

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

void DuaVeDangDuongCheoBang1 (double** &a, double* &b,int n)
{
    for ( int i = 0; i < n; i++ )
    {
        if ( a[i][i] == 0 )
        {
            for ( int j = 0; j < n; j++ )
            {
                if ( a[j][i] != 0 )
                {
                    for ( int k = 0; k < n; k++ )
                    {
                        swap(a[i][k], a[j][k]);
                    }
                    swap(b[i], b[j]);
                    j = n;
                }
            }
            i = -1;
        }
    }
    for ( int i = 0; i < n; i++ )
    {
        double p = (1.0)*a[i][i];
        for ( int j= 0;j < n; j++ )
        {
            a[i][j] = (1.0)*a[i][j]/p;
        }
        b[i] = (1.0)*b[i]/p;
    }
}

int main ()
{
    cout << "     ===== Giai he phuong trinh Ax=b =====\n";
    cout << "Nhap so an : "; int n; cin >> n;
    double* x = new double [n];
    double** a = MaTranA(n);
    double* b = MaTranB(n);
    for ( int i = 0; i < n; i++ ) x[i]= b[i];
    DuaVeDangDuongCheoBang1(a,b,n);
    system("cls");
    cout << "Nhap so lan lap : ";
    int t; cin >> t;
    system("cls");
    for ( int i = 0; i < n; i++ )
            cout << setw(9-i/10) << "x" << i+1;
    cout << endl;
    while ( t-- )
    {
        for ( int i = 0; i < n; i++ )
        {
            double s = 0;
            for ( int j = 0; j < n; j++ )
            {
                if ( j != i )
                {
                    s += (1.0)*a[i][j]*x[j];
                }
            }
            x[i] = (1.0)*b[i] - s;
        }
        for ( int i = 0; i < n; i++ )
            cout << setw(10) << setprecision(4) << fixed << x[i];
        cout << endl;
    }
    for ( int i = 0; i < n; i++ )
    {
        double s=0;
        for ( int j = 0; j < n; j++ )
        {
            s += (1.0)*a[i][j]*x[j];
        }
        if ( fabs(s-b[i]) > 0.01 ) batthuong = true;
    }
    if ( batthuong ) cout << "Phat hien bat thuong!\n( Vo nghiem || So lan lap qua it || He ban dau chua thoa man dieu kien de nghiem hoi tu )\nChu y de phuong phap hieu qua thi he ban dau co cac phan tu nam tren duong cheo chinh la lon nhat \ntrong hang va cot chua no neu co the!";
    else
    {
        cout << "He phuong trinh co nghiem :\n";
        for ( int i = 0; i < n; i++ )
        {
            cout << "x" << i+1 << " = " << setprecision(3) << fixed << setw(7) << x[i] << endl;
        }
    }
    return 0;
}




