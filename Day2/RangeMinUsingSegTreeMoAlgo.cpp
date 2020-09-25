/* 
    @Akash Kumar
    You are given a list of N numbers and Q queries. Each query is 
    specified by two numbers i and j; the answer to each query is
     the minimum number between the range [i, j] (inclusive).

    Note: the query ranges are specified using 0-based indexing.
    1.Using Mo's Algorithmn
    2.Using segment tree
*/ 
// Using Mo's Algorithmn...

int len=700;
vector<int> b(len);
 
void compute(vi a){
    int n=a.size();
    for(int i=0;i<len;i++){
        b[i]=INT_MAX;
    }
 
    for(int i=0;i<n;i++){
        b[i/len]=min(b[i/len],a[i]);
    }
}
 
int getmin(int l,int r,vi a){
 
    int ans=INT_MAX;
    int c_l=l/len,c_r=r/len;
    if(c_l==c_r)
    {
        for(int i=l;i<=r;i++)
            ans=min(ans,a[i]);
    }
    else{
        for(int i=l,end=(c_l+1)*len-1;i<=end;i++){
            ans=min(ans,a[i]);
        }
        for(int i=c_l+1;i<=c_r-1;i++)
        {
            ans=min(ans,b[i]);
        }
        for(int i=c_r*len; i<=r; i++){
            ans=min(ans,a[i]);
        }
    }
    return ans;
 
}

//-------------------------------------//


//Segement tree code...! 
int n;
int t[4*MAXN +1];

void build(int arr[],int v,int tl,int tr){
    if(tl==tr)
        t[v]=arr[tl];
    else
    {
        int tm=(tl+tr)/2;
        build(arr,2*v,tl,tm);
        build(arr,2*v+1,tm+1,tr);
        t[v]=min(t[2*v],t[2*v+1]);
    }
}

// remember the query range are l->r and 
// Zero based indexing..!
int query(int v,int tl,int tr,int l,int r){

    if(l>r)
        return INT_MAX;
    else if(l==tl && r==tr)
        return t[v];
    else{

        int tm=(tl+tr)/2;
        return min(query(2*v,tl,tm,l,min(tm,r)),
        query(2*v+1,tm+1,tr,max(tm+1,l),r));
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
        t[v]=min(t[2*v],t[2*v+1]);
    }
}

//----------------------------------//



int32_t main()
{
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    build(arr,1,0,n-1);

    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        cout<<query(1,0,n-1,l,r)<<endl;
    }

    return 0;
}
