#include <iostream>

using namespace std;

class Polynomial {
private:
    double* coefficients;
    int degree;

public:
    Polynomial() : coefficients(nullptr), degree(0) {}

    Polynomial(const double* coeffs, int deg) : degree(deg) {
        coefficients = new double[degree];
        for (int i = 0; i < degree; ++i) {
            coefficients[i] = coeffs[i];
        }
    }

    Polynomial add(const Polynomial& other) const {
        int resultDegree = (degree > other.degree) ? degree : other.degree;
        double* resultCoefficients = new double[resultDegree];

        for (int i = 0; i < resultDegree; ++i) {
            double coeff1 = (i < degree) ? coefficients[i] : 0.0;
            double coeff2 = (i < other.degree) ? other.coefficients[i] : 0.0;
            resultCoefficients[i] = coeff1 + coeff2;
        }

        return Polynomial(resultCoefficients, resultDegree);
    }

    Polynomial subtract(const Polynomial& other) const {
        int resultDegree = (degree > other.degree) ? degree : other.degree;
        double* resultCoefficients = new double[resultDegree];

        for (int i = 0; i < resultDegree; ++i) {
            double coeff1 = (i < degree) ? coefficients[i] : 0.0;
            double coeff2 = (i < other.degree) ? other.coefficients[i] : 0.0;
            resultCoefficients[i] = coeff1 - coeff2;
        }

        return Polynomial(resultCoefficients, resultDegree);
    }

    Polynomial multiply(const Polynomial& other) const {
        int resultDegree = degree + other.degree - 1;
        double* resultCoefficients = new double[resultDegree];

        for (int i = 0; i < resultDegree; ++i) {
            resultCoefficients[i] = 0.0;
            for (int j = 0; j <= i; ++j) {
                double coeff1 = (j < degree) ? coefficients[j] : 0.0;
                double coeff2 = (i - j < other.degree) ? other.coefficients[i - j] : 0.0;
                resultCoefficients[i] += coeff1 * coeff2;
            }
        }

        return Polynomial(resultCoefficients, resultDegree);
    }

    void printCoefficients() const {
        for (int i = 0; i < degree; ++i) {
            cout << coefficients[i] << " ";
        }
        cout << endl;
    }
};

int main() 
{
    setlocale(LC_ALL, "rus");
    double coeffs1[] = { 1, 2, 3 };  
    double coeffs2[] = { 4, 5, 6 };     

    Polynomial poly1(coeffs1, 3);
    Polynomial poly2(coeffs2, 3);

    Polynomial sum = poly1.add(poly2);
    Polynomial difference = poly1.subtract(poly2);
    Polynomial product = poly1.multiply(poly2);

    cout << "Сумма: ";
    sum.printCoefficients();

    cout << "Разность: ";
    difference.printCoefficients();

    cout << "Произведение: ";
    product.printCoefficients();

    return 0;
}