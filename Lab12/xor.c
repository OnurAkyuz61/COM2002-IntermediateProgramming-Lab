#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1000
#define MAX_KEY_LENGTH 100

// Mesajı XOR anahtarı ile şifreleyen fonksiyon
void xor_encrypt(char *message, const char *key) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    int i;
    
    for (i = 0; i < message_len; i++) {
        // Mesajın her karakterini anahtar ile XOR işlemine tabi tutma
        // Anahtarın sonuna gelince başa dön (döngüsel kullanım)
        message[i] = message[i] ^ key[i % key_len];
    }
}

int main(int argc, char *argv[]) {
    char message[MAX_MESSAGE_LENGTH] = {0};
    char key[MAX_KEY_LENGTH] = {0};
    char input_filename[100] = {0};
    char output_filename[100] = {0};
    FILE *input_file = NULL;
    FILE *output_file = NULL;
    int input_choice, output_choice;
    int char_count = 0;
    int c;
    
    printf("XOR Sifreleme Programi\n");
    printf("=====================\n\n");
    
    // Gizli anahtarı al
    printf("Gizli anahtari giriniz: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key[strcspn(key, "\n")] = 0; // Sonundaki yeni satır karakterini kaldır
    
    if (strlen(key) == 0) {
        printf("Hata: Anahtar bos olamaz!\n");
        return 1;
    }
    
    // Giriş seçeneğini al
    printf("\nGiris secenegi:\n");
    printf("1. Klavyeden mesaj gir\n");
    printf("2. Dosyadan oku\n");
    printf("Seciminiz (1-2): ");
    scanf("%d", &input_choice);
    getchar(); // Yeni satır karakterini tüket
    
    // Giriş seçeneğine göre işlem yap
    if (input_choice == 1) {
        // Klavyeden mesaj al
        printf("\nMesaji giriniz (bitirmek icin Enter'a basin):\n");
        fgets(message, MAX_MESSAGE_LENGTH, stdin);
        message[strcspn(message, "\n")] = 0; // Sonundaki yeni satır karakterini kaldır
    } else if (input_choice == 2) {
        // Dosyadan oku
        printf("\nOkunacak dosya adini giriniz: ");
        fgets(input_filename, sizeof(input_filename), stdin);
        input_filename[strcspn(input_filename, "\n")] = 0; // Sonundaki yeni satır karakterini kaldır
        
        input_file = fopen(input_filename, "r");
        if (input_file == NULL) {
            printf("Hata: '%s' dosyasi acilamadi!\n", input_filename);
            return 1;
        }
        
        // Dosyadan karakterleri oku
        while ((c = fgetc(input_file)) != EOF && char_count < MAX_MESSAGE_LENGTH - 1) {
            message[char_count++] = (char)c;
        }
        message[char_count] = '\0';
        
        fclose(input_file);
        printf("'%s' dosyasindan %d karakter okundu.\n", input_filename, char_count);
    } else {
        printf("Hata: Gecersiz secim!\n");
        return 1;
    }
    
    // Mesajı şifrele
    xor_encrypt(message, key);
    
    // Çıkış seçeneğini al
    printf("\nCikis secenegi:\n");
    printf("1. Ekranda goster\n");
    printf("2. Dosyaya kaydet\n");
    printf("Seciminiz (1-2): ");
    scanf("%d", &output_choice);
    getchar(); // Yeni satır karakterini tüket
    
    // Çıkış seçeneğine göre işlem yap
    if (output_choice == 1) {
        // Ekranda göster
        printf("\nSifreli mesaj:\n");
        for (int i = 0; i < char_count || (input_choice == 1 && i < strlen(message)); i++) {
            putchar(message[i]);
        }
        printf("\n");
    } else if (output_choice == 2) {
        // Dosyaya kaydet
        printf("\nKaydedilecek dosya adini giriniz: ");
        fgets(output_filename, sizeof(output_filename), stdin);
        output_filename[strcspn(output_filename, "\n")] = 0; // Sonundaki yeni satır karakterini kaldır
        
        output_file = fopen(output_filename, "w");
        if (output_file == NULL) {
            printf("Hata: '%s' dosyasi olusturulamadi!\n", output_filename);
            return 1;
        }
        
        // Şifreli mesajı dosyaya yaz
        int len = (input_choice == 1) ? strlen(message) : char_count;
        fwrite(message, sizeof(char), len, output_file);
        
        fclose(output_file);
        printf("Sifreli mesaj '%s' dosyasina kaydedildi.\n", output_filename);
    } else {
        printf("Hata: Gecersiz secim!\n");
        return 1;
    }
    
    printf("\nProgram basariyla tamamlandi.\n");
    return 0;
}
