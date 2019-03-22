#pragma warning(disable:4996)
#include<stdio.h>
#include<math.h>
#define MAX 100

typedef struct xy {
	int visit;
	int x;
	int y;
} XY;

int N;
int tour[MAX];
double min;
double Tour(XY city[], int k, double curSum);
double distance(XY data1, XY data2);
void swap(XY city[], int i, int j);

int main() {
	char input[20];
	printf("파일 이름을 입력하세요: ");
	scanf("%s", input);
	FILE *fp = fopen(input, "r");
	fscanf(fp, "%d", &N);
	XY city[MAX];
	for (int i = 0; i < N; i++) {
		city[i].visit = i;
		fscanf(fp, "%d %d", &city[i].x, &city[i].y);
	}
	for (int i = 0; i < N; i++) {
		if (i == N - 1) min += distance(city[i], city[0]);
		else min += distance(city[i], city[i + 1]);
	}

	printf("%lf\n", Tour(city, 0, 0));
	printf("경로: [ ");
	for (int i = 0; i < N - 1; i++)
		printf("%d, ", tour[i]);
	printf("%d ]\n", tour[N - 1]);
	fclose(fp);
	getch();
	return 0;
}


double Tour(XY city[], int k, double Sum) { 
	if (k > 1)
		Sum += distance(city[k - 2], city[k - 1]);


	if (k == N) {
		Sum = Sum + distance(city[k - 1], city[0]);
		if (min > Sum) {
			min = Sum;
			for (int i = 0; i < N; i++) tour[i] = city[i].visit;
		}
		return min;
	}

	for (int i = k; i < N; i++) {
		double tmp = Sum;
		swap(city, k, i);
		Tour(city, k + 1, Sum);
		Sum = tmp;
		swap(city, k, i);
	}
	return min;

}


double distance(XY data1, XY data2) 
{
	return sqrt((data1.x - data2.x)*(data1.x - data2.x) + (data1.y - data2.y)*(data1.y - data2.y));
}

void swap(XY city[], int i, int j)
{
	XY tmp = city[i];
	city[i] = city[j];
	city[j] = tmp;
}