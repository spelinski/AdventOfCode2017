import std.algorithm;
import std.stdio;
import std.string;
import std.conv;
import std.utf;
bool isValidPhrase(string[] wordsInPhrase)
{
	foreach( index, word; wordsInPhrase ) {
		if(wordsInPhrase[index+1..$].canFind(word)){
			return false;
		}
	}
	return true;
}

unittest
{
	assert(isValidPhrase(["aa","bb","cc","dd","ee"]) == true);
	assert(isValidPhrase(["aa","bb","cc","dd","aa"]) == false);	
	assert(isValidPhrase(["aa","bb","cc","dd","aaa"]) == true);	
}

bool isValidPhraseAnagrams(string[] wordsInPhrase)
{
	foreach( index, word; wordsInPhrase ) {
		char [] c = word.dup;
		wordsInPhrase[index] = to!string(sort(c.byCodeUnit));
	}
	return isValidPhrase(wordsInPhrase);
}

unittest
{
	assert(isValidPhraseAnagrams(["abcde","fghij"]) == true);
	assert(isValidPhraseAnagrams(["abcde","xyz","ecdab"]) == false);
	assert(isValidPhraseAnagrams(["a","ab","abc","abd","abf","abj"]) == true);
}

void main(){
	int validCount = 0;
	int anaValidCount = 0;
	auto file = File("challengeOneInput.txt");
	auto range = file.byLine();
	foreach (char[] line; range) {
		string myLine = to!string(line);
		string[] myWords = myLine.split;
		if(isValidPhrase(myWords)) {
			validCount++;
		}
		if(isValidPhraseAnagrams(myWords)) {
			anaValidCount++;
		}
	}
	writeln(validCount);
	writeln("second Challenge");
	writeln(anaValidCount);
}
