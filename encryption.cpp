#define num_runs 3
void secure_key(char order[],unsigned char * cchash, unsigned char obuf[])
{
    for (int i = 0; i < num_runs; i++)
    {
        if (order[i] == '1')
            cchash = /*your hash*/(cchash, strlen((char*)cchash), obuf);
        if (order[i] == '2')
            cchash = /*your hash*/(cchash,strlen((char*)cchash),obuf);
        if (order[i] == '3')
            cchash = /*your hash*/(cchash,strlen((char*)cchash),obuf);
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