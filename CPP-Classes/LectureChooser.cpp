#include <iostream>

void lecture1();
void lecture2();

bool LectureChooser(int i) {
	switch (i) {
	case 1:
		lecture1();
		return 1;
	case 2:
		lecture2();
		return 1;
	default:
		std::cout << "Invalid Entry";
		return 0;
	}
}
