#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>
using namespace std;
ifstream f("date.txt");
ofstream g("clasic_rez.txt");
ofstream o("matrice_clasic.txt");
void citire(float a[100][100], int n)
{

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            f >> a[i][j];
}

void afisare(float a[100][100], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << '\n';
    }
}

float det(int n, float mat[100][100])
{
    float d = 0;
    float submat[100][100];
    if (n == 2)
        return ((mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
    else
    {
        for (int c = 0; c < n; c++)
        {
            int subi = 0;
            for (int i = 1; i < n; i++)
            {
                int subj = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == c)
                        continue;
                    submat[subi][subj] = mat[i][j];
                    subj++;
                }
                subi++;
            }
            d = d + (pow(-1, c) * mat[0][c] * det(n - 1, submat));
        }
    }
    return d;
}

int main()
{
    int nm;
    f >> nm;
    float a[100][100];
    citire(a, nm);
    for (int n = 2; n <= nm; n++)
    {
        float detr;
        auto begin = std::chrono::high_resolution_clock::now();
        detr = det(n, a);
        o << n << " = " << detr;
        o << '\n';
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        float tims = elapsed.count() * 1e-9;
        g << tims << " ";
    }
    o.close();
    g.close();
    f.close();
    return 0;
}
