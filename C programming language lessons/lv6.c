#include <stdio.h>
#include <math.h>

int main() {
    float x = 3.14;

    x = sqrt(x);
    x = pow(x, 2.0f);
    x = round(x);
    x = ceil(x);
    x = floor(x);
    x = abs(x);
    x = log(x);
    x = sin(x);
    x = cos(x);
    x = tan(x);
    x = exp(x);
    x = fmod(x, 2.0f);
    x = hypot(x, 4.0f);
    x = atan2(x, 1.0f);

    double radius = 0.0;
    double area = 0.0;
    const double PI = 3.141592653589793;
    double surface_area = 0.0;
    double volume = 0.0;

    printf("Enter the radius of the circle: \n");
    scanf("%lf", &radius);

    area = PI * pow(radius, 2.0);
    surface_area = 4 * PI * pow(radius, 2.0);
    volume = (4.0 / 3.0) * PI * pow(radius, 3.0);

    printf("Area: %.2lf\n", area);
    printf("Surface Area: %.2lf\n", surface_area);
    printf("Volume: %.2lf\n", volume);
    
    return 0;
}