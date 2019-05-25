#include <iostream>
#include <functional>

#include "boost/algorithm/searching/boyer_moore_horspool.hpp"
#include "boost/algorithm/searching/knuth_morris_pratt.hpp"
#include "boost/timer/timer.hpp"
#include "boost/predef.h"

boost::int_least64_t timed1000( const std::string& name, const std::function<void()>& func ) {
    boost::timer::cpu_timer stopwatch;
    stopwatch.start();

    for( int i = 0; i < 1000; ++i ) {
        func();
    }

    stopwatch.stop();
    boost::int_least64_t ns = stopwatch.elapsed().wall;
    printf( "%30s : %3ld us\n", name.c_str(), ns / 1000 );
    return ns;
}

int main() {
    std::string text = "You can get there from here, but why on earth would you want to?";
    std::string term = "earth";
    size_t pos = 0;
    void* ptr = nullptr;
    std::string::iterator it;
    boost::algorithm::boyer_moore_horspool bmh( term.begin(), term.end() );
    boost::algorithm::knuth_morris_pratt kmp( term.begin(), term.end() );

    printf( "%s with %s\n", BOOST_PLATFORM, BOOST_COMPILER );
    printf( "~~~~\n" );

#if !WIN32
    boost::int_least64_t t_memmem = timed1000( "memmem", [&text, &term, &ptr] {
        ptr = memmem( text.data(), text.size(), term.data(), term.size() );
    } );
#endif

    boost::int_least64_t t_find = timed1000( "string::find", [&text, &term, &pos] {
        pos = text.find( term );
    } );

    boost::int_least64_t t_strstr = timed1000( "strstr", [&text, &term, &ptr] {
        ptr = ( void* )strstr( text.data(), term.data() );
    } );

    boost::int_least64_t t_BMH = timed1000( "boyer_moore_horspool_search", [&text, &term, &it, &bmh] {
        it = bmh( text.begin(), text.end() ).first;
    } );

    boost::int_least64_t t_KMP = timed1000( "knuth_morris_pratt_search", [&text, &term, &it, &kmp] {
        it = kmp( text.begin(), text.end() ).first;
    } );

    printf( "~~~~\n" );
    printf( "\n" );

    return 0;
}
