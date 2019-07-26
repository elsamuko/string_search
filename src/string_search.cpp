#include <iostream>
#include <functional>

#include "boost/algorithm/searching/boyer_moore_horspool.hpp"
#include "boost/algorithm/searching/knuth_morris_pratt.hpp"
#include "boost/predef.h"

#include "stopwatch.hpp"
#include "ssestr.hpp"
#include "stdstr.hpp"

// GPL text
#include "licence.hpp"

long timed1000( const std::string& name, const std::function<void()>& func ) {
    StopWatch stopwatch;
    stopwatch.start();

    for( int i = 0; i < 1000; ++i ) {
        func();
    }

    long ns = stopwatch.stop();
    printf( "%30s : %5ld us\n", name.c_str(), ns / 1000 );
    return ns;
}

int main() {

    printf( "%s with %s\n", BOOST_PLATFORM, BOOST_COMPILER );
    printf( "~~~~\n" );

    std::string full( ( const char* )licence, sizeof( licence ) );
    std::string small = R"gpl(
Moreover, your license from a particular copyright holder is
reinstated permanently if the copyright holder notifies you of the
violation by some reasonable means, this is the first time you have
received notice of violation of this License (for any work) from that
copyright holder, and you cure the violation prior to 30 days after
your receipt of the notice.

  Termination of your rights under this section does not terminate the
licenses of parties who have received copies or rights from you under
this License.  If your rights have been terminated and not permanently
reinstated, you do not qualify to receive new licenses for the same
material under section 10.
)gpl";


    for( std::string term : { "Termination", "t4tb7qfSFb2" } ) {

        if( term == "Termination" ) {
            printf( "Search for an existing substring with" );
        } else {
            printf( "Search for an non-existing substring with" );
        }

        for( std::string text : { small, full } ) {

            std::string_view view( text );
            size_t pos = 0;
            const char* ptr = nullptr;
            std::string::const_iterator it;
            boost::algorithm::boyer_moore_horspool bmh( term.begin(), term.end() );
            boost::algorithm::knuth_morris_pratt kmp( term.begin(), term.end() );

            printf( "%i bytes within %i bytes.\n", term.size(), text.size() );

            long t_std = timed1000( "fromStd", [&text, &term, &ptr] {
                ptr = fromStd::strstr( text.data(), text.size(), term.data(), term.size() );
            } );

            long t_find = timed1000( "string::find", [&text, &term, &pos] {
                pos = text.find( term );
            } );

#if !WIN32
            long t_ssestr = timed1000( "ssestr", [&text, &term, &ptr] {
                ptr = sse::scanstrN( text.data(), term.data(), term.size() );
            } );

            long t_memmem = timed1000( "memmem", [&text, &term, &ptr] {
                ptr = ( char* )memmem( text.data(), text.size(), term.data(), term.size() );
            } );
#endif

            long t_strstr = timed1000( "strstr", [&text, &term, &ptr] {
                ptr = strstr( text.data(), term.data() );
            } );

            long t_view = timed1000( "string_view", [&view, &term, &pos] {
                pos = view.find( term );
            } );

            long t_BMH = timed1000( "boyer_moore_horspool_search", [&text, &term, &it, &bmh] {
                it = bmh( text.begin(), text.end() ).first;
            } );

            long t_KMP = timed1000( "knuth_morris_pratt_search", [&text, &term, &it, &kmp] {
                it = kmp( text.begin(), text.end() ).first;
            } );

            printf( "\n" );
        }
    }

    printf( "~~~~\n" );
    printf( "\n" );
    return 0;
}
