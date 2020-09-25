/*
    counting the number of zeores and searching for
    Kth zero. in range [l-r]
    with updation using segment tree.

    It can be modelled as counting frequency of 
    a fixed number in range with updation 

    ** Finding index of kth occurance of number
*/

int n,t[4*MAXN+1];

void build(int arr[],int v,int tl,int tr){

    if(tl==tr){
        if(arr[tl]==0)
            t[v]=1;
        else
            t[v]=0;
    }
    else
    {
        int tm=(tl+tr)/2;
        build(arr,2*v,tl,tm);
        build(arr,2*v+1,tm+1,tr);
        t[v]=(t[2*v]+t[2*v+1]);
    }
}

int query(int v,int tl,int tr,int l,int r){

    if(l>r)
        return 0;
    else if(tl==l && tr==r)
        return t[v];
    else
    {
        int tm=(tl+tr)/2;
        return query(2*v,tl,tm,l,min(r,tm))+
            query(2*v+1,tm+1,tr,max(tm+1,l),r);
    }
}

void update(int v,int tl,int tr,int new_pos,int val){

    if(tl==tr)
    {
        if(val==0)
            t[v]=1;
        else
            t[v]=0;
    }
    else
    {
        int tm=(tl+tr)/2;
        if(new_pos <= tm){
            update(2*v,tl,tm,new_pos,val);
        }
        else
            update(2*v+1,tm+1,tr,new_pos,val);

        t[v]=(t[2*v]+t[2*v+1]);
    }
}


/*
    to solve the problem of finding the k-th zero 
    in the array a[]. To do this task, we will 
    descend the Segment Tree, starting at the root 
    vertex, and moving each time to either the 
    left or the right child, depending on which segment
    contains the k-th zero. In order to decide to 
    which child we need to go, it is enough to look at 
    the number of zeros appearing in the segment 
    corresponding to the left vertex. If this precomputed 
    count is greater or equal to k, it is necessary to
    descend to the left child, and otherwise descent to 
    the right child. Notice, if we chose the right child, 
 we have to subtract the number of zeros of the left child from k.

In the implementation we can handle the special case,
 a[] containing less than k zeros, by returning -1.
*/
int find_kth(int v,int tl,int tr,int k){

    if(k > t[v])
        return -1;
    if(tl==tr)
        return tl;

    int tm=(tl+tr)/2;
    if(t[2*v] >=k)
        return find_kth(2*v,tl,tm,k);
    else
        return find_kth(2*v+1,tm+1,tr,k-t[2*v]);
}

