#include <iostream>
#include <vector>

using namespace std;
void encrypt(uint32_t plainText[2], uint32_t key[4]){
    uint32_t L = plainText[0];
    uint32_t R = plainText[1];
    uint32_t delta = 0x9E3779B9;
    uint32_t sum = 0;
    for(int i = 0; i < 32; i++){
        sum = sum + delta;
        L = L + (((R<<4)+key[0])^(R+sum)^((R>>5)+key[1]));
        R = R + (((L<<4)+key[2])^(L+sum)^((L>>5)+key[3]));
    }
    plainText[0] = L;
    plainText[1] = R;
}
void decrypt(uint32_t cipherText[2], uint32_t key[4]){
    uint32_t iv[2] = {0x11223344, 0x55667788};
    uint32_t L = cipherText[0];
    uint32_t R = cipherText[1];
    uint32_t delta = 0x9E3779B9;
    uint32_t sum = delta << 5;
    for(int i = 0; i < 32; i++){
        R = R - (((L << 4) + key[2]) ^ (L + sum) ^ ((L >> 5) + key[3]));
        L = L - (((R << 4) + key[0]) ^ (R + sum) ^ ((R >> 5) + key[1]));
        sum = sum - delta;
    }
    cipherText[0] = L ^ iv[0];
    cipherText[1] = R ^ iv[1];
    
}

int main(){
    uint32_t iv[2] = {0x11223344, 0x55667788};
    uint32_t blocks[] = {0x01234567, 0x89abcdef}; // (L, R)
    uint32_t keys[4] = {0xA56BABCD, 0x00000000, 0xFFFFFFFF, 0xabcdef01}; // k[0], k[1], k[2], k[3]
    
    
    cout << hex << blocks[0] << ", " << hex << blocks[1] << endl;

    blocks[0] = blocks[0] ^ iv[0];
    blocks[1] = blocks[1] ^ iv[1];
    encrypt(blocks, keys);
    cout << hex << blocks[0] << ", " << hex << blocks[1] << endl;
    decrypt(blocks, keys);
    cout << hex << blocks[0] << ", " << hex << blocks[1] << endl;
    return 0;
}