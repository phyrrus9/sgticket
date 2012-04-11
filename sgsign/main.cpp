/* SGSIGN by Ethan Laur (phyrrus9) <phyrrus9@gmail.com>
 * sgsign is a signing utility for use with sgrun on the iPhone
 * to prevent binary modifications to apps.  This program uses
 * two command line arguements, the file to sign, and the signing
 * key combination.  The key combination is a 3-digit 1-3 number
 * set used in encrypting the signature.  These can be 111 for
 * three passes of hash #1, 123 for one pass of each hash, or
 * even 000, 444, or any 1>value>3 to skip the extra signature
 * function and sign with one MD4 hash only.  If you comment out
 * the MD4 hash, the file will simply be copied to the signature
 * file instead of signing it. */
#include <stdio.h>
#include <string.h>
#include <CommonCrypto/CommonDigest.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string.h>
#include <sstream>
#include "../encryption.cpp"
using namespace std;
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
    char order[num_runs];
    strcpy(program,argv[1]);
    strcpy(ofile,program);
    strcat(ofile,".sig");
    for (int j=0;j<num_runs;j++)
       order[i] = argv[2][i];
    ifile.close();
    file.open(program,ios::binary);
    if (!file)
    {
        cout << "ERR 2: COULD NOT OPEN PROGRAM OR FILE" << endl;
        return 2;
    }
    while (!file.eof())
    {
        file >> tmp;
        strcat(ibuf,tmp);
    }
    cchash = CC_MD4(ibuf,strlen(ibuf),obuf);
   secure_key(order,cchash,obuf);
    encrypt_order(order);
    ifile.open(ofile,ios::binary);
    if (!ifile)
    {
        cout << "ERR 3: COULD NOT OPEN SIGNATURE" << endl;
        return 3;
    }
    ifile << order << endl;
    ifile << cchash;
    ifile.close();
    return 0;
}