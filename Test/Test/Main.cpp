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

*/

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