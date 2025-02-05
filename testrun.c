#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define PI 3.1415

// Function Declarations
void arithmeticCalculator();
void scientificCalculator();
void reverseString(char *str);
char* convertToBinary(int decimalNum);
int convertToDecimal(const char* binaryNum);
void numberSystemConverter();
void quadraticRootsCalculator();
void pythagorasTheorem();
void historyManagement();
void saveHistory(const char *operation);

int main()
{
    int choice;

    while(true)
    {
        // Displaying the menu
        printf("\n\t\t\t\t\t\t\t***CALCULATOR***\n");
        printf("Menu:");
        printf("\n1. Arithmetic Calculator");
        printf("\n2. Scientific Calculator");
        printf("\n3. Number System Converter");
        printf("\n4. Quadratic Roots Calculator");
        printf("\n5. Pythagoras Theorem");
        printf("\n6. History Management");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            arithmeticCalculator();
            break;

        case 2:
            scientificCalculator();
            break;

        case 3:
            numberSystemConverter();
            break;

        case 4:
            quadraticRootsCalculator();
            break;

        case 5:
            pythagorasTheorem();
            break;

        case 6:
            historyManagement();
            break;

        case 7:
            printf("Exiting the program. Goodbye!\n");
            return 0;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

void arithmeticCalculator()
{
    int choice;

    do
    {
        float num1, num2, result;
        char op;

        printf("\n\nArithmetic Calculator\n");
        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);
        printf("Enter the operator (+, -, *, /): ");
        scanf(" %c", &op);

        switch (op)
        {
        case '+':
            result = num1 + num2;
            printf("Result: %.2f\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.2f\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.2f\n", result);
            break;
        case '/':
            if (num2 != 0)
            {
                result = num1 / num2;
                printf("Result: %.2f\n", result);
            }
            else
            {
                printf("Error! Division by zero.\n");
            }
            break;
        default:
            printf("Invalid operator entered.\n");
            continue;
        }

        char operation[100];
        sprintf(operation, "Arithmetic operation: %.2f %c %.2f = %.2f", num1, op, num2, result);
        saveHistory(operation);

        printf("\nDo you want to perform another operation? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);

    } while (choice != 0);
}

void scientificCalculator()
{
    int choice;

    while(true) {

        printf("\n\nScientific Calculator\n");
        printf("0. Go Back\n");
        printf("1. Square root\n");
        printf("2. Trigonometric functions\n");
        printf("3. Inverse Trigonometric functions\n");
        printf("4. Logarithmic functions\n");
        printf("5. Exponentiation\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        double num, result, exponent;
        char output[100];

        switch (choice)
        {
        case 0:
            return ;

        case 1:
            printf("Enter a number: ");
            scanf("%lf", &num);
            result = sqrt(num);
            sprintf(output, "Square root: %.2lf\n", result);
            break;

        case 2:
            printf("Enter angle (in degree): ");
            scanf("%lf", &num);
            double numInDegree = num * (PI / 180);
            sprintf(output, "Sin: %.2lf\nCos: %.2lf\nTan: %.2lf\n", sin(numInDegree), cos(numInDegree), tan(numInDegree));
            break;

        case 3:
            printf("Enter a number: ");
            scanf("%lf", &num);
            sprintf(output, "Arcsin: %.2lf\nArccos: %.2lf\nArctan: %.2lf\n", asin(num), acos(num), atan(num));
            break;

        case 4:
            printf("Enter a number: ");
            scanf("%lf", &num);
            sprintf(output, "Natural log: %.2lf\nBase-10 log: %.2lf\n", log(num), log10(num));
            break;

        case 5:
            printf("Enter base: ");
            scanf("%lf", &num);
            printf("Enter exponent: ");
            scanf("%lf", &exponent);
            result = pow(num, exponent);
            sprintf(output, "%.2lf raised to the power %.2lf is: %.2lf\n", num, exponent, result);
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            continue;
        }

        printf("%s", output);
        char operation[100];
        strcpy(operation, "Scientific operation: ");
        strcat(operation, output);
        saveHistory(operation);

    }
}

void numberSystemConverter()
{
    int choice;
    char binaryNum[100];
    int decimalNum;
    char hexNum[100];

    while(true) {

        printf("\n\nNumber System Converter\n");
        printf("0. Go Back\n");
        printf("1. Decimal to Binary\n");
        printf("2. Decimal to Hexadecimal\n");
        printf("3. Decimal to Octal\n");
        printf("4. Binary to Decimal\n");
        printf("5. Binary to Hexadecimal\n");
        printf("6. Binary to Octal\n");
        printf("7. Hexadecimal to Decimal\n");
        printf("8. Hexadecimal to Binary\n");
        printf("9. Hexadecimal to Octal\n");
        printf("10. Octal to Decimal\n");
        printf("11. Octal to Binary\n");
        printf("12. Octal to Hexadecimal\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        char output[100];

        switch (choice)
        {
        case 0:
            return ;
        case 1:
            // Decimal to Binary
            printf("Enter a decimal number: ");
            scanf("%d", &decimalNum);
            sprintf(output, "Decimal %d in binary is: %s\n", decimalNum, convertToBinary(decimalNum));
            break;
        case 2:
            // Decimal to Hexadecimal
            printf("Enter a decimal number: ");
            scanf("%d", &decimalNum);
            sprintf(hexNum, "%X", decimalNum);
            sprintf(output, "Decimal %d in hexadecimal is: %s\n", decimalNum, hexNum);
            break;
        case 3:
            // Decimal to Octal
            printf("Enter a decimal number: ");
            scanf("%d", &decimalNum);
            sprintf(output, "Decimal %d in octal is: %o\n", decimalNum, decimalNum);
            break;
        case 4:
            // Binary to Decimal
            printf("Enter a binary number: ");
            scanf("%s", binaryNum);
            sprintf(output, "Binary %s in decimal is: %d\n", binaryNum, convertToDecimal(binaryNum));
            break;
        case 5:
            // Binary to Hexadecimal
            printf("Enter a binary number: ");
            scanf("%s", binaryNum);
            sprintf(hexNum, "%X", convertToDecimal(binaryNum)); // Convert binary to decimal and then decimal to hexadecimal
            sprintf(output, "Binary %s in hexadecimal is: %s\n", binaryNum, hexNum);
            break;
        case 6:
            // Binary to Octal
            printf("Enter a binary number: ");
            scanf("%s", binaryNum);
            sprintf(output, "Binary %s in octal is: %o\n", binaryNum, convertToDecimal(binaryNum)); // Convert binary to decimal and then decimal to octal
            break;
        case 7:
            // Hexadecimal to Decimal
            printf("Enter a hexadecimal number: ");
            scanf("%s", hexNum);
            sprintf(output, "Hexadecimal %s in decimal is: %d\n", hexNum, strtol(hexNum, NULL, 16));
            break;
        case 8:
            // Hexadecimal to Binary
            printf("Enter a hexadecimal number: ");
            scanf("%s", hexNum);
            sprintf(output, "Hexadecimal %s in binary is: %s\n", hexNum, convertToBinary(strtol(hexNum, NULL, 16))); // Convert hexadecimal to decimal and then decimal to binary
            break;
        case 9:
            // Hexadecimal to Octal
            printf("Enter a hexadecimal number: ");
            scanf("%s", hexNum);
            sprintf(output, "Hexadecimal %s in octal is: %o\n", hexNum, strtol(hexNum, NULL, 16)); // Convert hexadecimal to decimal and then decimal to octal
            break;
        case 10:
            // Octal to Decimal
            printf("Enter an octal number: ");
            scanf("%o", &decimalNum);
            sprintf(output, "Octal %o in decimal is: %d\n", decimalNum, decimalNum);
            break;
        case 11:
            // Octal to Binary
            printf("Enter an octal number: ");
            scanf("%o", &decimalNum);
            sprintf(output, "Octal %o in binary is: %s\n", decimalNum, convertToBinary(decimalNum));
            break;
        case 12:
            // Octal to Hexadecimal
            printf("Enter an octal number: ");
            scanf("%o", &decimalNum);
            sprintf(hexNum, "%X", decimalNum);
            sprintf(output, "Octal %o in hexadecimal is: %s\n", decimalNum, hexNum);
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            continue;
        }

        printf("%s", output);
        char operation[100];
        sprintf(operation, "Number System Conversion: Choice %d", choice);
        saveHistory(operation);

    }
}


void reverseString(char *str) {
    int length = strlen(str);
    int start = 0, end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char* convertToBinary(int decimalNum) {
    static char binaryNum[100];
    int index = 0;

    if (decimalNum == 0) {
        binaryNum[index++] = '0';
    }
    else {
        while (decimalNum > 0) {
            binaryNum[index++] = (decimalNum % 2) + '0';
            decimalNum /= 2;
        }
    }

    binaryNum[index] = '\0';
    reverseString(binaryNum); // Reverse the string to get the correct binary representation

    return binaryNum;
}

int convertToDecimal(const char* binaryNum) {
    int decimalNum = 0;
    int length = strlen(binaryNum);

    for (int i = 0; i < length; i++) {
        if (binaryNum[i] < '0' || binaryNum[i] > '1') {
            // Check for invalid characters in the binary representation
            printf("Invalid binary number!\n");
            return -1; // Return -1 for an invalid binary number
        }

        // Multiply the decimal number by 2 and add the current binary digit (0 or 1)
        decimalNum = decimalNum * 2 + (binaryNum[i] - '0');
    }

    return decimalNum;
}

void quadraticRootsCalculator() {

    while (true) {
        float a, b, c;
        float discriminant, root1, root2;
        char output[100];

        printf("\n\nQuadratic Roots Converter\n");
        printf("Enter the coefficients of the quadratic equation (a, b, c): ");

        // Input validation loop for coefficients
        while (scanf("%f %f %f", &a, &b, &c) != 3 || (a == 0 && b == 0)) {
            printf("Invalid input. Please enter valid coefficients (a, b, c): ");
            while (getchar() != '\n'); // Clear input buffer
        }

        printf("The quadratic equation is: %.2fx^2 + %.2fx + %.2f = 0\n", a, b, c);

        discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            root1 = (-b + sqrt(discriminant)) / (2 * a);
            root2 = (-b - sqrt(discriminant)) / (2 * a);
            sprintf(output, "Root 1 = %.2f and Root 2 = %.2f\n", root1, root2);
        } else if (discriminant == 0) {
            root1 = root2 = -b / (2 * a);
            sprintf(output, "Root 1 = Root 2 = %.2f\n", root1);
        } else {
            float realPart = -b / (2 * a);
            float imaginaryPart = sqrt(-discriminant) / (2 * a);
            sprintf(output, "Roots are complex: %.2f + %.2fi and %.2f - %.2fi\n", realPart, imaginaryPart, realPart, imaginaryPart);
        }

        printf("%s\n", output);

        char operation[100];
        sprintf(operation, "Quadratic roots calculation for equation: %.2fx^2 + %.2fx + %.2f = 0 -> %s", a, b, c, output);
        saveHistory(operation);

        int continueCalculation = 1;
        printf("Do you want to calculate roots for another equation? (1 for Yes / 0 for No): ");
        scanf("%d", &continueCalculation);
        if(continueCalculation == 0) {
            break;
        }
    }
}

void pythagorasTheorem() {

    while (true) {
        float side1, side2, hypotenuse;

        printf("\n\nPythagoras Theorem Converter\n");
        printf("Enter length of side 1: ");
        while (scanf("%f", &side1) != 1 || side1 <= 0) {
            printf("Invalid input. Please enter a positive number for side 1: ");
            while (getchar() != '\n'); // Clear input buffer
        }

        printf("Enter length of side 2: ");
        while (scanf("%f", &side2) != 1 || side2 <= 0) {
            printf("Invalid input. Please enter a positive number for side 2: ");
            while (getchar() != '\n'); // Clear input buffer
        }

        hypotenuse = sqrt(side1 * side1 + side2 * side2);
        printf("Hypotenuse = %.2f\n", hypotenuse);

        char operation[100];
        sprintf(operation, "Pythagoras theorem calculation for sides: %.2f, %.2f -> Hypotenuse: %.2f", side1, side2, hypotenuse);
        saveHistory(operation);

        int continueCalculation = 1;
        printf("Do you want to calculate for another set of sides? (1 for Yes / 0 for No): ");
        scanf("%d", &continueCalculation);
        if (continueCalculation == 0) {
            break;
        }
    }
}

void saveHistory(const char *operation)
{
    FILE *file = fopen("history.txt", "a");
    if (file != NULL)
    {
        fprintf(file, "%s\n", operation);
        fclose(file);
    }
    else
    {
        printf("Error opening file for saving history.\n");
    }
}

void historyManagement() {
    int choice;

    while (true) {
        printf("\nHistory Management Menu:");
        printf("\n0. Go Back");
        printf("\n1. View entire history");
        printf("\n2. Clear entire history");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                return ;
            case 1:
                printf("\nViewing entire history:\n");
                FILE *file = fopen("history.txt", "r");
                if (file != NULL) {
                    char operation[500];
                    while (fgets(operation, sizeof(operation), file) != NULL) {
                        printf("%s", operation);
                    }
                    fclose(file);
                } else {
                    printf("No history found.\n");
                }
                break;
            case 2:
                remove("history.txt");
                printf("History cleared successfully.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}
