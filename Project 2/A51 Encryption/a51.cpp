#include <iostream>
#include <bitset>

using namespace std;

int main(){
    string binaryDataX = "1010101010101010101"; // 19 bits
    string binaryDataY = "1100110011001100110011"; // 22 bits
    string binaryDataZ = "11100001111000011110000"; // 23 bits

    unsigned int valueX = bitset<19>(binaryDataX).to_ulong();
    unsigned int registerValueX = 0;
    registerValueX |= valueX;

    unsigned int valueY = bitset<22>(binaryDataY).to_ulong();
    unsigned int registerValueY = 0;
    registerValueY |= valueY;

    unsigned int valueZ = bitset<23>(binaryDataZ).to_ulong();
    unsigned int registerValueZ = 0;
    registerValueZ |= valueZ;

    bitset<19> LFSR_1(registerValueX);
    bitset<22> LFSR_2(registerValueY);
    bitset<23> LFSR_3(registerValueZ);
    for(int i = 0; i < 32; i++){
        
// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22
// 22, 21, 20, 19 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
        bool bit_1 = LFSR_1[10];
        bool bit_2 = LFSR_2[11];
        bool bit_3 = LFSR_3[12];
        
        bool maj = (bit_1 and bit_2) ^ (bit_1 and bit_3) ^ (bit_2 and bit_3);

        if (bit_1 == maj){
            //bool newBit = LFSR_1[13] ^ LFSR_1[16] ^ LFSR_1[17] ^ LFSR_1[18];
            bool newBit = LFSR_1[5] ^ LFSR_1[2] ^ LFSR_1[1] ^ LFSR_1[0];
            LFSR_1 = LFSR_1 >> 1; // right shift register
            //LFSR_1[0] = LFSR_1[13] ^ LFSR_1[16] ^ LFSR_1[17] ^ LFSR_1[18];
            if(newBit){
                LFSR_1.set(18, 1);
            }
        }
        if (bit_2 == maj){
            //bool newBit = LFSR_2[20] ^ LFSR_2[21];
            bool newBit = LFSR_2[1] ^ LFSR_2[0];
            LFSR_2 = LFSR_2 >> 1; // right shift register
            //LFSR_2[0] = LFSR_2[20] ^ LFSR_2[21];
            if(newBit){
                LFSR_2.set(21, 1);
            }
        }
        if (bit_3 == maj){
            //bool newBit = LFSR_3[20] ^ LFSR_3[21] ^ LFSR_3[22];
            bool newBit = LFSR_3[15] ^ LFSR_3[2] ^ LFSR_3[1] ^ LFSR_3[0];
            LFSR_3 = LFSR_3 >> 1; // right shift register
            if(newBit){
                LFSR_3.set(22, 1);
            }
        }

        //cout << LFSR_1 << endl;
        //cout << LFSR_2 << endl;
        //cout << LFSR_3 << endl;

        bool keyStream_i = LFSR_1[0] ^ LFSR_2[0] ^ LFSR_3[0];
        //cout << "Keystream bit = " << LFSR_1[0] << " ^ " << LFSR_2[0] << " ^ " << LFSR_3[0] << " = " << keyStream_i << endl;
        cout << keyStream_i;

    }
    
    cout << endl;
    cout << LFSR_1 << endl;
    cout << LFSR_2 << endl;
    cout << LFSR_3 << endl;
    return 0;
}