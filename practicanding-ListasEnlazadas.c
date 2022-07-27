#include <stdio.h>
#include <stdlib.h>

typedef struct Tnodo{
	int valor;
	struct Tnodo *sgt;
		
}Tnodo;

Tnodo *creaLista();
void insertaAlInicio(Tnodo **start,int valor);
void insertaAlFinal(Tnodo **start,int valor);
void MostrarLista(Tnodo ** start );
Tnodo *BuscarNodo(Tnodo **start,int dato);
void EliminarNodo(Tnodo **start,int dato);

int main(){
	
	Tnodo *cabecera=NULL;
	Tnodo *cabecera2=NULL;
	printf("imprimiendo primera lista");
	insertaAlInicio(&cabecera,rand()%99);
	insertaAlInicio(&cabecera,10);
	insertaAlInicio(&cabecera,20);
	
	MostrarLista(&cabecera);
	
	printf("\n imprimiendo otra lista");
	
	insertaAlFinal(&cabecera,22);
	insertaAlFinal(&cabecera,33);
    MostrarLista(&cabecera);
    
    //buscando nodo
    
    Tnodo *nodoBuscado=BuscarNodo(&cabecera,10);
    MostrarNodo(nodoBuscado);
    
    //eliminamos un elemento de la lista
    
     EliminarNodo(&cabecera,10);
     MostrarLista(&cabecera);  
    
    
	
	printf("hola mundillo");
	getchar();
	
	return 0;
}

void EliminarNodo(Tnodo **start,int dato){
	Tnodo *Aux=*start;
	Tnodo *AuxAnterior;
	
	
	while(Aux&& Aux->valor!=dato){
		AuxAnterior=Aux;
		Aux=Aux->sgt;
	}
	if(Aux){
		AuxAnterior->sgt=Aux->sgt;
		printf("dato encontrado: %d y eliminado \n",Aux->valor);
		free(Aux);
	}
}


Tnodo *BuscarNodo(Tnodo **start,int dato){//busca y devuelve un nodo
	Tnodo *Aux=*start;
	Tnodo *nodobuscado=(Tnodo*)malloc(sizeof(Tnodo));
	while(Aux && Aux->valor!=dato){
		Aux=Aux->sgt;
	}
	nodobuscado->valor=Aux->valor;
	nodobuscado=Aux;
	nodobuscado->sgt=NULL;
	
	
	return nodobuscado;//devuelvo direccion del puntero 
}



void insertaAlInicio(Tnodo **start,int valor){
	Tnodo *nodo=(Tnodo*)malloc(sizeof(Tnodo));//reserva de memoria
	nodo->valor=valor;
	if(start==NULL){
		nodo->sgt=NULL;
		*start=nodo;
	}
	else{
		nodo->sgt=*start;
		*start=nodo;
	}
	
}

void insertaAlFinal(Tnodo **start,int valor){
	Tnodo * nodo=(Tnodo*)malloc(sizeof(Tnodo));
	Tnodo *Aux=*start;
	nodo->valor=valor;
	nodo->sgt=NULL;
	
	if(start==NULL){
		
		*start=nodo;
	}
	while(Aux->sgt!=NULL){
		Aux=Aux->sgt;
	}
	Aux->sgt=nodo;
	
}	


void MostrarLista(Tnodo **start ){
	Tnodo *Aux=*start;
	int i=1;
	printf("\n");
	while(Aux!=NULL){
		printf("elemento: %d valor del elemento: %d\n",i,Aux->valor);
		Aux=Aux->sgt;
		i++;
				
	}
	
}

void MostrarNodo(Tnodo *nodo){
	printf("valor del nodo buscado: %d\n",nodo->valor);

}

