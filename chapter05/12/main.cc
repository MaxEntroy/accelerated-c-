/*************************************************************************
    > File Name: main.cc
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2017年12月03日 星期日 14时34分41秒
 ************************************************************************/
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <deque>
#include <algorithm>

struct Element {
	std::string begin;
	std::deque<std::string> sentence;
	Element() {}
};

bool equal( const std::string& a, const std::string& b ) {
	std::string aa = a;
	std::string bb = b;
	aa[0] = tolower(aa[0]);
	bb[0] = tolower(bb[0]);
	return aa == bb;
}
bool cmp( const std::string& a, const std::string& b ) { 
	std::string aa = a;
	std::string bb = b;
	aa[0] = tolower(aa[0]);
	bb[0] = tolower(bb[0]);
	return aa < bb;
}
bool compare( const Element& a, const Element& b ) { 
	int sz_a = a.sentence.size();
	int sz_b = b.sentence.size();
	
	int i = 0;
	while( i < sz_a && i < sz_b ) {
		if( !equal( a.sentence[i], b.sentence[i] ) )	
			return cmp( a.sentence[i], b.sentence[i] );
		else
			++i;
	}
	if( i < sz_a ) return false;
	if( i < sz_b ) return true;
}

void get_sentence( const std::string& s, std::deque<std::string>& sentence );
void preprocess( std::deque<std::string>& sentence, std::vector<Element>& all_sentence );
std::vector<Element> merge_sentence( const std::vector<Element>& s1, const std::vector<Element>& s2 );
void show_sentence( const std::vector<Element>& all_sentence );

int main( void ) {
	const std::string s1( "The quick brown fox" );
	const std::string s2( "jumped over the fence" );

	std::deque<std::string> sentence1;
	std::deque<std::string> sentence2;

	get_sentence( s1, sentence1 );
	get_sentence( s2, sentence2 );

	std::vector<Element> all_sentence1;
	std::vector<Element> all_sentence2;

	preprocess( sentence1, all_sentence1 );
	preprocess( sentence2, all_sentence2 );

	std::vector<Element> ret = merge_sentence( all_sentence1, all_sentence2 );

	show_sentence( ret );

	return 0;
}

void get_sentence( const std::string& s, std::deque<std::string>& sentence ) {

	std::stringstream ss(s);
	std::string str;
	while( ss >> str ) 
		sentence.push_back(str);
	
	return;
}

void preprocess( std::deque<std::string>& sentence, std::vector<Element>& all_sentence ) {
	int sz = sentence.size();
	std::string begin( sentence[0] );

	for( int i = 0; i < sz; ++i ) {
		Element e;
		e.begin = begin;
		e.sentence = sentence;
		all_sentence.push_back(e);

		sentence.push_back( sentence.front() );
		sentence.pop_front();
	}
	return;
}

std::vector<Element> merge_sentence( const std::vector<Element>& s1, const std::vector<Element>& s2 ) {
	std::vector<Element> ret(s1);
	int sz = s2.size();
	for( int i = 0; i < sz; ++i ) ret.push_back(s2[i]);
	std::sort( ret.begin(), ret.end(), compare );
	
	return ret;
}

void show_sentence( const std::vector<Element>& all_sentence ) {
	int sz = all_sentence.size();
	int maxlen = 0;

	for( int i = 0; i < sz; ++i ) {
		const std::deque<std::string>& s = all_sentence[i].sentence;
		const std::string& b = all_sentence[i].begin;
		int new_sz = s.size();

		int curlen = 0;
		bool flag = false;
		for( int j = 0; j < new_sz; ++j ) {
			if(!flag){
				if( s[j] == b && j != 0 ) {
					flag = true;
					curlen += s[j].size();
				}
			}
			else {
				++curlen;
				curlen += s[j].size();
			}	
		}
		if( curlen > maxlen ) maxlen = curlen;
	}

	for( int i = 0; i < sz; ++i ) {
		const std::deque<std::string>& s = all_sentence[i].sentence;
		const std::string& b = all_sentence[i].begin;
		int new_sz = s.size();
		
		bool flag = false;
		std::string left;
		std::string right;
		for( int j = 0; j < new_sz; ++j ) {
			if(!flag) {
				if( s[j] == b && j != 0 ) {
					flag = true;
					left += s[j];
				}
				else {
					right += s[j];
					right += " ";
				}
			}
			else {
				left += " ";
				left += s[j];
			}
		}
		int left_sz = left.size();
		std::string space( maxlen - left_sz, ' ' );
		left = space + left;
		std::cout << left << "\t\t" << right << std::endl;
	}

	return ;
}
