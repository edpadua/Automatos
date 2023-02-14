#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cctype>

using namespace std;

ifstream arq_e("teste.txt");
ofstream arq_s;

char proximoChar(){
    char ch;
    arq_e.get(ch);
    return(ch);
}

int main () {

  fstream filestr;


  char ch;

  arq_s.open("test.txt");

  int Aceita[3];
  int Avance[3][3];
  int T[3][3];
  


  Aceita[0]=0;
  Aceita[1]=0;
  Aceita[2]=1;

  //letra 0 digito 1 outro 2


  T[0][0]=1;
  T[1][0]=1;
  T[1][1]=1;
  T[1][2]=2;
  Avance[0][0]=1;
  Avance[1][0]=1;
  Avance[1][1]=1;
  Avance[1][2]=1;
  Avance[2][0]=0;
  Avance[2][1]=0;
  Avance[2][2]=0;


  
  int tipo;
  char c;
     while(!arq_e.eof()){
      int erro=0;
      int estado=0;
      int novoestado=0;
      ch=proximoChar();
      
      cout << ch;
      if(!isalpha(ch)){
         erro=1;
         arq_s << ch;
       }
         while((!Aceita[estado])&&!erro){
             if(isalpha(ch)){
                tipo=0;
                cout <<"é letra ";
                //arq_s << ch;
             }
              else{
                  if(isdigit(ch)){
                     tipo=1;
                    // arq_s << ch;
                     cout <<"é digito";
                   }
                   else{
                   tipo=2;
                  // arq_s <<"<<ID>>";
                   //arq_s <<ch;
                   cout <<"outro";
                  }
              }
              
              
              novoestado=T[estado][tipo];
              cout <<"  novo estado "<< novoestado;
              c=getchar();
              
              if( Aceita[novoestado]){
                     arq_s <<"<<ID>>";
              }
              arq_s <<ch;
              
              if( Avance[estado][tipo]&&!Aceita[novoestado]){
                   
                    
                        ch=proximoChar();
                        cout <<" SS ";
                        cout << ch;
                  
                  
            
              }
               estado=novoestado;
               
        }
        /*if( Aceita[estado] ){
                  
                  
                  //arq_s << "<<ID>>";
                  //
                  arq_s << ch;
                  cout << "aceitacao";
                  //estado=0;
         }*/
         
   }      
   // fecha o arquivo
   arq_e.close();
   arq_s.close();



  return 0;
}
