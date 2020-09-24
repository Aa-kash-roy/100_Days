// Check weather two lines intersect or not

/*
	Given a line p1-q1 and line p2-q2. Check weather it intersect or
	not ???

	Case 1. Orientation of p1-q1-p2 != p1-q1-q2 and
	Orientation of p2-q2-p1 != p2-q2-q1 then lines 
	intersect.

	Case2. If any orientation is zero and some parts 
	of it lies on line i.e some portion of lines 
	are common two both the lines..!

*/

struct point {
	int x,y;
};

int orientation(point p,point q,point r){

	return (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
}

bool lieOnLine(point p,point q,point r){

	if((r.x <= max(p.x,q.x) && r.x >= min(p.x,q.x)) && (r.y >= min(p.y,q.y) 
		&& r.y <= max(p.y,q.y)))
		return true;
	return false;
}

bool intersect(point p1,point q1,point p2,point q2){

	int o1 = orientation(p1,q1,p2);
	int o2 = orientation(p1,q1,q2);
	int o3 = orientation(p2,q2,p1);
	int o4 = orientation(p2,q2,q1);

	// Case 1
	if(o1!=o2 && o3!=o4){
		return true;
	}
	// Case 2

	if(o1==0 && lieOnLine(p1,q1,p2))
		return true;
	if(o2==0 && lieOnLine(p1,q1,q2))
		return true;
	if(o3==0 && lieOnLine(p2,q2,p1))
		return true;
	if(o4==0 && lieOnLine(p2,q2,q1))
		return true;

	return false;
}
