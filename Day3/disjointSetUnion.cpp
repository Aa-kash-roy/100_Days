// Disjoint Set and Union..DSU tag Problems!

/* 
    1. Given n points which are initially a set 
    with one element.
    2. Combine Two sets
    3. Query on which set the specific element is from.
        make_set()
        union_set()
        find_set()

    Applications:
    1.Connected component in a graph.

    After forming the disjoint union set find number
    of node whose parent are same as node count of such
    node are number of component.
    
*/
//--------------------------------------//

int par[100001],sz[100001];
void make_set(int v){
    par[v]=v;
    sz[v]=1;
}

int find(int node){
    if(par[node]==node)
        return node;
    return par[node]= find(par[node]);
}

void union_set(int u,int v){

    u=find(u);
    v=find(v);
    if(u==v) return;
    else
    {
        if(sz[u] < sz[v])
            swap(u,v);
        par[v]=u;
        sz[u]=sz[u]+sz[v];
    }
}

//--------------------------------------//
