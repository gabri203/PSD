typedef struct point *point;

point creaPunto(float x, float y);
float ascissa(point p);			
float ordinata(point p);
float distanza(point p1, point p2);	
point centroide(point punti[], int n);
void sposta(point p, float deltaX, float deltaY);