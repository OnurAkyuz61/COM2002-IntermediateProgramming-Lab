#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

// Structure definitions for each geometric figure
typedef struct {
    double radius;
    double area;
    double circumference;
} Circle;

typedef struct {
    double width;
    double height;
    double area;
    double perimeter;
} Rectangle;

typedef struct {
    double side;
    double area;
    double perimeter;
} Square;

// Union to hold any of the geometric figures
typedef union {
    Circle circle;
    Rectangle rectangle;
    Square square;
} GeometricFigure;

// Structure containing both the union and type indicator
typedef struct {
    GeometricFigure figure;
    char type;  // 'C' for circle, 'R' for rectangle, 'S' for square
} Figure;

// Function prototypes
void calculateCircle(Circle *circle);
void calculateRectangle(Rectangle *rectangle);
void calculateSquare(Square *square);
void printFigure(Figure *fig);

int main() {
    Figure fig;
    char choice;
    double input;

    printf("Area and Perimeter Computation Program\n\n");

    do {
        printf("Enter a letter to indicate the object shape or Q to quit.\n");
        printf("C(circle), R(rectangle) or S(square)> ");
        scanf(" %c", &choice);
        choice = toupper(choice);

        if (choice == 'Q') break;

        switch (choice) {
            case 'C':
                do {
                    printf("Enter radius> ");
                    scanf("%lf", &input);
                    if (input <= 0)
                        printf("    The value must be greater than ZERO.\n");
                } while (input <= 0);

                fig.type = 'C';
                fig.figure.circle.radius = input;
                calculateCircle(&fig.figure.circle);
                break;

            case 'R':
                do {
                    printf("Enter height> ");
                    scanf("%lf", &input);
                    if (input <= 0)
                        printf("    The value must be greater than ZERO.\n");
                } while (input <= 0);
                fig.figure.rectangle.height = input;

                do {
                    printf("Enter width> ");
                    scanf("%lf", &input);
                    if (input <= 0 || input == fig.figure.rectangle.height)
                        printf("    The value must be greater than ZERO or Width and height must not equal to each other.\n");
                } while (input <= 0 || input == fig.figure.rectangle.height);
                fig.figure.rectangle.width = input;

                fig.type = 'R';
                calculateRectangle(&fig.figure.rectangle);
                break;

            case 'S':
                do {
                    printf("Enter length of a side> ");
                    scanf("%lf", &input);
                    if (input <= 0)
                        printf("    The value must be greater than ZERO.\n");
                } while (input <= 0);

                fig.type = 'S';
                fig.figure.square.side = input;
                calculateSquare(&fig.figure.square);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                continue;
        }

        printFigure(&fig);

    } while (1);

    return 0;
}

void calculateCircle(Circle *circle) {
    circle->area = M_PI * circle->radius * circle->radius;
    circle->circumference = 2 * M_PI * circle->radius;
}

void calculateRectangle(Rectangle *rectangle) {
    rectangle->area = rectangle->width * rectangle->height;
    rectangle->perimeter = 2 * (rectangle->width + rectangle->height);
}

void calculateSquare(Square *square) {
    square->area = square->side * square->side;
    square->perimeter = 4 * square->side;
}

void printFigure(Figure *fig) {
    printf("Object is a ");
    switch (fig->type) {
        case 'C':
            printf("circle whose members:\n");
            printf("    Area:%.2f\n", fig->figure.circle.area);
            printf("    Circumference:%.2f\n", fig->figure.circle.circumference);
            printf("    Radius:%.2f\n", fig->figure.circle.radius);
            break;

        case 'R':
            printf("rectangle whose members:\n");
            printf("    Area:%.2f\n", fig->figure.rectangle.area);
            printf("    Perimeter:%.2f\n", fig->figure.rectangle.perimeter);
            printf("    Width:%.2f\n", fig->figure.rectangle.width);
            printf("    Height:%.2f\n", fig->figure.rectangle.height);
            break;

        case 'S':
            printf("square whose members:\n");
            printf("    Area:%.2f\n", fig->figure.square.area);
            printf("    Perimeter:%.2f\n", fig->figure.square.perimeter);
            printf("    Side:%.2f\n", fig->figure.square.side);
            break;
    }
    printf("\n");
}