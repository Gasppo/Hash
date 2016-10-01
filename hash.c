#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "f_hash.c"

#define TAM_INICIAL 100
//LE VOY A PONER G A TODAS LAS DOCUMENTACIONES QUE HICE YO, TRATA DE PONERLE L A LAS TUYAS
//Son documentaciones para nosotros, y hay que borrarlas para la entrega

//ENUMERA LOS ESTADOS L
typedef enum {VACIO, BORRADO, LLENO} estado_t;

//LA ESTRUCTURA NODO_HASH G
typedef struct nodo_hash {
    const char* clave;
    void* dato;
    estado_t estado;
} nodo_hash_t;

//LA ESTRUCTURA HASH G
struct hash {
    size_t cantidad;
    size_t tamanio;
    hash_destruir_dato_t destruir_dato;
    //VA UN SOLO ASTERIZCO PORQUE EL VECTOR TIENE LOS NODOS ADENTRO L
    nodo_hash_t* tabla;
};

//LA ESTRUCTRUA ITERADORA DE HASH G
struct hash_iter {
    const hash_t* hash;
    size_t posicion;
};

//----------------------Primitivas del hash------------------------

//FUNCION PARA CREAR EL HASH G
hash_t *hash_crear(hash_destruir_dato_t destruir_dato){
    hash_t* hash = malloc(sizeof(hash_t));
    if (hash == NULL){
     return NULL;
    }

    hash->tabla = malloc(TAM_INICIAL * sizeof(nodo_hash_t));
    if (hash->tabla == NULL) {
        free(hash);
        return NULL;
    }

    //PONE TODOS LOS ESTADOS EN VACIO L
    for(int i = 0; i < 100; i++){
        hash->tabla[i].estado = VACIO;
    }

    hash->cantidad = 0;
    hash->tamanio = TAM_INICIAL;
    hash->destruir_dato = destruir_dato;
    return hash;
}

//Devuelve la cantidad de elementos guardados L
size_t hash_cantidad(const hash_t *hash){
    return hash->cantidad;
}

//Devuelve si la clave pertenece o no al hash
bool hash_pertenece(const hash_t *hash, const char *clave);



//----------------------Primitivas de los nodos--------------------

//CREAR UN NODO_HASH (Es una funcion auxiliar para facilitar el creado de los nodos) G
/*nodo_hash_t* nodo_hash_crear(const char *clave, void *dato){
    nodo_hash_t* nodo = malloc(sizeof(nodo_hash_t));
    if (nodo == NULL){  
     return NULL;
    }
    nodo->clave = strdup(clave);
    nodo->dato = dato;
    nodo->estado = VACIO;
    return nodo;
}*/

//----------------------Primitivas del iterador--------------------



