#include <sodium.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char message[512];

    /* Initialize Sodium */
    if (sodium_init() == -1) {
        printf("Error: Failure in sodium_init()\n");
        exit(1);
    } else {
        printf("sodium_init() successful\n");
    }

    /* Introduce the goal of the app */
    printf("Welcome to Paper Football!\n");
    printf("Paper Football encrypts your messages.\n\n");

    /* Read in the message */
    printf("Your message? ");
    if (fgets(message, sizeof(message), stdin) != NULL) {
        message[strcspn(message, "\n")] = '\0';
    };
    printf("message=\"%s\"\n\n", message);

    /* TODO: Produce a custom encryption key */
    unsigned char key[crypto_secretbox_KEYBYTES];
    printf("Encryption key: ");
    if (fgets(key, sizeof(key), stdin) != NULL) {
        key[strcspn(key, "\n")] = '\0';
     }
     printf("key=\"%s\"\n", key);

    /* TODO: Create the ciphertext */
    unsigned char nonce[crypto_secretbox_NONCEBYTES];
    //unsigned char key[crypto_secretbox_KEYBYTES];
    unsigned char ciphertext[(crypto_secretbox_MACBYTES + strlen(message))];
    randombytes_buf(nonce, sizeof(nonce));
         crypto_secretbox_easy(ciphertext, (const unsigned char *)message, strlen(message), nonce, key);
    //crypto_secretbox_easy(ciphertext, message, strlen(message), nonce, key);

    /* TODO: Print the ciphertext in hex */
    printf("Encrypted message: ");
    for (int i = 0; i < sizeof(ciphertext); i++) {
        printf("%x", ciphertext[i]);
    }
    printf("\n");
}
