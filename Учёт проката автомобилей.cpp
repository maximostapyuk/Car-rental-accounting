#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>
#include <conio.h>
using namespace std;

char par_user[15] = {};
char par_admin[15] = {};
int KEY = 7;  

          //СТРУКТУРЫ
struct car_description //характеристики автомобиля
{
	char car_mark[30];//марка автомобиля
	int car_cost;//цена автомобиля
	char car_type[30];//тип автомобиля
};                                                 
struct car //автомобиль
{
	int car_code;//код автомобиля
	struct car_description car_d;
	int rental_cost;//стоимость проката автомобиля
};
struct car CARS[15];//АВТОМОБИЛИ
struct car CARTMP;//структура для сортировки
struct full_name //полное имя клиентов
{
	char name[20];//имя клиента
	char surname[20];//фамилия клиента
	char patronymic[20];//отчество клиента
};
struct customer //клиент
{
	int cust_code;//код клиента
	struct full_name cust_name;
	char cust_address[60];//адрес клиента
	int cust_phone_number;//номер телефона клиента
};
struct customer CUST[13];//массив структур КЛИЕНТОВ
struct customer CUSTMP;//структура для сортировки
struct issue_date //дата выдачи
{
	int day;//день выдачи
	int month;//месяц выдачи
	int year;//год выдачи
};
struct return_date //дата возврата
{
	int day;//день возврата
	int month;//месяц возврата
	int year;//год возврата
};
struct issued_cars //выданные автомобили
{
	struct customer cust;
	struct car car;
	struct issue_date is_d;
	struct return_date ret_d;
};
struct issued_cars issued[20];//массив структур ВЫДАННЫЕ автомобили
struct issued_cars ISSTMP;//структура для сортировки
struct admin //администратор
{
	char admin_log[20];
	char admin_par[20];
};
struct admin Adm[2];//массив структур АДМИНИСТРАТОРЫ
struct user //пользователь
{
	char user_log[20];
	char user_par[20];
};
struct user Users[4]; //массив структур ПОЛЬЗОВАТЕЛИ
struct Size  //структура размеров массивов
{
	int admin;
	int user;
	int cars;
	int customers;
	int issued;
};
             //ФУНКЦИИ
//меню:
int menu(Size* s);//меня первого уровня
int menu_admin(Size* s);//меню администратора
int menu_user(Size* s);//меню пользователя
int menu_add(Size* s);//меню добавления записи
int menu_upravlen_us(Size* s);//меню управления пользователями
//поиск и фильтрация данных
int menu_poiska_filtr(Size* s);//меню поиска и фильтрации
int menu_poisk(Size* s);//меню поиска
int menu_filtr(Size* s);//меню фильтрации         
int menu_mas();//меню определения массива данных
int menu_red(Size* s);//меню редактирования
int menu_del(Size* s);//меню удаления
//РЕДАКТИРОВАНИЕ
void red_car(Size* s);//редактирование данных об автомобиле
void red_cust(Size* s);//редактирование данных о клиенте
void red_iss(Size* s);//редактирование данных о выданном автомобиле
//ПОИСК ДАННЫХ
//автомобиль
void poisk_car(Size* s);//поиск данных об автомобилях
void carp_cod(Size* s);//поиск записи по коду
void carp_mark(Size* s);
void carp_cost(Size* s);//поиск записи по цене
void carp_is_cost(Size* s);//поиск записи по цене проката
void carp_type(Size* s);//поиск записи по типу
//клиент
void poisk_cust(Size* s);//поиск данных о клиентах
void custp_cod(Size* s);//поиск по коду
void custp_fam(Size* s);//поиск по фамилии
void custp_phnum(Size* s);//поиск по номеру телефона
//выданный автомобиль
void poisk_iss(Size* s);//поиск данных о выданных автомобилях
void issp_carcod(Size* s);//поиск по коду автомобиля
void issp_custcod(Size* s);//поиск по коду клиента
//ФИЛЬТРАЦИЯ
//автомобиль
void filtr_car(Size* s);//фильтрация данных об автомобилях
//клиент
void filtr_cust(Size* s);//фильтрация данных о клиентах
//выданный автомобиль
void filtr_iss(Size* s);//фильтрация данных о выданных автомобилях
void zapis(Size* s);//запись все данных в файл после завершения программы
//добавление записей
void add_car(Size* s);//автомобиль
void add_customer(Size* s);//клиент
void add_issued_car(Size* s);//выданный автомобиль
//работа с данными о пользователях
void add_user(Size* s);
void vivod_users(Size* s);
void dell_user(Size* s);
//функции авторизации:
int admin_avt(Size* s); //авторизация администратора
int user_avt(Size* s); //авторизация пользователя
//void shifr_par(char par[]); //шифрование пароля 
bool vvod_chek(Size* s);//проверка на ввод данных из файла
//вывод данных
void vivod_car_tabl();//вывод таблицы автомобили
void vivod_car(int num);//вывод структуры автомобиль
void vivod_cust_tabl();//вывод таблицы клиенты 
void vivod_cust(int n);//вывод структуры клиенты
void vivod_iss_tabl();//вывод таблицы выданные автомобили
void vivod_iss(int n);//вывод структуры выданные автомобили
//ввод данных
int vvod_data_avt(Size* s); //ввод паролей и логинов из файлов
int vvod_data(Size* s);//ввод массивов структур
int vvod_int(); //ввод целого числа
int vvod_chisel();//ввод данных в виде чисел
int StrToInt(char* s);//преобразование числовой строки в число
int menu_sort(Size* s);//меню сортировки
void swap_car(int i);//замена двух структур автомобили местами
void swap_cust(int i);//замена двух структур клиенты местами
void swap_iss(int i);//замена двух структур выданные автомобили местами
int zadacha(Size* s);//выполнение задачи    

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	char pass[20] = "2262733";
	for (int i = 0; i < strlen(pass); i++)
	{
		int sym = int(pass[i])+3;
		pass[i] = sym;
	}
	cout << pass << endl;

	/*Size *s;
	s = new struct Size;
	vvod_data_avt(s);
	vvod_data(s);
	menu(s);
	zapis(s);
	delete s;*/

	return 0;
}
int menu(Size* s)
{
	while (1)
	{
		system("cls");
		cout << "*** Главное меню ***" << endl;
		cout << "1-Вход под администратором" << endl;
		cout << "2-Вход под пользователем" << endl;
		cout << "3-Выход" << endl;
		cout << "Ваш выбор: ";
		switch (vvod_int())
		{
		case 1: 
			admin_avt(s); break;
		case 2:	
			user_avt(s); break;
		case 3:
			return 0; break;
		default: system("cls"); cout << "Введите допустимое значение" << endl; Sleep(1500); break;
		}
	}
	return 0;
};
int admin_avt(Size* s)
{
	int ggg = 0;
	char login[15];
	cout << "Логин: ";
	cin >> login;
	cout << "Пароль: ";
	cin >> par_admin;
	system("cls");
	for (int i = 0; i < s->admin; i++)
	{
		if (strcmp(Adm[i].admin_log, login) == 0)
		{
			if (strcmp(Adm[i].admin_par, par_admin) == 0)
			{
				ggg = 1;
				menu_admin(s);
			}
			else
			{
				cout << "Неверный пароль" << endl;
				Sleep(1500);
				return 0;
			}
		}
	}
	if (ggg == 0)
	{
		cout << "Неверный логин" << endl;
		Sleep(1500);
	}
	return 0;
};
int user_avt(Size* s)
{
	int ggg = 0;
	char login[15];
	cout << "Логин: ";
	cin >> login;
	cout << "Пароль: ";
	cin >> par_user;
	system("cls");
	for (int i = 0; i < s->user; i++)
	{
		if (strcmp(Users[i].user_log, login) == 0)
		{
			if (strcmp(Users[i].user_par, par_user) == 0)
			{
				ggg = 1;
				menu_user(s);
			}
			else
			{
				cout << "Неверный пароль" << endl;
				Sleep(1500);
				return 0;
			}
		}
	}
	if (ggg == 0)
	{
		cout << "Неверный логин" << endl;
		Sleep(1500);
	}
	return 0;
};
int menu_admin(Size* s)
{
	int flag1 = 1;
	while (flag1)
	{
		system("cls");
		cout << "*** Меню администратора ***" << endl;
		cout << "1-Создание/открытие файла с данными" << endl;
		cout << "2-Добавление записи" << endl;
		cout << "3-Редактирование записи" << endl;
		cout << "4-Удаление записи" << endl;
		cout << "5-Просмотр всех данных в табличной форме" << endl;
		cout << "6-Процедуры поиска, фильтрации и сортировки данных" << endl;
		cout << "7-Управление пользователями" << endl;
		cout << "8-Выход в меню 1-го уровня" << endl;
		cout << "Ваш выбор: ";
		switch (vvod_int())
		{
		case 1:
		{
			if (vvod_chek(s))
			{
				cout << "Файл с данными создан/открыт" << endl;
				Sleep(1500);
			}
			else vvod_data(s);
			
		}break;
		case 2:
		{
			if (vvod_chek(s)) 
				menu_add(s);
			else
			{
				cout << "Введите данные." << endl;
				Sleep(1000);
			}
		}break;
		case 3:
		{
			if (vvod_chek(s))
				menu_red(s);
			else
			{
				cout << "Введите данные." << endl;
				Sleep(1000);
			}
		}break;
		case 4: {
			if (vvod_chek(s))
				menu_del(s);
			else
			{
				cout << "Введите данные." << endl;
				Sleep(1000);
			}
		}break;
		case 5: 
		{
			if (vvod_chek(s))
			{
				vivod_car_tabl();
				for (int i = 0; i < s->cars; i++)
					vivod_car(i);
				vivod_cust_tabl();
				for (int i = 0; i < s->customers; i++)
					vivod_cust(i);
				vivod_iss_tabl();
				for (int i = 0; i < s->issued; i++)
					vivod_iss(i);
				system("pause");
			}
			else
			{
				cout << "Введите данные." << endl;
				Sleep(1500);
			}
		}  break;
		case 6: 
		{
			if (vvod_chek(s))
				menu_poiska_filtr(s);
			else
			{
				cout << "Введите данные." << endl;
				Sleep(1500);
			}
		}  break;
		case 7: 
		{
			if (vvod_chek(s))
				menu_upravlen_us(s);
			else
			{
				cout << "Введите данные." << endl;
				Sleep(1500);
			}
		}break;
		case 8: flag1 = 0; break;
		default: system("cls"); cout << "Введите допустимое значение" << endl; Sleep(1500); break;
		}
	}
	return 0;
};
int menu_user(Size* s)
{
	int flag2 = 1;
	while (flag2)
	{
		system("cls");
		cout << "*** Меню пользователя ***" << endl;
		cout << "1-Открытие файла с данными" << endl;
		cout << "2-Просмотр всех данных в табличной форме" << endl;
		cout << "3-Выполнение задачи" << endl;
		cout << "4-Процедуры поиска, фильтрации и сортировки данных" << endl;
		cout << "5-Выход в меню 1-го уровня" << endl;
		cout << "Ваш выбор: ";
		switch (vvod_int())
		{
		case 1:   
		{
			if (vvod_chek(s))
			{
				cout << "Файл с данными открыт" << endl;
				Sleep(1500);
			}
				else vvod_data(s);
		}break;
		case 2: 
		{
			if (vvod_chek(s))
			{
				vivod_cust_tabl();
				for (int i = 0; i < s->customers; i++)
					vivod_cust(i);
				vivod_iss_tabl();
				for (int i = 0; i < s->issued; i++)
					vivod_iss(i);
				vivod_car_tabl();
				for (int i = 0; i < s->cars; i++)
					vivod_car(i);
				system("pause");
			}
			else
			{
				cout << "Введите данные." << endl;
				Sleep(1500);
			}
		}break;
		case 3: 
		{
			if (vvod_chek(s))
				zadacha(s);
			else
			{
				cout << "Введите данные." << endl;
				Sleep(1500);
			}
		}break;
		case 4: 
		{
			if (vvod_chek(s))
				menu_poiska_filtr(s);
			else
			{
				cout << "Введите данные." << endl;
				Sleep(1500);
			}
		}break;
		case 5:  flag2 = 0; break;
		default:system("cls"); cout << "Введите допустимое значение" << endl; Sleep(1500); break;
		}
	}
	return 0;
};
int vvod_int()
{
	int ch = 0;
	while (scanf_s("%d", &ch) == 0 && (ch = getchar()) < '0' || ch > '9')
	{
		cout<<"Вводятся только цифры."<<endl<<"Введите цифру: ";
	}
	return ch;
};
int vvod_chisel()
{
	int number;
	char c;
	while (1) {
		if (!scanf_s("%d", &number) || getchar() != '\n') {
			while ((c = getchar()) != '\n' && c != EOF);
		}
		else
			return number;
		printf_s("Неправильный ввод.\nПопробуйте ещё раз: ");
	}
};
int vvod_data_avt(Size* s)
{
	int n = 0; 
	FILE* file;
	FILE* user_f;
	fopen_s(&file, "Admin.txt", "r+");
	while (!feof(file))
	{
		fgets(Adm[n].admin_log, 15, file);           //ввод данных администратора
		int na = strlen(Adm[n].admin_log);
		for (int i = 0; i < na; i++)
			if (Adm[n].admin_log[i] == '\n')
				Adm[n].admin_log[i] = '\0';
		fgets(Adm[n].admin_par, 15, file);
		int nb = strlen(Adm[n].admin_par);
		for (int i = 0; i < nb; i++)
			if (Adm[n].admin_par[i] == '\n')
				Adm[n].admin_par[i] = '\0';
		for (int pp = 0; pp < strlen(Adm[n].admin_par); pp++)
		{
			int symbol = int(Adm[n].admin_par[pp]) - KEY;
			Adm[n].admin_par[pp] = symbol;
		}
		n += 1;
	}
	fclose(file);
	if (n == 1) s->admin = n;
	else s->admin = n - 1;
	n = 0;
	fopen_s(&user_f, "User.txt", "r+");               //ввод данных пользователей
	while (!feof(user_f))
	{
		fgets(Users[n].user_log, 15, user_f);
		int nc = strlen(Users[n].user_log);
		for (int i = 0; i < nc; i++)
			if (Users[n].user_log[i] == '\n')
				Users[n].user_log[i] = '\0';
		fgets(Users[n].user_par, 15, user_f);
		int nd = strlen(Users[n].user_par);
		for (int i = 0; i < nd; i++)
			if (Users[n].user_par[i] == '\n')
				Users[n].user_par[i] = '\0';
		for (int pp = 0; pp < strlen(Users[n].user_par); pp++)
		{
			int symbol = int(Users[n].user_par[pp]) - KEY;
			Users[n].user_par[pp] = symbol;
		}
		n += 1;
	}
	fclose(user_f);
	if (n == 1) s->user = n;
	else s->user = n - 1;
	return 0;
};
int vvod_data(Size* s)
{
	int n = 0;
	FILE* fcar;
	FILE* fcast;
	FILE* fiss;
	char a[30];
	fopen_s(&fcar, "Cars.txt", "r+");                  //ввод данных автомобилей
	while (!feof(fcar))
	{
		fgets(a, 30, fcar);
		int ne = strlen(a);
		for (int i = 0; i < ne; i++)
			if (a[i] == '\n')
				a[i] = '\0';
		CARS[n].car_code=StrToInt(a);
		fgets(CARS[n].car_d.car_mark, 30, fcar);
		int nf = strlen(CARS[n].car_d.car_mark);
		for (int i = 0; i < nf; i++)
			if (CARS[n].car_d.car_mark[i] == '\n')
				CARS[n].car_d.car_mark[i] = '\0';
		fgets(a, 30, fcar);
		int ng = strlen(a);
		for (int i = 0; i < ng; i++)
			if (a[i] == '\n')
				a[i] = '\0';
		CARS[n].car_d.car_cost = StrToInt(a);
		fgets(a, 30, fcar);
		int nt = strlen(a);
		for (int i = 0; i < nt; i++)
			if (a[i] == '\n')
				a[i] = '\0';
		CARS[n].rental_cost = StrToInt(a);
		fgets(CARS[n].car_d.car_type, 30, fcar);
		int ny = strlen(CARS[n].car_d.car_type);
		for (int i = 0; i < ny; i++)
			if (CARS[n].car_d.car_type[i] == '\n')
				CARS[n].car_d.car_type[i] = '\0';
		n += 1;
	}
	fclose(fcar);
	if (n == 1) s->cars = n;
	else s->cars = n - 1;
	n = 0;
	fopen_s(&fcast, "Customers.txt", "r+");                  //ввод данных клиентов
	while (!feof(fcast))
	{
		fgets(a, 30, fcast);
		int nq = strlen(a);
		for (int i = 0; i < nq; i++)
			if (a[i] == '\n')
				a[i] = '\0';
		CUST[n].cust_code= StrToInt(a);
		fgets(CUST[n].cust_name.surname, 20, fcast);
		int np = strlen(CUST[n].cust_name.surname);
		for (int i = 0; i < np; i++)
			if (CUST[n].cust_name.surname[i] == '\n')
				CUST[n].cust_name.surname[i] = '\0';
		fgets(CUST[n].cust_name.name, 20, fcast);
		int no = strlen(CUST[n].cust_name.name);
		for (int i = 0; i < no; i++)
			if (CUST[n].cust_name.name[i] == '\n')
				CUST[n].cust_name.name[i] = '\0';
		fgets(CUST[n].cust_name.patronymic, 20, fcast);
		int ni = strlen(CUST[n].cust_name.patronymic);
		for (int i = 0; i < ni; i++)
			if (CUST[n].cust_name.patronymic[i] == '\n')
				CUST[n].cust_name.patronymic[i] = '\0';
		fgets(CUST[n].cust_address, 40, fcast);
		int nr = strlen(CUST[n].cust_address);
		for (int i = 0; i < nr; i++)
			if (CUST[n].cust_address[i] == '\n')
				CUST[n].cust_address[i] = '\0';
		fgets(a, 30, fcast);
		int nh = strlen(a);
		for (int i = 0; i < nh; i++)
			if (a[i] == '\n')
				a[i] = '\0';
		CUST[n].cust_phone_number = StrToInt(a);
		n += 1;
	}
	fclose(fcast);
	if (n == 1) s->customers = n;
	else s->customers = n - 1;
	n = 0;
	fopen_s(&fiss, "Issued cars.txt", "r+");                  //ввод данных выданные автомобили
	while (!feof(fiss))
	{
		fgets(a, 30, fiss);
		int na = strlen(a);
		for (int i = 0; i < na; i++)
			if (a[i] == '\n')
				a[i] = '\0';
		issued[n].car.car_code = StrToInt(a);
		fgets(a, 30, fiss);
		int ng = strlen(a);
		for (int i = 0; i < ng; i++)
			if (a[i] == '\n')
				a[i] = '\0';
		issued[n].cust.cust_code = StrToInt(a);
		fgets(a, 30, fiss);
		int nz = strlen(a);
		for (int i = 0; i < nz; i++)
			if (a[i] == '\n')
				a[i] = '\0';
		issued[n].is_d.day = StrToInt(a);
		fgets(a, 30, fiss);
		int p = strlen(a);
		for (int i = 0; i < p; i++)
			if (a[i] == '\n')
				a[i] = '\0';
		issued[n].is_d.month = StrToInt(a);
		fgets(a, 30, fiss);
		int nl = strlen(a);
		for (int i = 0; i < nl; i++)
			if (a[i] == '\n')
				a[i] = '\0';
		issued[n].is_d.year = StrToInt(a);
		fgets(a, 30, fiss);
		int q = strlen(a);
		for (int i = 0; i < q; i++)
			if (a[i] == '\n')
				a[i] = '\0';
		issued[n].ret_d.day = StrToInt(a);
		fgets(a, 30, fiss);
		int z = strlen(a);
		for (int i = 0; i < z; i++)
			if (a[i] == '\n')
				a[i] = '\0';
		issued[n].ret_d.month = StrToInt(a);
		fgets(a, 30, fiss);
		int l = strlen(a);
		for (int i = 0; i < l; i++)
			if (a[i] == '\n')
				a[i] = '\0';
		issued[n].ret_d.year = StrToInt(a);
		n += 1;
	}
	fclose(fcast);
	if (n == 1) s->issued = n;
	else s->issued = n - 1;
	return 0;
};
int StrToInt(char* s)
{
	int temp = 0; // число
	int i = 0;
	while (s[i] >= 0x30 && s[i] <= 0x39)
	{
		temp = temp + (s[i] & 0x0F);
		temp = temp * 10;
		i++;
	}
	temp = temp / 10;
	return(temp);
}
bool vvod_chek(Size* s)
{
	if (s->cars != 0) return true;
	else return false;
};
int menu_del(Size* s)
{
	int flag2 = 1;
	while (flag2)
	{
		system("cls");
		cout << "*** Меню удаления ***" << endl;
		cout << "1-Удаление структуры автомобилей" << endl;
		cout << "2-Удаление структуры клиентов" << endl;
		cout << "3-Удаление структуры выданных автомобилей" << endl;
		cout << "4-Выход в меню администратора"<<endl;
		cout << "Ваш выбор: ";
		switch (vvod_int())
		{
		case 1:
		{
			int num;
			vivod_car_tabl();
			for (int i = 0; i < s->cars; i++)
				vivod_car(i);
			cout << "Введите номер структуры: ";
			num = vvod_chisel();
			cout << endl;
			if (num < s->cars+1 && num>0)
			{
				for (int i = num - 1; i < s->cars; i++)
					CARS[i] = CARS[i + 1];
				s->cars -= 1;
				cout << "Запись удалена" << endl;
				Sleep(1500);
			}
			else
			{
				cout << "Стурктура с таким номером не существует." << endl;
				Sleep(1500);
			}
		}break;
		case 2: 
		{
			int num;
			vivod_cust_tabl();
			for (int i = 0; i < s->customers; i++)
				vivod_cust(i);
			cout << "Введите номер структуры: ";
			num = vvod_chisel();
			cout << endl;
			if (num < s->customers+1 && num>0)
			{
				for (int i = num - 1; i < s->customers; i++)
					CUST[i] = CUST[i + 1];
				s->customers -= 1;
				cout << "Запись удалена" << endl;
				Sleep(1500);
			}
			else
			{
				cout << "Стурктура с таким номером не существует." << endl;
				Sleep(1500);
			}
		}break;
		case 3:
		{
			int num;
			vivod_iss_tabl();
			for (int i = 0; i < s->issued; i++)
				vivod_iss(i);
			cout << "Введите номер структуры: ";
			num = vvod_chisel();
			cout << endl;
			if (num < s->issued+1 && num>0)
			{
				for (int i = num - 1; i < s->issued; i++)
				{
					issued[i] = issued[i + 1];
					s->issued -= 1;
				}
				cout << "Запись удалена" << endl;
				Sleep(1500);
			}
			else
			{
				cout << "Стурктура с таким номером не существует." << endl;
				Sleep(1500);
			}
		}break;
		case 4: flag2 = 0;  break;
		default:system("cls"); cout << "Введите допустимое значение" << endl; Sleep(1500); break;
		}
	}
	return 0;
};
int menu_add(Size* s)
{
	int flag = 1;
	while (flag)
	{
		system("cls");
		cout << "### Меню добавления записи ###" << endl;
		cout << "1-Добавление записи об автомобиле" << endl;
		cout << "2-Добавление записи о клиенте" << endl;
		cout << "3-Добавление записи о выданном автомобиле" << endl;
		cout << "4-Выход в меню администратора" << endl;
		cout << "Ваш выбор: ";
		switch (vvod_int())
		{
		case 1:  add_car(s); break;
		case 2:  add_customer(s); break;
		case 3:  add_issued_car(s); break;
		case 4: flag = 0; break;
		default:system("cls"); cout << "Введите допустимое значение" << endl; Sleep(1500); break;
		}
	}
	return 0;
};
void add_car(Size* s)
{
	cout << "Введите код автомобиля: ";
	CARS[s->cars].car_code= vvod_chisel();
	cout << endl;
	cout << "Введите марку автомобиля: ";
	cin >> CARS[s->cars].car_d.car_mark;
	cout << endl;
	cout << "Введите стоимость автомобиля($): ";
	CARS[s->cars].car_d.car_cost = vvod_chisel();
	cout << endl;
	cout << "Введите стоимость проката автомобиля(руб.): ";
	CARS[s->cars].rental_cost = vvod_chisel();
	cout << endl;
	cout << "Введите тип автомобиля: ";
	cin >> CARS[s->cars].car_d.car_type;
	cout << endl;
	s->cars += 1;
};
void add_customer(Size* s)
{
	cout << "Введите код клиента: ";
	CUST[s->customers].cust_code = vvod_chisel();
	cout << endl;
	cout << "Введите фамилию клиента: ";
	cin >> CUST[s->customers].cust_name.surname;
	cout << endl;
	cout << "Введите имя клиента: ";
	cin >> CUST[s->customers].cust_name.name;
	cout << endl;
	cout << "Введите отчество клиента: ";
	cin >> CUST[s->customers].cust_name.patronymic;
	cout << endl;
	cout << "Введите адрес проживания клиента: ";
	cin >> CUST[s->customers].cust_address;
	cout << endl;
	cout << "Введите номер клиента(+375-...): ";
	CUST[s->customers].cust_phone_number = vvod_chisel();
	cout << endl;
	s->customers += 1;
};
void add_issued_car(Size* s)
{
	cout << "Введите код автомобиля: ";
	issued[s->issued].car.car_code= vvod_chisel();
	cout << endl;
	cout << "Введите код клиента: ";
	issued[s->issued].cust.cust_code= vvod_chisel();
	cout << endl;
	cout << "Введите день выдачи: ";
	issued[s->issued].is_d.day = vvod_chisel();
	cout << endl;
	cout << "Введите месяц выдачи(номер месяца): ";
	issued[s->issued].is_d.month = vvod_chisel();
	cout << endl;
	cout << "Введите год выдачи: ";
	issued[s->issued].is_d.year = vvod_chisel();
	cout << endl;
	cout << "Введите день возврата: ";
	issued[s->issued].ret_d.day = vvod_chisel();
	cout << endl;
	cout << "Введите месяц возврата(номер месяца): ";
	issued[s->issued].ret_d.month = vvod_chisel();
	cout << endl;
	cout << "Введите год возврата: ";
	issued[s->issued].ret_d.year = vvod_chisel();
	cout << endl;
	s->issued += 1;
};
int menu_upravlen_us(Size* s)
{
	int flag = 1;
	while (flag)
	{
		system("cls");
		cout << "@@@ Меню управления пользователями @@@" << endl;
		cout << "1-Добавление пользователя" << endl;
		cout << "2-Просмотр данных о пользователях" << endl;
		cout << "3-Удаление пользователя" << endl;
		cout << "4-Выход в меню администратора" << endl;
		cout << "Ваш выбор: ";
		switch (vvod_int())
		{
		case 1: add_user(s); break;
		case 2: vivod_users(s); break;
		case 3: dell_user(s); break;
		case 4: flag = 0; break;
		default:system("cls"); cout << "Введите допустимое значение" << endl;Sleep(1500); break;
		}
	}
	return 0;
};
void add_user(Size* s)
{
	cout << "Введите логин пользователя: ";
	cin >> Users[s->user].user_log;
	cout << endl;
	cout << "Введите пароль пользователя: ";
	cin >> Users[s->user].user_par;
	cout << endl;
	s->user += 1;
	cout << "Пользователь зарегестрирован" << endl;
	Sleep(1500);
};
void vivod_users(Size* s)
{
	cout << " _____________________________________________" << endl;
	cout << "|  №  |       Логин       |       Пароль      |" << endl;
	cout << "|_____|___________________|___________________|" << endl;
	for (int i = 0; i < s->user; i++)
	{
		printf("|%5d|%19s|%19s|\n", i + 1, Users[i].user_log, Users[i].user_par);
		printf("|_____|___________________|___________________|\n");
	}
	system("pause");
};
void dell_user(Size* s)
{
	int num;
	cout << "Введите номер пользователя, которого хотите удалить: ";
	num = vvod_int();
	if (num > s->user)
	{
		cout << "Пользователя с таким номером нету" << endl;
		Sleep(1500);
	}

	else
	{
		for (int i = num - 1; i < s->user; i++)
			Users[i] = Users[i + 1];
		s->user -= 1;
		Sleep(1500);
	}
};
int menu_red(Size* s)
{
	int flag = 1;
	while (flag)
	{
		system("cls");
		cout << "### Меню редактирования записи ###" << endl;
		cout << "1-Редактирование записи об автомобиле" << endl;
		cout << "2-Редактирование записи о клиенте" << endl;
		cout << "3-Редактирование записи о выданном автомобиле" << endl;
		cout << "4-Выход в меню администратора" << endl;
		cout << "Ваш выбор: ";
		switch (vvod_int())
		{
		case 1: red_car(s); break;
		case 2: red_cust(s); break;
		case 3: red_iss(s); break;
		case 4: flag = 0; break;
		default:system("cls"); cout << "Введите допустимое значение" << endl;	Sleep(1500); break;
		}
	}
	return 0;
};
void red_car(Size* s)
{
	int redn,red;
	vivod_car_tabl();
	for (int i = 0; i < s->cars; i++)
		vivod_car(i);
	cout << "Введите номер записи для редактирования: ";
	redn = vvod_chisel();
	cout << endl;
	cout << s->cars << endl;
	if (redn == 0 || redn > s->cars)
	{
		cout << "Запись с таким номером не обнаружена." << endl;
		Sleep(1500);
		return;
	}
	cout << "Выберите какой критерий будете редактировать: "<<endl;
	cout << "1-Код автомобиля" << endl;
	cout << "2-Марка автомобиля" << endl;
	cout << "3-Стоимость автомобиля($)" << endl;
	cout << "4-Стоимость проката автомобиля(руб.)" << endl;
	cout << "5-Тип автомобиля" << endl;
	cin >> red;
	switch (red)
	{
	case 1:
	{
		int code;
		cout << "Введите новый код: ";
		code = vvod_chisel();
		cout << endl;
		CARS[redn - 1].car_code = code;
		cout << "Запись отредактирована." << endl;
		Sleep(1500);
	}break;
	case 2:
	{
		cout << "Введите новую марку: ";
		cin >> CARS[redn - 1].car_d.car_mark;
		cout << "Запись отредактирована." << endl;
		Sleep(1500);
	}break;
	case 3:
	{
		int cost;
		cout << "Введите новую стоимость: ";
		cost = vvod_chisel();
		cout << endl;
		CARS[redn - 1].car_d.car_cost = cost;
		cout << "Запись отредактирована." << endl;
		Sleep(1500);
	}break;
	case 4:
	{
		int cost;
		cout << "Введите новую стоимость проката: ";
		cost = vvod_chisel();
		cout << endl;
		CARS[redn - 1].rental_cost= cost;
		cout << "Запись отредактирована." << endl;
		Sleep(1500);
	}break;
	case 5:
	{
		cout << "Введите новый тип автомобиля: ";
		cin >> CARS[redn - 1].car_d.car_type;
		cout << "Запись отредактирована." << endl;
		Sleep(1500);
	}break;
	default: system("cls"); cout << "Введите допустимое значение" << endl; Sleep(1500);  break;
	}
};
void red_cust(Size* s)
{
	int redn, red;
	vivod_cust_tabl();
	for (int i = 0; i < s->customers; i++)
		vivod_cust(i);
	cout << "Введите номер записи для редактирования: ";
	redn = vvod_chisel();
	cout << endl;
	if (redn == 0 || redn > s->customers)
	{
		cout << "Запись с таким номером не обнаружена." << endl;
		Sleep(1500);
		return;
	}
	cout << "Выберите какой критерий будете редактировать: " << endl;
	cout << "1-Код" << endl;
	cout << "2-Фамилия" << endl;
	cout << "3-Имя" << endl;
	cout << "4-Отчество" << endl;
	cout << "5-Адрес" << endl;
	cout << "6-Номер телефона" << endl;
	cin >> red;
	switch (red)
	{
	case 1:
	{
		int code;
		cout << "Введите новый код: ";
		code = vvod_chisel();
		cout << endl;
		CUST[redn-1].cust_code = code;
		cout << "Запись отредактирована." << endl;
		Sleep(1500);
	}break;
	case 2:
	{
		cout << "Введите фамилию: ";
		cin >> CUST[redn-1].cust_name.surname;
		cout << "Запись отредактирована." << endl;
		Sleep(1500);
	}break;
	case 3:
	{
		cout << "Введите имя: ";
		cin >> CUST[redn - 1].cust_name.name;
		cout << "Запись отредактирована." << endl;
		Sleep(1500);
	}break;
	case 4:
	{
		cout << "Введите отчество: ";
		cin >> CUST[redn - 1].cust_name.patronymic;
		cout << "Запись отредактирована." << endl;
		Sleep(1500);
	}break;
	case 5:
	{
		cout << "Введите адрес: ";
		cin >> CUST[redn - 1].cust_address;
		cout << "Запись отредактирована." << endl;
		Sleep(1500);
	}break;
	case 6:
	{
		int phone;
		cout << "Введите номер телефона: ";
		phone = vvod_chisel();
		cout << endl;
		CUST[redn - 1].cust_phone_number = phone;
		cout << "Запись отредактирована." << endl;
		Sleep(1500);
	}break;
	default:system("cls"); cout << "Введите допустимое значение" << endl; Sleep(1500); break;
	}
};
void red_iss(Size* s)
{
	int redn, red;
	vivod_iss_tabl();
	for (int i = 0; i < s->issued; i++)
		vivod_iss(i);
	cout << "Введите номер записи для редактирования: ";
	redn = vvod_chisel();
	cout << endl;
	if (redn == 0 || redn > s->issued)
	{
		cout << "Запись с таким номером не обнаружена." << endl;
		Sleep(1500);
		return;
	}
	cout << "Выберите поле для редактирования: " << endl;
	cout << "1-Код автомобиля" << endl;
	cout << "2-Код клиента" << endl;
	cout << "3-День выдачи" << endl;
	cout << "4-Месяц выдачи" << endl;
	cout << "5-Год выдачи" << endl;
	cout << "6-День возврата" << endl;
	cout << "7-Месяц возврата" << endl;
	cout << "8-Год возврата" << endl;
	cin >> red;
	switch (red)
	{
	case 1:
	{
		int code;
		cout << "Введите новый код: ";
		code = vvod_chisel();
		cout << endl;
		issued[redn-1].car.car_code = code;
		cout << "Запись отредактирована." << endl;
		Sleep(1500);
	}break;
	case 2:
	{
		int code;
		cout << "Введите новый код: ";
		code = vvod_chisel();
		cout << endl;
		issued[redn - 1].cust.cust_code = code;
		cout << "Запись отредактирована." << endl;
		Sleep(1500);
	}break;
	case 3:
	{
		int day;
		cout << "Введите день: ";
		day = vvod_chisel();
		cout << endl;
		issued[redn - 1].is_d.day = day;
		cout << "Запись отредактирована." << endl;
		Sleep(1500);
	}break;
	case 4:
	{
		int month;
		cout << "Введите месяц: ";
		month = vvod_chisel();
		cout << endl;
		issued[redn - 1].is_d.month = month;
		cout << "Запись отредактирована." << endl;
		Sleep(1500);
	}break;
	case 5:
	{
		int year;
		cout << "Введите год: ";
		year = vvod_chisel();
		cout << endl;
		issued[redn - 1].is_d.year = year;
		cout << "Запись отредактирована." << endl;
		Sleep(1500);
	}break;
	case 6:
	{
		int day;
		cout << "Введите день: ";
		day = vvod_chisel();
		cout << endl;
		issued[redn - 1].ret_d.day = day;
		cout << "Запись отредактирована." << endl;
		Sleep(1500);
	}break;
	case 7:
	{
		int month;
		cout << "Введите месяц: ";
		month = vvod_chisel();
		cout << endl;
		issued[redn - 1].ret_d.month = month;
		cout << "Запись отредактирована." << endl;
		Sleep(1500);
	}break;
	case 8:
	{
		int year;
		cout << "Введите год: ";
		year = vvod_chisel();
		cout << endl;
		issued[redn - 1].ret_d.year = year;
		cout << "Запись отредактирована." << endl;
		Sleep(1500);
	}break;
	default:system("cls"); cout << "Введите допустимое значение" << endl; Sleep(1500); break;
	}
};
int menu_poiska_filtr(Size* s)
{
	int flag = 1;
	while (flag)
	{
		system("cls");
		cout << "*** Меню поиска, фильтрации и сортировки данных ***" << endl;
		cout << "1-Поиск данных" << endl;
		cout << "2-Фильтрация данных" << endl;
		cout << "3-Сортировка данных" << endl;
		cout << "4-Выход в меню второго уровня" << endl;
		cout << "Ваш выбор: ";
		switch (vvod_int())
		{
		case 1: menu_poisk(s); break;
		case 2: menu_filtr(s); break;
		case 3: menu_sort(s); break;
		case 4: flag = 0; break;
		default: system("cls"); cout << "Введите допустимое значение" << endl; Sleep(1500); break;
		}
	}
	return 0;
};
int menu_filtr(Size* s)
{
	//system("cls");
	cout << "*** Меню фильтрации ***" << endl;
	switch (menu_mas())
	{
	case 1: filtr_car(s); break;
	case 2: filtr_cust(s); break;
	case 3: filtr_iss(s); break;
	default:system("cls"); cout << "Массива данных с таким номером нету" << endl;	Sleep(1500); break;
	}
	return 0;
};
void filtr_car(Size* s)
{
	int flag = 1,ch;
	while (flag)
	{
		system("cls");
		cout << "@@@ Фильтрация данных @@@" << endl;
		cout << "Выберите критерий для фильтрации:" << endl;
		cout << "1-По диапазону стоимости" << endl;
		cout << "2-По марке" << endl;
		cout << "3-По диапазону стоимости проката" << endl;
		cout << "4-Выход в меню меню поиска и фильтрации" << endl;
		cout << "Ваш выбор: ";
		ch = vvod_int();
		switch (ch)
		{
		case 1:
		{
			int left, right, gh=0;
			cout << "Введите левую границу: ";
			left = vvod_chisel();
			cout << endl;
			cout << "Введите правую границу: ";
			right = vvod_chisel();
			cout << endl;
			for (int i = 0; i < s->cars; i++)
			{
				if (CARS[i].car_d.car_cost>=left && CARS[i].car_d.car_cost<=right)
				{
					gh = 1;
					vivod_car_tabl();
					vivod_car(i);
				}
			}
			if (gh == 0)
			{
				cout << "Данные об автомобиле из этого ценового диапазона не найдены" << endl;
				Sleep(1500);
			}
			else 			
				system("pause");
		}break;
		case 2: 
		{
			int gh = 0;
			char mark[30];
			cout << "Введите марку: ";
			cin >> mark;
			for (int i = 0; i < s->cars; i++)
			{
				if (strcmp(CARS[i].car_d.car_mark,mark)==0)
				{
					gh = 1;
					vivod_car_tabl();
					vivod_car(i);
				}
			}
			if (gh == 0)
			{
				cout << "Данные об автомобиле этой марки не найдены" << endl;
				Sleep(1500);
			}
			else 
				system("pause");
		}break;
		case 3: 
		{
			int left, right, gh = 0;
			cout << "Введите левую границу: ";
			left = vvod_chisel();
			cout << endl;
			cout << "Введите правую границу: ";
			right = vvod_chisel();
			cout << endl;
			for (int i = 0; i < s->cars; i++)
			{
				if (CARS[i].rental_cost >= left && CARS[i].rental_cost <= right)
				{
					gh = 1;
					vivod_car_tabl();
					vivod_car(i);
					system("pause");
				}
			}
			if (gh == 0)
			{
				cout << "Данные об автомобиле из этого ценового диапазона не найдены" << endl;
				Sleep(1500);
			}
		}break;
		case 4: flag = 0; break;
		default:system("cls"); cout << "Введите допустимое значение" << endl; Sleep(1500); break;
		}
	}
};
void filtr_cust(Size* s)
{
	int flag = 1, ch;
	while (flag)
	{
		system("cls");
		cout << "@@@ Фильтрация данных @@@" << endl;
		cout << "Выберите критерий для фильтрации:" << endl;
		cout << "1-По диапазону кодов клиентов" << endl;
		cout << "2-Выход в меню меню поиска и фильтрации" << endl;
		cout << "Ваш выбор: ";
		ch = vvod_int();
		switch (ch)
		{
		case 1:
		{
			int left, right, gh = 0;
			cout << "Введите левую границу: ";
			left = vvod_chisel();
			cout << endl;
			cout << "Введите правую границу: ";
			right = vvod_chisel();
			cout << endl;
			for (int i = 0; i < s->customers; i++)
			{
				if (CUST[i].cust_code >= left && CUST[i].cust_code <= right)
				{
					gh = 1;
					vivod_car_tabl();
					vivod_car(i);
					system("pause");
				}
			}
			if (gh == 0)
			{
				cout << "Данные о клиенте из этого диапазона кодов не найдены" << endl;
				Sleep(1500);
			}
		}break;
		case 2: flag = 0; break;
		default:system("cls"); cout << "Введите допустимое значение" << endl; Sleep(1500); break;
		}
	}
};
void filtr_iss(Size* s)
{
	int flag = 1, ch;
	while (flag)
	{
		system("cls"); 
		cout << "@@@ Фильтрация данных @@@" << endl;
		cout << "Выберите критерий для фильтрации:" << endl;
		cout << "1-По диапазону кодов автомобилей" << endl;
		cout << "2-По диапазону кодов клиентов" << endl;
		cout << "3-Выход в меню меню поиска и фильтрации" << endl;
		cout << "Ваш выбор: ";
		ch = vvod_int();
		switch (ch)
		{
		case 1:
		{
			int left, right, gh = 0;
			cout << "Введите левую границу: ";
			left = vvod_chisel();
			cout << endl;
			cout << "Введите правую границу: ";
			right = vvod_chisel();
			cout << endl;
			for (int i = 0; i < s->issued; i++)
			{
				if (issued[i].car.car_code >=left && issued[i].car.car_code <= right)
				{
					gh = 1;
					vivod_car_tabl();
					vivod_car(i);
					system("pause");
				}
			}
			if (gh == 0)
			{
				cout << "Данные о выданных автомобилях из этого диапазона кодов не найдены" << endl;
				Sleep(1500);
			}
		}break;
		case 2:
		{
			int left, right, gh = 0;
			cout << "Введите левую границу: ";
			left = vvod_chisel();
			cout << endl;
			cout << "Введите правую границу: ";
			right = vvod_chisel();
			cout << endl;
			for (int i = 0; i < s->issued; i++)
			{
				if (issued[i].cust.cust_code>=left && issued[i].cust.cust_code <= right)
				{
					gh = 1;
					vivod_car_tabl();
					vivod_car(i);
					system("pause");
				}
			}
			if (gh == 0)
			{
				cout << "Данные о выданных автомобилях из этого диапазона кодов не найдены" << endl;
				Sleep(1500);
			}
		}break;
		case 3: flag = 0; break;
		default:system("cls"); cout << "Введите допустимое значение" << endl; Sleep(1500); break;
		}
	}
};
int menu_mas()
{
	int ch;
	system("cls");
	cout << "Выберите массив данных, с которыми вы хотите работать: " << endl;
	cout << "1-Автомобили" << endl;
	cout << "2-Клиенты" << endl;
	cout << "3-Выданные автомобили" << endl;
	cout << "Ваш выбор: ";
	ch = vvod_int();
	return ch;
};
int menu_poisk(Size* s)
{
	
	cout << "*** Меню поиска ***" << endl;
	switch (menu_mas())
	{
	case 1: poisk_car(s); break;
	case 2: poisk_cust(s); break;
	case 3: poisk_iss(s); break;
	default:system("cls"); cout << "Массива данных с таким номером нету" << endl;	Sleep(1500); break;
	}
	return 0;
};
void poisk_car(Size* s)
{
	
	int flag9 = 1;
	while (flag9)
	{
		system("cls");
		cout << "*** Поиск данных об автомобиле ***" << endl;
		cout << "1-Поиск по коду автомобиля" << endl;
		cout << "2-Поиск по марке автомобиля" << endl;
		cout << "3-Поиск по стоимости автомобиля" << endl;
		cout << "4-Поиск по стоимости проката автомобиля" << endl;
		cout << "5-Поиск по типу автомобиля" << endl;
		cout << "6-Выход в меню поиска" << endl;
		cout << "Ваш выбор: ";
		switch (vvod_int())
		{
		case 1: carp_cod(s); break;
		case 2: carp_mark(s); break;
		case 3: carp_cost(s); break;
		case 4: carp_is_cost(s); break;
		case 5: carp_type(s); break;
		case 6: flag9 = 0; break;
		default:system("cls"); cout << "Введите допустимое значение" << endl; Sleep(1500); break;
		}
	}
};
void carp_cod(Size* s)
{
	int f,d=0;
	cout << "Введите код для поиска: ";
	f = vvod_chisel();
	cout << endl;
	for (int i = 0; i < s->cars; i++)
	{
		if (CARS[i].car_code==f)
		{
			vivod_car_tabl();
			vivod_car(i);
			d = 1;
			system("pause");
		}
	}
	if (d == 0)
	{
		cout << "Запись с таким кодом автомобиля не обнаружена" << endl;
		Sleep(1500);
	}
};
void carp_mark(Size* s)
{
	int d = 0;
	char f[30];
	cout << "Введите марку для поиска: ";
	cin >> f;
	cout << endl;
	for (int i = 0; i < s->cars; i++)
	{
		if (strcmp(f,CARS[i].car_d.car_mark)==0)
		{
			vivod_car_tabl();
			vivod_car(i);
			d = 1;
			system("pause");
		}
	}
	if (d == 0)
	{
		cout << "Запись с такой маркой автомобиля не обнаружена" << endl;
		Sleep(1500);
	}
};
void carp_cost(Size* s)
{
	int f, d = 0;
	cout << "Введите стоимость для поиска: ";
	f = vvod_chisel();
	cout << endl;
	for (int i = 0; i < s->cars; i++)
	{
		if (CARS[i].car_d.car_cost == f)
		{
			vivod_car_tabl();
			vivod_car(i);
			d = 1;
			system("pause");
		}
	}
	if (d == 0)
	{
		cout << "Запись с такой стоимостью автомобиля не обнаружена" << endl;
		Sleep(1500);
	}
};
void carp_is_cost(Size* s)
{
	int f, d = 0;
	cout << "Введите стоимость проката для поиска: ";
	f = vvod_chisel();
	cout << endl;
	for (int i = 0; i < s->cars; i++)
	{
		if (CARS[i].rental_cost == f)
		{
			vivod_car_tabl();
			vivod_car(i);
			d = 1;
			system("pause");
		}
	}
	if (d == 0)
	{
		cout << "Запись с такой стоимостью проката автомобиля не обнаружена" << endl;
		Sleep(1500);
	}
};
void carp_type(Size* s)
{
	int d = 0;
	char f[30];
	cout << "Введите тип для поиска: ";
	cin >> f;
	cout << endl;
	for (int i = 0; i < s->cars; i++)
	{
		if (strcmp(f, CARS[i].car_d.car_type) == 0)
		{
			vivod_car_tabl();
			vivod_car(i);
			d = 1;
			system("pause");
		}
	}
	if (d == 0)
	{
		cout << "Запись с таким типом автомобиля не обнаружена" << endl;
		Sleep(1500);
	}
};
void poisk_cust(Size* s)
{
	
	int flag10 = 1;
	while (flag10)
	{
		system("cls");
		cout << "*** Поиск данных о клиенте ***" << endl;
		cout << "1-Поиск по коду клиента" << endl;
		cout << "2-Поиск по фамилии клиента" << endl;
		cout << "3-Поиск по номеру телефону клиента" << endl;
		cout << "4-Выход в меню поиска" << endl;
		cout << "Ваш выбор: ";
		switch (vvod_int())
		{
		case 1: custp_cod(s); break;
		case 2: custp_fam(s); break;
		case 3: custp_phnum(s); break;
		case 4: flag10 = 0; break;
		default:system("cls"); cout << "Введите допустимое значение" << endl; Sleep(1500); break;
		}
	}
};
void custp_cod(Size* s)
{
	int f, d = 0;
	cout << "Введите код для поиска: ";
	f = vvod_chisel();
	cout << endl;
	for (int i = 0; i < s->customers; i++)
	{
		if (CUST[i].cust_code == f)
		{
			vivod_cust_tabl();
			vivod_cust(i);
			d = 1;
			system("pause");
		}
	}
	if (d == 0)
	{
		cout << "Запись с таким кодом клиента не обнаружена" << endl;
		Sleep(1500);
	}
};
void custp_fam(Size* s)
{
	int d = 0;
	char f[30];
	cout << "Введите фамилию для поиска: ";
	cin >> f;
	cout << endl;
	for (int i = 0; i < s->customers; i++)
	{
		if (strcmp(CUST[i].cust_name.surname,f) == 0)
		{
			vivod_cust_tabl();
			vivod_cust(i);
			d = 1;
			system("pause");
		}
	}
	if (d == 0)
	{
		cout << "Запись с такой фамилией клиента не обнаружена" << endl;
		Sleep(1500);
	}
};
void custp_phnum(Size* s)
{
	int f, d = 0;
	cout << "Введите номер телефона для поиска: ";
	f = vvod_chisel();
	cout << endl;
	for (int i = 0; i < s->customers; i++)
	{
		if (CUST[i].cust_phone_number== f)
		{
			vivod_cust_tabl();
			vivod_cust(i);
			d = 1;
			system("pause");
		}
	}
	if (d == 0)
	{
		cout << "Запись с таким номером телефона клиента не обнаружена" << endl;
		Sleep(1500);
	}
};
void poisk_iss(Size* s)
{
	int flag1 = 1;
	while (flag1)
	{
		system("cls");
		cout << "*** Поиск данных о выданном автомобиле ***" << endl;
		cout << "1-Поиск по коду автомобиля" << endl;
		cout << "2-Поиск по коду клиента" << endl;
		cout << "3-Выход в меню поиска" << endl;
		cout << "Ваш выбор: ";
		switch (vvod_int())
		{
		case 1: issp_carcod(s); break;
		case 2: issp_custcod(s); break;
		case 3: flag1 = 0; break;
		default:system("cls"); cout << "Введите допустимое значение" << endl; Sleep(1500); break;
		}
	}
};
void issp_carcod(Size* s)
{
	int f, d = 0;
	cout << "Введите код для поиска: ";
	f = vvod_chisel();
	cout << endl;
	for (int i = 0; i < s->issued; i++)
	{
		if (issued[i].car.car_code == f)
		{
			vivod_iss_tabl();
			vivod_iss(i);
			d = 1;
			system("pause");
		}
	}
	if (d == 0)
	{
		cout << "Запись с таким кодом автомобиля не обнаружена" << endl;
		Sleep(1500);
	}
};
void issp_custcod(Size* s)
{
	int f, d = 0;
	cout << "Введите код для поиска: ";
	f = vvod_chisel();
	cout << endl;
	for (int i = 0; i < s->issued; i++)
	{
		if (issued[i].cust.cust_code == f)
		{
			vivod_iss_tabl();
			vivod_iss(i);
			d = 1;
			system("pause");
		}
	}
	if (d == 0)
	{
		cout << "Запись с таким кодом клиента не обнаружена" << endl;
		Sleep(1500);
	}
};
void zapis(Size* s)
{
	FILE* fadm;
	FILE* fus;
	FILE* fcar;
	FILE* fcast;
	FILE* fis;

	fadm = fopen("Admin.txt", "w");
	for (int i = 0; i < s->admin; i++)
	{
		for (int n = 0; n < strlen(Adm[i].admin_par); n++)
		{
			int symbol = int(Adm[i].admin_par[n]) + KEY;
			Adm[i].admin_par[n] = symbol;
		}
		fprintf(fadm, "%s\n", Adm[i].admin_log);
		fprintf(fadm, "%s\n", Adm[i].admin_par);
	}
	fclose(fadm);
	fus = fopen("User.txt", "w");
	for (int i = 0; i < s->user; i++)
	{
		for (int n = 0; n < strlen(Users[i].user_par); n++)
		{
			int symbol = int(Users[i].user_par[n]) + KEY;
			Users[i].user_par[n] = symbol;
		}
		fprintf(fus, "%s\n", Users[i].user_log);
		fprintf(fus, "%s\n", Users[i].user_par);
	}
	fclose(fus);
	fcar = fopen("Cars.txt", "w");
	for (int i = 0; i < s->cars; i++)
	{
		fprintf(fcar, "%u\n", CARS[i].car_code);
		fprintf(fcar, "%s\n", CARS[i].car_d.car_mark);
		fprintf(fcar, "%u\n", CARS[i].car_d.car_cost);
		fprintf(fcar, "%u\n", CARS[i].rental_cost);
		fprintf(fcar, "%s\n", CARS[i].car_d.car_type);
	}
	fclose(fcar);
	fcast = fopen("Customers.txt", "w");
	for (int i = 0; i < s->customers; i++)
	{
		fprintf(fcast, "%u\n", CUST[i].cust_code);
		fprintf(fcast, "%s\n", CUST[i].cust_name.surname);
		fprintf(fcast, "%s\n", CUST[i].cust_name.name);
		fprintf(fcast, "%s\n", CUST[i].cust_name.patronymic);
		fprintf(fcast, "%s\n", CUST[i].cust_address);
		fprintf(fcast, "%u\n", CUST[i].cust_phone_number);
	}
	fclose(fcast);
	fis = fopen("Issued cars.txt", "w");
	for (int i = 0; i < s->issued; i++)
	{
		fprintf(fis, "%u\n", issued[i].car.car_code);
		fprintf(fis, "%u\n", issued[i].cust.cust_code);
		fprintf(fis, "%u\n", issued[i].is_d.day);
		fprintf(fis, "%u\n", issued[i].is_d.month);
		fprintf(fis, "%u\n", issued[i].is_d.year);
		fprintf(fis, "%u\n", issued[i].ret_d.day);
		fprintf(fis, "%u\n", issued[i].ret_d.month);
		fprintf(fis, "%u\n", issued[i].ret_d.year);
	}
	fclose(fis);
};
void vivod_car_tabl()
{
	cout << " _______________________________________________________________________________________" << endl;
	cout << "| № | Код автомобиля |      Марка      | Стоимость($) |Стоимость проката(руб.)|   Тип   |" << endl;
	cout << "|___|________________|_________________|______________|_______________________|_________|" << endl;
}
void vivod_car(int num)
{

	printf("|%3d|%16d|%17s|%14d|%23d|%9s|\n", num + 1, CARS[num].car_code, CARS[num].car_d.car_mark, CARS[num].car_d.car_cost, CARS[num].rental_cost, CARS[num].car_d.car_type);
	cout << "|___|________________|_________________|______________|_______________________|_________|" << endl;
};
void vivod_cust_tabl()
{
	cout << " _____________________________________________________________________________________________________________________" << endl;
	cout << "| № | Код клиента |     Фамилия      |      Имя      |    Отчество    |          Адрес          |   Телефон(+375...)  |" << endl;
	cout << "|___|_____________|__________________|_______________|________________|_________________________|_____________________|" << endl;
};
void vivod_cust(int n)
{
	printf("|%3d|%13d|%18s|%15s|%16s|%25s|%21d|\n", n + 1, CUST[n].cust_code, CUST[n].cust_name.surname, CUST[n].cust_name.name, CUST[n].cust_name.patronymic, CUST[n].cust_address, CUST[n].cust_phone_number);
	cout << "|___|_____________|__________________|_______________|________________|_________________________|_____________________|" << endl;
};
void vivod_iss_tabl()
{
	cout << " ____________________________________________________________________" << endl;
	cout << "| № | Код автомобиля | Код клиента |   Дата выдачи  |  Дата возврата |" << endl;
	cout << "|   |                |             |День|Месяц| Год |День|Месяц| Год |" << endl;
	cout << "|___|________________|_____________|____|_____|_____|____|_____|_____|" << endl;
};
void vivod_iss(int n)
{
	printf("|%3d|%16d|%13d|%4d|%5d|%5d|%4d|%5d|%5d|\n", n + 1, issued[n].car.car_code, issued[n].cust.cust_code, issued[n].is_d.day, issued[n].is_d.month, issued[n].is_d.year, issued[n].ret_d.day, issued[n].ret_d.month, issued[n].ret_d
		.year);
	cout << "|___|________________|_____________|____|_____|_____|____|_____|_____|" << endl;
};
int menu_sort(Size* s)
{
	int flag = 1;
	while (flag)
	{
		system("cls");
		cout << "*** Сортировка данных ***" << endl;
		cout << "1-Сортировка данных об автомобилях" << endl;
		cout << "2-Сортировка данных о клиентах" << endl;
		cout << "3-Сортировка данных о выданных автомобилях" << endl;
		cout << "4-Выход из меню сортировки" << endl;
		cout << "Ваш выбор: ";
		switch (vvod_int())
		{
		case 1:
		{
			cout << "Выберите способ сортировки:" << endl;
			cout << "1-По коду автомобиля" << endl;
			cout << "2-По стоимости проката автомобиля" << endl;
			cout << "Ваш выбор: " << endl;
			switch (vvod_int())
			{
			case 1:
			{
				for (int i = 0; i < s->cars; i++)
					for (int j = 0; j < s->cars - 1; j++)
						if (CARS[j].car_code > CARS[j + 1].car_code)
							swap_car(j);
				cout << "Сортировка выполнена:" << endl;
				vivod_car_tabl();
				for (int f = 0; f < s->cars; f++)
					vivod_car(f);
				system("pause");
			}break;
			case 2:
			{
				for (int i = 0; i < s->cars; i++)
					for (int j = 0; j < s->cars - 1; j++)
						if (CARS[j].rental_cost > CARS[j + 1].rental_cost)
							swap_car(j);
				cout << "Сортировка выполнена:" << endl;
				vivod_car_tabl();
				for (int f = 0; f < s->cars; f++)
					vivod_car(f);
				system("pause");
			}break;
			default: system("cls"); cout << "Введите допустимое знаение" << endl; Sleep(1500); break;
			}
		}break;
		case 2:
		{
			cout << "Выберите способ сортировки:" << endl;
			cout << "1-По коду клиента" << endl;
			cout << "2-По фамилии клиента" << endl;
			cout << "Ваш выбор: " << endl;
			switch (vvod_int())
			{
			case 1:
			{
				for (int i = 0; i < s->customers; i++)
					for (int j = 0; j < s->customers - 1; j++)
						if (CUST[j].cust_code > CUST[j+1].cust_code)
							swap_cust(j);
				cout << "Сортировка выполнена:" << endl;
				vivod_cust_tabl();
				for (int f = 0; f < s->customers; f++)
					vivod_cust(f);
				system("pause");
			}break;
			case 2:
			{
				for (int i = 0; i < s->customers; i++)
					for (int j = 0; j < s->customers - 1; j++)
						if (CUST[j].cust_name.surname > CUST[j + 1].cust_name.surname)
							swap_cust(j);
				cout << "Сортировка выполнена:" << endl;
				vivod_cust_tabl();
				for (int f = 0; f < s->customers; f++)
					vivod_cust(f);
				system("pause");
			}break;
			default: system("cls"); cout << "Введите допустимое знаение" << endl; Sleep(1500); break;
			}
		}break;
		case 3:
		{
			cout << "Выберите способ сортировки:" << endl;
			cout << "1-По коду автомобиля" << endl;
			cout << "2-По коду клиента" << endl;
			cout << "Ваш выбор: " << endl;
			switch (vvod_int())
			{
			case 1:
			{
				for (int i=0;i<s->issued;i++)
					for (int j = 0; j < s->issued-1; j++)
						if (issued[j].car.car_code> issued[j+1].car.car_code)
							swap_iss(j);
				cout << "Сортировка выполнена:" << endl;
				vivod_iss_tabl();
				for (int f = 0; f < s->issued; f++)
					vivod_iss(f);
				system("pause");
			}break;
			case 2:
			{
				for (int i = 0; i < s->issued; i++)
					for (int j = 0; j < s->issued - 1; j++)
						if (issued[j].cust.cust_code > issued[j + 1].cust.cust_code)
							swap_iss(j);
				cout << "Сортировка выполнена:" << endl;
				vivod_iss_tabl();
				for (int f = 0; f < s->issued; f++)
					vivod_iss(f);
				system("pause");
			}break;
			default: system("cls"); cout << "Введите допустимое знаение" << endl; Sleep(1500); break;
			}
		}break;
		case 4: flag = 0; break;
		default:system("cls"); cout << "Введите допустимое знаение" << endl; Sleep(1500); break;
		}
	}
	return 0;
};
void swap_car(int i)
{
	CARTMP = CARS[i];
	CARS[i]=CARS[i+1];
	CARS[i + 1]= CARTMP;
};
void swap_cust(int i)
{
	CUSTMP = CUST[i];
	CUST[i] = CUST[i+1];
	CUST[i + 1] = CUSTMP;
};
void swap_iss(int i)
{
	ISSTMP = issued[i];
	issued[i]=issued[i+1];
	issued[i + 1] = ISSTMP;
};
int zadacha(Size* s)
{
	for (int i = 0; i < s->issued; i++)
		for (int j = 0; j < s->issued - 1; j++)
			if (issued[j].cust.cust_code < issued[j + 1].cust.cust_code)
				swap_iss(j);
	int count=0,cod;
	cod = issued[0].cust.cust_code;
	for (int t = 0; t < s->issued; t++)
		if (issued[t].cust.cust_code == cod)
			count++;
	if (count >= 3)
	{
		for (int j = 0; j < s->customers; j++)
			if (CUST[j].cust_code == cod)
			{
				cout << "Данный клиент арендовал автомобиль 3 и более раз" << endl;
				vivod_cust_tabl();
				vivod_cust(j);
				j = s->customers;
				system("pause");
			}
	}
	else
	{
		cout << "Не один клиент не арендовал автомобиль 3 и более раз" << endl;
		Sleep(1500);
	}
	return 0;
};