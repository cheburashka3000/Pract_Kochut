#include <iostream>
#include <chrono>
using namespace std;
int main(int argc, char **argv)
{
	string Month[12]{" январь ", " февраль ", " март ", " апрель ", " май ", " июнь ", " июль ", " август ", " сентябрь ", " октябрь ", " ноябрь ", " декабрь "};
	string Days[7]{"воскресенье", "понедельник", "вторник", "среда", "четверг", "пятница", "суббота"};
	time_t t = time(NULL);
	tm * ptm;
	ptm = gmtime(&t);
	cout << Days[ptm->tm_wday] << Month[ptm->tm_mon] << ptm->tm_mday << " " << ptm-> tm_hour + 3 << ":" << ptm->tm_min << ":" << ptm->tm_sec << " " << ptm->tm_year + 1900 << endl;
	return 0;
}
