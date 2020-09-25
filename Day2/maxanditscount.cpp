/*

Author @Akash kumar
finding the maximum, we also have to find 
    the number of occurrences of the maximum.

// l and r should be given on basis of zero 
    indexing..1

// t represents the segment tree..!
    Key Ideas..!

    1. Only combine function will change from 
    problem to problem.
    2. Return value when l>r should have no effect
    on ans of query.
    3. Base case in build function and update 
    should be carefully taken


*/
int n;
pair<int,int> t[4*MAXN+1];


// Here combine function can be altered to change 
//  the results and solution to many problem..

pair<int,int> combine(pair<int,int> a, pair<int,int> b){
    pair<int,int> temp;
    temp.F = max(a.F,b.F);
    if(a.F == b.F)
        temp.S = a.S + b.S;
    else{
        int mx=max(a.F,b.F);
        if(a.F== mx)
            temp.S = a.S;
        else
            temp.S = b.S; 
    }
    return temp;
}

void build(int arr[],int v,int tl,int tr){
    if(tl==tr){
        t[v].F = arr[tl];
        t[v].S = 1;
    }
    else{
        // Building left and right tree..!
        int tm=(tl+tr)/2;
        build(arr,2*v,tl,tm);
        build(arr,2*v+1,tm+1,tr);

        t[v]= combine(t[2*v],t[2*v+1]);
    }
}

pair<int,int> QueryAns(int v,int tl,int tr,int l,int r){

    // If l>r return a value which have no affect
    // on result
    if(l>r)
        return {INT_MIN,0};
    // when the range is completely overlapping..!
    else if(tl==l && tr==r)
        return t[v];
    else{

        int tm=(tl+tr)/2;
        return combine(sum(2*v,tl,tm,l,min(tm,r)),
        sum(2*v+1,tm+1,tr,max(tm+1,l),r));
        // Here + can be changed to other function
        // which return results required min,max xor etc.
    }
}

void update(int v,int tl,int tr,int new_pos,int val){

    // when position in the segment tree is found
    if(tl==tr){
        t[v].F=val;
        t[v].S=1;
    }
    else {

        int tm=(tl+tr)/2;
        // Based on position of updation switch to 
        // different branches of the tree..!
        if(new_pos <= tm)
            update(2*v,tl,tm,new_pos,val);
        else
            update(2*v+1,tm+1,tr,new_pos,val);

        t[v]=combine(t[2*v],t[2*v+1]);
    }
}

