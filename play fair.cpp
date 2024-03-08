#include <stdio.h>
#include <string.h>


void prepareKeyMatrix(char key[], char keyMatrix[5][5]) {
    int i, j, k, flag = 0;
    int keyMap[26] = {0};

    for (i = 0; i < strlen(key); i++) {
        if (key[i] != 'j') {
            if (keyMap[key[i] - 97] == 0) {
                keyMap[key[i] - 97] = 1;
                keyMatrix[flag / 5][flag % 5] = key[i];
                flag++;
            }
        }
    }

    for (k = 0; k < 26; k++) {
        if (k != 9) {
            if (keyMap[k] == 0) {
                keyMatrix[flag / 5][flag % 5] = (char)(k + 97);
                flag++;
            }
        }
    }
}


void encryptPlayfairCipher(char input[], char keyMatrix[5][5]) {
    int i, j;
    char a, b;
    for (i = 0; i < strlen(input); i += 2) {
        a = input[i];
        b = input[i + 1];
        int row1, row2, col1, col2;

        
        for (j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (keyMatrix[j][k] == a) {
                    row1 = j;
                    col1 = k;
                }
                if (keyMatrix[j][k] == b) {
                    row2 = j;
                    col2 = k;
                }
            }
        }

        
        if (row1 == row2) {
            printf("%c%c", keyMatrix[row1][(col1 + 1) % 5], keyMatrix[row2][(col2 + 1) % 5]);
        }
        
        else if (col1 == col2) {
            printf("%c%c", keyMatrix[(row1 + 1) % 5][col1], keyMatrix[(row2 + 1) % 5][col2]);
        }
        
		        else {
            printf("%c%c", keyMatrix[row1][col2], keyMatrix[row2][col1]);
        }
    }
}

int main() {
    char key[100], input[100];
    char keyMatrix[5][5];
    
    printf("Enter the key (without spaces and 'j' replaced with 'i'): ");
    scanf("%s", key);
    
    printf("Enter the input text (without spaces and 'j' replaced with 'i'): ");
    scanf("%s", input);

    
    prepareKeyMatrix(key, keyMatrix);

    printf("Encrypted text: ");
    encryptPlayfairCipher(input, keyMatrix);

    return 0;
}
