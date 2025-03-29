// area of triangle if vertices given
// remember to multiply all vertices (x*2, y*2);

struct point{
	int x, y;
};
int64_t triangle_area(point a, point b, point c) {
	return abs((b.x-a.x)*(c.y-b.y) - (b.y-a.y)*(c.x-b.x));
}

int64_t polygon_area(vector<point> &U) {
	int64_t A = 0;
	for(int i=2; i<U.size(); ++i) {
		A += triangle_area(U[0], U[i-1], U[i]);
	}
	// visualise the proof it's just keep on adding triangles from the start
	return A;
}
