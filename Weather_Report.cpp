/******************************************************************************

Create a class named weather report that holds a daily weather report with data 
members day_of_month, hightemp, lowtemp,a mount_rain and amount_snow. 
Use different types of constructors to initialize the objects. Also include a 
function that prompts the user and sets values for each field so that you can 
override the default values. Write a menu driven program in C++ with options to 
enter data and generate monthly report that displays average of each attribute.


*******************************************************************************/
#include <iostream>
#include <stdlib.h>

using namespace std;

class WEATHER
{
	int day_of_month;
	float hightemp, lowtemp, amount_rain, amount_snow;

  public:
	WEATHER()
	{
		day_of_month = 100;
		hightemp = 100;
		lowtemp = -100;
		amount_rain = 0;
		amount_snow = 0;
	}

	void
	ACCEPT(int date)
	{
		day_of_month = date;
		cout << "Enter high temp of day : ";
		cin >> hightemp;
		cout << "Enter low temp of day : ";
		cin >> lowtemp;
		cout << "Enter amount of rain of day : ";
		cin >> amount_rain;
		cout << "Enter amount of snow of day : ";
		cin >> amount_snow;
		cout << "\n";
	}

	void DISPLAY()
	{
		cout << day_of_month << "\t\t" << hightemp << "\t\t" << lowtemp << "\t\t" << amount_rain << "\t\t" << amount_snow << "\n";
	}

	void AVERAGE(WEATHER w[31], int count)
	{
		int i;
		float total_hightemp = 0;
		float total_lowtemp = 0;
		float total_amount_rain = 0;
		float total_amount_snow = 0;
		float avg_hightemp = 0;
		float avg_lowtemp = 0;
		float avg_amount_rain = 0;
		float avg_amount_snow = 0;

		for (i = 0; i < 31; i++)
		{
			if (w[i].day_of_month != 100)
			{
				total_hightemp += w[i].hightemp;
				total_lowtemp += w[i].lowtemp;
				total_amount_rain += w[i].amount_rain;
				total_amount_snow += w[i].amount_snow;
			}
		}

		avg_hightemp = total_hightemp / count;
		avg_lowtemp = total_lowtemp / count;
		avg_amount_rain = total_amount_rain / count;
		avg_amount_snow = total_amount_snow / count;

		cout << "\nAverage High temp : " << avg_hightemp;
		cout << "\nAverage Low temp : " << avg_lowtemp;
		cout << "\nAverage amount of rain:" << avg_amount_rain;
		cout << "\nAverage amount of snow : " << avg_amount_snow;
	}
};

void main()
{
	WEATHER w[31], w1;
	int choice;
	int i, d, date, count;

	do
	{
		cout << "\n*****MENU*****\n\n1) ENTER DATA \n2) DISPLAY DATA\n3) AVERAGE\n4) EXIT\n*****************\n\n";
		cout << "\nEnter your choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			int count, i;
			cout << "\nEnter number of days :";
			cin >> count;
			for (i = 1; i <= count; i++)
			{
				cout << "Enter date :";
				cin >> date;
				w[date].ACCEPT(date);
			}
			break;

		case 2:
			cout << "day_of_month"
				 << "\t"
				 << "hightemp"
				 << "\t"
				 << "lowtemp"
				 << "\t"
				 << "amount_rain"
				 << "\t"
				 << "amount_snow"
				 << "\n";

			for (i = 1; i <= 31; i++)
			{
				w[i].DISPLAY();
			}
			break;

		case 3:
			w1.AVERAGE(w, count);
			break;

		case 4:
			exit(0);
		}
	} while (choice != 4);
}

