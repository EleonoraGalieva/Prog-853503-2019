#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <string.h>
#include <math.h>
#include <conio.h>

/*3 �������. ��� �������. ����������� ���������, ���� ������� ���������
������������ ��������� ��������� �������:
� ������ ���������� ������ � ����� ���� �������� � ���������
������������.
� ����������, ����� �� �� ���� �������� ��������� �����������.
� ���� ��� ��������, �� ���������� ��� ������������
(����������, �������������, ��������������, �������������
����).
� ��������� �������� ������������� ������������.
� ��������� ������� ������������
� ���������� � ������ � ������ ���������.
� ����� �� ���������.*/


double Input() //������� ��� �������� ������������ ����� �����, ���������� ����� ������� 
{
	long result = 0;
	while (1)
	{
		int wrong_symbol = FALSE;
		size_t length = 1;
		char ch, *str = (char*)malloc(length * sizeof(char));
		while ((ch = getchar()) != '\n')
		{
			str[length - 1] = ch;
			length++;
			str = (char*)realloc(str, length * sizeof(char));
		}
		str[length - 1] = '\0';
		int period_counter = 0;
		for (int i = 0; i < length - 1; i++)
		{
			if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == ',' || str[i] == '-')
			{
				if (str[i] == '.' || str[i] == ',')
				{
					if (str[i] == ',')
						str[i] = '.';
					period_counter++;
				}
				continue;
			}
			else
			{
				printf("\n������������ ����! ���������� ��� ���:\n");
				str[0] = '\0';
				wrong_symbol = TRUE;
				break;
			}
		}
		if (period_counter > 1)
		{
			printf("\n������������ ����! ���������� ��� ���:\n");
			str[0] = '\0';
			wrong_symbol = TRUE;
		}
		if (!wrong_symbol)
		{
			result = atof(str);
			break;
		}
	}
	return result;
}

double Full_Input(double *x1, double *y1, double *x2, double *y2, int index) //���� ���� ������ ������������
{
	printf("������� ���������� ������ %d �������:\nX: ", index);
	*x1 = Input();
	printf("\nY: ");
	*y1 = Input();
	printf("������� ���������� ����� %d �������:\nX: ", index);
	*x2 = Input();
	printf("\nY: ");
	*y2 = Input();
	return sqrt(pow((*x2 - *x1), 2) + pow((*y2 - *y1), 2));
}

//����� ����������� �����������, ����� ���� ������ ������������ ������ ������ ���� ������ ������� �������.
int Possibility(double *length_1, double *length_2, double *length_3)
{
	if (((*length_1 + *length_2) > *length_3) && ((*length_2 + *length_3) > *length_1) && ((*length_1 + *length_3) > *length_2))
		return TRUE;
	else return FALSE;
}

void Triangle_Type(double *length_1, double *length_2, double *length_3)
{
	int ravn_st = FALSE, pr = FALSE, ravn_b = FALSE;
	if (*length_1 == *length_2 == *length_3)
		ravn_st = TRUE;
	double s1 = sqrt(pow(*length_2, 2) + pow(*length_3, 2));
	double s2 = sqrt(pow(*length_1, 2) + pow(*length_3, 2));
	double s3 = sqrt(pow(*length_2, 2) + pow(*length_1, 2));
	if (*length_1 == s1 || *length_2 == s2 || *length_3 == s3)
		pr = TRUE;
	if ((*length_1 == *length_2) || (*length_2 == *length_3) || (*length_1 == *length_3))
		ravn_b = TRUE;
	if (ravn_st==TRUE&&ravn_b==FALSE&&pr==FALSE)
		printf("\n������ ����������� �������� ��������������. ����� ������: %f, %f, %f", *length_1, *length_2, *length_3);
	else if (ravn_st==FALSE&&ravn_b==TRUE&&pr==FALSE)
		printf("\n������ ����������� �������� ��������������. ����� ������: %f, %f, %f", *length_1, *length_2, *length_3);
	else if (ravn_st==FALSE&&ravn_b==FALSE&& pr==TRUE)
		printf("\n������ ����������� �������� �������������. ����� ������: %f, %f, %f", *length_1, *length_2, *length_3);
	else if (ravn_st==FALSE && ravn_b==TRUE&& pr==TRUE)
		printf("\n������ ����������� �������� ������������� � ��������������. ����� ������: %f, %f, %f", *length_1, *length_2, *length_3);
	else if (ravn_st == FALSE && ravn_b == FALSE && pr == FALSE)
		printf("\n������ ����������� �������� ������������. ����� ������: %f, %f, %f", *length_1, *length_2, *length_3);
	return;
}

void Perimeter(double *length_1, double *length_2, double *length_3)
{
	printf("\n�������� ������� ������������: %f", *length_1 + *length_2 + *length_3);
}

//������ ������� �� ������� ������
void Square(double *length_1, double *length_2, double *length_3)
{
	double half_of_the_perimeter = (*length_1 + *length_2 + *length_3) / 2;
	double S = sqrt(half_of_the_perimeter*(half_of_the_perimeter - *length_1)*(half_of_the_perimeter - *length_2)*(half_of_the_perimeter - *length_3));
	printf("\n������� ������� ������������: %f", S);
	return;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int cycle = TRUE;
	while (cycle)
	{
		double x1 = 0, y1 = 0, x2 = 0, y2 = 0; //���������� ������ � ����� �������, ��� ����� ������ ������� ��� ����������������
		double length_1 = 0, length_2 = 0, length_3 = 0; //����� ��������
		length_1 = Full_Input(&x1, &y1, &x2, &y2, 1); 
		length_2 = Full_Input(&x1, &y1, &x2, &y2, 2);
		length_3 = Full_Input(&x1, &y1, &x2, &y2, 3);
		if (Possibility(&length_1, &length_2, &length_3))//���� ����������� ���������� 
		{
			printf("\n�� ������ �������� ����� ��������� �����������.");
			Triangle_Type(&length_1, &length_2, &length_3);
			Perimeter(&length_1, &length_2, &length_3);
			Square(&length_1, &length_2, &length_3);
		}
		else //���� ���
		{
			printf("\n�� ������ �������� ������ ��������� �����������.");
		}
		printf("\n��� ������� ��������� ������� �, ��� ���������� - ����� ������ �������.\n��������� ��������� �������, ��. 853503.\n");
		char answer; //����������� ����� ��� ������ ������������ 
		answer = _getch();
		if (answer != 'l'&& answer != '�'&&answer != '�')
			cycle = FALSE;
	}
	system("pause");
	return 0;
}