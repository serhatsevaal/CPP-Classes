#include <iostream>

void lab1();
void lab2();

bool LabChooser(int i) {
	switch(i){
	case 1:
		lab1();
		return 1;
	
	case 2:
		lab2();
		return 1;
	default:
		std::cout << "Invalid Entry";
		return 0;
	}
}