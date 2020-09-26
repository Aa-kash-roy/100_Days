/*
    @Akash kumar
    -->Segment tree Application
    Searching for an array prefix with a given amount.
    The task is to solve for a given x we have to
    quickly find smallest index i such that the sum of 
    first i elements of the array a[] is greator or 
    equal to x.
*/


//---------------------------------------//

// Here v=1,tl=0,tr=n-1,k=sum 
// It returns the index of element upto which 
// sum of array elements greator than or equal
// to k.

int find_idxPreSum(int v,int tl,int tr,int k){

    if(k > t[v])
        return -1;
    if(tl==tr)
        return tl;

    int tm=(tl+tr)/2;
    if(t[2*v] >=k)
        return find_idxPreSum(2*v,tl,tm,k);
    else
        return find_idxPreSum(2*v+1,tm+1,tr,k-t[2*v]);
}

//---------------------------------------//
