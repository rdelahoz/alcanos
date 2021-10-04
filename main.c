#include <stdio.h>
#include "estructura.h"
#include <string.h>



int main(void) {

  int i= 0;
  char cadena[] = "22+-#23##23#22-#23#+#3#223";

  FILE *archivo;
	char caracter;
	
	/*archivo = fopen("alcanos.txt","r");
	
	if (archivo == NULL)
        {
            printf("\nError de apertura del archivo. \n\n");
        }
        else
        {           
          while((caracter = fgetc(archivo)) != EOF)
          {        
            
            printf("%s",cadena);
          }
        }
        fclose(archivo);
	return 0;
*/


  
  Lista *listaIngreso = creaLista();
  Lista *listaFinal = creaLista();
  Lista *nombreInicio = creaLista();
  




  /* Lee la cadena */
  for(i=0;i<strlen(cadena);i++){
    insertaSiguiente(listaIngreso,cadena[i]);    
  }

  /* traspasa a estructura */
  traspasaLista(listaIngreso,listaFinal);

  
  muestraSalida(listaFinal);
  return 0;

}