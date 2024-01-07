#include <stdio.h>

// Fungsi untuk mencari nilai maksimum antara dua bilangan
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Fungsi untuk menyelesaikan permasalahan knapsack
int knapsack(int values[], int weights[], int capacity, int n)
{
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity];
}

int main()
{
    // Data
    int values[] = {45000000, 35000000, 25000000, 40000000, 55000000, 35000000, 75000000};
    int weights[] = {7, 5, 2, 5, 10, 3, 6};
    int capacity = 29;
    int n = sizeof(values) / sizeof(values[0]);

    // Memanggil fungsi knapsack
    int result = knapsack(values, weights, capacity, n);

    // Menampilkan hasil
    printf("Keuntungan maksimum yang dapat diperoleh: %d\n", result);

    return 0;
}
