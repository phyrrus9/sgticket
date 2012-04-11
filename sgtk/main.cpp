#include <stdio.h>
#include <string.h>
#include <CommonCrypto/CommonDigest.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string.h>
#include <sstream>
#define num_runs 3
using namespace std;
void decrypt_order(char[]);
int main(int argc,char**argv)
{
    if (argc < 2)
        exit(EXIT_FAILURE);
    ifstream file;
    ifstream ifile;
    char ibuf[500000];
    char ofile[50];
    char tmp[500000];
    char program[20];
    unsigned char obuf[5000];
    unsigned char * cchash;
    char order[100];
    char u_cchash[500];
    strcpy(program,argv[1]);
        strcpy(ofile,program);
        strcat(ofile,".sig");
    ifile.open(ofile,ios::binary);
    ifile >> order;
        ifile >> u_cchash;
        ifile.close();
        file.open(program,ios::binary);
        while (!file.eof())
        {
            file >> tmp;
            strcat(ibuf,tmp);
        }
        cchash = CC_MD4(ibuf,strlen(ibuf),obuf);
    decrypt_order(order);
    for (int i = 0; i < 4; i++)
    {
        if (order[i] == '1')
            cchash = /*your function*/(cchash, strlen((char*)cchash), obuf);
        if (order[i] == '2')
            cchash = /*your function*/(cchash,strlen((char*)cchash),obuf);
        if (order[i] == '3')
            cchash = /*your function*/(cchash,strlen((char*)cchash),obuf);
    }
        file.close();
        ostringstream s1cchash,s2cchash;
        s1cchash << cchash;
        s2cchash << u_cchash;
        if (s1cchash.str() == s2cchash.str())
        {
            cout << "SIG: OK" << endl;
            system(program);
        }
        else
        {
            cout << "ERR 2: INVALID SIGNATURE" << endl;
            return 2;
        }
    return 0;
}
void decrypt_order(char order[])
{
    //your decryption code here
}