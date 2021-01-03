#include <iostream>
#include <string>

void printComparison(const std::string &string1, const std::string &string2);
std::string ReplaceAll(std::string str, const std::string& from, const std::string& to);

int main()
{
    std::string sameString1 = "lalala"; // value: "lalala"
    std::string sameString2 = "lalala"; // value: "lalala"

    printComparison(sameString1, sameString2);
    // RESULTS:
    // values:      the same
    // references:  different

    sameString1 = "lalalala";   // value: "lalalala"
    sameString2 += "la";        // value: "lalalala"

    printComparison(sameString1, sameString2);
    // RESULTS:
    // values:                                  the same
    // references:                              different
    // references vs first value assignment:    the same for both variables

    std::string stringToBeChanged = "lala";  // value: "lala"

    // 1st argument value: "lala"
    // 2nd argument value: "lalala"
    printComparison(stringToBeChanged, (stringToBeChanged + "la"));
    // RESULTS:
    // values:      different
    // references:  different

    // 1st argument value: "lala"
    // 2nd argument value: "lele"
    printComparison(stringToBeChanged, (ReplaceAll(stringToBeChanged, "a", "e")));
    // RESULTS:
    // values:                                  different
    // references:                              different
    // references vs first value assignment:    the same for the 1st argument, different for the 2nd

    std::cout << "stringToBeChanged value: " << stringToBeChanged;
    // WORTH TO NOTE: stringToBeChanged value: "lala" - it was not modified by ReplaceAll() function.
    // This method has created another string object without modifying the provided one, but in
    // contrast to C# in C++ it is possible to do this - if you modify the function so it takes
    // reference to the object instead of its value - then it will modify the value in the existing
    // variable.
}

void printComparison(const std::string &string1, const std::string &string2) {
    std::cout << &string1 << ": " << string1 << "\n"
        << &string2 << ": " << string2 << "\n"
        << "    Values are equal: " << (string1 == string2) << "\n"
        << "References are equal: " << (&string1 == &string2) << "\n\n";
}

// function taken from: https://stackoverflow.com/questions/2896600/how-to-replace-all-occurrences-of-a-character-in-string
std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}