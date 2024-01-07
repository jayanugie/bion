#include <stdio.h>

int main()
{
    int iNilaiCari = 146;
    int iMaxCari = 146;
    int iJumKoin = 6;
    int koin[] = {0, 1, 5, 10, 25, 50, 100};
    int C[147];

    for (int i = 1; i <= iMaxCari; i++)
    {
        C[i] = 0;
    }

    for (int j = 1; j <= iJumKoin; j++)
    {
        C[koin[j]] = 1;
    }

    for (int n = 1; n <= iMaxCari; n++)
    {
        for (int j = 1; j <= iJumKoin; j++)
        {
            if ((n - koin[j]) >= 1 && C[n - koin[j]] > 0)
            {
                if (C[n] == 0 || C[n] > (1 + C[n - koin[j]]))
                {
                    C[n] = 1 + C[n - koin[j]];
                }
            }
        }
    }

    int bBisaDicari = (C[iNilaiCari] > 0);
    int iJumKoinMinimal;

    if (bBisaDicari)
    {
        printf("Nilai %d bisa dicapai dengan jumlah koin minimal: %d\n", iNilaiCari, C[iNilaiCari]);
    }
    else
    {
        printf("Nilai %d tidak bisa dicapai.\n", iNilaiCari);
    }

    return 0;
}
