#include <stdio.h>
#include <stdbool.h>

int main()
{
    int iNilaiCari = 146;
    int iJumKoin = 6;
    int koin[] = {0, 1, 5, 10, 25, 50, 100};
    int iMaxCari = 146;
    int C[147] = {0}; // Inisialisasi array C dengan 0

    for (int i = 1; i <= iMaxCari; ++i)
    {
        C[i] = 0;
    }

    for (int j = 1; j <= iJumKoin; ++j)
    {
        C[koin[j]] = 1;
    }

    for (int n = 1; n <= iMaxCari; ++n)
    {
        for (int j = 1; j <= iJumKoin; ++j)
        {
            if ((n - koin[j]) >= 0)
            {
                C[n] = C[n] + C[n - koin[j]];
            }
        }
    }

    bool bBisaDicari;
    int iJumKemungkinan;

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
        printf("Nilai %d bisa dicari dan memiliki %d kemungkinan.\n", iNilaiCari, iJumKemungkinan);
    }
    else
    {
        printf("Nilai %d tidak dapat dicari.\n", iNilaiCari);
    }

    return 0;
}
