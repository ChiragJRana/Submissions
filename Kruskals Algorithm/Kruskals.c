    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>

    struct Edge
    {
         int source;
         int destination;
         int weight;
    };

    int V;
    int E;
    struct Edge* edge[15];
    struct Edge* solution[15];
    int count=0;

    void input()
    {
     printf("\nEnter the number of vertices: ");
     scanf("%d",&V);

     printf("\nEnter the number of edges: ");
     scanf("%d",&E);
     //edge = (struct Edge*)malloc(E*sizeof(struct Edge));
     printf("Enter the data in the form source, weight, destination\n");
     for(int i=0;i<E;i++)
     {
         edge[i] = (struct Edge*)malloc(sizeof(struct Edge));
         scanf("%d",&edge[i]->source);
         scanf("%d",&edge[i]->weight);
         scanf("%d",&edge[i]->destination);
     }
    }
    void sort_edges()
    {
     int min, min_index;
     for(int i=0; i<E-1; i++)
     {
         min=edge[i]->weight;
         min_index=i;
         for(int j=i;j<E;j++)
         {
             if(min>=edge[j]->weight)
             {
                 min=edge[j]->weight;
                 min_index=j;
             }
         }
         struct Edge *temp;
         temp=edge[i];
         edge[i]=edge[min_index];
         edge[min_index]=temp;
        }
    }
    int find(int parent[], int i)
    {
     if(parent[i]==-1)
        return i;
     return find(parent,parent[i]);
    }
    void Union(int parent[],int x,int y)
    {
        parent[x]=y;
    }
    void minimum_spanning_tree()
    {
     int n_sorted_edges =0;
     int n_solution_edges=0;
     int parent[15];
     for (int i = 0; i < 15; i++)
     {
         parent[i]=-1;
     }
     while(n_solution_edges<V-1 && n_sorted_edges<E)
     {
         struct Edge* new_edge = edge[n_sorted_edges++];
         int x = find(parent,new_edge->source);
         int y = find(parent,new_edge->destination);
         if(x!=y)
         {
             solution[n_solution_edges++]=new_edge;
             count++;
             Union(parent,x,y);
         }
     }
     printf("\nFollowing are the edges in the constructed MinimumSpanning Tree:\n");
     printf("No.\tSource\tDestination\tWeight\n");
     for (int i = 0; i < count; i++)
     {
        printf(" %d\t %d\t %d\t\t%d \n",i+1,solution[i]->source,solution[i]->destination,solution[i]->weight);
     }
    }
    int main()
    {
     input();
     sort_edges();
     printf("Sorted Edges are:\n ");
     printf("No.\tSource\tDestination\tWeight\n");
     for(int i=0;i<E;i++)
     {
        printf(" %d\t %d\t %d\t\t%d \n",i+1,edge[i]->source,edge[i]->destination,edge[i]->weight);
     }
     minimum_spanning_tree();
     return 0;
    }
