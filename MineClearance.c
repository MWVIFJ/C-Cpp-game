#define _CRT_SECURE_NO_WARNINGS 1
#include"MineClearance.h"
char show_mine[row][col] = { 0 };
char real_mine[row][col] = { 0 };
double start, finish;

void muen()
{
	printf("************************************************\n");
	printf("*****1.play   2.�����ϵ��ӽǺ�����    0.exit****\n");
	printf("************************************************\n");
}


void init_mine()//��ʼ����������
{
	int i = 0;
	int j = 0;
	for (int i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			show_mine[i][j] = '*';	//����ӽǣ��������궼������
			real_mine[i][j] = '0';	//�ϵ��ӽǣ��ܿ������׵㣨��1����0��
		}
	}
}


void print_player()//��ӡ�������
{
	int i = 0;
	int j = 0;
	printf("0  ");
	for (i = 1; i < row - 1; i++)
	{
		printf("%d ", i);//��ӡ��꣨0--10��
	}
	printf("\n");
	for (i = 1; i < row - 2; i++)//��ӡ���꣨1--10��
	{
		printf("%d  ", i);
		for (j = 1; j < col - 1; j++)
		{
			printf("%c ", show_mine[i][j]);//�����������,��������ӽǵĵ�ͼ
			//ȫ*���ԡ� �����������Ӿ����۵�Ч��
		}
		printf("\n");
	}
	printf("10 ");//��ʼ��ӡ���һ��
	for (i = 1; i < row - 1; i++)
	{
		printf("%c ", show_mine[10][i]); //������ӡ���һ��
	}
	printf("\n");
}


void print_mine()//��ӡ���������
{
	int i = 0;
	int j = 0;
	printf("0  ");
	for (i = 1; i < row - 1; i++)
	{
		printf("%d ", i);//��ӡ��꣨0--10��
	}
	printf("\n");
	for (i = 1; i < row - 2; i++)//��ӡ���꣨1--10��
	{
		printf("%d  ", i);
		for (j = 1; j < col - 1; j++)
		{
			printf("%c ", real_mine[i][j]);
		}
		printf("\n");
	}
	printf("10 ");//��ʼ��ӡ���һ��
	for (i = 1; i < row - 1; i++)
	{
		printf("%c ", real_mine[10][i]);
	}
	printf("\n");
}



void set_mine()//����������̲���
{
	int x = 0;
	int y = 0;
	int count = COUNT;//������
	while (count)	  //�ײ��������ѭ��
	{
		int x = rand() % 10 + 1;	//����1��10����������������±�Ϊ1��10�ķ�Χ�ڲ���
		int y = rand() % 10 + 1;	//����1��10����������������±�Ϊ1��10�ķ�Χ�ڲ���
		//�����д��������������ָ��
		if (real_mine[x][y] == '0') //�Ҳ����׵ĵط�����
		{
			real_mine[x][y] = '1';//���ף���1��д0�������ڴˣ�ֱ�������꣩
			count--;
		}
	}
}


int count_mine(int x, int y)//�����Χ8�������׵ĸ���
{
	int count = 0;
	if (  real_mine[x - 1][y - 1] == '1'
		||real_mine[x - 1][y] == '1'
		||real_mine[x - 1][y + 1] == '1'
		||real_mine[x][y - 1] == '1'
		||real_mine[x][y + 1] == '1'
		||real_mine[x + 1][y - 1] == '1'
		||real_mine[x + 1][y] == '1'
		||real_mine[x + 1][y + 1] == '1')
		count++;
	return count;
}

int safe_mine()//�����һ��ը��
{
	int x = 0;
	int y = 0;
	char ch = 0;
	int count = 0;
	int ret = 1;
	printf("��������ɨ��\n");
	while (1)
	{
		scanf_s("%d%d", &x, &y);//ֻ������1��10�����������������
		if ((x >= 1 && x <= 10) && (y >= 1 && y <= 10))//��������
		{
			if (real_mine[x][y] == '1')//��һ�βȵ��׺󲹾�
			{
				real_mine[x][y] = '0';//��дΪ0�ͻᰲȫ
				char ch = count_mine(x, y);//chΪͳ����Χ�׵ĸ���
				show_mine[x][y] = ch + '0';//���ֶ�Ӧ��ASCIIֵ�������ַ���Ӧ��ASCIIֵ���48����'0'��ASCIIֵ
				open_mine(x, y);//������Χ��չ������
				while (ret)//�������пյĵط�����һ���ף����׵���������ƽ�⣩
				{
					int x = rand() % 10 + 1;//����1��10����������������±�Ϊ1��10�ķ�Χ�ڲ���
					int y = rand() % 10 + 1;//����1��10����������������±�Ϊ1��10�ķ�Χ�ڲ���
					if (real_mine[x][y] == '0')//�Ҳ����׵ĵط�����
					{
						real_mine[x][y] = '1';
						ret--;
						break;
					}
				}break;//�����˺���	
				
			}
			if (real_mine[x][y] == '0')//��һ��û�ȵ���
			{
				char ch = count_mine(x, y);//chΪͳ����Χ�׵ĸ���
				show_mine[x][y] = ch + '0';//���ֶ�Ӧ��ASCIIֵ�������ַ���Ӧ��ASCIIֵ���48����'0'��ASCIIֵ
				//Ϊ֮���open_mine����ֱ�Ӵ�0��ʼ
				open_mine(x, y);//������Χ��չ������
				break;
			}
		}
		else//�������
		{
			printf("���������������\n");
		}
	}
	
}


int sweep_mine()//ɨ�׺������ȵ��׷���1��û�вȵ��׷���0
{
	int x = 0;
	int y = 0;
	int count = 0;
	printf("��������ɨ��\n");
	scanf_s("%d%d", &x, &y);//ֻ������1��10
	if ((x >= 1 && x <= 10) && (y >= 1 && y <= 10))//�ж����������Ƿ��������������������
	{
		if (real_mine[x][y] == '0')//û�ȵ���
		{
			char ch = count_mine(x, y);
			show_mine[x][y] = ch + '0';//���ֶ�Ӧ��ASCIIֵ�������ַ���Ӧ��ASCIIֵ���48����'0'��ASCIIֵ
			open_mine(x, y);
			if (count_show_mine() == COUNT)//�ж�ʣ��δ֪����ĸ���������Ϊ����ʱ���Ӯ
			{
				print_mine();
				printf("���Ӯ��\n\n");
				return 0;
			}
		}
		else if (real_mine[x][y] == '1')//�ȵ���
		{
			return 1;
		}

	}
	else
	{
		printf("���������������\n");
	}
	return 0;//û�ȵ���
}



void open_mine(int x, int y)//������Χչ������
{
	if (real_mine[x - 1][y - 1] == '0')
	{
		show_mine[x - 1][y - 1] = count_mine(x - 1, y - 1) + '0';//��ʾ��������Χ����
	}
	if (real_mine[x - 1][y] == '0')
	{
		show_mine[x - 1][y] = count_mine(x - 1, y) + '0';//��ʾ��������Χ����
	}
	if (real_mine[x - 1][y + 1] == '0')
	{
		show_mine[x - 1][y + 1] = count_mine(x - 1, y + 1) + '0';//��ʾ��������Χ����
	}
	if (real_mine[x][y - 1] == '0')
	{
		show_mine[x][y - 1] = count_mine(x, y - 1) + '0';//��ʾ��������Χ����
	}
	if (real_mine[x][y + 1] == '0')
	{
		show_mine[x][y + 1] = count_mine(x, y + 1) + '0';//��ʾ��������Χ����
	}
	if (real_mine[x + 1][y - 1] == '0')
	{
		show_mine[x + 1][y - 1] = count_mine(x + 1, y - 1) + '0';//��ʾ��������Χ����
	}
	if (real_mine[x + 1][y] == '0')
	{
		show_mine[x + 1][y] = count_mine(x + 1, y) + '0';//��ʾ��������Χ����
	}
	if (real_mine[x + 1][y + 1] == '0')
	{
		show_mine[x + 1][y + 1] = count_mine(x + 1, y + 1) + '0';//��ʾ��������Χ����
	}
}


int count_show_mine()//�ж�ʣ��δ֪����ĸ���������Ϊ����ʱ���Ӯ��ɨ���Ÿɾ�����������ȫ�����ף�
{
	int count = 0;
	int i = 0;
	int j = 0;
	for (i = 1; i <= row - 2; i++)
	{
		for (j = 1; j <= col - 2; j++)
		{
			if (show_mine[i][j] == '*')
			{
				count++;
			}
		}

	}
	return count;
}

void game_GOD()
{

	int ret = 0;
	init_mine();//��ʼ��������̺����������
	set_mine();//����������̲���
	printf("�����ϵ��ӽ�\n");
	print_mine();//��ӡ��������̣��ɲ���ӡ��
	printf("\n");
	print_player();//��ӡ�������
	start = clock();
	safe_mine();//�����һ�α�ը��
		printf("Ϊ�����������һ���ף���������һ�ξ��԰�ȫ���Ĵ�ʩ���ױ����������������ٸ��㿴һ��\n");
		print_mine();
		printf("\n");
	

	if (count_show_mine() == COUNT)//Ӯ�����
	{
		print_mine();
		printf("���Ӯ��\n\n");
		return;
	}print_player(); //��ӡ�������

	while (1)//ѭ��ɨ��
	{
		int ret = sweep_mine();//ɨ��,�ȵ��׷���1��û�вȵ��׷���0
		if (count_show_mine() == COUNT)//��������̵�'*'����Ϊ����ʱ��ɨ����ɣ���Ϸʤ��
		{
			print_mine();//��ӡ���������
			printf("���Ӯ��\n\n");
			finish = clock();//ȡ����ʱ��
			printf("��ʱ %d ��\n", (int)(finish - start) / CLOCKS_PER_SEC);//ȡʱ��Ŀ���ָ��
			break;
		}
		if (ret)//�ж��Ƿ�ȵ���
		{
			printf("����ը��\t");
			finish = clock();//ȡ����ʱ��
			printf("��ʱ %d ��\n", (int)(finish - start) / CLOCKS_PER_SEC);
			printf("\n��������\n");
			print_mine();//��ӡ����������Բ鿴�׵ķֲ�
			break;
		}
		print_player();//��ӡ�������
	}
}


void game()
{

	int ret = 0;
	init_mine();//��ʼ��������̺����������
	set_mine();//����������̲���
	//printf("�����ϵ��ӽ�\n");
	//print_mine();//��ӡ��������̣��ɲ���ӡ��
	printf("\n");
	print_player();//��ӡ�������
	start = clock();
	safe_mine();//�����һ�α�ը��

	if (count_show_mine() == COUNT)//Ӯ�����
	{
		print_mine();
		printf("���Ӯ��\n\n");
		return;
	}print_player(); //��ӡ�������

	while (1)//ѭ��ɨ��
	{
		int ret = sweep_mine();//ɨ��,�ȵ��׷���1��û�вȵ��׷���0
		if (count_show_mine() == COUNT)//��������̵�'*'����Ϊ����ʱ��ɨ����ɣ���Ϸʤ��
		{
			print_mine();//��ӡ���������
			printf("���Ӯ��\n\n");
			finish = clock();//ȡ����ʱ��
			printf("��ʱ %d ��\n", (int)(finish - start) / CLOCKS_PER_SEC);//ȡʱ��Ŀ���ָ��
			break;
		}
		if (ret)//�ж��Ƿ�ȵ���
		{
			printf("����ը��\t");
			finish = clock();//ȡ����ʱ��
			printf("��ʱ %d ��\n", (int)(finish - start) / CLOCKS_PER_SEC);
			printf("\n��������\n");
			print_mine();//��ӡ����������Բ鿴�׵ķֲ�
			break;
		}print_player();//��ӡ�������
	}
}
