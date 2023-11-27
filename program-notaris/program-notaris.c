#include <stdio.h>

// fungsi untuk menghitung total honor berdasarkan peraturan
int calculateTotalHonor(int harga_rumah, int nilai_sosiologis)
{
    if (harga_rumah <= 100000000)
    { // <= 100 juta
        return (harga_rumah * 0.025) + nilai_sosiologis;
    }
    else if (harga_rumah > 100000000 && harga_rumah <= 1000000000)
    { // > 100juta && <= 1 milyar
        return (harga_rumah * 0.015) + nilai_sosiologis;
    }
    else if (harga_rumah > 1000000000)
    { // > 1 milyar
        return (harga_rumah * 0.010) + nilai_sosiologis;
    }

    return 0;
}

// fungsi untuk validasi input
int validateInput(int harga_rumah, int nilai_sosiologis)
{
    if (harga_rumah < 0 || nilai_sosiologis < 0)
    {
        printf("Input tidak valid. Masukkan nilai yang benar.");
        return 1;
    }

    if (nilai_sosiologis > 5000000)
    {
        printf("Nilai sosiologis lebih dari 5 juta. Keluar dari program.");
        return 1;
    }

    return 0;
}

int main()
{
    int harga_rumah;
    int nilai_sosiologis;
    int total_honor;

    printf("Masukkan Harga Objek Rumah: ");
    scanf("%d", &harga_rumah);

    printf("Masukkan Nilai Sosiologis (max 5 Juta): ");
    scanf("%d", &nilai_sosiologis);

    printf("\n");

    if (validateInput(harga_rumah, nilai_sosiologis) != 0)
    {
        return 1;
    }

    total_honor = calculateTotalHonor(harga_rumah, nilai_sosiologis);

    printf("Total Honor: Rp %d", total_honor);

    return 0;
}
