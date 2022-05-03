#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tareas{
	int TareaID;
	char *descripcion;
	int duracion;
}Tarea;

typedef struct TNodo{
	Tarea T;
	struct Nodo *sgt;
}Nodo;

void cargarArreglo(Tarea *arreTarea,int cantT);
void mustraArr(Tarea *arreglo,int cantT);
Nodo *crearnodo(Tarea tarea);
void insertar(Nodo**Lista,Nodo *nodo);

void mostrarLista(Nodo *Lista);

int main (){
	int cantT,i;
	Nodo *ListaPend=NULL;
	//TNodo **ListaReal=NULL;

		
	printf("ingrese la cant de tareas\n");
	fflush(stdin);
	scanf("%d",&cantT);
	fflush(stdin);
	Tarea arreglo[cantT];//vector de estructuras
	
	
	ListaPend=(Nodo*)malloc(cantT*sizeof(Nodo));
	//ListaReal=(Nodo**)malloc(cantT*sizeof(Nodo*));
	
	cargarArreglo(arreglo,cantT);//cargo este arreglo para luego pasarlo de a 1 
	//mustraArr(arreglo,cantT);
	for(i=0;i<cantT;i++){
			
		printf("insercion %d",i);
		
		insertarNodo(ListaPend,crearnodo(arreglo[i]));
	}
	//mostrarLista(ListaPend);

//	cargarListaPend(ListaPend,arreglo, cantT);
//	mostrarLista(ListaPend);		
	
	return 0;
}

void cargarArreglo(Tarea *arreTarea,int cantT){
	int i;
	char *buff;
	buff=(char*)malloc(50*sizeof(char));	
	
	for(i=0;i<cantT;i++){
		
		arreTarea[i].TareaID=i;
		
		fflush(stdin);
		printf("ingrese la descripcion de la tarea %d:  ",i+1);
		fflush(stdin);
		gets(buff);
		
		arreTarea[i].descripcion=(char*)malloc(strlen(buff+1)*sizeof(char));
		strcpy(arreTarea[i].descripcion,buff);		
		arreTarea[i].duracion=rand()%90+10;
					
	}
	free(buff);

}

void mustraArr(Tarea *arreglo,int cantT){
	int i;
		for(i=0;i<cantT;i++){
		printf("id %d\n",arreglo[i].TareaID);
		printf("desc %s\n",arreglo[i].descripcion);
		printf("duracion %d\n",arreglo[i].duracion);
	}
}


Nodo *crearnodo(Tarea tarea){
	Nodo *nodoNuevo=NULL;
	nodoNuevo=(Nodo*)malloc(sizeof(Nodo));
	nodoNuevo->T=tarea;
	nodoNuevo->sgt=NULL;	
	printf("se creo el nodo\n");
	return nodoNuevo;
	
}

void insertar(Nodo**Lista,Nodo *nodo){
	Nodo *nuevo;
	nuevo=(Nodo*)malloc(sizeof(Nodo));
	nuevo=nodo;
	nuevo->sgt=*Lista;
	*Lista=nuevo;
}

void mostrarLista(Nodo *Lista){
	int i=1;
	while(Lista!=NULL){
		printf("datos tarea %d\n",i);
		printf("tareaID %d\n",Lista->T.TareaID);
		printf("descripcion %s\n",Lista->T.descripcion);
		printf("duracion %d\n",Lista->T.duracion);
		printf("\n");
		i++;	
		Lista=Lista->sgt;
	}
}


