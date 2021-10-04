struct Nodo{
	char valor;
	struct Nodo *siguiente;
  struct Nodo *arriba;
  struct Nodo *abajo;
} typedef Nodo;


struct Lista{
	Nodo *inicio;
  Nodo *fin; 
	int largo;  
  int largoArriba; 
  int largoAbajo;   
} typedef Lista;


Lista *creaLista();
void nombreSalida(Lista *listaIn);
void muestraLista(Lista *listaIn);
void muestraSalida(Lista *listaIn);
void insertaSiguiente(Lista *listaIn, char valorIn);
void traspasaLista(Lista *listaIn, Lista *listaOut);
