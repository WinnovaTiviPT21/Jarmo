#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include "date.h"

class Employee
{ public:
    std::string etunimi;
    std::string sukunimi;
    std::string sukupuoli;

    Date birthDate;
    Date hiringDate;
};



#endif // EMPLOYEE_H
