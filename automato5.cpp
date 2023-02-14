#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cctype>
#include<string.h>
#include<string>

using namespace std;

ifstream arq_e("sample.tny");
ofstream arq_s;

char proximoChar(){
    char ch;
    arq_e.get(ch);
    return(ch);
}



void proximaLinha( char ch[256]){
    arq_e.getline(ch,256);

}

int tipo( char ch ){
    int tipo=0;
    switch ( ch ) {
                     case ' ':
                         tipo=0;
                     break;
                     case '{':
                         tipo=1;
                     break;
                     case '}':
                         tipo=2;
                     break;
                     case ':':
                         tipo=5;
                     break;
                     case '=':
                         tipo=8;
                     break;
                    
                     default:
                            if( ch=='+'|| ch=='-'|| ch=='*'||ch=='<'||ch=='/'||ch=='('||ch==')'||ch==';'){
                               tipo=6;
                            }
                            else{
                                 if(isalpha(ch)){
                                    tipo=4;
                                 }
                                 else{
                                     if(isdigit(ch)){
                                         tipo=3;
                                      }
                                      else{
                                         tipo=7;
                                      }
                                 }
                            }
                     break;

             }
              return tipo;
}

void inicializaTabela( int Ac[6], int Avance[6][9], int T[5][9] ){
       Ac[0]=0;
       Ac[1]=0;
       Ac[2]=0;
       Ac[3]=0;
       Ac[4]=0;
       Ac[5]=1;

       /*
      0 espaÃ§o
      1 {
      2 }
      3 digito
      4 letra
      5 :
   /  6 +-*/   /* <=();
      7 outro
      8 =

  */


       T[0][0]=0; // estado 0 espaço
       T[0][1]=1; // estado 0 {
       T[0][2]=1; //
       T[0][3]=2; //digito
       T[0][4]=3; // letra
       T[0][5]=4; //:
       T[0][6]=5; //+-*/<=();
       T[0][7]=5; //
       T[0][8]=5;

       T[1][0]=1; // estado 0 espaço
       T[1][1]=1; // estado 0 {
       T[1][2]=0; //
       T[1][3]=1; //digito
       T[1][4]=1; // letra
       T[1][5]=1; //:
       T[1][6]=1; //+-*/<=();
       T[1][7]=1; //
       T[1][8]=1;

       T[2][0]=5; // estado 0 espaço
       T[2][1]=5; // estado 0 {
       T[2][2]=5; //
       T[2][3]=2; //digito
       T[2][4]=5; // letra
       T[2][5]=5; //:
       T[2][6]=5; //+-*/<=();
       T[2][7]=5; //
       T[2][8]=5;


       T[3][0]=5; // estado 0 espaço
       T[3][1]=5; // estado 0 {
       T[3][2]=5; //
       T[3][3]=5; //digito
       T[3][4]=3; // letra
       T[3][5]=5; //:
       T[3][6]=5; //+-*/<=();
       T[3][7]=5; //
       T[3][8]=5;

       T[4][0]=6; // estado 0 espaço
       T[4][1]=6; // estado 0 {
       T[4][2]=6; //
       T[4][3]=6; //digito
       T[4][4]=6; // letra
       T[4][5]=6; //:
       T[4][6]=6; //+-*/<=();
       T[4][7]=6; //
       T[4][8]=5;


      Avance[0][0]=1;
      Avance[0][1]=1;
      Avance[0][2]=1;
      Avance[0][3]=1;
      Avance[0][4]=1;
      Avance[0][5]=1;
      Avance[0][6]=0;
      Avance[0][7]=1;
 


      Avance[1][0]=1;
      Avance[1][1]=1;
      Avance[1][2]=1;
      Avance[1][3]=1;
      Avance[1][4]=1;
      Avance[1][5]=1;
      Avance[1][6]=1;
      Avance[1][7]=1;
  


      Avance[2][0]=0;
      Avance[2][1]=0;
      Avance[2][2]=0;
      Avance[2][3]=1;
      Avance[2][4]=0;
      Avance[2][5]=0;
      Avance[2][6]=0;
      Avance[2][7]=0;
    

      Avance[3][0]=0;
      Avance[3][1]=0;
      Avance[3][2]=0;
      Avance[3][3]=0;
      Avance[3][4]=1;
      Avance[3][5]=0;
      Avance[3][6]=0;
      Avance[3][7]=0;
   

      Avance[4][0]=0;
      Avance[4][1]=0;
      Avance[4][2]=0;
      Avance[4][3]=0;
      Avance[4][4]=0;
      Avance[4][5]=0;
      Avance[4][6]=0;
      Avance[4][7]=0;
      Avance[4][8]=1;





}


void gravaLinha( int l, string linha ){
      
      if(linha.size()>0){
        int j=0;
        
        char c;
        string s;
     
        arq_s <<"   "<<l<<": ";
        arq_s <<linha<<"\n";
      }
}

void gravaLex( int estado, int l, string Lex ){
                               arq_s <<"         "<<l<<": ";


                                switch ( estado ) {
                                   case 0:
                                     arq_s <<Lex;
                                   break;
                                   case 2:
                                     arq_s <<"NUM, val= ";
                                     arq_s <<Lex;
                                   break;
                                   case 3:
                                        cout <<"token\n"<<Lex;
                                        if(((Lex=="if")||(Lex=="else")||(Lex=="then")||(Lex=="end")||(Lex=="repeat")||(Lex=="until")||(Lex=="read")||(Lex=="write"))){
                                            

                                             //arq_s <<"        "<<l<<":";
                                             arq_s <<"reserved word: ";
                                             arq_s <<Lex;
                                            // arq_s <<"\n";
                                             
                                             estado=0;
                                            
                                             Lex="";
                                      }
                                      else{
                                          arq_s <<"ID, name= ";
                                          arq_s <<Lex;
                                   }
                                   break;
                                   case 4:
                                       arq_s <<":=";

                                   break;

                                   default:

                                   break;

                                }


                                arq_s <<"\n";

}



int main () {

  fstream filestr;


  char ch;

  arq_s.open("test.txt");

  int Aceita[6];
  int Avance[6][9];
  int T[5][9];

  inicializaTabela( Aceita, Avance, T );

  //letra 0 digito 1 outro 2
  int t;
  int l=0;
  char c;
  char linha[256];

  arq_s <<"TINY COMPILATION: sample.tny\n";
  //arq_s <<"1:";
           int estado=0;
           int estadoAnt=0;
           int novoestado=0;
           int fimLeitura=0;
           string lex;
           lex="";
  while((!fimLeitura)&&(novoestado!=6)){
           int j=0;
           int ant=0;
           int fimlinha;
           int linhagravada=0;
          
           if((!arq_e.eof())){
              fimlinha=0;
              proximaLinha( linha );
             
              l++;
              cout<<lex<<"\n";
              cout<<l<<"\n";
             
              cout<< linha;
             
              cout<<"\n";
              
          
           }
           else{
               if( lex=="end"){
               fimLeitura=1;
               gravaLex( estado, l-1, lex );
               arq_s <<"         "<<l<<": EOF";
               }
               
           }

          
               while((!Aceita[estado])&&(j<strlen(linha))&&(ch!='\n' )&&(novoestado!=6)){
                  ch=linha[j];
                  t=tipo( ch );
                  int aux;
                 //cout<<"j "<<j;
                   cout<<"ch "<<ch;
                   cout<<"tipo"<<t;

                   novoestado=T[estado][t];

                   cout<<" estado atual  " <<estado;
                   cout<<" novo estado  " <<novoestado;
                   cout<<"\n";

                   aux=l;
                   if( Aceita[novoestado] ){
                    
                      if( (!linhagravada)&&(j>0))
                      
                      {
                        gravaLinha( l, linha );
                        linhagravada=1;
                      }
                      else{
                         if(j==0){
                             l=l-1;
                             }
                      }     
                      
                      
                      if ( estado==0 ){
                           if( ch!=' ' ){
                            lex=lex+ch;
                          }
                         j++;     
                      }
                      if ( estado==4 ){
                            lex=":=";
                            j++;
                            
                            
                            
                      }
                      cout<<" aceita \n";
                      cout<<"lexema "<<lex<<"\n";
                      
                    
                      gravaLex( estado, l, lex );
                       l=aux;
                       
                      
                      estado=0;
                       //novoestado=0;
                      
                       lex="";
                       
                       
                 }
                 else{
                      
                      
                      
                       if( estado !=1 && t !=1 ){ 
                        if( ch!=' ' ){
                            lex=lex+ch;
                        }
                        }
                        
                          estadoAnt=estado;
                          estado=novoestado;
                          j++;
                 }
                
            
          //  c=getchar();
           }
            if( !linhagravada ){
                      
                        gravaLinha( l, linha );
                        linhagravada=1;
            }
           
       
   }
   
       //
       
       
       
       
       
      // c=getchar();
        
        
        

   // fecha o arquivo
   arq_e.close();
   cout<<"arquivo fechado";
   arq_s.close();



  return 0;
}
