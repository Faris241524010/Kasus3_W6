/* File        : antriBank.c */
/* Deskripsi   : body file untuk menangani antriBank */
/* Dibuat oleh : Faris Ichsan Alyawa */

#include "antriBank.h"
#include <stdio.h>

// Fungsi untuk menampilkan menu antrian bank
void menu() {
    Queue *antrian;
    create_Queue(&antrian);  // Menggunakan pointer pointer untuk memodifikasi antrian

    int pilihan;
    infotype nomor_antrian;

    while (1) {
        printf("\nPilih aksi:\n");
        printf("1. Ambil antrian\n");
        printf("2. Proses antrian\n");
        printf("3. Cetak antrian\n");
        printf("4. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                // Ambil nomor antrian berikutnya
                nomor_antrian = Ambil_AntrianBerikutnya(*antrian);
                enqueue(antrian, nomor_antrian);  // Menambahkan nomor antrian ke dalam antrian
                Cetak_Antrian(*antrian);  // Cetak antrian
                break;
            case 2:
                // Proses antrian (dequeue)
                dequeue(antrian, &nomor_antrian);  // Proses dequeue dan ambil nomor antrian
                Cetak_Antrian(*antrian);  // Cetak antrian
                break;
            case 3:
                // Cetak daftar antrian
                Cetak_Antrian(*antrian);  // Cetak antrian
                break;
            case 4:
                // Keluar dari program
                printf("Terima kasih! Program selesai.\n");
                return;
            default:
                printf("Pilihan tidak valid. Silakan pilih lagi.\n");
        }
    }
}

// Fungsi untuk mencetak semua nomor antrian
void Cetak_Antrian(Queue Q) {
    if (Q.front == NULL) {
        printf("Antrian kosong.\n");
        return;
    }
    
    address current = Q.front;
    printf("Daftar antrian: ");
    while (current != NULL) {
        printf("%d ", current->info);  // Menampilkan info yang berisi nomor antrian
        current = current->next;
    }
    printf("\n");
}

// Fungsi untuk mengambil nomor antrian berikutnya
infotype Ambil_AntrianBerikutnya(Queue Q) {
    static infotype nomor_antrian = 1;
    return nomor_antrian++;
}

