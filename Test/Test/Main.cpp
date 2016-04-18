#include <stdio.h>


/*
-=1.1=-

char* Task();

int main(void) {
	printf("Hello");
	printf(Task());
	return 0;
}

char* Task() {
	return "\tNow :)\n";
}
*/

/*
-=1.3=-

int main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	printf("This is the heading above the table!\n");
	while (fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}
*/

/*
-=1.4=-

int main() {
	int lower = 5, upper = 45;

	printf("Celsius Fahr\n");
	while (lower <= upper) {
		printf("   %d %6.1f\n", lower, lower * (9.0 / 5.0) + 32);
		lower += 3;
	}

	return 0;
}
*/

//#define lower = 5;
//#define upper = 45;


/*
-=1.6=-

int main() {

	//int c = getchar() != EOF;
	//printf("%d", c);

	int c = (getchar() != EOF);
	printf("%d", c);

	return 0;
}
*/

/*
-=1.12=-

int main() {

	char text[1023];

	printf("Insert yout text here: \n");
	fgets(text, 1023, stdin);
	printf("\n");

	int i = 0;

	while (text[i] != NULL) {
		if (text[i] == ' ') {
			printf("\n");
		} else {
			printf("%c", text[i]);
		}
		i++;
	}

	return 0;
}
*/

/*
-=1.13=-

int main() {

	char text[1023];
	int wordsLength[255] = { 0 };

	printf("Insert yout text here: \n");
	fgets(text, 1023, stdin);
	printf("\n");

	int i = 0, temp = 0;

	while (text[i] != '\n') {
		if (text[i] != ' ') {
			wordsLength[temp]++;
		} else {
			temp++;
		}
		i++;
	}

	for (int n = 0; n <= temp; n++) {
		for (int k = 0; k < wordsLength[n]; k++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}

*/

/*
-=1.14=-

Version: 1

#include <map>

int main() {

	char text[1023];
	std::map<char, int> charsMap;
	std::map<char, int>::iterator it;

	printf("Insert yout text here: \n");
	fgets(text, 1023, stdin);
	printf("\n");

	int i = 0;

	while (text[i] != '\n') {
		if (text[i] != ' ') {
			it = charsMap.find(text[i]);
			if (it == charsMap.end()) {
				charsMap[text[i]] = 1;
			}
			else {
				charsMap[text[i]]++;
			}
		}
		i++;
	}

	for (auto& x : charsMap) {
		int n = 0;
		while (n < x.second) {
			printf("*");
			n++;
		}
		printf("\n");
	}

	return 0;
}


-=1.14=-
Version 2

int main() {

	char text[1023];
	int charCodes[150] = {0};

	printf("Insert yout text here: \n");
	fgets(text, 1023, stdin);
	printf("\n");

	int i = 0;

	while (text[i] != '\n') {
		if (charCodes[(int)text[i]] == 0) {
			charCodes[(int)text[i]] = 1;
		} else {
			charCodes[(int)text[i]]++;
		}
		i++;
	}

	for (int k = 0; k < 150; k++) {
		int n = 0;
		while (n < charCodes[k]) {
			if (n == 0) {
				printf("%c: ", k);
			}
			printf("*");
			n++;
		}
		if (charCodes[k] != 0) {
			printf("\n");
		}
	}

	return 0;
}

*/

/*
-=1.15=-


float CelToFahr(int *);
float CelToFahr(int &);

int main() {
	int lower = 5, upper = 45;

	printf("Celsius Fahr\n");
	while (lower <= upper) {
		printf("   %d %6.1f\n", lower, CelToFahr(&lower));
		//printf("   %d %6.1f\n", lower, CelToFahr(lower));
		lower += 3;
	}

	return 0;
}

float CelToFahr(int *cel) {
	float result = *cel * (9.0 / 5.0) + 32;
	return result;
}

float CelToFahr(int & cel) {
	float result = cel * (9.0 / 5.0) + 32;
	return result;
}
*/

/*
-=1.19=-

void Reverse(char *, int, int);

int main() {
	char text[1023], reversedText[1023] = {0}, temp[102];

	printf("Insert yout text here: \n");
	fgets(text, 1023, stdin);

	int i = 0, k = 0, p, sum = 0;

	while (text[i] != '\0') {
		if (text[i] != '^' && text[i] != '\n') {
			temp[k] = text[i];
			k++;
		} else {
			Reverse(temp, 0, k - 1);

			p = sum;
			while (p < k + sum) {
				reversedText[p] = temp[p - sum];
				p++;
			}

			reversedText[p] = '\n';

			sum += ++k;
			k = 0;
		}
		i++;
	}

	printf("%s", reversedText);

	return 0;
}

void Reverse(char *string, int begin, int end) {
	char c;

	if (begin >= end) {
		return;
	}

	c = *(string + begin);
	*(string + begin) = *(string + end);
	*(string + end) = c;

	Reverse(string, ++begin, --end);
}

*/


/*
-=2.2=-


int GetLine(char line[], int maxLine);

int main() {
	char line[1000];
	int i = 0;

	while (GetLine(line, 1000) > 5) {
		printf("%d\n", i);
		i++;
	}
	return 0;
}

int GetLine(char s[], int lim) {
	int c, i;

	//for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		//s[i] = c;
	//}
	i = 0;
	while ((c = getchar()) != EOF) {
		if (i > lim - 1) {
			break;
		} else if (c == '\n') {
			s[i] = c;
			++i;
			break;
		}
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}

*/

/*
-=2.3=-

int Htoi(char *number);

int main() {
	char hexNumber[10], temp;
	int i = 0;

	printf("Enter the HEX number!\n");

	while ((temp = getchar()) != '\n') {
		hexNumber[i] = temp;
		i++;
	}

	printf("%d", Htoi(hexNumber));

	return 0;
}

int Htoi(char *number) {
	int i = 0;

	if (number[i] == '0') {
		i++;
	}

	if (number[i] == 'x' || number[i] == 'X') {
		i++;
	}

	int result = 0, hexNum;
	bool inHex = true;

	while (inHex) {
		if (number[i] >= '0' && number[i] <= '9') {
			hexNum = number[i] - '0';
		} else if (number[i] >= 'a' && number[i] <= 'f') {
			hexNum = number[i] - 'a' + 10;
		} else if (number[i] >= 'A' && number[i] <= 'F') {
			hexNum = number[i] - 'A' + 10;
		} else {
			inHex = false;
		}
		i++;

		if (inHex) {
			result = 16 * result + hexNum;
		}
	}

	return result;
}
*/


/*
-=2.4=-

#include <string.h>

void Squeeze(char [], char []);

int main() {
	char in[50], from[50];

	printf("Delete matching chars from string:\n");
	fgets(in, 50, stdin);

	printf("Matching chars:\n");
	fgets(from, 50, stdin);

	Squeeze(in, from);

	printf("Result (string without the mathing chars): %s\n", in);

	return 0;
}

void Squeeze(char in[], char from[]) {
	int i = 0, n, s;
	char temp[50];

	while (from[i] != '\0') {
		n = 0;
		while (in[n] != '\0') {
			if (from[i] == in[n]) {
				in[n] = '\n';
			}
			n++;
		}
		i++;
	}

	n = 0;
	s = 0;

	while (in[n] != '\0') {
		if (in[n] != '\n') {
			temp[s] = in[n];
			s++;
		}
		n++;
	}

	i = 0;

	memset(in, 0, sizeof in);
	while (i < s) {
		memmove(in, temp, s);
		i++;
	}
}

*/

/*
-=2.5=-

int Any(char *, char *);

int main() {
	char in[100], from[20];
	int posit;

	printf("Insert a string for searching into!\n");
	fgets(in, 100, stdin);

	printf("Insert searching chars!\n");
	fgets(from, 20, stdin);

	posit = Any(in, from);

	printf("\nResult\n\nPosition: %d\nChar: %c\n", posit, in[posit]);

}

int Any(char *in, char *from) {
	int i = 0, pos, result = -1;

	while (from[i] != '\n') {
		pos = 0;
		while (in[pos] != '\n') {
			if (from[i] == in[pos]) {
				result = pos;
				break;
			}
			pos++;
		}
		i++;
	}
	
	return result;
}
*/

/*
-=2.9=-

int main() {
	//unsigned int x = 101;

	//x &= (x - 1); // x = x & (x - 1);

	//printf("%d\n", x);

	unsigned int x;

	printf("Enter decimal number: ");
	scanf("%d", &x);

	//int b, c = 0;
	//for (b = 0; x != 0; x>>= 1) {
	//	if (x & 01) {
	//		b++;
	//	}
	//	c++;
	//}

	//int b;
	//x = x - ((x >> 1) & 0x55555555);
	//x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	//b = (((x + (x >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24; 

	int b = 0;
	while (x) {
		x &= (x - 1);
		b++;
	}

	printf("%d\n", b);

	return 0;
}

*/

/*
-=Task 7=-

void RotateLeft(unsigned int, unsigned int);

int main() {
	char temp;
	unsigned int bits, i = 0, hexNumber;

	printf("Enter the number of bits for the left rotating shift: ");
	scanf("%d", &bits);

	printf("Enter the HEX number: ");
	scanf("%x", &hexNumber);

	RotateLeft(hexNumber, bits);

	return 0;
}

void RotateLeft(unsigned int x, unsigned int n) {
	printf("%x\n", (x << n) | (x >> (32 - n)));
}

//const char * HexToBin(unsigned char c) {
//	char * quads[] = { "0000", "0001", "0010", "0011", "0100", "0101", "0110", 
//		"0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110" ,"1111" };
//
//	if (c >= '0' && c <= '9') {
//		return quads[c - '0'];
//	} else if (c >= 'A' && c <= 'F') {
//		return quads[10 + c - 'A'];
//	} if (c >= 'a' && c <= 'f') {
//		return quads[10 + c - 'a'];
//	}
//
//	return "error";
//}

*/

/*
-=Task: 6=-


int Check(unsigned int, char);

int main() {
	unsigned int num;
	char func = 'd';

	//num = 0x000000ff;

	printf("Enter:\n'a' for finding a bit different from '0'\n"
		"'b' for finding a bit different from '1'\n"
		"'c' for finding out if there is a '1' bits in least significant byte\n"
		"'d' for finding out if there is a '0' bits in most significant byte\n\n"
		"Function: ");
	scanf("%c", &func);

	printf("\nEnter the number: ");
	scanf("%x", &num);
	
	printf("%d\n\n", Check(num, func));

	return 0;
}

int Check(unsigned int num, char c) {
	switch (c) {
		case 'a': {
			//int i, n = 0;
			//for (i = 0; num != 0; num >>= 1) {
			//	if (num & 01) {
			//		i++;
			//	}
			//	n++;
			//}
			//if (i != n) {
			//	return 1;
			//}
			//return 0;
			return ((num & 0xf) != 0xf);
		} break;
		case 'b': {
			//int i;
			//for (i = 0; num != 0; num >>= 1) {
			//	if (num & 01) {
			//		return 1;
			//	}
			//}
			//return 0;
			return((num & 0xf) != 0x0);
		} break;
		case 'c': {
			return ((num & 0xff) != 0);
		} break;
		case 'd': {
			unsigned int temp;

			//if (num <= 0xf) { temp = 0xf; }
			//else if (num <= 0xff) { temp = 0xff; }
			//else if (num <= 0xfff) { temp = 0xff0; }
			//else if (num <= 0xffff) { temp = 0xff00; }
			//else if (num <= 0xfffff) { temp = 0xff000; }
			//else if (num <= 0xffffff) { temp = 0xff0000; }
			//else if (num <= 0xfffffff) { temp = 0xff00000; }
			//else if (num <= 0xffffffff) { temp = 0xff000000; }

			//printf("Size of:  %d \n", sizeof(num));

			return (((num >> 24) & 0xff) != 0xff);
		} break;
	}
	return -1;
}

*/

/*
Задача 1 от допълнителните

unsigned int SetBit(unsigned int, unsigned char);

int main() {
	//Променят се при тестване -->
	unsigned int num = 0xabcc;
	unsigned char posit = 0;
	//<--

	printf("Result: 0x%x\n", SetBit(num, posit));

	return 0;
}

//Тук не бях сигурен дали трябва да връща стойност, но ако нещо ще променя функцията
//или мога да използвам поинтъри, за да не се налага да връщам нищо
//
//И за Hex числа unsigned int или char да използвам? Кое е по-добре?
//
//Също така само на position ли да използвам unsigned или и на самото число
//Как е по-добре
unsigned int SetBit(unsigned int num, unsigned char position) {
	return (num |= (1 << position));
}
*/

/*
Задача 2 от допълнителните

//Тази задача я направих с unsigned char, за да видя дали всичко работи с него като при int
unsigned char ClearBit(unsigned char, unsigned char);

int main() {
	//Променят се при тестване -->
	unsigned char 
		posit = 1, 
		num = 0xf;
	//<--

	printf("Result: 0x%x\n", ClearBit(num, posit));

	return 0;
}

unsigned char ClearBit(unsigned char num, unsigned char position) {
	//В такива функции, в които мога да напиша всичко на един ред
	//в този формат ли да пиша или да разделям отделните части, променливи и т.н.
	return num &= ~(1 << position);
}
*/

/*
Задача 3 от допълнителните

unsigned int IsPowerOfTwo(unsigned int);

int main() {
	unsigned int hexNumber;

	//Променят се при тестване -->
	hexNumber = 0x0101;
	//<--

	printf("%d\n", IsPowerOfTwo(hexNumber));

	return 0;
}

unsigned int IsPowerOfTwo(unsigned int number) {
	return (!(number & (number - 1)) && (number != 0));
}
*/

/*
Задача 4 от допълнителните

unsigned int CheckOneBitSet(unsigned int);

int main() {
	unsigned int hexNumber;

	//Променят се при тестване -->
	hexNumber = 0;
	//<--

	printf("%d\n", CheckOneBitSet(hexNumber));

	return 0;
}

unsigned int CheckOneBitSet(unsigned int number) {
	return (number && !(number & (number - 1)));
}
*/

/*
Задача 5 от допълнителните

unsigned int CheckParity(unsigned int);

int main() {
	unsigned int hexNumber;

	//Променят се при тестване -->
	hexNumber = 5;
	//<--

	printf("%d\n", CheckParity(hexNumber));

	return 0;
}

unsigned int CheckParity(unsigned int number) {
	//За 32 битови машини
	number ^= number >> 16;
	number ^= number >> 8;
	number ^= number >> 4;
	number ^= number >> 2;
	number ^= number >> 1;
	return !((~number) & 1);
}
*/

/*
Задача 6 от допълнителните


int main() {
	int a = 5;
	int b = 3;

	a ^= b;
	b ^= a;
	a ^= b;

	printf("a=%d, b=%d\n", a, b);

	return 0;
}
*/

/*
Task: 3.3


void Expand(char [], char []);

int main() {
	//Test values -->
	char text[] = { "t0shk0 a-f a-c-pA-Z t0shk0" }, result[255];
	//<--

	Expand(text, result);

	printf("Result character string: %s", result);

	return 0;
}

void Expand(char shortNotation[], char complNotation[]) {
	short i = 0, k = 0;
	char firstChar = -52, secondChar = -52;
	bool tempResult = false;

	while (shortNotation[i] != -52) {
		if (shortNotation[i] != 45 && shortNotation[i] != 32 &&
			shortNotation[i + 1] == '-' && shortNotation[i + 2] > shortNotation[i]) {

			firstChar = shortNotation[i];
			secondChar = shortNotation[i + 2];

			tempResult = true;

			if (complNotation[k - 1] == firstChar) { k--; }

			while (firstChar < secondChar) {
				complNotation[k] = firstChar;

				firstChar++;
				k++;
			}

			complNotation[k--] = firstChar;

			firstChar = secondChar = -52;
			i++;
		}

		if (!tempResult) { complNotation[k] = shortNotation[i]; } 
		else { tempResult = false; }

		k++;
		i++;
	}
}
*/


/*
Task: 3.6

#include <string.h>

void Reverse(char []);
void Itoa(int, char [], int);

int main() {
	//Test values -->
	char test[15];
	Itoa(54568, test, 10);
	//<--

	printf("Number, converted to character string:%s\n", test);

	return 0;
}

void Itoa(int n, char s[], int minWidth) {
	int i = 0, sign;

	if ((sign = n) < 0) { n = -n; }

	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign < 0) { s[i++] = '-'; }

	if (i < minWidth) {
		while (i < minWidth) {
			s[i] = ' ';
			i++;
		}
	}

	s[i] = '\0';
	Reverse(s);
}

void Reverse(char s[]) {
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
*/

/*
Task: 7.1 - 7.8

This program provides a simple 5-function calculator.

===> OTHER DOCUMENTATION HERE

Input:  a char, stored in operation;
two reals, stored in op1 and op2;
Output: the result of the expression (op1 operation op2).
--------------------------------------------------------------*/

#include <math.h>

char getMenuChoice(const char [], char, char);
double apply(char, double, double);

int main() {
	char name[15];
	int age;

	printf("Please enter your name: ");
	scanf("%s", &name);
	
	do {
		printf("Please enter your age: ");
		scanf("%i", &age);
		fseek(stdin, 0, SEEK_END);
	} while (age < 0 || age > 110);
	
	const char menu[] = { "\nPlease enter:\n"
		"\ta - to perform addition;\n"
		"\tb - to perform subtraction;\n"
		"\tc - to perform multiplication;\n"
		"\td - to perform division;\n"
		"\te - to perform exponentiation;\n"
		"\tf - to exit\n"
		"--> " };

	while (1) {
		char operation = getMenuChoice(menu, 'a', 'f');

		if (operation == 'f') { break; }

		double op1 = -9.2559631349317831e+61, op2 = -9.2559631349317831e+61, result;

		do {
			printf("Now enter your valid operands: ");
			scanf("%lf %lf", &op1, &op2);
			fseek(stdin, 0, SEEK_END);
		} while (op1 == -9.2559631349317831e+61 || op2 == -9.2559631349317831e+61);

		result = apply(operation, op1, op2);

		printf("\nThe result for %s:%i is %lf \n\n", name, age, result);
	}

	return 0;
}

char getMenuChoice(const char menu[], char firstChoice, char lastChoice) {
	char choice;
	
	do {
		printf("%s", menu);
		fseek(stdin, 0, SEEK_END);
		choice = getchar();
	} while (choice < firstChoice || choice > lastChoice);
	
	return choice;
}

double apply(char operation, double op1, double op2) {
	switch (operation) {
	case 'a':
		return op1 + op2;
		break;
	case 'b':
		return op1 - op2;
		break;
	case 'c':
		return op1 * op2;
		break;
	case 'd':
		return op1 / op2;
		break;
	case 'e':
		return pow(op1, op2);
		break;
	default: return 0;
	}
}
