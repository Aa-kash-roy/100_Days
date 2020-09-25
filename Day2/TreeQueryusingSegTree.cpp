/* 
    @Akash Kumar
    Consider a Tree where each node is assigned a
    value and Our task is to support the following
    queries
    1. Update the value of the node
    2. Calculate the sum of values in the subtree
    of a node..

    Key concepts
    use dfs to construct tree traversal array which
    contains nodeId, subtreesize, nodeValue

    And then use segment tree over the nodeValue
    array for queries..!

    Read from book
*/  
#include<bits/stdc++.h>
using namespace std;
#define pb          push_back
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define endl        "\n"
#define fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int         long long int
#define mod         1000000007
#define test        int t;cin>>t;while(t--)
#define REP(i,a,b)  for(int i=a,i<=b;i++)
#define MAXN        100001

//Graph input variables..!
vi adj[MAXN],dfsTree;
int subTree[MAXN],val[MAXN];
int n;

int t[4*MAXN +1];
// This dfs traversal gives the reqd three array.
void dfs(int src,int par){
    dfsTree.pb(src);
    subTree[src]++;
    for(auto x:adj[src]){
        if(x!=par)
            dfs(x,src);
    }
    subTree[par]+=subTree[src];
}
//Segement tree code...!

void build(int arr[],int v,int tl,int tr){
    if(tl==tr)
        t[v]=arr[tl];
    else
    {
        int tm=(tl+tr)/2;
        build(arr,2*v,tl,tm);
        build(arr,2*v+1,tm+1,tr);
        t[v]=t[2*v]+t[2*v+1];
    }
}

// remember the query range are l->r and 
// Zero based indexing..!
int query(int v,int tl,int tr,int l,int r){

    if(l>r)
        return 0;
    else if(l==tl && r==tr)
        return t[v];
    else{

        int tm=(tl+tr)/2;
        return query(2*v,tl,tm,l,min(tm,r)) +
        query(2*v+1,tm+1,tr,max(tm+1,l),r);
    }
}

void update(int v,int tl,int tr,int idx,int val){

    if(tl==tr)
        t[v]=val;
    else{

        int tm=(tl+tr)/2;
        if(idx <= tm)
            update(2*v,tl,tm,idx,val);
        else
            update(2*v+1,tm+1,tr,idx,val);
        t[v]=t[2*v]+t[2*v+1];
    }
}

//----------------------------------//

int32_t main()
{
    // input + build Array
    cin>>n;
    int u,v;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    dfs(1,0);

    //--------------------------------//

    // Using segment tree for query processing

    int hash[MAXN];
    memset(hash,0,sizeof(0));
    for(int i=0;i<dfsTree.size();i++)
        hash[dfsTree[i]]=i;
    // Hash array is map of nodeId from original
    // to dfsTree array ..!
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=val[dfsTree[i]];
    }
    
    build(arr,1,0,n-1);

    // query is we want to find out the sum of nodes in
    // the subtree of nodeId = k;

    int query1=4,idx=hash[4];
    int l=hash[4],r=hash[4]+subTree[hash[4]]-1;

    cout<<query(1,0,n-1,l,r)<<endl;
    update(1,0,n-1,hash[4],100);
    cout<<query(1,0,n-1,l,r)<<endl;

    return 0;
}
