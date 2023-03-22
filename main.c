#include <stdio.h>
#define MAX(i, j) (((i) > (j)) ? (i) : (j))
#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

polynomial a = { 5, {10, 0, 0, 0, 6, 3} };

polynomial poly_mul(polynomial A, polynomial B) {
	polynomial C; // 결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {
			C.coef[Cpos++] = A.coef[Apos++] * B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void print_poly(polynomial p) {
	for (int i = p.degree; i > 0; i--) {
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	}
	printf("%3.1f \n", p.coef[p.degree]);
}

int main(void) {
	polynomial a = {3, {4, 3, 2, 1}};
	polynomial b = {2, {3, 2, 8}};
	polynomial c;
	polynomial x = {6, {7, 0, 0, 5, 9, 0, 1}};
	polynomial y = {3, {5, 2, 1, 10}};
	polynomial z;

	printf("결과 확인 1\n");
	print_poly(a);
	print_poly(b);
	c = poly_mul(a, b);
	printf("-----------------------------------------------------------------------------\n");
	print_poly(c);
	printf("\n결과 확인 2\n");
	print_poly(x);
	print_poly(y);
	z = poly_mul(x, y);
	printf("-----------------------------------------------------------------------------\n");
	print_poly(z);

	system("pause");
	return 0;
}