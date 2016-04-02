#include<struct.h>
#include<prototypes.h>


void InitializeRectangle(struct Shape *s, double v1, double v2, double v3, double v4) {
	s->st = ST_Rectangle;
	s->su.r.minX = v1;
	s->su.r.maxX = v2;
	s->su.r.minY = v3;	
	s->su.r.maxY = v4;
	
	s->ft.GetArea = GetRectangleArea;
	s->ft.GetBoundingBox = GetRectangleBoundingBox;
}
void InitializeCircle(struct Shape *s, double r, double o, double oY) {
	s->st = ST_Circle;
	
	s->su.c.radius = r;
	s->su.c.origin = o;
	s->su.c.originY = oY;

	s->ft.GetArea = GetCircleArea;
	s->ft.GetBoundingBox = GetCircleBoundingBox;
}
void InitializeTriangle(struct Shape *s, double v1, double v2, double v3, double v4) {
	s->st = ST_Triangle;

	s->su.t.pt1X = v1;
	s->su.t.pt2X = v2;
	s->su.t.minY = v3;
	s->su.t.maxY = v4;
	
	s->ft.GetArea = GetTriangleArea;
	s->ft.GetBoundingBox = GetTriangleBoundingBox;
}


double GetRectangleArea(struct Shape *s) {
	return ((s->su.r.maxX)-(s->su.r.minX))*((s->su.r.maxY)-(s->su.r.minY));	
}
double GetCircleArea(struct Shape *s) {
	return (3.14159*(s->su.c.radius)*(s->su.c.radius));
}
double GetTriangleArea(struct Shape *s) {
	return (((s->su.t.pt2X)-(s->su.t.pt1X))*((s->su.t.maxY)-(s->su.t.minY))/2);
}


void GetRectangleBoundingBox(struct Shape *s, double *bbox) {
	bbox[0] = (s->su.r.minX);
	bbox[1] = (s->su.r.maxX);
	bbox[2] = (s->su.r.minY);
	bbox[3] = (s->su.r.maxY);
}
void GetCircleBoundingBox(struct Shape *s, double *bbox) {
	bbox[0] = (s->su.c.origin)-(s->su.c.radius);
	bbox[1] = (s->su.c.origin)+(s->su.c.radius);
	bbox[2] = (s->su.c.originY)-(s->su.c.radius);
	bbox[3] = (s->su.c.originY)+(s->su.c.radius);
}
void GetTriangleBoundingBox(struct Shape *s, double *bbox) {
	bbox[0] = (s->su.t.pt1X);
	bbox[1] = (s->su.t.pt2X);
	bbox[2] = (s->su.t.minY);
	bbox[3] = (s->su.t.maxY);
}

