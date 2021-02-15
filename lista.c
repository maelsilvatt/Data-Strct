#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*Variáveis globais*/
typedef struct lista Lista;
struct lista {
	int info;
	Lista *prox;
};

/*Protótipos das funções*/
Lista* lst_cria(){
	return NULL;
}

int lst_vazia(Lista *l){
	return (l==NULL);
}

Lista* lst_remove_rec(Lista *l, int info){
	if(!lst_vazia(l))
		if(l->info==info){
			Lista* lAux = l;
			l = l->prox;
			free(lAux);
		}
		else{
			l->prox = lst_remove_rec(l->prox,info);
		
	}
	return l;
	
	int lst_vazia(Lista *l){
		return (l==NULL);
	}

}

void lst_imprime_invertida_rec(Lista* l){
	if(lst_vazia(l)){
	return;
		}else{
			lst_imprime_invertida_rec(l->prox);
			printf("info: %d\n",l->info);
		}
}

void lst_imprime_rec (Lista *l){
	if (lst_vazia (l))    
		return;
  			else
    		{      
				printf ("info: %d\n", l->info);
				lst_imprime_rec (l->prox); 
			}
		}
		
Lista *lst_remove (Lista *l, int info)
	{
  	if (l != NULL){
    Lista *lAux = l->prox;     
    
	if (l->info == info){
		free (l);
		return lAux;	
	}else
	
		{
		Lista *lAnt = l;
		while (lAux != NULL)
	    	{
	    		if (lAux->info == info)
			{
				lAnt->prox = lAux->prox;
				free (lAux);
		  		break;
		}else
		
	{
	lAnt = lAux;
	lAux = lAux->prox;		
	
	}
	    
}
	
}
    
}
  
return l;
}

void lst_libera(Lista *l){
	Lista* lprox;
	
	while(l!=NULL){
		lprox = l->prox;
		free(l);
		l = lprox;
	}
}

void lst_imprime(Lista *l){
	Lista* lAux = l;
	
	while(lAux!=NULL){
		printf("Info = %d\n",lAux->info);
		lAux = lAux->prox;
	}
}

Lista* lst_insere(Lista *l, int info){
	Lista* lAux = (Lista*)malloc(sizeof(Lista));

	lAux->info = info;
	lAux->prox = l;

	return lAux;
}

//Função para verificar o comprimento das estruturas:
int comprimento(Lista* l){
	Lista* lAux = l;
	int n=0;
		
	while(lAux!=NULL){
		n++;
		lAux = lAux->prox;
	}
	return n;
}

//Função para verificar quantas estruturas possuem no campo "info" um numero menor que n:
int menores(Lista* l, int n){
	Lista* lAux = l;
	int k=0;
	
	while(lAux!=NULL){
		if(lAux->info<n){
			k++;
		}
		
	lAux = lAux->prox;
	}
	
	return k;
}

//Função para somar os elementos no campo "info":
int soma(Lista* l){
	Lista* lAux = l;
	int k=0;
	
	while(lAux!=NULL){
		k=k+lAux->info;
		lAux = lAux->prox;
	}
	
	return k;
}
//Função para verificar quantos nós possuem um número primo no campo "info":
int primos(Lista* l){
	Lista* lAux = l;
	int k=0; int i; int j=0;
	
	while(lAux!=NULL){
		j = 0;
		
		for(i=2; i<=lAux->info; i++){
			
			if(lAux->info%i==0){
				j++;
				
			}	
		}
		
		if(j==1){
			k++;
		}
		
		lAux = lAux->prox;
	}
	
	return k;
}

//Função para concatenar listas:
Lista* lst_conc(Lista* l1, Lista* l2){
	Lista* lAux1 = l1;
	Lista* lAux2 = l2;
	Lista* lAux3 = lst_cria();
	Lista* lAux4 = lst_cria();
	
	while(lAux1!=NULL){
		lAux3 = lst_insere(lAux3, lAux1->info);
		lAux1 = lAux1->prox;
	}
	
	while(lAux2!=NULL){
		lAux1 = lst_insere(lAux1, lAux2->info);
		lAux2 = lAux2->prox;
	}
	
	
	while(lAux1!=NULL){
		lAux3 = lst_insere(lAux3, lAux1->info);
		lAux1 = lAux1->prox;
	}
	
	while(lAux3!=NULL){
		lAux4 = lst_insere(lAux4, lAux3->info);
		lAux3 = lAux3->prox;
	}
	
	return lAux4;
}

//Função para subtrair nós repetidos entre duas listas:
Lista* lst_diferenca(Lista* l1, Lista* l2){
	Lista *lAux1 = l1;
	Lista *lAux2 = l2;
	
	while(lAux1!=NULL){
		if(lAux1->info == lAux2->info){
			l1 = lst_remove (lAux1, lAux2->info);
			
		}
		
		lAux2 = lAux2->prox;
		
		if(lAux2 == NULL){
			lAux2 = l2;
			lAux1 = lAux1->prox;
			
		}
	}
	return l1;
}
