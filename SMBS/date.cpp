#include "date.h"
#include <iostream>
#include <string>




string Date::Show() {
	return (to_string(day) + "-" + to_string(month) + "-" + to_string(year));
}
