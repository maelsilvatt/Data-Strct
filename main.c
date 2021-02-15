#include <stdio.h>
#include <locale.h>
#include "lista.h"

int main(void){
setlocale(LC_ALL, "Portuguese");
Lista* l1 = lst_cria();
l1 = lst_insere(l1,6);
l1 = lst_insere(l1,13);
l1 = lst_insere(l1,25);
l1 = lst_insere(l1,28);
l1 = lst_insere(l1,40);
l1 = lst_remove(l1,25);
l1 = lst_remove_rec(l1,40);
lst_imprime(l1);
lst_imprime_invertida_rec(l1);

printf("Num. n�s c/ info < que 22: %d\n",menores(l1,22));
printf("O comprimento da lista � %d\n",comprimento(l1));
printf("Soma dos valores dos n�s %d\n",soma(l1));
printf("Num. n�s com val. primos � %d\n",primos(l1));
Lista* l2 = lst_cria();

l2 = lst_insere(l2,28);
l2 = lst_insere(l2,130);
Lista* l3=lst_conc(l1,l2);
lst_imprime(l3);
l1=lst_diferenca(l1,l2);
lst_imprime(l1);
lst_libera(l1);
lst_libera(l2);
lst_libera(l3);

system("PAUSE");
return 0;
}
