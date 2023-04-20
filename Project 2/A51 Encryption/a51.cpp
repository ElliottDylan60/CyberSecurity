#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int binaryDataX = 0b1010101010101010101; // 19 bits
    int binaryDataY = 0b1100110011001100110011; // 22 bits
    int binaryDataZ = 0b11100001111000011110000; // 23 bits

    bitset<19> LFSR_1(binaryDataX);
    bitset<22> LFSR_2(binaryDataY);
    bitset<23> LFSR_3(binaryDataZ);


    cout << "Keystream:" << endl;

    for(int i = 0; i < 32; i++){
        // Clocking bits
        bool bit_1 = LFSR_1[10];
        bool bit_2 = LFSR_2[11];
        bool bit_3 = LFSR_3[12];

        // Majority
        bool maj = (bit_1 and bit_2) ^ (bit_1 and bit_3) ^ (bit_2 and bit_3);

        if (bit_1 == maj){
            // Register steps
            bool newBit = LFSR_1[5] ^ LFSR_1[2] ^ LFSR_1[1] ^ LFSR_1[0]; // Tapped Bits 13, 16, 17, 18
            LFSR_1 = LFSR_1 >> 1; // right shift register
            if(newBit){
                LFSR_1.set(18, 1);
            }
        }
        if (bit_2 == maj){
            // Register steps
            bool newBit = LFSR_2[1] ^ LFSR_2[0]; // Tapped bits 20, 21
            LFSR_2 = LFSR_2 >> 1; // right shift register
            if(newBit){
                LFSR_2.set(21, 1);
            }
        }
        if (bit_3 == maj){
            // Register steps
            bool newBit = LFSR_3[15] ^ LFSR_3[2] ^ LFSR_3[1] ^ LFSR_3[0];// Tapped bits 7, 20, 21, 22
            LFSR_3 = LFSR_3 >> 1; // right shift register
            if(newBit){
                LFSR_3.set(22, 1);
            }
        }
        bool keyStream_i = LFSR_1[0] ^ LFSR_2[0] ^ LFSR_3[0];
        cout << keyStream_i;

    } 
    
    cout << "\nRegisters:" << endl;;
    cout << "LFSR1: " << LFSR_1 << endl;
    cout << "LFSR2: " << LFSR_2 << endl;
    cout << "LFSR3: " << LFSR_3 << endl;
    return 0;
}