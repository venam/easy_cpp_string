Easy String In CPP
-------------------


# WIP #


Inspired by a conversation on IRC with [Pr0Wolf29](https://github.com/Pr0Wolf29/)


Things to check:

* my regex.hpp
* Pr0Wolf29 tools.cpp
* Pr0Wolf29 libwolfstring.hpp
* George xstring.h
* Other languages such as Perl & Ruby
* http://www.cplusplus.com/reference/regex/
* PCRE - with regex


Possibility to choose between a class extending string or to use simple
functions that take strings and return strings (or as reference) in a namespace (obviously)

Set for camelcase

#Functions To Implement:


* `remove_html_comments`
* `to_lower`
* `to_upper`
* `is_lower`
* `is_upper`
* `is_space`
* `word_in` //check if another string is in the string
* `replace` //replace one string inside another
* `replace_all` //replace all occurence of a string inside another
* `replace_all_recursive` //replace all occurence of a string inside another recursively, against injection
* `int_to_string`
* `string_to_int`
* `float_to_string`
* `string_to_float`
* `string_to_long`
* `long_to_string`
* `strip` //need to check all the character that needs to be stripped \t \n \r
* `rstrip` //(start from the end) need to check all the character that needs to be stripped \t \n \r
* `rstrip`
* `lstrip`
* `is_hex` //check if a string is a valid hexadecimal
* `split` //split by a string and returns a vector, the string is not included in what is returned
* `split_lines` //split at \n
* `starts_with`
* `ends_with`
* `match`
* `is_number`
* `remove_space` //remove all space and separator characters in a string
* `remove_endline` //only remove endlines
* `remove_occurence` //remove all occurence of a string inside another
* `remove_occurence_recursive` //remove all occurence of a string inside another recursively (safe)
* `remove_special_chars` //keep only alphanumerics
* `substring`
* `capitalize` //only first characters of every word capitalized
* `center` //Return S centered in a string of length width. Padding is done using the specified fill character (default is a space)
* `count` (s,start,end)//return the number of non-overlapping occurence of a substring inside a string
* `decode`
* `encode`
* `expand_tabs` //Return a copy of S where all tab characters are expanded using spaces.If tabsize is not given, a tab size of 8 characters is assumed.
* `find`
* `partition` //search for the first occurence of a separator and return 2 strings
* `rpartition` //same but start searching from the right
* `swap_case` //change upper by lower and lower by upper
* `translate` //transliteration
* `zfill` //numeral padding with 0 on the left so it fits a width

