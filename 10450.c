#include <stdio.h>
#include <stdbool.h>

int main()
{
  int ax, ay, bx, by, cx, cy, dx, dy;
  
  scanf("%d%d%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
#ifdef DEBUG
  printf("%d %d %d %d %d %d %d %d\n", ax, ay, bx, by, cx, cy, dx, dy);
#endif
  int ab = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
  int bc = (bx - cx) * (bx - cx) + (by - cy) * (by - cy);
  int cd = (cx - dx) * (cx - dx) + (cy - dy) * (cy - dy);
  int da = (dx - ax) * (dx - ax) + (dy - ay) * (dy - ay);
  int ac = (ax - cx) * (ax - cx) + (ay - cy) * (ay - cy);
  int bd = (bx - dx) * (bx - dx) + (by - dy) * (by - dy);

  bool ab_cd_same = ab == cd;
  bool bc_da_same = bc == da;
  bool db_same = ab_cd_same && bc_da_same;
  bool four_same = db_same && (ab == bc);
  bool diag_same = ac == bd;

  int dyab = ay - by;
  int dxab = ax - bx;
  int dydc = dy - cy;
  int dxdc = dx - cx;
  bool abdc_parallel = dyab * dxdc == dydc * dxab;

  int dybc = by - cy;
  int dxbc = bx - cx;
  int dyad = ay - dy;
  int dxad = ax - dx;
  bool bcad_parallel = dybc * dxad == dyad * dxbc;
  
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
