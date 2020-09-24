/*

    There are N points on 2D plane located as p(x,y)
    what is the maximum possible manhattan distance
    between two points
    3
    1 1
    2 4
    3 2
    output: 4
    
*/
int32_t main()
{
    int n;cin>>n;

    int x,y;
    vector<int> xCod,yCod;

    for(int i=0;i<n;i++){
        cin>>x>>y;
        xCod.pb(x+y);
        yCod.pb(y-x);
    }

    sort(all(xCod));
    sort(all(yCod));

    int ans= abs(xCod[0]-xCod[n-1]);
    ans = max(ans,abs(yCod[0]-yCod[n-1]));

    cout<<ans<<endl;

    return 0;
}
