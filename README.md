###El Ritmi
en 
un puntero doble , que esté cargado con punteros a estructuras 
se debe reservar memoria para el primer puntero con la cantidad de estructuras
que tendra,punterodoble=(struc**)malloc(elementos*sizeof(struct*))
luego por cada uno de los punteros que apuntan a estructuras hay que reservar memoria , 
punterosimple[elemento]=(struct*)malloc(sizeof(struct))

en el ejercicio 2 _5_6_7_8 no me salio lo de conseguir el error del branch
nose bien porqué no me salio , pero bueno , ya fue , las funciones solicitadas estan en el main 
hay que descomentar nomas y funca todo