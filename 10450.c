#include <stdio.h>
#include <stdbool.h>

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  int dx;
  int dy;
} Vector;

Point readPoint()
{
  Point p;
  scanf("%d%d", &(p.x), &(p.y));
  return p;
}

void writePoint(Point p)
{
  printf("(%d, %d)\n", p.x, p.y);
}

Vector computeVector(Point a, Point b)
{
  Vector v = {b.x - a.x, b.y - a.y};
  return v;
}

void writeVector(Vector v)
{
    printf("(%d, %d)\n", v.dx, v.dy);
}

int length(Vector v)
{
  return v.dx * v.dx + v.dy * v.dy;
}

bool parallel(Vector v, Vector w)
{
  return v.dx * w.dy == v.dy * w. dx;
}

int main()
{
  Point a = readPoint();
  Point b = readPoint();
  Point c = readPoint();
  Point d = readPoint();

  Vector ab = computeVector(a, b);
  Vector bc = computeVector(b, c);
  Vector cd = computeVector(c, d);
  Vector da = computeVector(d, a);
  Vector ac = computeVector(a, c);
  Vector bd = computeVector(b, d);

  bool ab_cd_same = length(ab) == length(cd);
  bool bc_da_same = length(bc) == length(da);
  bool db_same = ab_cd_same && bc_da_same;
  bool four_same = db_same && (length(ab) == length(bc));
  bool diag_same = length(ac) == length(bd);

  bool abdc_parallel = parallel(ab, cd);
  bool bcad_parallel = parallel(bc, da);
  
  if (db_same) {
    if (four_same) {
      if (diag_same)
	printf("1\n");
      else 
	printf("3\n");
    } else {
      if (diag_same)
	printf("2\n");
      else
	printf("4\n");
    }
  } else {
    if (abdc_parallel || bcad_parallel)
      printf("5\n");
    else
      printf("6\n");
  }

  
  return 0;
}
