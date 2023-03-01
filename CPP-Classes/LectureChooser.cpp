#include <iostream>

void lecture1();

bool LectureChooser(int i) {
	switch (i) {
	case 1:
		lecture1();
		return 1;
	default:
		std::cout << "Invalid Entry";
		return 0;
	}
}