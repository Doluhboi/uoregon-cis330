/* struct.h Megan McMillan 4/24/14 */

typedef struct {
	double minX, maxX, minY, maxY;
} Rectangle;

typedef struct {
	double pt1X, pt2X, minY, maxY;
} Triangle;

typedef struct {
	double radius, origin, originY;
} Circle;

typedef union {
	Circle c; 
	Rectangle r;
	Triangle t;
} ShapeUnion;

typedef enum {
	ST_Rectangle, 
	ST_Circle, 
	ST_Triangle
} ShapeType;

struct Shape;

typedef struct {
	double (*GetArea)(struct Shape *);
	void (*GetBoundingBox)(struct Shape*, double *);
} FunctionTable;

struct Shape {
	ShapeUnion su;
	ShapeType st;
	FunctionTable ft;
};


