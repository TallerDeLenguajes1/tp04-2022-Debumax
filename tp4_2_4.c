#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarea{
int TareaID;//numero en ciclo iterativo
char *descripcion;
int duracion;//10-100
}Tarea;

void Cargar_tareas(Tarea **tareasPendientes,int cantTarea);
void mostrarTareas(Tarea **Tareas,int cantTarea);
void realizoLaTarea(Tarea **tareasPendientes,Tarea **TareasRealizadas , int cantTareas);
void mostrarTareasRealizadas(Tarea **tarea,int cantTareas);
void mostrarTareasPendintes(Tarea **tarea,int cantTareas);

int main(){
	int cantTarea;
	Tarea **tareasPendientes;	
	tareasPendientes=(Tarea**)malloc(cantTarea*sizeof(Tarea*));
	Tarea **tareasRealizadas;
	tareasRealizadas=(Tarea**)malloc(cantTarea*sizeof(Tarea*));
	
	printf("ingrese la cantidad de tareas a realizar: \n");
	fflush(stdin);
	scanf("%d",&cantTarea);
	fflush(stdin);
	printf("\n");

	Cargar_tareas(tareasPendientes, cantTarea);
//	mostrarTareas(tareasPendientes, cantTarea);
	realizoLaTarea(tareasPendientes,tareasRealizadas , cantTarea);
	
	printf("MOSTRANDO TAREAS PENDIENTES \n\n");
	mostrarTareasPendintes( tareasPendientes,cantTarea);
	printf("MOSTRANDO TAREAS REALIZADAS \n\n");
	mostrarTareasRealizadas(tareasRealizadas, cantTarea);
		
	
	
	return 0;
	
}

void Cargar_tareas(Tarea **tareasPendientes,int cantTarea){
	int i;
	char *buff;
	buff=(char*)malloc(50*sizeof(char));

	for(i=0;i<cantTarea;i++){
		tareasPendientes[i]=(Tarea*)malloc(sizeof(Tarea));//debo reservar memoria por cada tarea que tengo
		//cada tarea es una estructura 
		tareasPendientes[i]->TareaID=i;
		fflush(stdin);
		printf("              tarea: %d\n",tareasPendientes[i]->TareaID+1);		
		printf("ingrese la descripcion de la tarea %d: ",i+1);
		fflush(stdin);
		gets(buff);		
		tareasPendientes[i]->descripcion=(char*)malloc((strlen(buff)+1)*sizeof(char));		
		strcpy(tareasPendientes[i]->descripcion,buff);
		printf("descripcion: %s\n",tareasPendientes[i]->descripcion);
		tareasPendientes[i]->duracion=rand()%90+10;                             
		printf("duracion: %d\n",tareasPendientes[i]->duracion);
		printf("\n");	
				
	}
	free(buff);

}

void realizoLaTarea(Tarea **tareasPendientes,Tarea **TareasRealizadas , int cantTarea){
	int i;
	char rpt;
	
	printf("      *** CHEQUEO DE TAREAS *****\n");
	

	for (i=0;i<cantTarea;i++){
		printf("              tarea: %d\n",tareasPendientes[i]->TareaID+1);
		printf("descripcion: %s\n",tareasPendientes[i]->descripcion);
		printf("duracion: %d\n",tareasPendientes[i]->duracion);
		printf("\n");
		printf("Ralizo esta tarea s/n ? \n");
		fflush(stdin);
		scanf("%c",&rpt);
		printf("\n");

		
		if(rpt=='s'){
			
			TareasRealizadas[i]=(Tarea*)malloc(sizeof(Tarea));
			TareasRealizadas[i]=tareasPendientes[i];
			printf("TAREA OK \n");
			printf("ID tarea: %d\n",TareasRealizadas[i]->TareaID+1);
			printf("descripcion: %s\n",TareasRealizadas[i]->descripcion);
			printf("duracion: %d\n",TareasRealizadas[i]->duracion);
			printf("\n");
			*(tareasPendientes+i)=NULL; 
		}
		if(rpt=='n'){
			*(TareasRealizadas+i)=NULL;
		}
		
		
	}
	printf("   *** FIN CHEQUEO TAREAS \n\n");

}

void mostrarTareas(Tarea **Tareas,int cantTarea){
	int i;
	printf("\n");
	printf("+++++++LISTADO DE TAREAS ++++++++ \n");
	for (i=0;i<cantTarea;i++){
		printf("     Tarea : %d\n",Tareas[i]->TareaID+1);
		printf("     Descripcion: %s\n",Tareas[i]->descripcion);
		printf("     Duracion: %d\n",Tareas[i]->duracion);
		printf("\n");
	}
		
}


void mostrarTareasPendintes(Tarea **tarea,int cantTareas){
	int i;
	
	for (i=0;i<cantTareas;i++){
		if(*(tarea+i)==NULL){
			printf("TAREA %d REALIZADA \n",i+1);
			printf("\n");
		}
		if(*(tarea+i)!=NULL){
			printf("     Tarea %d pendiente\n",i+1);
			printf("     TareaID: %d\n",tarea[i]->TareaID);
			printf("     Descripcion: %s\n",tarea[i]->descripcion);
			printf("     Duracion: %d\n",tarea[i]->duracion);
			printf("\n");
		}
	}
		
}

void mostrarTareasRealizadas(Tarea **tarea,int cantTareas){
	int i;
	
	for (i=0;i<cantTareas;i++){
		if(*(tarea+i)==NULL){
			printf("TAREA Pendiente\n");
		}
		else{
			printf("     Tarea %d realizada: \n",i+1);
			printf("     IDTarea : %d\n",tarea[i]->TareaID);
			printf("     Descripcion: %s\n",tarea[i]->descripcion);
			printf("     Duracion: %d\n",tarea[i]->duracion);
			printf("\n");
		}
	}	
}


