/*************************************************************************
    > File Name: main.cc
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2018年03月14日 星期三 00时43分26秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>

typedef std::string::const_iterator const_iter;

std::vector<std::string> get_url( const std::string& text );
const_iter url_begin( const_iter, const_iter );
const_iter url_end( const_iter, const_iter );

bool legal_urlch(char c);
bool illegal_urlch(char c) { return !legal_urlch(c); }

int main( void ) {
	
	const std::string text( "w://w<<<<<<:/<<<<<://<<<<http://www.baidu.com<<<<://weibo.com" );
	std::vector<std::string> ret = get_url( text );
	int sz = ret.size();
	for( int i = 0; i < sz; ++i ) {
		std::cout << ret[i] << std::endl;
	}
	
	return 0;
}

std::vector<std::string> get_url( const std::string& text ) {
	std::vector<std::string> ret;
	
	const_iter b = text.begin();
	const_iter e = text.end();

	while( b != e ) {
		
		b = url_begin(b, e);
		
		if( b != e ) {
			const_iter after = url_end( b, e );
			ret.push_back( std::string( b, after ) );
			b = after;
		}

	}
	
	return ret;
}

const_iter url_begin( const_iter b, const_iter e ) {

	static const std::string sep("://");
	while( b != e ) {
		const_iter beg = search( b, e, sep.begin(), sep.end() );
		
		// We can't find sep, return e at once.
		if( beg == e ) return e;
		
		const_iter beg_copy = beg;
		
		// A sep consisit of text, return e at once.
		if( beg == b && beg+sep.size() == e ) return e;
		
		// There is no character before sep, so the sep is invalid.
		if( beg == b && beg+sep.size() != e ){
			b = b+sep.size();
			continue;
		}

		// There is no character after sep, return e at once.
		if( beg != b && beg+sep.size() == e ) return e;

		while( beg != b && legal_urlch( beg[-1] ) ) --beg;
		// There is no valid character before sep, so the sep is invalid.
		if( beg == beg_copy ) {
			b = beg+sep.size();
			continue;
		}
		
		if( legal_urlch( beg_copy[sep.size()] ) ) return beg;
		else {// There is no valid character after sep, so the sep is invalid.
			b = beg_copy+sep.size();
			continue;
		}
	}
	return e;
}
const_iter url_end( const_iter b, const_iter e ) {
	const_iter end = find_if( b, e, illegal_urlch );
	return end;
}

bool legal_urlch(char c) {
	static const std::string url_ch("~;/?:@=&$-_.+!*'(),");
	return isalnum(c) || (  find( url_ch.begin(), url_ch.end(), c ) != url_ch.end() );
}
