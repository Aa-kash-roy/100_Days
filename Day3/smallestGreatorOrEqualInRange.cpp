/*
    @Akash kumar
    -->Segment tree Application
    Minimal Number ( Not index ) Greator than or
    equal to a specified number with no modification.

    Here we will use merge sort tree.
    Key Idea:
    1. Segment Tree node will consist of a sorted
    list of number in range [l-r].
    2. In query will use Binary search to get the
    ans in Base case...!
*/
vector<int> t[4*MAXN+1];
void build(int arr[],int v,int tl,int tr){

    if(tl==tr){
        t[v]= vector<int> (1,arr[tl]);
    }
    else
    {
        int tm=(tl+tr)/2;
        build(arr,2*v,tl,tm);
        build(arr,2*v+1,tm+1,tr);
        // merge two vector in sorted form 
        // In O(n) time
        merge(t[v*2].begin(),t[v*2].end(),t[2*v+1].begin(),
                t[v*2+1].end(),back_inserter(t[v]));
    }
}

int query(int v,int tl,int tr,int l,int r,int k){

    if(l>r)
        return INT_MAX;
    else if(tl==l && tr==r)
    {
        auto idx = lower_bound(t[v].begin(),t[v].end(),k);
        if(idx==t[v].end())
            return INT_MAX;
        return int(*idx);
    }
    else
    {
        int tm=(tl+tr)/2;
        return min(query(2*v,tl,tm,l,min(r,tm),k),
            query(2*v+1,tm+1,tr,max(tm+1,l),r,k));
    }
}
