# Tabela Hash: Endereçamento fechado

![Linguagem C](https://img.shields.io/badge/Linguagem-C-green.svg)


<h1> Problema</h1>

Implementação de duas tabelas hash: i) endereçamento fechado e; ii) endereçamento aberto por hash dupla. O trabalho deve receber diretamente no seu código um vetor de no mínimo 20 valores inteiros, os quais serão utilizados como entrada  para as duas estruturas que, por sua vez, são criadas com o dobro do tamanho do vetor (i.e., número primo maior que esse valor dobro). Feito isso, como resultado da execução deve-se apresentar o número de colisões ocorridas para ambas as estruturas quando o mesmo vetor é armazenado. Por fim, contemplar no README.mb uma breve discussão dos motivos que levaram uma estrutura a apresentar melhores resultados. .
<br></br>

<h1>Implementação </h1>
<h2>Funções</h2>
Para a implementação foram desenvolvidas as funções <code>Initialize</code>, <code>Imprime</code> e <code>Insert</code>.
<h2>Initialize</h2>
A função <code>Initialize</code> é implementada para criar as duas listas que serão utilizadas para a hash fechada, setar (-1) para todas as posições definindo que elas estão sem chaves e zerando o seu valor.
<ul>

```   C
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
 ```
<br></br>
<h2>Imprime</h2>
A função <code>Imprime</code> printa as chaves e valores.
<br></br>

```   C
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
 ```
<h2>Insert</h2>
A função <code>Insert</code> realiza o calculo da Hash e verifica se a posição não tem uma chave e valor, caso já tenha, adiciona a chave e valor a segunda lista.
<br></br>

```   C
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
 ```
<h1>Resultados </h1> 
Ao criar inserir 20 Chaves e valores em uma Hash de 41 posições (o primeiro numero primo maior que o dobro do tamanho do vetor) obtemos: 

<p align = 'center' ><img src="https://user-images.githubusercontent.com/56900319/177896795-32f5bf80-6e14-4a7d-986d-9a725ccbad60.png" width = "60%"></p>



Sendo printado chave, valor de forma com que as chaves e valores printados a direita são da segunda lista, ou seja são valores que colidiram, tambem é printado a quantidade de colisões que aconteceram na execução.
# Compilação e Execução


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
