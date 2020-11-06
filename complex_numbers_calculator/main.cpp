//
//  main.cpp
//  complex_numbers_calculator
//
//  Created on 17/01/2020.
//  Copyright © 2020 All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

// already works
//#define _USE_MATH_DEFINES
//#define M_PI       3.14159265358979323846

class ComplexNumbersCalculator{
    
private:
    
    struct Numb{
        double Real;
        double Imaginary;
    };
    
    Numb a;
    
    int start(){
        int answer(0);
        
        do{
            cout << "(1) Sum" << endl;
            cout << "(2) Substract" << endl;
            cout << "(3) Multiply" << endl;
            cout << "(4) Devide" << endl;
            cout << "(5) Power" << endl;
            cout << "(6) Root" << endl;
            cout << "(7) Module" << endl;
            cout << "Answer: ";
            cin >> answer;
            
            if (answer != 1 && answer != 2 && answer != 3 && answer != 4 && answer != 5 && answer != 6 && answer != 7 && answer != 11) cout << endl << "Your input was incorrect. Try again." << endl;
            
        } while (answer != 1 && answer != 2 && answer != 3 && answer != 4 && answer != 5 && answer != 6 && answer != 7 && answer != 11);
        
        return answer;
    }
    
    void printNumb(){
        cout << endl << "Classic result: " << endl;
        
        //if (a.Real == -0) a.Real = 0;
        //if (a.Imaginary == -0) a.Imaginary = 0;
        
        cout << "Real ~> " << a.Real << endl;
        cout << "Imaginary ~> " << a.Imaginary << endl;
    }
    
    void technicalSum(Numb b){
        a.Real += b.Real;
        a.Imaginary += b.Imaginary;
    }
    
    void technicalMultiply(Numb b){
        
        double buf(a.Real);
        a.Real = (a.Real * b.Real - a.Imaginary * b.Imaginary);
        a.Imaginary = (buf * b.Imaginary + a.Imaginary * b.Real);
    }
    
    double modul(Numb b){
        return (sqrt(b.Real * b.Real + b.Imaginary * b.Imaginary));
    }

    void technicalPower(int pow){
        
        if (a.Imaginary == 0 && a.Real == 0){
            cout << "Not defindes for 0 && 0" << endl;
            return;
        }
        // !
        double rd (exp(pow * log(modul(a))));
        double angle (pow * atan2(a.Imaginary, a.Real));
        
        
        a.Real =  abs(sin(angle)) == 1 ? 0 : rd * cosl(angle);
        a.Imaginary = abs(cos(angle)) == 1 ? 0 : rd * sinl(angle);

        
        cout << endl << "Trigonometry result ~> " << rd << "(cos(" << angle * 180 / M_PI << ") + (sin(" << angle * 180 / M_PI << ")i)" << endl;
        
        printNumb();
    }
    
    void technicalRoot(double r){
        double rd (exp(1/r * log(modul(a))));
        double angle (1/r * atan2(a.Imaginary, a.Real));
        
        cout << endl << "Trigonometry & classic results:" << endl << endl;
        
        for (int k = 0; k < r; k++){
            cout << "(" << k + 1 << ") " << rd << "(cos(" << (angle + (2 * M_PI * k) / r) * 180 / M_PI << ") + (sin(" << (angle + (2 * M_PI * k) / r) * 180 / M_PI << ")i)" << endl;
            
            double f = abs(sin((angle + ( 2 * M_PI * k) / r))) == 1 ? 0 : rd * cos((angle + ( 2 * M_PI * k) / r));
            double g = abs(cos((angle + ( 2 * M_PI * k) / r))) == 1 ? 0 : rd * sin((angle + (2 * M_PI * k) / r));
            
            cout << "(" << k + 1 << ") " << f << " + (" << g << ")i" << endl << endl;
        }
    }
    
    Numb negativeValue(Numb b){
        b.Real *= -1; b.Imaginary *= -1;
        return b;
    }
    
    Numb reverseValue(Numb b){
        
        double buf(b.Real);
        b.Real = (b.Real / (b.Real * b.Real + b.Imaginary * b.Imaginary));
        b.Imaginary = -(b.Imaginary) / ((buf * buf + b.Imaginary * b.Imaginary));
        return b;
    }
    
    ComplexNumbersCalculator& sum(){
        cout << endl << "{Sum}" << endl;
        cout << "Input the second numb." << endl;
        Numb b;
        cout << "Real part: "; cin >> b.Real;
        cout << "Imaginary part: "; cin >> b.Imaginary;
        
        technicalSum(b);

        printNumb();
        
        return *this;
    }
    
    ComplexNumbersCalculator& substract(){
        cout << endl << "{Substract}" << endl;
        cout << "Input the second numb." << endl;
        Numb b;
        cout << "Real part: "; cin >> b.Real;
        cout << "Imaginary part: "; cin >> b.Imaginary;
        
        technicalSum(negativeValue(b));
        
        printNumb();
        
        return *this;
    }
    
    ComplexNumbersCalculator& multiply(){
        cout << endl << "{Multiply}" << endl;
        cout << "Input the second numb." << endl;
        Numb b;
        cout << "Real part: "; cin >> b.Real;
        cout << "Imaginary part: "; cin >> b.Imaginary;
        
        technicalMultiply(b);
        
        printNumb();
        
        return *this;
    }
    
    ComplexNumbersCalculator& devide(){
        cout << endl << "{Devide}" << endl;
        cout << "Input the second numb." << endl;
        Numb b;
        cout << "Real part: "; cin >> b.Real;
        cout << "Imaginary part: "; cin >> b.Imaginary;
        
        technicalMultiply(reverseValue(b));
        
        printNumb();
        
        return *this;
    }
    
    ComplexNumbersCalculator& power(){
        cout << endl << "{Power}" << endl;
        int p(0);
        cout << "Input the power: "; cin >> p;
        
        technicalPower(p);
        
        return *this;
    }
    
    ComplexNumbersCalculator& root(){
        cout << endl << "{Root}" << endl;
        double p(0);
        cout << "Input the root degree: "; cin >> p;
        
        technicalRoot(p);
        
        return *this;
    }
    
    ComplexNumbersCalculator& module(){
        cout << endl << "{Module}" << endl;
        cout << "Result ~> " << modul(a) << endl;
        a.Real = modul(a);
        a.Imaginary = 0;
        
        printNumb();
        
        return *this;
    }
     
public:
    
    ComplexNumbersCalculator(){
        
        cout << "Input the number." << endl;
        cout << "Real part: "; cin >> a.Real;
        cout << "Imaginary part: "; cin >> a.Imaginary; cout << endl;
        
        cout << "Complex numbers calculator." << endl << endl;
        
        while (true){
            switch (start()){
                case 1:
                    sum(); cout << endl;
                    break;
                case 2:
                    substract(); cout << endl;
                    break;
                case 3:
                    multiply(); cout << endl;
                    break;
                case 4:
                    devide(); cout << endl;
                    break;
                case 5:
                    power(); cout << endl;
                    break;
                case 6:
                    root(); //cout << endl;
                    break;
                case 7:
                    module(); cout << endl;
                    break;
                case 11:
                    return;
            };
        }
    }
    
};

int main(int argc, const char * argv[]) {
    ComplexNumbersCalculator na = ComplexNumbersCalculator();
    return 0;
}
