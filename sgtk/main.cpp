/* SGTK (sgrun) version 1 by Ethan Laur (phyrrus9) <phyrrus9@gmail.com>
 * This program will run a signed binary files, passing any parameters
 * given from the command line to the program.  The binary file this 
 * program launches is NOT secure unless it makes sure that argv[0]
 * is "/bin/sgrun" and nothing else! It is signed using sgsign which
 * will be compiled for mac os X ONLY!  It uses encryption.cpp (blank)
 * for the decryption function and hash generator. If the signature has
 * been invalidated or incorrect, the program will send the error code 2
 * meaning BAD SIGNATURE */
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
    if (!file.good())
    {
        cout << "ERR 4: FILE NOT GOOD" << endl;
        return 4;
    }
    if (!file)
    {
        cout << "ERR 3: COULD NOT OPEN PROGRAM OR FILE" << endl;
        return 3;
    }
        while (!file.eof())
        {
            file >> tmp;
            strcat(ibuf,tmp);
        }
        cchash = CC_MD4(ibuf,strlen(ibuf),obuf);
    decrypt_order(order);
	secure_key(order,cchash,obuf); //complete the security
        file.close();
        ostringstream s1cchash,s2cchash;
        s1cchash << cchash;
        s2cchash << u_cchash;
        if (s1cchash.str() == s2cchash.str())
        {
            cout << "SIG: OK" << endl;
            string command;
            for (int i = 1; i < argc; i++)
            {
                command += argv[i];
                command += " ";
            }
            system(command.c_str());
        }
        else
        {
            cout << "ERR 2: INVALID SIGNATURE" << endl;
            return 2;
        }
    return 0;
}