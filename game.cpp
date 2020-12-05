// Gallows game by Kindane
// Number of mistakes: 7
#include<iostream>
#include<string>
#include<cctype> // tolower()
#include<ctime> // time(0)

const int words_count = 20;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;

	srand(time(0));
	string words[] {"australia", "romania",
					"fingers", "flower",
					"enter", "queue",
					"password", "stickman",
					"author", "keyboard",
					"magnificent", "jocker",
					"backpack", "statusbar",
					"quarantine", "america",
					"cactus", "minecraft",
					"monitor", "programmer"
	};
	cout.width(15);
	cout << "Welcome to the Kindane's gallows game\n";
	cout << "press [p]lay or [q]uit\n";
	char choice;
	while (cin >> choice)
	{
		if (choice == 'p')
			break;
		if (choice == 'q')
			exit(EXIT_FAILURE);
		else
			cout << "You should enter p or q\n";
	}

	string word = words[rand()%words_count];
	string result(word.length(), '*');
	string already_typed = "";
	cout << "This word contain " << word.length() << " letters\n";

	char letter;
	int error_count = 0;
	while (result != word)
	{
		if (error_count >= 7)
		{
			cout << "Errors: " << error_count << "/7\n";
			cout << "You failed. My word is: " << word << endl;
			exit(EXIT_FAILURE);
		}
		cout << "Errors: " << error_count << "/7\n";
		cout << "Now your word is: " << result << endl;
		cout << "Please, enter letter: ";
		cin >> letter;
		letter = tolower(letter);
		if (already_typed.find(letter) == already_typed.npos)
		{
			if (word.find(letter) != word.npos)
			{
				already_typed += letter;
				int last_index = 0;
				while (true)
				{
					result[word.find(letter)] = letter;
					if (word.find(letter, last_index+1) != word.npos)
					{
						last_index = word.find(letter, last_index+1);
						result[last_index] = letter;
					}
					else
						break;
				}
			}
			else
			{
				cout << "This is not correct letter.\n";
				error_count++;
				already_typed += letter;
			}
		}
		else
		{
			cout << "You already typed this letter.\n";
			cout << "All typed letters: " << already_typed << endl;
		}
		
	}
	cout << "\nYou win!\n";
	cout << "Word is: " << word << endl;
}