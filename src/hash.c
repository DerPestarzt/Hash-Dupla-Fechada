#include "hash.h"


void Initialize(HashTable *h, int M){
	h->table = (TableLine*) malloc (M * sizeof(TableLine));

	for(int j=0; j<M; j++){
		h->table[j].dados = (DataTable*) malloc (M * sizeof(DataTable));
		for(int i=0; i<M; i++){
			h->table[j].dados[i].key   = -1;
			h->table[j].dados[i].value = 0;
		}
		h->table[j].W = 0;
	}
	h->M = M;
}


void Imprime(HashTable *h){
	for(int j=0; j<h->M; j++){
		if(h->table[j].W != 0){
			for(int i=0; i<h->table[j].W; i++){
				printf("%d -> %d\t", h->table[j].dados[i].key, h->table[j].dados[i].value);
			}
			printf("\n");
		}
	}
	printf("\n");
}


void Insert(HashTable *h, int key, int value, int *cont){
	int idx = hash(key, h->M);
	if (h->table[idx].W == h->M){
		printf("Está Cheia\n");
		return;
	}
	if (h->table[idx].W != 0){
		(*cont)++;
	}
	
	h->table[idx].dados[h->table[idx].W].key   = key;
	h->table[idx].dados[h->table[idx].W].value = value;
	h->table[idx].W++;
}


