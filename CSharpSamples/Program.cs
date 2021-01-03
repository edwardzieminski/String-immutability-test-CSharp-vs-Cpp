using CSharpSamples;
using System;
using static System.Console;

Action<string, string> printComparison = (string string1, string string2) =>
{
    WriteLine($"{ string1.Ref() }: { string1 }");
    WriteLine($"{ string2.Ref() }: { string2 }");
    WriteLine($"    Values are equal: { Equals(string1, string2) }");
    WriteLine($"References are equal: { ReferenceEquals(string1, string2) }\n");
};

string sameString1 = "lalala";  // value: "lalala"
string sameString2 = "lalala";  // value: "lalala"

printComparison(sameString1, sameString2);
// RESULTS:
// values:      the same
// references:  the same

sameString1 = "lalalala";   // value: "lalalala"
sameString2 += "la";        // value: "lalalala"

printComparison(sameString1, sameString2);
// RESULTS:
// values:                                  the same
// references:                              different
// references vs first value assignment:    different for both variables

string stringToBeChanged = "lala";  // value: "lala"

// 1st argument value: "lala"
// 2nd argument value: "lalala"
printComparison(stringToBeChanged, stringToBeChanged + "la");
// RESULTS:
// values:      different
// references:  different

// 1st argument value: "lala"
// 2nd argument value: "lele"
printComparison(stringToBeChanged, stringToBeChanged.Replace('a', 'e'));
// RESULTS:
// values:                                  different
// references:                              different
// references vs first value assignment:    the same for the 1st argument, different for the 2nd

WriteLine($"stringToBeChanged value: { stringToBeChanged }");
// WORTH TO NOTE: stringToBeChanged value: "lala" - it was not modified by Replace() method.
// This method has created another string object without modifying the provided one, as in
// C# it is not possible to modify existing string object anyway (at least without Reflection).