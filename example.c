#include <sodium.h>

#define MESSAGE ((const unsigned char *) "test")
#define MESSAGE_LEN 4
#define CIPHERTEXT_LEN (crypto_secretbox_MACBYTES + MESSAGE_LEN)
#define HEXTEXT_LEN (CIPHERTEXT_LEN * 2 + 1)

int main() {
    unsigned char nonce[crypto_secretbox_NONCEBYTES];
    unsigned char key[crypto_secretbox_KEYBYTES];
    unsigned char ciphertext[CIPHERTEXT_LEN];

    randombytes_buf(nonce, sizeof nonce);
    randombytes_buf(key, sizeof key);
    crypto_secretbox_easy(ciphertext, MESSAGE, MESSAGE_LEN, nonce, key);

    unsigned char hextext[HEXTEXT_LEN];
    // size_t b = HEXTEXT_LEN;
    sodium_bin2hex((char*)hextext, 512, ciphertext, CIPHERTEXT_LEN);
    printf("crypto_secretbox_MACBYTES=%u\n", crypto_secretbox_MACBYTES);
    printf("%lu::%s\n", sizeof(ciphertext), hextext);

    // unsigned char decrypted[MESSAGE_LEN];
    // if (crypto_secretbox_open_easy(decrypted, ciphertext, CIPHERTEXT_LEN, nonce, key) != 0) {
    //     /* message forged! */
    // }
}
