#include <iostream>

bool LabChooser(int i);
bool LectureChooser(int i);

int main() {

	int selectorSelector;
	std::cout << "To access Lectures press 0 to access Labs press 1: ";
	std::cin >> selectorSelector;
	
	if (selectorSelector == 0) {
		int selection;
		std::cout << "Which Lecture do you want to run?: ";
		std::cin >> selection;
		LectureChooser(selection);
		return 1;
	}
	if (selectorSelector == 1) {
		int selection;
		std::cout << "Which Lab do you want to run?: ";
		std::cin >> selection;
		LabChooser(selection);
		return 1;
	}
	else {
		std::cout << "Invalid Entry";
		return 0;
	}
}