#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cctype>
#include<string.h>
#include<string>

using namespace std;

ifstream arq_e("sample.txt");
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
       T[0][7]=1; //
       T[0][8]=5; //=

       T[1][0]=1; // estado 0 espaço
       T[1][1]=1; // estado 0 {
       T[1][2]=0; // 
       T[1][3]=1; //digito
       T[1][4]=1; // letra
       T[1][5]=1; //:
       T[1][6]=1; //+-*/<=();
       T[1][7]=1; //
       T[1][8]=1; //=
  
       T[2][0]=5; // estado 0 espaço
       T[2][1]=5; // estado 0 {
       T[2][2]=5; // 
       T[2][3]=2; //digito
       T[2][4]=5; // letra
       T[2][5]=5; //:
       T[2][6]=5; //+-*/<=();
       T[2][7]=5; //
       T[2][8]=5; //=
  
  
       T[3][0]=5; // estado 0 espaço
       T[3][1]=5; // estado 0 {
       T[3][2]=5; // 
       T[3][3]=5; //digito
       T[3][4]=3; // letra
       T[3][5]=5; //:
       T[3][6]=5; //+-*/<=();
       T[3][7]=5; //
       T[3][8]=5; //=
  
       T[4][0]=5; // estado 0 espaço
       T[4][1]=5; // estado 0 {
       T[4][2]=5; // 
       T[4][3]=5; //digito
       T[4][4]=5; // letra
       T[4][5]=5; //:
       T[4][6]=5; //+-*/<=();
       T[4][7]=5; //
       T[4][8]=5; //=
  
  
      Avance[0][0]=1;
      Avance[0][1]=1;
      Avance[0][2]=1;
      Avance[0][3]=1;
      Avance[0][4]=1;
      Avance[0][5]=1;
      Avance[0][6]=0;
      Avance[0][7]=1;
      Avance[0][8]=0;
  
  
      Avance[1][0]=1;
      Avance[1][1]=1;
      Avance[1][2]=1;
      Avance[1][3]=1;
      Avance[1][4]=1;
      Avance[1][5]=1;
      Avance[1][6]=1;
      Avance[1][7]=1;
      Avance[1][8]=1;
  
  
      Avance[2][0]=0;
      Avance[2][1]=0;
      Avance[2][2]=0;
      Avance[2][3]=1;
      Avance[2][4]=0;
      Avance[2][5]=0;
      Avance[2][6]=0;
      Avance[2][7]=0;
      Avance[2][8]=0;
  
      Avance[3][0]=0;
      Avance[3][1]=0;
      Avance[3][2]=0;
      Avance[3][3]=0;
      Avance[3][4]=1;
      Avance[3][5]=0;
      Avance[3][6]=0;
      Avance[3][7]=0;
      Avance[3][8]=0;
  
      Avance[4][0]=0;
      Avance[4][1]=0;
      Avance[4][2]=0;
      Avance[4][3]=0;
      Avance[4][4]=0;
      Avance[4][5]=0;
      Avance[4][6]=0;
      Avance[4][7]=0;
      Avance[4][8]=0;



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
     while(!arq_e.eof()){
           proximaLinha( linha );
           l++;
           arq_s <<"   "<<l<<":"; 
           arq_s <<" "<<linha<<"\n"; 
           cout<< linha;
           cout<<"\n";
           int j=0;
           int ant=0;
           int estado=0;
           int estadoAnt=0;
           int novoestado=0;
           int preserv=0;
          // ch=linha[j];
          // j++;

          // cout <<"\n"; 
          // cout << ch;
          
         string token;
          
           token="";
           
         while( (j<strlen(linha))&&(ch!='\n' )){
             while((!Aceita[estado])&&(j<=strlen(linha))&&(ch!='\n' )){
                 ch=linha[j];
                 t=tipo( ch );
                 novoestado=T[estado][t];
                
                     
                cout<<"ch  " <<ch; 
                 ant=j;
                 
                          if( (token=="if")||(token=="else")||(token=="then")||(token=="end")||(token=="repeat")||(token=="until")||(token=="read")||(token=="write")){
                       cout <<" foi "<< token;   
                      
                          arq_s <<"        "<<l<<":"; 
                          arq_s <<"reserved word: ";
                          arq_s <<token;
                          arq_s <<"\n";
                          estadoAnt=0;
                          estado=0;
                          novoestado=0;
                          token="";
                          }
                 else{
                 if(!Aceita[novoestado]){
                       j++;
                       if(ch!=' '){
                                
                          token=token+ch;
                        }
                 }     
                 else{
                      if(estado==2 && Aceita[novoestado]){
                           token=token;
                      }
                      else{
                           
                      token=token+ch;
                      }
                     if(((estado==0) && Aceita[novoestado])||((estado==4) && Aceita[novoestado]))
                      {
                         j++;
                      }   
                      else{
                           
                         j=ant;
                      }
                      
                       
                         cout<<"token  " <<token;  
                      
                      
                       if( Aceita[novoestado] ){ 
                       
                      
                      
                        
                  arq_s <<"        "<<l<<":"; 
                  
                  
                  
                  
                  
                  
                  switch ( estado ) {
                     case 0:
                          arq_s <<token;
                     break;
                     case 2:
                          arq_s <<"NUM, val= ";
                          arq_s <<token;
                     break;
                     case 3:
                          arq_s <<"ID, name= ";
                          arq_s <<token;
                     break;
                     case 4:
                          arq_s <<":=";
                          
                     break;
                     
                     default:
                            
                     break;
                    
                  } 
                
                
                 arq_s <<"\n";
                
         
         }
         }             
                      
                 }
                             
                 cout<<"estado atual  " <<estado;  
                 cout<<"novo estado  " <<novoestado;  
               
                 estadoAnt=estado;
                 estado=novoestado;
                 novoestado=0;
                     
                 
                 
                 
                 
                 //cout<<"token  " <<token;
                 
                 
          // c=getchar();
           }
           estado=0;
           token="";
         
       }
   }
   // fecha o arquivo
   arq_e.close();
   arq_s.close();



  return 0;
}
