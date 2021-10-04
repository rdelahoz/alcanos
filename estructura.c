#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "estructura.h"



Lista* creaLista(){
	Lista* listaSalida = (Lista*)malloc(sizeof(Lista));
	listaSalida->inicio = NULL;
  listaSalida->largo = 0;	
	return listaSalida;
}


void insertaSiguiente(Lista *listaIn, char valorIn){
  Nodo *nodoNuevo = (Nodo*)malloc(sizeof(Nodo));
	nodoNuevo->valor = valorIn;
	nodoNuevo->siguiente = NULL;
 
  /* Evalua si la lista esta vacia */
	if (listaIn->largo == 0){
		listaIn->inicio = nodoNuevo;
    listaIn->fin = nodoNuevo;
	}	else {
		Nodo *nodo = listaIn->fin;
		nodo->siguiente = nodoNuevo;
    listaIn->fin = nodoNuevo;
	}
	listaIn->largo = listaIn->largo + 1;
}

void insertaArriba(Lista *listaIn, char valorIn){
  Nodo *nodoNuevo = (Nodo*)malloc(sizeof(Nodo));
	nodoNuevo->valor = valorIn;
	nodoNuevo->arriba = NULL;
 
  /* Evalua si la lista esta vacia */
	Nodo *nodo = listaIn->fin;

  if(nodo->arriba == NULL){
    nodo->arriba = nodoNuevo;
  }else{
    while(nodo->arriba != NULL){
      nodo = nodo->arriba;
		}
    nodo->arriba = nodoNuevo;
  }	  
	//listaIn->largoArriba = listaIn->largoArriba + 1;
}

void insertaAbajo(Lista *listaIn, char valorIn){
  Nodo *nodoNuevo = (Nodo*)malloc(sizeof(Nodo));
	nodoNuevo->valor = valorIn;
	nodoNuevo->abajo = NULL;
 
  /* Evalua si la lista esta vacia */
	Nodo *nodo = listaIn->fin;

  if(nodo->abajo == NULL){
    nodo->abajo = nodoNuevo;
  }else{
    while(nodo->abajo != NULL){
      nodo = nodo->abajo;
		}
    nodo->abajo = nodoNuevo;
  }	  
	//listaIn->largoArriba = listaIn->largoArriba + 1;
}


void muestraLista(Lista *listaIn){
	
  if(listaIn->largo > 0){
		Nodo *nodo = listaIn->inicio;
		while(nodo != NULL){      
      
      if(nodo->valor == *"4"){
        printf("CH\n");
      }else{
        printf("%c", nodo->valor);
      }
			
			nodo = nodo->siguiente;
		}
		printf("\n");
	}
	else {
		printf(" *** LA LISTA ESTA VACIA \n");
	}
}


void traspasaLista(Lista *listaIn, Lista *listaOut){
  
  int cont=0;
  char aux;
  Nodo *nodo = listaIn->inicio;
  while(nodo != NULL){
    
    if(nodo->siguiente !=NULL && nodo->valor == *"+" && nodo->siguiente->valor == *"-"){
      nodo = nodo->siguiente->siguiente;
      insertaSiguiente(listaOut,*"C");
      cont=0;
      while(nodo != NULL && cont<4){
          if(nodo->valor == *"#"){
            cont++;
          }else{
            if(cont<2){              
              insertaArriba(listaOut,nodo->valor);              
            }else{
              insertaAbajo(listaOut,nodo->valor);              
            }
          }
          nodo = nodo->siguiente;
        }


    }else if(nodo->valor == *"+"){
      cont=0;
      nodo = nodo->siguiente;
      insertaSiguiente(listaOut,*"H");
      while(nodo != NULL && cont<2){
        if(nodo->valor == *"#"){
          cont++;
        }else{
          insertaArriba(listaOut,nodo->valor);          
        }
        nodo = nodo->siguiente;
      }
      
    }else if(nodo->valor == *"-"){
      cont=0;
      nodo = nodo->siguiente;
      insertaSiguiente(listaOut,*"H");
      while(nodo != NULL && cont<2){
        if(nodo->valor == *"#"){
          cont++;
        }else{
          insertaAbajo(listaOut,nodo->valor);          
        }
        nodo = nodo->siguiente;
      }
    }else{      
      insertaSiguiente(listaOut,nodo->valor);
      nodo = nodo->siguiente;
    }
    
  }

}

void nombreSalida(Lista *listaIn){

Nodo *nodo = listaIn->inicio;
Nodo *nodoArriba; 
Nodo *nodoAbajo; 
char *salida;
char *apellido = malloc(10);
int contGeneral=0;
int contArriba=0;
int contAbajo=0;
int contMax=0;

  if(listaIn->largo > 0){	
    
    nodo = listaIn->inicio;
    contGeneral++;

    while(nodo != NULL){      

      if(nodo->arriba != NULL){        
        contArriba = contGeneral;
        nodoArriba = nodo->arriba;
        while(nodoArriba != NULL){
          contArriba++;
          nodoArriba = nodoArriba->arriba;
        }
        if(contArriba>contMax){
          contMax = contArriba;
          printf("Largo %i \n",contMax);
        }
      }

      if(nodo->abajo != NULL){        
        contAbajo = contGeneral;
        nodoAbajo = nodo->abajo;
        while(nodoAbajo != NULL){
          contAbajo++;
          nodoAbajo = nodoAbajo->abajo;
        }
        if(contAbajo>contMax){
          contMax = contAbajo;
          printf("Largo %i \n",contMax);
        }
      }

    contGeneral++;
    nodo = nodo->siguiente;

		}
		
  }	


  
  printf("Largo %s \n",salida);  

}




void muestraSalida(Lista *listaIn){

Nodo *nodo = listaIn->inicio;
Nodo *nodoArriba; 
Nodo *nodoAbajo; 
char salida[200];

  if(listaIn->largo > 0){	
        
    while(nodo != NULL){
      if(nodo->arriba == NULL && nodo->abajo == NULL){
        printf("   ");
      }else if(nodo->arriba != NULL && nodo->abajo != NULL){
        nodoArriba = nodo->arriba;
        while(nodoArriba != NULL){
          printf("CH%c", nodoArriba->valor);
          nodoArriba = nodoArriba->arriba;
        } 
      }else if(nodo->arriba != NULL){
        nodoArriba = nodo->arriba;
        while(nodoArriba != NULL){
          printf("CH%c", nodoArriba->valor);
          nodoArriba = nodoArriba->arriba;
        } 
      }else if(nodo->abajo != NULL){        
        printf("  ");
      }
			nodo = nodo->siguiente;
		}
		printf("\n");
    nodo = listaIn->inicio;
    while(nodo != NULL){
      if(nodo->valor == *"C"){
        printf("C");
      }else if(nodo->valor == *"H"){
        printf("CH");
      }else{
        printf("CH%c", nodo->valor);
      }
			nodo = nodo->siguiente;
		}

		printf("\n");
    nodo = listaIn->inicio;
    while(nodo != NULL){
      if(nodo->arriba == NULL && nodo->abajo == NULL){
        printf("   ");
      }else if(nodo->arriba != NULL && nodo->abajo != NULL){
        nodoAbajo = nodo->abajo;
        while(nodoAbajo != NULL){
          printf("CH%c", nodoAbajo->valor);
          nodoAbajo = nodoAbajo->abajo;
        } 
      }else if(nodo->abajo != NULL){
        nodoAbajo = nodo->abajo;
        while(nodoAbajo != NULL){
          printf("CH%c", nodoAbajo->valor);
          nodoAbajo = nodoAbajo->abajo;
        } 
      }else if(nodo->arriba != NULL){        
        printf("  ");
      }
			nodo = nodo->siguiente;
		}
  printf("\n");

  }
}

