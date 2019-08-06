#include "stdafx.h"
#include "AutomaticDiff.h"
#include "FwdTest.h"
#include "NewtonRaphson.h"


int _tmain(int argc, _TCHAR* argv[])
{

    double spot = 27248.94;
    double nominal= 100;
    double discFuerte = 1.001859032;
    double discDebil = 0.971376058;

    FwdTest miFwd{nominal,spot, discFuerte, discDebil};

    double strike;

    std::cout << "Ingrese Punto Inicio: ";
    std::cin >> strike;

    std::cout << "Valor Inicial: " << miFwd.Value(strike) << "\n";

    double target = 0;
    double start = strike;
    double tolerance = 0.000001;
   
    strike = NewtonRaphson<FwdTest, &FwdTest::Value, &FwdTest::Derivative>(target, start, tolerance, miFwd);

    std::cout << "Valor Strike: " << strike << "\n";
    
    std::cin >> target;

    getchar();

    return 0;
}
/*

int _tmain(int argc, _TCHAR* argv[])
{
    double y_;

    std::vector<double> x_{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    unsigned int n{ x_.size() };

    sum_cuadrado(n, x_, y_);
    std::cout << "y: " << y_ << "\n";

    // Metodo de las tangentes
    std::vector<double> x_tng(10);
    double y_tng;

    // Cada una de las derivadas parciales.
    for (unsigned int i = 0; i < n; i++)
    {
        x_tng.at(i) = 1;
        sum_cuadrado_tng(n, x_, y_, x_tng, y_tng);
        x_tng.at(i) = 0;
        std::cout << "y_tng: " << y_tng << "\n";
    }

    // Adjoints
    std::vector<double> x_adj(10);
    double y_adj{ 1.0 };

    sum_cuadrado_adj(n, x_, y_, x_adj, y_adj);

    for (unsigned int i = 0; i < n; i++)
    {
        std::cout << "y_adj: " << x_adj[i] << "\n";
    }

    // Adjoints
    mult_todas_adj(n, x_, y_, x_adj, y_adj);

    for (unsigned int i = 0; i < n; i++)
    {
        std::cout << "y_adj_mult: " << x_adj[i] << "\n";
    }


    getchar();

    return 0;
}

*/