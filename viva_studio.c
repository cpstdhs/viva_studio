#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Clothes
{
	struct Clothes* next;
	char name[96];
	int price;
	int size;
}CLOTHES;

CLOTHES* target_tmp;
CLOTHES* head;
int cloth_num;

typedef struct Person {
	int money;
	char* name;
}PERSON;

void init_list()
{
	head = (CLOTHES*)malloc(sizeof(CLOTHES));
	head->next = NULL;
}
CLOTHES* put_cloth(CLOTHES* target, CLOTHES* tmp)
{
	CLOTHES* new;
	new = (CLOTHES*)malloc(sizeof(CLOTHES));
	*new = *tmp;

	new->next = target->next;
	target->next = new;
	cloth_num++;
	return new;
}
bool del_cloth(CLOTHES* target, CLOTHES tmp)
{
	CLOTHES* del;
	CLOTHES* temp = target;
	
	while(strcmp(target->next->name, tmp.name))
	{
		target = target -> next;
		if(target->next == NULL)
			break;
	}
	del = target->next;
	target_tmp=del;
	if(del == NULL)
		return false;
	target->next = del->next;
	free(del);
	target = temp;
	cloth_num--;
	return true;
}
void init(PERSON* man)
{
	char name[10];
	printf("Enter your name: ");
	scanf("%10s", name);
	man->money = 100000;
	strcpy(man->name, name);
}
void menu()
{
	printf("----j-------------------------------\n");
	printf("ㅣWelcome to the viva studio!      ㅣ\n");
	printf("ㅣWould you like to be a celebrity?ㅣ\n");
	printf("ㅣ1. Shop                          ㅣ\n");
	printf("ㅣ2. Reform                        ㅣ\n");
	printf("ㅣ3. Closet                        ㅣ\n");
	printf("ㅣ4. Clear                         ㅣ\n");
	printf("ㅣ5. Exit                          ㅣ\n");
	printf("----------c----------------h--------\n");
}

bool payment(PERSON* man, CLOTHES tmp, int buy_or_sell)
{
	if(buy_or_sell == 1)
	{
		if(man->money > tmp.price)
		{
			man->money -= tmp.price;
			printf("***payment done***\n");
			return true;
		}
		else
		{
			printf("***lack of money***\n");
			return false;
		}
	}
	else
	{
		man->money += target_tmp->price - 15000;
		printf("***payment done***\n");
		return true;
	}
}

void buy_sell(PERSON* man , CLOTHES tmp, CLOTHES* target, int buy_or_sell)
{
	if(buy_or_sell == 1)
	{
		if(payment(man, tmp, buy_or_sell))
		{
			target->next = put_cloth(target, &tmp);
		}	
	}
	else if(buy_or_sell == 2 && cloth_num > 0)
	{
		if(del_cloth(target, tmp))
		{
			printf("sell done\n");
			payment(man, tmp, buy_or_sell);
		}
	}
	else
	{
		printf("No!\n");
		exit(1);
	}

}

void clear()
{
	if(cloth_num >= 10)
	{
		system("/bin/cat flag"); // clear !
	}else {
		printf("you aren't have sufficient clothes for fasionista!\n");
	}
}
void shop(PERSON* man)
{
	int sel;
	int buy_or_sell;
	int size;
	CLOTHES* target;
	target=head;
	CLOTHES tmp;
	memset(tmp.name, 0, 80);

	while(1)
	{
		printf("-------------------------------------------\n");
		printf("1. CLASSIC RIDERS JACKET HA[BLACK] (58,000$)\n");
		printf("2. TERRY RIDERS JACKET HA [BLACK] (60,000$)\n");
		printf("3. LEATHER STADIUM JACKET HA [BLACK] (60,000$)\n");
		printf("4. SALES SHORT SLEEVE HS [MELANGE] (18,000$)\n");
		printf("5. BASIC SALES LONG SLEEVE HS [NEON GREEN] (15,000$)\n");
		printf("6. return to main menu\n");
		printf("-------------------------current money: %d\n", man->money);
		printf("-------------------------------------------\n\n");
		printf("What number do you like to buy or sell?: ");
		scanf("%d", &sel);
		if(sel == 6)
			break;
		printf("Size?: ");
		scanf("%d", &size);
		
		printf("1.buy\n2.sell\n> ");
		scanf("%d", &buy_or_sell);
		switch(sel)
		{
			case 1:
				strncpy(tmp.name, "CLASSIC RIDERS JACKET HA[BLACK]", 32);
				tmp.price = 58000;
				tmp.size = size;
				buy_sell(man , tmp, target, buy_or_sell);
				break;
			case 2:
				strcpy(tmp.name, "TERRY RIDERS JACKET HA [BLACK]");
				tmp.price = 60000;
				tmp.size = size;
				buy_sell(man , tmp, target, buy_or_sell);
				//if(payment(man, tmp, buy_or_sell))
				//target->next = put_cloth(target, &tmp);
				break;
			case 3:
				strcpy(tmp.name, "LEATHER STADIUM JACKET HA [BLACK]");
				tmp.price = 60000;
				tmp.size = size;
				buy_sell(man , tmp, target, buy_or_sell);
				break;
			case 4:
				strcpy(tmp.name, "SALES SHORT SLEEVE HS [MELANGE]");
				tmp.price = 18000;
				tmp.size = size;
				buy_sell(man , tmp, target, buy_or_sell);
				break;
			case 5:
				strcpy(tmp.name, "CLASSIC RIDERS JACKET HA[BLACK]");
				tmp.price = 15000;
				tmp.size = size;
				buy_sell(man , tmp, target, buy_or_sell);
				clear();
				break;
			default:
				printf("No!\n");
				exit(1);
		}
	}
}

void closet()
{
	for(CLOTHES* target = head->next; target; target = target->next)
	{
		printf("------------------------------------\n");
		printf("name: %s\n", target->name);
		printf("price: %d\n", target->price);
		printf("size: %d\n", target->size);
		printf("------------------------------------\n");
	}
}

void reform()
{
	int sel;
	for(CLOTHES* target = head->next; target; target = target->next)
	{
		printf("------------------------------------\n");
		printf("name: %s\n", target->name);
		printf("price: %d\n", target->price);
		printf("size: %d\n", target->size);
		printf("------------------------------------\n");
		printf("this one? Yes:1 ,No:0\n");
		scanf("%d", &sel);
		getchar();
		if(sel)
		{
			printf("change the cloth name: ");
			scanf("%[^\n]", target->name);
			printf("change the cloth size: ");
			scanf("%d", &target->size);
		}	
	}
}
int main()
{
	int sel;
	PERSON* man;

	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	init(man);
	init_list();
	
	while(1)
	{
		menu();
		printf("sel: ");
		scanf("%d", &sel);
		switch(sel)
		{
			case 1:
				shop(man);
				break;
			case 2:
				reform();
				break;
			case 3:
				closet();
				break;
			case 4:
				clear();
				break;
			case 5:
				printf("bye\n");
				exit(1);
			default:
				printf("NO!\n");
				exit(1);
		}
	}
	return 0;
}
