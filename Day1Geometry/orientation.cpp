// Program to find the position of a 
// point with respect to line


/* Orientation 
	P1 and P2 points of p1---p2 and position of Q1.
	slope of p1 p2
	and slope of p2 q1 
	1. if slope of p1-p2 is less than p2-q1 them 
	counterclockwise.
	2. if slope of p1-p2 == p2-q1 then collinear
	3. Else Clockwise direction

*/

int checkOrientation(pair<int,int> p1,pair<int,int> p2,pair<int,int> q1){

	return (p2.S-p1.S)*(q1.F-p2.S) - (q1.S-p2.S)*(p2.F-p1.F);
}

int32_t main()
{
	pair<int,int> p1,p2,q1;

	int dir=checkOrientation(p1,p2,q1);
	if(dir==0)
		cout<<"collinear"<<endl;
	else if(dir < 0)
		cout<<"counterclockwise"<<endl;
	else
		cout<<"clockwise"<<endl;

	return 0;
}
