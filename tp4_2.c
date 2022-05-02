#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarea{
int TareaID;//numero en ciclo iterativo
char *descripcion;
int duracion;//10-100
}Tarea;

void Cargar_tareas(Tarea **tareasPendientes,int cantTarea);

int main(){
	int cantTarea;
	printf("ingrese la cantidad de tareas a realizar: \n");
	fflush(stdin);
	scanf("%d",&cantTarea);
	fflush(stdin);
	printf("\n");
	Tarea **tareasPendientes;
	tareasPendientes=(Tarea**)malloc(cantTarea*sizeof(Tarea*));
	Tarea **tareasRealizadas;
	Cargar_tareas(tareasPendientes, cantTarea);
	free(*tareasPendientes);
	
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
