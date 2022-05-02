###El Ritmi
en un puntero doble , que esté cargado con punteros a estructuras 
se debe reservar memoria para el primer puntero con la cantidad de estructuras
que tendra,punterodoble=(struc**)malloc(elementos*sizeof(struct*))
luego por cada uno de los punteros que apuntan a estructuras hay que reservar memoria , 
punterosimple[elemento]=(struct*)malloc(sizeof(struct))