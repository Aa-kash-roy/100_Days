// Disjoint Set and Union..DSU tag Problems!

/*  
    Author:@Akash Kumar
    Sometimes in specific applications of the DSU
    you need to maintain the distance between
    a vertex and the representative of its set 
    (i.e. the path length in the tree from the current
    node to the root of the tree).

    if we store the distance to the parent as additional
    information for each node.

    In the implementation it is convenient to 
    use an array of pairs for parent[] and the function 
    find_set now returns two numbers: the representative 
    of the set, and the distance to it.
    
*/
//--------------------------------------//

pair<int,int> par[100001],sz[100001];
void make_set(int v){
    par[v]={v,0};
    sz[v]=1;
}

pair<int,int> find(int node){
    if(par[node].F!=node){
        int len = par[v].second;
        par[v] = find_set(par[v].F);
        par[v].S += len;
    }
    return par[v];
}

void union_set(int u,int v){

    u=find(u).F;
    v=find(v).F;
    if(u==v) return;
    else
    {
        if(sz[u] < sz[v])
            swap(u,v);
        par[v]={u,1};
        sz[u]=sz[u]+sz[v];
    }
}

//--------------------------------------//
