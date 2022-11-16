#include <iostream>
using namespace std;

//Function value checker
int value(char r)
{
        switch(r){
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
        default:
            return -1;

        }
    }


class romanType
{
    private:
        string romanNumeral;
        int decimalResult;
    public:
        int romanToDecimal(string);
        void setRoman(string);
        void setDecimal(string);
        string getRoman();
        int getDecimal();
        void displayRoman();
        void displayDecimal();
};


int romanType :: romanToDecimal(string roman)
{
    int res = 0;

	// Traverse given input
	for (int i = 0; i < roman.length(); i++) {
		// Getting value of symbol s[i]
		int s1 = value(roman[i]);

		if (i + 1 < roman.length()) {
			// Getting value of symbol s[i+1]
			int s2 = value(roman[i + 1]);

			// Comparing both values
			if (s1 >= s2) {
				res = res + s1;
			}
			else {
				res = res + s2 - s1;
				i++;
			}
		}
		else {
			res = res + s1;
		}
	}
	return res;
}

void romanType :: setRoman (string romanx)
{
    romanNumeral = romanx;
}

void romanType :: setDecimal (string romany)
{
    decimalResult = romanToDecimal(romany);
}

string romanType :: getRoman()
{
    return romanNumeral;
}

int romanType :: getDecimal()
{
    return decimalResult;
}

void romanType :: displayRoman()
{
    cout <<"The Roman Numberal is : " <<  romanNumeral << endl;
}

void romanType :: displayDecimal()
{
    cout << "The result of convertin Roman Numeral to Decimal Number is : " << decimalResult << endl;
}



// Driver Code
int main()
{
    string romanInput;
    int choice;
    
	cout << "Program Convert Roman into Decimal Started\n\n";
    cout << "Input your Roman Numeral (Capital Only): ";
    cin >> romanInput;

    romanType roman1;
    roman1.setRoman(romanInput);
    roman1.romanToDecimal(romanInput);
    roman1.setDecimal(romanInput);

    while (choice > 3){
        cout << "Show the result (input the number) :\n(1) Roman\n(2) Decimal\n(3) Both\n " << endl;
        cin >> choice;
            
                if (choice == 1)
                    roman1.displayRoman();
                else if (choice == 2)
                    roman1.displayDecimal();
                else if(choice == 3)
                    cout << "The result of " << roman1.getRoman() << " is " << roman1.getDecimal();
                else
                    cout << "Wrong Input!\n\n";
            
    }
	return 0;
}