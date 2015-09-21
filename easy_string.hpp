/*
Copyright (c) 2015, Patrick Louis <patrick at iotek.org>
All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    1.  The author is informed of the use of his/her code. The author does not have to consent to the use; however he/she must be informed.
    2.  If the author wishes to know when his/her code is being used, it the duty of the author to provide a current email address at the top of his/her code, above or included in the copyright statement.
    3.  The author can opt out of being contacted, by not providing a form of contact in the copyright statement.
    4.  If any portion of the author’s code is used, credit must be given.
            a. For example, if the author’s code is being modified and/or redistributed in the form of a closed-source binary program, then the end user must still be made somehow aware that the author’s work has contributed to that program.
            b. If the code is being modified and/or redistributed in the form of code to be compiled, then the author’s name in the copyright statement is sufficient.
    5.  The following copyright statement must be included at the beginning of the code, regardless of binary form or source code form.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Except as contained in this notice, the name of a copyright holder shall not
be used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization of the copyright holder.
*/

#ifndef EASY_STRING_HPP_INCLUDED
#define EASY_STRING_HPP_INCLUDED


#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <string.h>
#include <regex> //use that in a smart way ψ(｀∇´)ψ

namespace easy_string {
	/*
	 *
	 * nice sexy body here
	 *
	 */

	std::string remove_html_comments(std::string html_body);
	std::string to_lower(std::string s);
	std::string lc(std::string s) { return to_lower(s); }
	std::string to_upper(std::string s);
	std::string uc(std::string s) { return to_upper(s); }
	bool is_lower(std::string s);
	bool is_upper(std::string s);
	bool is_space(std::string s);
	//check if another string is in the string
	bool is_word_in(std::string sentence, std::string word);
	//replace one string inside another
	std::string replace(std::string s, std::string from, std::string to);
	//replace all occurence of a string inside another
	std::string replace_all(std::string s, std::string from, std::string to);
	//replace all occurence of a string inside another recursively, against injection
	std::string replace_all_recursive(std::string s, std::string from, std::string to) {
		while(is_word_in(s, from)) {
			s = replace_all(s, from, to);
		}
		return s;
	}
	std::string int_to_string(int an_integer);
	int string_to_int(std::string s);
	int to_i(std::string s) { return string_to_int(s); }
	std::string float_to_string(float a_float);
	float string_to_float(std::string s);
	float to_f(std::string s) { return string_to_float(s); }
	long string_to_long(std::string s);
	std::string long_to_string(long a_long);
	//need to check all the character that needs to be stripped \t \n \r
	std::string strip(std::string s);
	std::string chomp(std::string s){
		return strip(s);
	};
	//Removes line ending characters from a string or array of strings.
	std::string chomp(std::string s);
	//(start from the end) need to check all the character that needs to be stripped \t \n \r
	std::string rstrip(std::string s);
	std::string lstrip(std::string s);
	//check if a string is a valid hexadecimal
	bool is_hex(std::string s);
	//split by a string and returns a vector, the string is not included in what is returned
	std::vector<std::string> split(std::string s, std::string separator);
	//split at \n
	std::vector<std::string> split_lines(std::string s) {
		return split(s, "\n");
	}
	bool starts_with(std::string s, std::string start);
	bool ends_with(std::string s, std::string end);
	bool is_number(std::string s);
	//remove all space and separator characters in a string
	std::string remove_space(std::string s);
	//only remove endlines
	std::string remove_endline(std::string s);
	//remove all occurence of a string inside another
	std::string remove_occurence(std::string s, std::string word);
	//remove all occurence of a string inside another recursively (safe)
	std::string remove_occurence_recursive(std::string s, std::string word) {
		while(is_word_in(s, word)){
			s = remove_occurence(s, word);
		}
		return s;
	}
	//keep only alphanumerics
	std::string remove_special_chars(std::string s);
	//already there but just listing
	std::string substring(std::string s, int start, int end);
	//only first characters of every word capitalized
	std::string capitalize(std::string s);
	//Return S centered in a string of length width. Padding is done using the specified fill character (default is a space)
	std::string center(std::string s, int width, int padding);
	//return the number of non-overlapping occurence of a substring inside a string
	int count(std::string s, int start,int end);
	/* TODO: binary foos
	decode
	encode
	*/
	//Return a copy of S where all tab characters are expanded using spaces.If tabsize is not given, a tab size of 8 characters is assumed.
	std::string expand_tabs(std::string s, int tabsize);
	//also already implemented
	std::string find(std::string s, std::string to_find, int start);
	//search for the first occurence of a separator and return 2 strings
	std::vector<std::string> partition(std::string s, std::string separator);
	//same but start searching from the right
	std::vector<std::string> rpartition(std::string s, std::string separator);
	//change upper by lower and lower by upper
	std::string swap_case(std::string s);
	//transliteration
	std::string translate(std::string s, std::string from, std::string to);
	std::string translate(std::string s, std::vector<char> from, std::vector<char> to);
	std::string tr(std::string s, std::string from, std::string to);
	std::string tr(std::string s, std::vector<char> from, std::vector<char> to);
	//numeral padding with 0 on the left so it fits a width
	std::string zfill(std::string s, int padding);
	//This function returns the position of the first occurance of the specified SEARCH string. If POSITION is specified, the occurance at or after the position is returned. The value -1 is returned if the SEARCH string is not found.
	int index(std::string s, std::string to_find, int start_pos);
	//STRING,SEARCH,POSITION from the end, no position = 0
	int rindex(std::string s, std::string to_find, int start_pos);
	//Removes the last character from a string or array of strings.
	std::string chop(std::string s);
	//already implemented
	std::string reverse(std::string s);
	//pattern matching
	std::vector<std::string> match(std::string s, std::string pattern);
	//pattern substitution
	std::string gsub(std::string s, std::string pattern);
}

#endif 
