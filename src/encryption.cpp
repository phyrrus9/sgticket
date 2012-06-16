#include <CommonCrypto/CommonDigest.h>
#include <cstring>
#define num_runs 7
void secure_key(char order[],unsigned char * cchash, unsigned char obuf[])
{
    
    for (int i = 0; i < num_runs; i++)
    {
        if (order[i] == '1')
            cchash = CC_MD4(cchash, strlen((char*)cchash), obuf);
        if (order[i] == '2')
            cchash = CC_MD2(cchash,strlen((char*)cchash),obuf);
        if (order[i] == '3')
            cchash = CC_MD5(cchash,strlen((char*)cchash),obuf);
        if (order[i] == '4')
            cchash = CC_MD2(cchash, strlen((char*)cchash), obuf);
        if (order[i] == '5')
            cchash = CC_MD4(cchash,strlen((char*)cchash),obuf);
    }
}
void encrypt_order(char order[])
{
   /*your encryption*/
}
void decrypt_order(char order[])
{
    /*your decryption*/
}