// the glory is for GOD

/*
    Name: Reynaldo Lázaro Aguilar Casajuana
    Author: rlac
    Date: 22/11/12 16:37
    Description: Fast Fourier Transform (FFT)
    Verified:	SPOJ 31. Fast Multiplication
                SPOJ 235. Very Fast Multiplication
                COJ  1760 - Triple Sums
                SPOJ 8372 - TSUM
*/

#include <bits/stdc++.h>

#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;

using namespace std;

typedef complex<double> point;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1 << 19;
point p1[MAXN], p2[MAXN];
int rev[MAXN];

#define tolong(x) ((ll)floor(x.real() + 0.5))	/* This macro is for arithmetic precision

/* Fast Fourier Transform */
/* n = size of a = a power of 2, theta = 2 * PI / n */
/* for inverse fft, theta = -2 * PI / n */
void fft (point a[], double theta, int n)
{
    for (int m = n; m >= 2; m >>= 1, theta *= 2)
    {
        int mh = m >> 1;

        for (int i = 0; i < mh; ++i)
        {
            point w = polar(1.0, i * theta);

            for (int j = i; j < n; j += m)
            {
                int k = j + mh;
                point x = a[j] - a[k];
                a[j] += a[k];
                a[k] = w * x;
            }
        }
    }

    for (int j = 1; j < n - 1; ++j)
    {
        int idx = rev[j];
        
        if (j < idx)
            swap(a[j], a[idx]);
    }
}

/* This function multiplies two given polynomials. A polynomial is represented as: p[i] * (x ^ i)	*/
void multiply (point p1[], point p2[], int N)
{
    for (int j = 1, i = 0; j < N - 1; ++j)
    {
        for (int k = N >> 1; k > (i ^= k); k >>= 1);
        
        rev[j] = i;
    }
    
    double theta = 2 * M_PI / N, inv = 1.0 / N;
    fft(p1, theta, N);
    fft(p2, theta, N);

    for (int i = 0; i < N; ++i)
        p1[i] *= p2[i];

    fft(p1, -theta, N);

    for (int i = 0; i < N; ++i)
        p1[i] *= inv;
        
    // at this point p1 is the resultant polynomial
}

int main ()
{
    //Improvement region
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}

