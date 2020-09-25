// @Akash kumar

// segment tree implementation over array A 
// for sum in the range with point updation
// remember here index is zero based for
// geeting query and updation 
#define MAXN        100001

// t represents the segment tree..!
int n,t[4*MAXN+1];

void build(int arr[],int v,int tl,int tr){
    if(tl==tr)
        t[v]=arr[tl];
    else{
        // Building left and right tree..!
        int tm=(tl+tr)/2;
        build(arr,2*v,tl,tm);
        build(arr,2*v+1,tm+1,tr);

        t[v]=t[2*v]+t[2*v+1];
    }
}

int sum(int v,int tl,int tr,int l,int r){

    // If l>r return a value which have no affect
    // on result
    if(l>r)
        return 0;
    // when the range is completely overlapping..!
    else if(tl==l && tr==r)
        return t[v];
    else{

        int tm=(tl+tr)/2;
        return sum(2*v,tl,tm,l,min(tm,r))+
        sum(2*v+1,tm+1,tr,max(tm+1,l),r);
        // Here + can be changed to other function
        // which return results required min,max xor etc.
    }
}

void update(int v,int tl,int tr,int new_pos,int val){

    // when position in the segment tree is found
    if(tl==tr)
        t[v]=val;
    else {

        int tm=(tl+tr)/2;
        // Based on position of updation switch to 
        // different branches of the tree..!
        if(new_pos <= tm)
            update(2*v,tl,tm,new_pos,val);
        else
            update(2*v+1,tm+1,tr,new_pos,val);

        t[v]=t[2*v]+t[2*v+1];
    }
}
