#include <stdio.h>
#include <string.h>

#define ALPHABET_LENGTH 26

char* encrypt(char* plaintext, char* key);
char* decrypt(char* ciphertext, char* key);

int main() {
    char plaintext[100], key[ALPHABET_LENGTH + 1], ciphertext[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the key (a permutation of the alphabet): ");
    fgets(key, sizeof(key), stdin);

    char* encrypted_text = encrypt(plaintext, key);
    printf("Encrypted text: %s\n", encrypted_text);

    char* decrypted_text = decrypt(encrypted_text, key);
    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}

char* encrypt(char* plaintext, char* key) {
    int i;
    char* ciphertext = strdup(plaintext);

    for (i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = key[plaintext[i] - 'a'];
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = key[plaintext[i] - 'A'] - 'a' + 'A';
        }
    }

    return ciphertext;
}

char* decrypt(char* ciphertext, char* key) {
    int i, j;
    char* plaintext = strdup(ciphertext);

    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            for (j = 0; j < ALPHABET_LENGTH; j++) {
                if (key[j] == ciphertext[i]) {
                    plaintext[i] = 'a' + j;
                    break;
                }
            }
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            for (j = 0; j < ALPHABET_LENGTH; j++) {
                if (key[j] == ciphertext[i] + 'a' - 'A') {
                    plaintext[i] = 'A' + j;
                    break;
                }
            }
        }
    }

}
