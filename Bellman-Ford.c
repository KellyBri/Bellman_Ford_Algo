// Bellman-Ford Algorithm


#include <stdio.h>
#include <stdlib.h>

struct node{
    int source;
    int destination;
    int weight;
    node *next;
};
node *head;
node *ptr, *temp;


int main() {
    
    unsigned int N, m, M, i, j, s, flag;
    float w;
    int d[51],parent[51];
    
    head=(node *)malloc(sizeof(node));
    head=NULL;
    
    scanf("%d %d",&N,&M);
    if (N>=1 && N<=50 && M>=1 && M<=200) {
        
        for (m=1; m<=M; m++) {
            
            scanf("%d %d %f", &i, &j, &w);
            if (i>N || i<1 || j>N || j<1 || i==j) break;
            
            ptr=(node *)malloc(sizeof(node));
            temp=(node *)malloc(sizeof(node));
            
            ptr->source=i;
            ptr->destination=j;
            ptr->weight=w;
            temp=head;
            ptr->next=temp;
            head=ptr;
        }
        
        scanf("%d",&s);
        for (i=0; i<=50; i++) d[i]=2147483000;
        d[s]=0;
        if (s<=N && s>=1) {
            for (i=1; i<=N-1; i++) {
                ptr=head;
                while (ptr!=NULL) {
                    if (d[ptr->destination]>d[ptr->source]+ptr->weight) {
                        d[ptr->destination]=d[ptr->source]+ptr->weight;
                        parent[ptr->destination]=ptr->source;
                    }
                    ptr=ptr->next;
                }
            }
            ptr=head;
            while (ptr!=NULL) {
                if (d[ptr->destination]>d[ptr->source]+ptr->weight) {
                    flag=1;
                    break;
                }
                ptr=ptr->next;
            }
            
            //output
            if (flag==1) {
                printf("There is a negative weight cycle in the graph");
            }else{
                for (i=1; i<=N; i++) {
                    printf("%d",d[i]);
                    if (i!=N) printf(" ");
                }
                printf("\n");
                for (i=1; i<=N; i++) {
                    printf("%d",parent[i]);
                    if (i!=N) printf(" ");
                }
                printf("\n");
            }
        }
    }
    return 0;
}