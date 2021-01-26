#include <stdio.h>

void main()
{
	int i,j;
	char array[6][6];
	int position_array[6][6];

	for (j = 0; j < 6; j++)
		for (i = 0; i < 6; i++)
			array[i][j] = 1;

	for (i = 0; i < 6; i++)
	{
		array[0][i] = 0;
		array[i][0] = 0;
		array[5][i] = 0;
		array[i][5] = 0;
	}

	//랜덤으로 position_array에서 a~f 문자를 섞음(if array==1인 곳에서)

}