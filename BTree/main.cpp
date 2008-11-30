#include <iostream>
#include <fstream>
using namespace std;

typedef struct registro
{
    char nome[40];
    char RG[10];
    char CPF[12];
    char RA[7];
    char cidade[20];
    char rua[35];
    char numero[5];
    char CEP[9];
    char UF[3];
    char telefone[11];
    char rua2[35];
    char numero2[5];
    char CEP2[9];
    char telefone2[11];
    char curso[25];
    char anoIngresso[4];

};



#include "src/Registro.h"
#include "src/Arquivo.h"


int main()
{

    //ifstream f("registro.txt");
   // registro r;
    Arquivo objArq("registro.txt");
   
    /*char nome[242];

     

      int dim[16];
      dim[0]= 40;
      dim[1]= 10;
      dim[2]= 12;
      dim[3]= 7;
      dim[4]= 20;
      dim[5]= 35;
      dim[6]= 5;
      dim[7]= 9;
      dim[8]= 3;
      dim[9]= 11;
      dim[10]= 35;
      dim[11]= 5;
      dim[12]= 9;
      dim[13]= 11;
      dim[14]= 25;
      dim[15]= 4;*/

      //f.seekg(456, ios::beg);
      //f.seekg(637, ios::beg);
      //f.seekg(sizeof(r),ios::cur);
      //f.seekg(7*242);
      //f.read(reinterpret_cast<char *> (&r), sizeof(r));
      /*f.getline(reinterpret_cast<char *> (&r),242,'\n');
       
      cout << "registro" << endl;
      for (int i = 0; i < 1; ++i)
      {
          cout << r.RA;
      }
     
      f.getline(reinterpret_cast<char *> (&r),242,'\n');

      cout << "registro2" << endl;
      for (int i = 0; i < 1; ++i)
      {
          cout << r.RA;

      }

     
     
     
      f.close();*/

      cout << endl <<  "Fim" << endl;
      return 0;
}
