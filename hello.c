/**
 * Simple program to test the gettext tools
 *
 * Build with
 *
 *     make hello
 *
 * (yes, this works without a Makefile)
 *
 * Extract the messages with
 *
 *     xgettext -k_ -o hello.pot hello.c
 *
 * Author:  Stefan Hundhammer <shundhammer@suse.de>
 * License: GPL V2
 **/

#include <stdio.h>
#include <libintl.h>
#include <locale.h>

#define TEXTDOMAIN "hello"

#define _(MSG)  dgettext( TEXTDOMAIN, (MSG) )


int main( int argc, char **argv )
{
    setlocale( LC_ALL, "" );
    bindtextdomain( TEXTDOMAIN, "/usr/share/locale" );
    textdomain( TEXTDOMAIN );
    
    printf( _( "Hello, world!\n"    ) );  // printf -> recognized as c-format
    puts  ( _( "How are you today?" ) );  // no c-format

    printf( _( "printf-like parameters %s and %s\n" ), "foo", "bar" );
    printf( _( "Numbered printf parameters %2$s and %1$s\n" ), "foo", "bar" );

    
    // Just emulating YaST / Ruby style for the gettext tools;
    // this does not do anyting useful with plain C/C++:
    
    puts( _( "sformat-like message with parameters %1 and %2" ) );
    puts( _( "Named parameters %{foo} and %{bar}" ) );
    puts( _( "Named parameters %<foo> and %<bar>" ) );
}
