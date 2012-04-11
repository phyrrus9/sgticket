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
void encrypt_order(char[]);
int main(int argc,char**argv)
{
    if (argc < 3)
        exit(EXIT_FAILURE);
    ifstream file;
    ofstream ifile;
    char ibuf[500000];
    char ofile[50];
    char tmp[500000];
    char program[20];
    unsigned char obuf[5000];
    unsigned char * cchash;
    char order[] = {argv[2][0],argv[2][1],argv[2][2]};
    strcpy(program,argv[1]);
    strcpy(ofile,program);
    strcat(ofile,".sig");
    ifile.close();
    file.open(program,ios::binary);
    while (!file.eof())
    {
        file >> tmp;
        strcat(ibuf,tmp);
    }
    cchash = CC_MD4(ibuf,strlen(ibuf),obuf);
    for (int i = 0; i < 4; i++)
    {
        if (order[i] == '1')
            cchash = /*your function*/(cchash, strlen((char*)cchash), obuf);
        if (order[i] == '2')
            cchash = /*your function*/(cchash,strlen((char*)cchash),obuf);
        if (order[i] == '3')
            cchash = /*your function*/(cchash,strlen((char*)cchash),obuf);
    }
    encrypt_order(order);
    ifile.open(ofile,ios::binary);
    ifile << order << endl;
    ifile << cchash;
    ifile.close();
    return 0;
}
void encrypt_order(char order[])
{
    //your decryption goes here
}