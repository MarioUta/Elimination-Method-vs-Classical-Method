#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;
ifstream f("date.txt");
ofstream g("gauss_rez.txt");
ofstream o("matrice_gaus.txt");
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

void transformare_gaus(float a[100][100], int n, int &epsilon, bool &ok)
{
    for (int k = 0; k < n; k++)
    {
        ok = true;
        if (a[k][k] == 0)
        {
            ok = false;
            for (int i = k + 1; i < n; i++)
                if (a[i][k] != 0)
                {
                    ok = true;
                    for (int j = 0; j < n; j++)
                        swap(a[i][j], a[k][j]);
                    epsilon++;
                    break;
                }
        }
        if (ok == true)
        {
            for (int i = k + 1; i < n; i++)
            {
                float ratie = a[i][k] / a[k][k];
                // ratie = ceil(ratie * 100.0) / 100.0;
                for (int j = 0; j < n; j++)
                {
                    a[i][j] = a[i][j] - a[k][j] * ratie;
                    // a[i][j] = ceil(a[i][j] * 100.0) / 100.0;
                }
            }
        }
        else
            break;
    }
}

int main()
{
    int nm;
    f >> nm;
    float a[100][100];
    citire(a, nm);

    for (int n = 2; n <= nm; n++)
    {
        int epsilon = 0;
        bool ok = true;
        auto begin = std::chrono::high_resolution_clock::now();
        transformare_gaus(a, n, epsilon, ok);
        //afisare(a, n);
        if (ok == false)
            o << 0 << '\n';
        else
        {
            float p = 1;
            for (int i = 0; i < n; i++)
                p = p * a[i][i];
            o <<n<<" = "<< p * pow(-1, epsilon) << '\n';
            
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(begin - end).count();
        double tims = duration * 1e-9;
        g << tims << " ";
    }
    g.close();
    f.close();
    return 0;
}