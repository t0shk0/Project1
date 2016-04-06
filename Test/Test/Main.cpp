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