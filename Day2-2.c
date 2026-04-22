#include <stdio.h>
#define PI 3.1416

int main() {
    float radius, area, circumference;

    
    printf("Enter radius of circle: ");
    scanf("%f", &radius);

    
    area = PI * radius * radius;
    circumference = 2 * PI * radius;


    printf("Area of circle = %.2f\n", area);
    printf("Circumference of circle = %.2f\n", circumference);

    return 0;
}
