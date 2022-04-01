#include<conio.h>
#include<stdio.h>>
#include<iostream>
#include<string.h>
#include<windows.h>
#include<Math.h>
#include<stdlib.h>
#include<iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstdio>
#define USER "c++"
#define PASS "java"
#define L 80 
#include <cstdlib> 
#include <conio.h> 
#include <vector>
#define ENTER 13 
#define BACKSPACE 8

using namespace std;
char alf[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void euclides_extendido(int a,int b, int *q1, int *q2, int *q3){
    int d,x,y,x1,x2,y1,y2,q,r;
    if(b==0){
        d=a;
        x=1;
        y=0;
        
    }
    x1=0;
    x2=1;
    y1=1;
    y2=0;
    while(b>0){
        q=a/b;
        r=a-(q*b);
        x=x2-(q*x1);
        y=y2-(q*y1);
        a=b;
        b=r;
        x2=x1;
        x1=x;
        y2=y1;
        y1=y;
    }
    d=a;
    x=x2;
    y=y2;
    *q1=d;
    *q2=x;
    *q3=y;
}

int inverso(int n,int a){
	 int d,x,y,inver;
	 int *p1=&d;
	 int *p2=&x;
	 int *p3=&y;
     euclides_extendido(a,n,p1,p2,p3);
     if(d>1){
     	return 0;
     }
     else{
     	if(x<0){
     		inver=n+x;
     	}
     	else{
     		inver=x;
     	}
     }
     return(inver);
}





int esta_matriz (char letra,char matriz[5][5]){
    for(int i=0;i<5;i++){
       for(int j=0;j<5;j++){
            if(letra == matriz[i][j]){
                  return 1;
            }
       }
    }
    return -1;
}

void llenar_matriz(char clave[],char matriz[5][5]){
    int fila=0;
    int columna=0;
    int aux;
    for(int i=0;i<strlen(clave);i++){
         aux=esta_matriz(clave[i],matriz);
         if(aux==-1&&clave[i]!=106){
              if(columna==5){
                  fila++;
                  columna=0;
              }
		        matriz[fila][columna]=clave[i];
		        columna++;
         }            
    }
    for(int j=0;j<strlen(alf);j++){
        aux=esta_matriz(alf[j],matriz); 
        if(aux==-1&&alf[j]!=106){
              if(columna==5){
                  fila++;
                  columna=0;
              }
		        matriz[fila][columna]=alf[j];
		        columna++;
         }   
    } 
}

void acomodar_mensaje (char m2[],char m[]){
	int j=0;
	for(int i=0;i<strlen(m);i++){		
		if(m[i]!=32){
		   m2[j]=m[i];
		   j++;
		}
	}
	m2[j]='\0';

		
	int i=0;
	j=1;
	while(j<=strlen(m2)){
		if(m2[i]==m2[j]){
			for(int k=strlen(m2)+1;k>j;k--){
				m2[k]=m2[k-1];
			}
			m2[j]='x';
		}
		i=i+2;
		j=j+2;
	}
	
	if(strlen(m2)%2!=0){
		m2[strlen(m2)+1]='\0';
		m2[strlen(m2)]='x';		
	}

}




int Hallar_determinante(int a[][26],int orden)
{
   int det=0;
	int aux1[26][26];
   int aux2[26][26];


	if(orden==1)
   	return a[0][0];

   for(int i=0;i<orden;i++)
     {
      if(i%2==0)
       {for(int y=0;y<orden;y++)
       	 for(int x=0;x<orden;x++)
          	if(x<i)
      	 		aux1[x][y]=a[x][y+1];
            else
               aux1[x][y]=a[x+1][y+1];

      	 det=det+a[i][0]*Hallar_determinante(aux1,orden-1);
       }
      else
       {for(int y=0;y<orden;y++)
       	 for(int x=0;x<orden;x++)
          	if(x<i)
      	 		aux2[x][y]=a[x][y+1];
            else
               aux2[x][y]=a[x+1][y+1];

      	det=det-a[i][0]*Hallar_determinante(aux2,orden-1);
       }
      }
   return det;
}

int es_invertible(int matriz[][26],int d){
	
	int det=Hallar_determinante(matriz,d);
	cout<<"Determinante: "<<det<<endl;
	if(det<0){
		det=-1*det;
	}

	if(det%2==0 || det%13==0){
		return 0;
	}
	else{
		return 1;
	}
	
}

void quitar_espacios (char m2[],char m[], int d){
	int j=0;
	for(int i=0;i<strlen(m);i++){		
		if(m[i]!=32){
		   m2[j]=m[i];
		   j++;
		}
	}
	m2[j]='\0';
	
	while(strlen(m2)%d!=0){
		m2[strlen(m2)+1]='\0';
		m2[strlen(m2)]='x';		
	}
}

void multiplica (int matriz[][26],int indices[],int d){
	int indices_aux[d];
	for(int i=0;i<d;i++){
		int aux=0;
		for(int j=0;j<d;j++){	
			aux=(matriz[i][j]*indices[j])+aux;
		}
		//cout<<aux;
		indices_aux[i]=aux%26;

	}
	for(int i=0;i<d;i++){
		indices[i]=indices_aux[i];
	
	}
}

void unico(){
	int d,n1,n2;
	char m[100];
	fflush(stdin);
	cout<<"Ingrese mensaje a cifrar:";
	cin.getline(m,100);
	
	fflush(stdin);
	char m2[100];
			
	do{
		cout<<"Ingrese un la matriz o llave:";
		cin>>d;	
	}while(d<0||d>25);
	quitar_espacios(m2,m,d);
	cout<<m2<<endl;
	
	int matriz[26][26];
	cout<<"	Digite la matriz: "<<endl;
	do{
		for(int i=0;i<d;i++){
			for(int j=0;j<d;j++){
				do{
					cout<<"Ingrese elemento ["<<i<<"]["<<j<<"]:";
					cin>>matriz[i][j];
				}while(matriz[i][j]<0||matriz[i][j]>25);
			}
		}
		
	}while(es_invertible(matriz,d)==0);
	
	int indices[100];
	int k=0;
	int l=0;
	
	for(int i=0; i<strlen(m2);i++){	
			for(int j=0;j<strlen(alf);j++){
				if(m2[i]==alf[j]){
					 indices[k]=j;
					 
				}
			}
			k++;
			if(k%d==0){
				multiplica(matriz,indices,d);
				for(int i=0;i<d;i++){
					m2[l]=alf[indices[i]];
					l++;
				}
				k=0;
			}				
	}
	cout<<"El mensaje cifrado es:";
	int conta=0;
	for(int i=0;i<strlen(m2);i++){	
		cout<<m2[i];
		conta++;
		if(conta%d==0){
			cout<<" ";
		}
	}
	cout<<endl<<endl;
	
}
void convertir(char *s){
	while(*s != '\0'){
		if(*s>='A' && *s<='P'){
			*s=*s+10;
			s+=1;
			
		} else if(*s>='Q' && *s<='Z'){
			*s=*s-16;
			s+=1;
		
		} else if(*s>='a' && *s<='p'){
			*s=*s+10;
			s+=1;
			
		} else if(*s>='q' && *s<='z'){
			*s=*s-16;
			s+=1;
		
		} else if(*s=' '){
			*s=32;
			s+=1;
		}
	}
}
double determinante(double matriz[][26], int d)
{
    double det;
    if(d==2)
    {
        det=(matriz[0][0]*matriz[1][1])-(matriz[1][0]*matriz[0][1]);
        return det;
    }
    double suma=0;
    for(int i=0; i<d; i++){
    double nm[d-1][26];
        for(int j=0; j<d; j++){
            if(j!=i){
                for(int k=1; k<d; k++){
                int indice=-1;
                if(j<i)
                indice=j;
                else if(j>i)
                indice=j-1;
                nm[indice][k-1]=matriz[j][k];
                }
            }
        }
        if(i%2==0)
        suma+=matriz[i][0] * determinante(nm,(d-1));
        else
        suma-=matriz[i][0] * determinante(nm,(d-1));
    }
    return suma;
}
void matrizCofactores (double matriz[][26], int d ){
    double nm[d][d];
    for(int i=0;i<d;i++) {
        for(int j=0;j<d;j++) {
            double det[d-1][26];
            double detValor;
            for(int k=0;k<d;k++) {
                if(k!=i) {
                    for(int l=0;l<d;l++) {
                        if(l!=j) {
                        int indice1=k<i ? k : k-1 ;
                        int indice2=l<j ? l : l-1 ;
                        det[indice1][indice2]=matriz[k][l];
                        }
                    }
                }
            }
            detValor=determinante(det,d-1);
            nm[i][j]=detValor * (double)pow(-1, i+j+2);
        }
    }
    for(int i=0;i<d;i++) 
        for(int j=0;j<d;j++) 
   			 matriz[i][j]=nm[i][j];
}

void matrizTranspuesta(double matriz[][26], int d ){
    double nuevam[d][d];
    for(int i=0; i<d; i++)
    {
        for(int j=0; j<d; j++)
            nuevam[i][j]=matriz[j][i];
    }
    for(int i=0;i<d;i++) 
        for(int j=0;j<d;j++) 
   			 matriz[i][j]=nuevam[i][j];
}
void matrizAdjunta(double  matriz[][26], int d){
    matrizCofactores(matriz, d);
    matrizTranspuesta(matriz, d);
    
}

void multiplicarMatriz(double n, double matriz[][26], int d) {
    for(int i=0;i<d;i++)
        for(int j=0;j<d;j++)
            matriz[i][j]*=n;
}

void matrizInversa(double matriz[][26], int d){
	double det;
	det= 1/determinante(matriz,d);
	matrizAdjunta(matriz,d);
	
}

void descifrado(){
int d;
	char m[100];
	fflush(stdin);
	cout<<"Ingrese mensaje a descifrar:";
	cin.getline(m,100);
	
	fflush(stdin);
	char m2[100];
			
	do{
		cout<<"Ingrese la matriz o llave:";
		cin>>d;	
	}while(d<0||d>25);
	quitar_espacios(m2,m,d);
	double matriz[26][26];
	cout<<"Digite la clave dependiendo de la matriz: "<<endl;
		for(int i=0;i<d;i++){
			for(int j=0;j<d;j++){
				do{
					cout<<"Ingrese los valores de la matriz ["<<i<<"]["<<j<<"]:";
					cin>>matriz[i][j];
				}while(matriz[i][j]<0||matriz[i][j]>25);
			}
		}
	int matriz_aux[26][26];
	for(int i=0;i<d;i++){
			for(int j=0;j<d;j++){
				matriz_aux[i][j]=(int)matriz[i][j];
			}
		}
	
	int deter =Hallar_determinante(matriz_aux,d);
	deter=inverso(26,deter%26);
	//cout<<deter<<endl;
	matrizInversa(matriz,d);
	for(int i=0;i<d;i++)
		for(int j=0;j<d;j++){
			matriz[i][j]=matriz[i][j]*deter;
		}
	
	int matriz_aux2[26][26];
	for(int i=0;i<d;i++){
			for(int j=0;j<d;j++){
				matriz_aux2[i][j]=(int)matriz[i][j];
			}
		}
	for(int i=0;i<d;i++){
			for(int j=0;j<d;j++){
				if(matriz_aux2[i][j]<0){
					while(matriz_aux2[i][j]<0){
						matriz_aux2[i][j]=matriz_aux2[i][j]+26;
					}
				}
				else{
					matriz_aux2[i][j]=matriz_aux2[i][j]%26;
				}
			}
	}	
	cout<<endl;
	int indices[100];
	int k=0;
	int l=0;		
	for(int i=0; i<strlen(m2);i++){	
			for(int j=0;j<strlen(alf);j++){
				if(m2[i]==alf[j]){
					 indices[k]=j;
				
				}
			}
			k++;
			if(k%d==0){
				multiplica(matriz_aux2,indices,d);
				for(int i=0;i<d;i++){
					m2[l]=alf[indices[i]];
					l++;
				}
				k=0;
			}				
	}
	cout<<"El mensaje descifrado es:";
	int conta=0;
	for(int i=0;i<strlen(m2);i++){	
		cout<<m2[i];
		conta++;
	
	}
	cout<<endl<<endl;	
	
}

bool validar(char palabra[], int n){
	int cont=0;
	cout<<palabra<<endl;
	cout<<n<<endl;
	for(int i=0;i<n;i++){
		if(palabra[i]!=49 || palabra[i]!=48){
			return false;
		}
	}	
	return true;
}
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}




void cuadro(int x5, int y5, int x6, int y6){
    int i;
    for (i=x5;i<x6;i++){	
		gotoxy(i,y5);printf("Ä") ; 
		gotoxy(i,y6);printf("Ä") ; 
    }

    for (i=y5;i<y6;i++){	
		gotoxy(x5,i);printf("³") ; 
		gotoxy(x6,i);printf("³") ; 
    }
    
    gotoxy(x5,y6); printf("Ú"); 
    gotoxy(x5,y6); printf("À");
    gotoxy(x6,y5); printf("¿");
    gotoxy(x6,y6); printf("Ù");
}




int main(){
		system ("COLOR B0");
		char texto[50];
    char a;
    int i;
    int opciones;
    vector<string> usuarios;
    vector<string> claves;
    
	
	int opc,opc2;

    usuarios.push_back("luis");
    usuarios.push_back("jorge");
    usuarios.push_back("james");
    usuarios.push_back("johan");
    usuarios.push_back("kevin");
    
    claves.push_back("123");
    claves.push_back("456");
    claves.push_back("789");
    claves.push_back("abc");
    claves.push_back("efg");
    
    
    string usuario, password;
    
    int contador = 0;
    bool ingresa = false;
    
    do {
        system("cls");
        cout << "\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\tUsuario: ";
        getline(cin, usuario);
        
        char caracter;
        
        cout << "\tPassword: ";
        caracter = getch();
        
        password = "";
        
        while (caracter != ENTER) {
        
            if (caracter != BACKSPACE) {
                password.push_back(caracter);
                cout << "*";
                
            } else {
                if (password.length() > 0) {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }
            
            caracter = getch();
        }
        
        for (int i = 0; i < usuarios.size(); i++) {
            if (usuarios[i] == usuario && claves[i] == password) {
                ingresa = true;
                break;
            }
        }
        
        if (!ingresa) {
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }
        
    } while (ingresa == false && contador < 3);
    
    if (ingresa == false) {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    } else {
        
	do{
		cuadro(0,0,78,24);
		cuadro(1,1,77,3);
		gotoxy(30,2);
		cout<<"Mensajeria Privada";
		gotoxy(2,6);
		cout<<"1.- Cifrado de mensajeria"<<endl;
		gotoxy(2,7);
		cout<<"7.- Salir"<<endl;
		gotoxy(2,8);
		cout<<"Ingrese Opcion:";
		cin>>opc;
		
		switch(opc){	
			case 1: system("cls");
					do{		
						 cout<<"1.- Cifrar"<<endl;
						
						 cout<<"2.- Descrifrar"<<endl;
						 
						 cout<<"3.- Salir"<<endl;
						
						 cout<<"Ingrese Opcion:";
						 cin>>opc2;
						switch(opc2){
							case 1: unico(); break;
							case 2: descifrado(); break;
						}
					}while(opc2!=3);
					system("cls");			
					break;	
					
		
		}
	}while(opc!=7);
	getch();
}
}

