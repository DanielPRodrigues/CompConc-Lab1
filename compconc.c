#include <stdio.h>
#include <pthread.h>
#define tam 10000 //tamanho do vetor

int ident[tam]; //vetor com os valores

void * threadzada (void *arg)
{
    int i;
    int k = * (int *) arg;
    if(k==tam/2) //diferenciar uma thread da outra no for
        i=0;
    if(k==tam)   //diferenciar uma thread da outra no for
        i=tam/2;
    for(i;i<k;i++){
    int quadrado = ident[i];
    ident[i]=ident[i]*ident[i];
    printf("O numero %d ao quadrado e igual a %d\n",quadrado,ident[i]);}
    pthread_exit(NULL);
}
int main()
{
    int l;
    int k[2]={tam/2,tam};
    for(l=0;l<tam;l++){
   ident[l]=rand()%100+1;} //pensei em diversos modos de botar os valores no vetor, mas achei mais interessante colocar valores aleatórios entre 1 e 100
   pthread_t tid[tam]; //identificador da thread
   if(pthread_create(&tid[0],NULL,threadzada,&k[0]))//primeira thread criada
        printf("deu ruim na thread\n");
   if(pthread_create(&tid[1],NULL,threadzada,&k[1]))//segunda thread criada
        printf("deu ruim na thread\n");
    for(l=0;l<2;l++){
    if(pthread_join(tid[l],NULL))
       printf("deu ruim na thread\n");
    }
    printf("\nThread Principal Finalizada\n");
    pthread_exit(NULL);



return 0;
}
