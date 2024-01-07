#include <stdio.h>
#include <stdbool.h>

int main()
{
    int iNilaiCari = 146;
    int iJumKoin = 6;
    int koin[] = {0, 1, 5, 10, 25, 50, 100};
    int iMaxCari = 146;
    long long C[147] = {0}; // menggunakan long long untuk mengatasi potensi integer overflow

    for (int i = 0; i <= iJumKoin; ++i)
    {
        C[i] = 0;
    }

    C[0] = 1;

    for (int j = 1; j <= iJumKoin; ++j)
    {
        for (int n = koin[j]; n <= iMaxCari; ++n)
        {
            C[n] += C[n - koin[j]];
        }
    }

    bool bBisaDicari;
    long long iJumKemungkinan;

    if (C[iNilaiCari] > 0)
    {
        bBisaDicari = true;
        iJumKemungkinan = C[iNilaiCari];
    }
    else
    {
        bBisaDicari = false;
    }

    // Tampilkan hasil
    if (bBisaDicari)
    {
        printf("Nilai %d bisa dicari dan memiliki %lld kemungkinan.\n", iNilaiCari, iJumKemungkinan);
    }
    else
    {
        printf("Nilai %d tidak dapat dicari.\n", iNilaiCari);
    }

    return 0;
}
