// Copyright MJ 2024

#include <iostream>
#include <map>
#include <vector>

using std::cout, std::cin, std::endl;

const std::map<std::string, std::string> kSeasonNounMap = {
    {"spring", "STL guru"},
    {"summer", "C++ expert"},
    {"autumn", "coding beast"},
    {"winter", "software design hero"}};

const std::array<std::string, 3UL> kEndings = {
    "eats UB for breakfast", "finds errors quicker than the compiler",
    "is not afraid of C++ error messages"};

int get_adjective_index(const std::vector<std::string>& adjectives,
                        const std::string& name) {
  return name.length() % adjectives.size();
}

int get_ending_index(const std::string& name) {
  return name.length() % kEndings.size();
}

int main() {
  std::string name{}, season{};
  std::vector<std::string> adjectives;
  std::string adjective;
  int size_of_adjectives{}, size_of_endings{};
  std::string output_msg{};

  cout << "Welcome to the fortune teller program!" << endl;
  cout << "Please enter your name:" << endl;
  cin >> name;

  cout << "Please enter the time of year when you were born:" << endl;
  cout << "(pick from 'spring', 'summer', 'autumn', 'winter')" << endl;
  cin >> season;

  cout << "Please enter an adjective:" << endl;
  cin >> adjective;
  adjectives.push_back(adjective);

  cout << "Please enter another adjective:" << endl;
  cin >> adjective;
  adjectives.push_back(adjective);

  size_of_adjectives = adjectives.size();
  size_of_endings = kEndings.size();

  std::string final_adjective =
      adjectives.at(get_adjective_index(adjectives, name));

  std::string final_noun = kSeasonNounMap.at(season);
  std::string final_ending = kEndings.at(get_ending_index(name));

  cout << "\nHere is your description:" << endl;
  cout << name << ", "
       << "the " << final_adjective << " " << final_noun << " that "
       << final_ending << endl;

  return 0;
}
