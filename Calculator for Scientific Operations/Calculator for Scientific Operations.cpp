#include <iostream>
#include <cmath>
#include <string>

void pause()
{
	system("pause");
}

void clearConsole()
{
	system("cls");
}

enum operationType
{
	addition,
	subtraction,
	multiplication,
	division,
	modulus,
	elevation,
	unvalid
};

operationType selectOperator(char input) {
	if (input == '+') return addition;
	else if (input == '-') return subtraction;
	else if (input == '*') return multiplication;
	else if (input == '/') return division;
	else if (input == '%') return modulus;
	else if (input == '^') return elevation;
	else return unvalid;
}

void printCommands()
{
	std::cout << "\n\n\n\n These are the commands you can use!";
	std::cout << "\n + | For addition";
	std::cout << "\n - | For subtraction";
	std::cout << "\n * | For multiplication";
	std::cout << "\n / | For division";
	std::cout << "\n % | For modulus";
	std::cout << "\n ^ | For elevation";
	for (int i = 0; i < 10; i++)
	{
		std::cout << "\033[F";
	}
}

double doOperation(double firstValue, double secondValue, char operationChar)
{
	double result;
	switch (selectOperator(operationChar))
	{
	case addition:
		result = firstValue + secondValue;
		return result;
		break;
	case subtraction:
		result = firstValue - secondValue;
		return result;
		break;
	case multiplication:
		result = firstValue * secondValue;
		return result;
		break;
	case division:
		result = firstValue / secondValue;
		return result;
		break;
	case modulus:
	{
		int newfirst = (int)round(firstValue);
		int	newsecond = (int)round(secondValue);
		result = newfirst % newsecond;
		return result;
		break;
	}
	case elevation:
		result = pow(firstValue, secondValue);
		return result;
		break;
	}
}

bool evaluateOperator(char operatorChar)
{
	switch (selectOperator(operatorChar))
	{
	case addition:
		return true;
		break;
	case subtraction:
		return true;
		break;
	case multiplication:
		return true;
		break;
	case division:
		return true;
		break;
	case modulus:
		return true;
		break;
	case elevation:
		return true;
		break;
	case unvalid:
		return false;
		break;
	}
}

void clearCin()
{
	clearConsole();
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool evaluateInput(int firstValue, int secondValue, char operationChar)
{
	if (!evaluateOperator(operationChar))
	{
		std::cout << '\a';
		std::cout << "That's not a valid operator!\n";
		pause();
		clearConsole();
		return false;
	}
	return true;
}

int main()
{
	int firstValue, secondValue;
	char operationChar;
	while (true)
	{
		printCommands();
		std::cin >> firstValue >> operationChar >> secondValue;
		if (std::cin.fail())
		{
			firstValue = NULL;
			secondValue = NULL;
			clearCin;
			std::cout << '\a';
			std::cout << "Values must be only numbers!\n";
			pause();
			clearConsole();
		}

		else
		{
			if (evaluateInput(firstValue, secondValue, operationChar))
			{
				clearConsole();
				printCommands();
				std::cout << doOperation(firstValue, secondValue, operationChar) << " ";
			}
		}
	}
}