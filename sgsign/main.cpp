#include <stdio.h>
#include <string.h>
#include <CommonCrypto/CommonDigest.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;

int main(int argc,char**argv)
{
    if (argc < 2)
        exit(EXIT_FAILURE);
    cout << argv[1] << endl;
    ifstream file;
    ofstream ifile;
    char ibuf[500000];
    char ofile[50];
    char tmp[500000];
    char program[20];
    unsigned char obuf[5000];
    unsigned char * cchash;
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
    ifile.open(ofile,ios::binary);
    ifile << cchash;
    ifile.close();
    return 0;
}