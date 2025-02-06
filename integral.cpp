#include<iostream>
#include<math.h>
using namespace std;
// تابعی برای نمایش انتگرال چندجمله‌ای
void displayIntegral(double coeff[], int degree) {
    cout << "The integral of the polynomial is: ";
    for (int i = degree; i >= 0; i--) {
        if (coeff[i] != 0) { // فقط ضرایب غیرصفر را نمایش می‌دهیم
            if (i != degree) cout << " + "; // علامت + بین جملات
            double newCoeff = coeff[i] / (i + 1); // ضریب جدید بعد از انتگرال
            cout << newCoeff;
            if (i > 0) cout << "x";
            if (i >= 1) cout << "^" << (i + 1);
        }
    }
    cout << endl; // بدون ثابت C
}
// تابعی برای محاسبه‌ی مقدار چندجمله‌ای در نقطه‌ی x
double polynomial(double x, double coeff[], int degree) {
    double result = 0.0;
    for (int i = 0; i <= degree; i++) { // حلقه از ۰ شروع می‌شود
        result += coeff[i] * pow(x, i);
    }
    return result;
}

// تابعی برای محاسبه‌ی انتگرال به روش مستطیلی
double integral(double a, double b, double coeff[], int degree) {
    int n = 100000;
    double h = (b - a) / n; // عرض هر مستطیل
    double sum = 0.0; // جمع مساحت مستطیل‌ها

    for (int i = 0; i < n; i++) {
        double x = a + i * h; // نقطه‌ی شروع هر مستطیل
        sum += polynomial(x, coeff, degree) * h; // مساحت مستطیل را به جمع اضافه کنید
    }
    return sum; // مقدار انتگرال
}

// تابعی برای نمایش چندجمله‌ای به ساده‌ترین شکل
void displaypolynomial(double coeff[], int degree) {
    bool firstterm = true; // برای مدیریت علامت + بین جملات
    cout << "The polynomial is: ";
    for (int i = degree; i >= 0; i--) {
        if (coeff[i] != 0) { // فقط ضرایب غیرصفر را نمایش می‌دهیم
            if (!firstterm) {
                cout << " + ";
            }
            if (i == 0) {
                cout << coeff[i]; // جمله‌ی ثابت
            } else if (i == 1) {
                cout << coeff[i] << "x"; // جمله‌ی x
            } else {
                cout << coeff[i] << "x^" << i; // جمله‌های با توان بالاتر
            }
            firstterm = false;
        }
    }
    cout << endl;
}
int main() {
    double a, b;
    int degree;

    // دریافت بازه‌ی انتگرال‌گیری و بررسی محدوده
    bool validinput = false;
    while (!validinput) {
        cout << "Enter the lower bound (a) between -1 and 5: ";
        cin >> a;
        cout << "Enter the upper bound (b) between -1 and 5: ";
        cin >> b;

        // بررسی محدوده‌ی a و b
        if (a < -1 || a > 5 || b < -1 || b > 5) {
            cout << "Error: Limits must be between -1 and 5." << endl;
        } else if (b <= a) {
            cout << "Error: Upper limit (b) must be greater than lower limit (a)." << endl;
        } else {
            validinput = true; // ورودی معتبر است
        }
    }

    // دریافت درجه‌ی چندجمله‌ای
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    // بررسی درجه‌ی چندجمله‌ای
    if (degree < 0) {
        cout << "Error: The degree must be positive." << endl;
        return 1; // پایان برنامه با خطا
    }

    // دریافت ضرایب چندجمله‌ای
    double coeff[degree + 1]; // آرایه برای ذخیره‌ی ضرایب
    cout << "Enter the coefficients of the polynomial (from x^0 to x^" << degree << "):" << endl;
    for (int i = 0; i <= degree; i++) {
        cout << "Coefficient of x^" << i << ": ";
        cin >> coeff[i];
    }

    // نمایش چندجمله‌ای 
    displaypolynomial(coeff, degree);
    //نمایش انتگرال  چند جمله ای 
    displayIntegral(coeff , degree) ;
    // محاسبه‌ی انتگرال و نمایش نتیجه
    double result = integral(a, b, coeff, degree);
    cout << "The integral of the polynomial from " << a << " to " << b << " is: " << result << endl;

    return 0;
}