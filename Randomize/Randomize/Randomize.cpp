#include <iostream>
#include <random>
#include <ctime>

enum class Result {
	GUESS,
	LESS,
	MORE
};

int getRandomNumber(int min, int max) {
	int r = ((rand() % max) + min);
	return r;
}

void printResult(Result result) {
	switch (result) {
	case Result::GUESS:
		std::cout << "You guessed" << std::endl;
		break;
	case Result::LESS:
		std::cout << "Less" << std::endl;
		break;
	case Result::MORE:
		std::cout << "More" << std::endl;
		break;
	default:
		std::cout << "Error" << std::endl;
		break;
	}
}

bool compareResult(int generalResult, int getResult, bool flag) {
	int count{};
	do {
		std::cin >> getResult;

	if (generalResult == getResult) {
		printResult(Result::GUESS);
		flag = false;
	}
	else if (generalResult > getResult) {
		printResult(Result::MORE);
	}
	else {
		printResult(Result::LESS);
	}
	++count;
}
while (flag && (count < 7));

return flag;
}

bool playAgain() {
	char answer{};
	std::cout << "If you want to play again, write: y, vice versa: n ::" << std::endl;
	do {
		std::cout << "Enter the number: " << std::endl;
		std::cin >> answer;
	} while (answer != 'n' && answer != 'y');

	return (answer == 'y');
}

int main()
{
	int getResult{};
	bool flag = true;

	do {
		std::cout << "It's a game. Write the number!" << std::endl;
		srand((int)time(0));
		int generalResult = getRandomNumber(1, 100);

		flag = compareResult(generalResult, getResult, flag);

		if (flag) {
			std::cout << "You lost. Correct answer: " << generalResult << std::endl;
		}

	} while (playAgain());

}

