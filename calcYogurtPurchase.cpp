#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cctype>                             
#include <string>
using namespace std;

	//Author: James Saylor
	//Description : Program prompts user to input yogurt size, container choice,
	//toppings amount and customer card discount. The program will take that info
	//and calculate the final cost of the order
	
	//constants
	const double REG_YOGURT = 0.44;
	const double WAFFLE_CONES = 0.57;
	const double TOPPINGS = 0.63;
	const double DISCOUNT_ONE = 0.72;
	const double DISCOUNT_TWO = 1.58;
	const double FIVE_PUNCHES = 0.5;
	const double THRESHOLD_ONE = 16;
	const double THRESHOLD_TWO = 31;
	const string WAFFLE = "Waffle Cone";
	const string PLASTIC = "Plastic Cup";
	
	//functions
	double DiscountCalc(double ounces)
	{
		double discount;
		
		if(ounces >= THRESHOLD_ONE && ounces <= THRESHOLD_TWO)
		{
			discount = DISCOUNT_ONE;
		}
		else if(ounces > THRESHOLD_TWO)
		{
			discount = DISCOUNT_TWO;
		}
		else //filler
		{
			discount = 0;
		}
		return discount;
	}
	
int main ()
{
	//variables
	char container;
	char toppings;
	double ounces;
	double toppingPrice;
	double subTotal;
	double custDiscount;
	double yogurtPrice;
	int numOfToppings;
	bool wantsToppings;
	bool waffleCone = false;
	string customerCard;
	
	//input
	cout << "Yogurt Purchase Calculation Program" << endl << endl;
	cout << "Enter the weight of the yogurt, in ounces: ";
	cin >> ounces;
	cout << endl << endl << "Plastic cup or waffle cone (P/W)? ";
	cin >> container;
	container = toupper(container);
	cout << endl << "Toppings wanted (T for toppings/N for no toppings)? ";
	cin >> toppings;
	toppings = toupper(toppings);
	if(toppings == 'T' || toppings == 't')
	{
		wantsToppings = true;
		cout << "Number of toppings? ";
		cin >> numOfToppings;
		cout << endl << endl;
	}
	else
	{
		wantsToppings = false;
		numOfToppings = 0;
		cout << endl << endl;
	}
	cout << "Are there 5 punches on card (yes or no, all lowercase)? ";
	cin >> customerCard;
	cout << endl << endl;
	
	//output
	cout << "Yogurt Order" << endl;
	cout << "Weight (oz):" << setw(25) << ounces << endl;
	if(container == 'P')
	{
		cout << "Container:" << setw(27) << PLASTIC << endl;
	}
	else
	{
		cout << "Container:" << setw(27) << WAFFLE << endl;
		waffleCone = true;
 	}
 	cout << "Number of Toppings:" << setw(18) << numOfToppings << endl << endl;
 	
 	//calculation
	yogurtPrice = ounces * REG_YOGURT;
 	toppingPrice = numOfToppings * TOPPINGS;
 	if(waffleCone)
 	{
 		subTotal = yogurtPrice + toppingPrice + WAFFLE_CONES;
 	}
	else
	{
		subTotal = yogurtPrice + toppingPrice;
	}
	
	//output
	cout << showpoint << fixed << setprecision(2);
	cout << "Yogurt Bill" << endl;
	cout << "Yogurt Cost:" << setw(25) << yogurtPrice << endl;
	if(waffleCone)
		{
			cout << "Plus Cone:" << setw(27) << WAFFLE_CONES << endl;
		}
	cout << "Plus Toppings:" << setw(23) << toppingPrice << endl;
	cout << setw(37) << "--------" << endl;
	if(ounces >= THRESHOLD_ONE)
	{
		cout << "Subtotal:" << setw(28) << subTotal;
		custDiscount = DiscountCalc(ounces);
		cout << endl << "Less Discount:" << setw(23) << custDiscount << endl;
		subTotal = subTotal - custDiscount;
		cout << setw(37) << "--------" << endl;
	}
	cout << "Bill Total:" << setw(26) << subTotal;
	if(customerCard == "yes")
	{
		cout << endl << endl;
		subTotal = subTotal * FIVE_PUNCHES;
		cout << "5 punch reduced price:" << setw(15) << subTotal;
	}
	
	
 	cout << endl << endl;
 	return 0;
}

