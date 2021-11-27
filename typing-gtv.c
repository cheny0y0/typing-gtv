/* THIS IS A FREE SOFTWARE.
THIS SOFTWARE IS WITHOUT ANY LICENSES. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

long long seed ; // for function ranlonglong ;
unsigned long long start_time ;

long long ranlonglong( long long from , long long to )
{
    long long res ;
    res = abs( time( NULL ) * time( NULL ) * time( NULL ) * seed ) ;
    seed = res % ( to - from + 1 ) + from ;
    return seed ;
} ;

char pl_typing_str[ 80 ] ;

int main( int argc , char *argv[] )
{
    char score_mode ;
    if ( argc == 2 )
    {
        if ( ( strcmp( argv[ 1 ] , "-?" ) == 0 ) || ( strcmp( argv[ 1 ] , "--help" ) == 0 ) )
        {
            printf( "Usage: %s [paramters]\nAvailable paramters:\n  -?, --help               Show the help and exit.\n  -S, --to-unsigned-short  If the score reaches 65535, end the game.\n  -s, --to-signed-short    If the score reaches 32767, end the game.\n  -T, --to-10000           If the score reaches 10000, end the game.\n  -t, --to-1000            If the score reaches 1000, end the game.\n  -c, --to-char            If the score reaches 255, end the game.\n  -v, --ver                Show the version info and exit.\n" , argv[ 0 ] ) ;
            return 0 ;
        } ;
        if ( ( strcmp( argv[ 1 ] , "-v" ) == 0 ) || ( strcmp( argv[ 1 ] , "--ver" ) == 0 ) )
        {
            printf( "Typing-GTV v0.2.0.013846\n\nAUTHORS:(sorted by joining time)\ncheny0y0\n\nSend email to <cyy144881@icloud.com> to report the mistakes or the glitches of the translation.\n" ) ;
            return 0 ;
        } ;
        if ( ( strcmp( argv[ 1 ] , "-?v" ) == 0 ) || ( strcmp( argv[ 1 ] , "-v?" ) == 0 ) )
        {
            printf( "Usage: %s [paramters]\nAvailable paramters:\n  -?, --help               Show the help and exit.\n  -S, --to-unsigned-short  If the score reaches 65535, end the game.\n  -s, --to-signed-short    If the score reaches 32767, end the game.\n  -T, --to-10000           If the score reaches 10000, end the game.\n  -t, --to-1000            If the score reaches 1000, end the game.\n  -c, --to-char            If the score reaches 255, end the game.\n  -v, --ver                Show the version info and exit.\n\nTyping-GTV v0.2.0.013846\n\nAUTHORS:(sorted by joining time)\ncheny0y0\n\nSend email to <cyy144881@icloud.com> to report the mistakes or the glitches of the translation.\n" , argv[ 0 ] ) ;
            return 0 ;
        } ;
        if ( ( strcmp( argv[ 1 ] , "-c" ) == 0 ) || ( strcmp( argv[ 1 ] , "--to-char" ) == 0 ) )
        {
            score_mode = 0 ;
        }
        else if ( ( strcmp( argv[ 1 ] , "-t" ) == 0 ) || ( strcmp( argv[ 1 ] , "--to-1000" ) == 0 ) )
        {
            score_mode = 1 ;
        }
        else if ( ( strcmp( argv[ 1 ] , "-T" ) == 0 ) || ( strcmp( argv[ 1 ] , "--to-10000" ) == 0 ) )
        {
            score_mode = 2 ;
        }
        else if ( ( strcmp( argv[ 1 ] , "-s" ) == 0 ) || ( strcmp( argv[ 1 ] , "--to-signed-short" ) == 0 ) )
        {
            score_mode = 3 ;
        }
        else if ( ( strcmp( argv[ 1 ] , "-S" ) == 0 ) || ( strcmp( argv[ 1 ] , "--to-unsigned-short" ) == 0 ) )
        {
            score_mode = 4 ;
        }
        else
        {
            score_mode = 5 ;
        } ;
    }
    else if ( argc == 3 )
    {
        if ( ( ( strcmp( argv[ 1 ] , "-?" ) == 0 ) && ( strcmp( argv[ 2 ] , "-v" ) == 0 ) ) || ( ( strcmp( argv[ 1 ] , "-?" ) == 0 ) && ( strcmp( argv[ 2 ] , "--ver" ) == 0 ) ) || ( ( strcmp( argv[ 1 ] , "--help" ) == 0 ) && ( strcmp( argv[ 2 ] , "-v" ) == 0 ) ) || ( ( strcmp( argv[ 1 ] , "--help" ) == 0 ) && ( strcmp( argv[ 2 ] , "--ver" ) == 0 ) ) )
        {
            printf( "Usage: %s [paramters]\nAvailable paramters:\n  -?, --help               Show the help and exit.\n  -S, --to-unsigned-short  If the score reaches 65535, end the game.\n  -s, --to-signed-short    If the score reaches 32767, end the game.\n  -T, --to-10000           If the score reaches 10000, end the game.\n  -t, --to-1000            If the score reaches 1000, end the game.\n  -c, --to-char            If the score reaches 255, end the game.\n  -v, --ver                Show the version info and exit.\n\nTyping-GTV v0.2.0.013846\n\nAUTHORS:(sorted by joining time)\ncheny0y0\n\nSend email to <cyy144881@icloud.com> to report the mistakes or the glitches of the translation.\n" , argv[ 0 ] ) ;
            return 0 ;
        } ;
    } ;
    seed = 100 ; // initial random seed ;
    unsigned long long score ;
    score = 0 ;
    ranlonglong( 33 , 126 ) ;
    for ( char i = 0 ; i < 79 ; i++ )
    {
        pl_typing_str[ i ] = ( ranlonglong( 33 , 126 ) + i ) % 94 + 33 ;
    } ;
    start_time = time( NULL ) ;
    while ( 1 )
    {
        system( "clear" ) ;
        if ( 1 )
        {
            char show_str[ 79 ] ;
            for ( char i = 0 ; i < 78 ; i++ )
            {
                show_str[ i ] = pl_typing_str[ i + 1 ] ;
            }
            printf( "Typing-GTV - Score: %lld  Time used: %lld seconds  Speed: %f characters/s\n\033[31m%c\033[39m%s\n" , score , time( NULL ) - start_time , score / 1.0 / ( time( NULL ) - start_time ) , pl_typing_str[ 0 ] , show_str ) ;
        } ;
        // bash special token: \'"()`~*;&|<>#$
        if ( pl_typing_str[ 0 ] == '\\' )
        {
            if ( system( "bash -c \"read -srd \\\\\"" ) == 2 )
            {
                break ;
            } ;
        }
        else if ( pl_typing_str[ 0 ] == '\'' )
        {
            if ( system( "bash -c \"read -srd \\'\"" ) == 2 )
            {
                break ;
            } ;
        }
        else if ( pl_typing_str[ 0 ] == '"' )
        {
            if ( system( "bash -c 'read -srd \\\"'" ) == 2 )
            {
                break ;
            } ;
        }
        else if ( pl_typing_str[ 0 ] == '(' )
        {
            if ( system( "bash -c \"read -srd \\(\"" ) == 2 )
            {
                break ;
            } ;
        }
        else if ( pl_typing_str[ 0 ] == ')' )
        {
            if ( system( "bash -c \"read -srd \\)\"" ) == 2 )
            {
                break ;
            } ;
        }
        else if ( pl_typing_str[ 0 ] == '`' )
        {
            if ( system( "bash -c 'read -srd \\`'" ) == 2 )
            {
                break ;
            } ;
        }
        else if ( pl_typing_str[ 0 ] == '~' )
        {
            if ( system( "bash -c \"read -srd \\~\"" ) == 2 )
            {
                break ;
            } ;
        }
        else if ( pl_typing_str[ 0 ] == '*' )
        {
            if ( system( "bash -c \"read -srd \\*\"" ) == 2 )
            {
                break ;
            } ;
        }
        else if ( pl_typing_str[ 0 ] == ';' )
        {
            if ( system( "bash -c \"read -srd \\;\"" ) == 2 )
            {
                break ;
            } ;
        }
        else if ( pl_typing_str[ 0 ] == '&' )
        {
            if ( system( "bash -c \"read -srd \\&\"" ) == 2 )
            {
                break ;
            } ;
        }
        else if ( pl_typing_str[ 0 ] == '|' )
        {
            if ( system( "bash -c \"read -srd \\|\"" ) == 2 )
            {
                break ;
            } ;
        }
        else if ( pl_typing_str[ 0 ] == '<' )
        {
            if ( system( "bash -c \"read -srd \\<\"" ) == 2 )
            {
                break ;
            } ;
        }
        else if ( pl_typing_str[ 0 ] == '>' )
        {
            if ( system( "bash -c \"read -srd \\>\"" ) == 2 )
            {
                break ;
            } ;
        }
        else if ( pl_typing_str[ 0 ] == '#' )
        {
            if ( system( "bash -c \"read -srd \\#\"" ) == 2 )
            {
                break ;
            } ;
        }
        else if ( pl_typing_str[ 0 ] == '$' )
        {
            if ( system( "bash -c \"read -srd \\$\"" ) == 2 )
            {
                break ;
            } ;
        }
        else
        {
            char shell_script[ 22 ] ;
            strcpy( shell_script , "bash -c \"read -srd  \"" ) ;
            shell_script[ 19 ] = pl_typing_str[ 0 ] ;
            if ( system( shell_script ) == 2 )
            {
                break ;
            } ;
        } ;
        score++ ;
        for ( char i = 0 ; i < 78 ; i++ )
        {
            pl_typing_str[ i ] = pl_typing_str[ i + 1 ]  ;
        } ;
        if ( score_mode == 0 )
        {
            if ( score == 255 )
            {
                printf( "\nTyping-GTV - ENDED\nTime used: %lld seconds  Speed: %f characters/s\n" , time( NULL ) - start_time , 255 / 1.0 / ( time( NULL ) - start_time ) ) ;
                return 0 ;
            }
            else if ( score > 176 )
            {
                pl_typing_str[ 78 ] = ' ' ;
            }
            else
            {
                pl_typing_str[ 78 ] = ( ranlonglong( 33 , 126 ) + score ) % 94 + 33 ;
            } ;
        }
        else if ( score_mode == 1 )
        {
            if ( score == 1000 )
            {
                printf( "\nTyping-GTV - ENDED\nTime used: %lld seconds  Speed: %f characters/s\n" , time( NULL ) - start_time , 1000 / 1.0 / ( time( NULL ) - start_time ) ) ;
                return 0 ;
            }
            else if ( score > 921 )
            {
                pl_typing_str[ 78 ] = ' ' ;
            }
            else
            {
                pl_typing_str[ 78 ] = ( ranlonglong( 33 , 126 ) + score ) % 94 + 33 ;
            } ;
        }
        else if ( score_mode == 2 )
        {
            if ( score == 10000 )
            {
                printf( "\nTyping-GTV - ENDED\nTime used: %lld seconds  Speed: %f characters/s\n" , time( NULL ) - start_time , 10000 / 1.0 / ( time( NULL ) - start_time ) ) ;
                return 0 ;
            }
            else if ( score > 9921 )
            {
                pl_typing_str[ 78 ] = ' ' ;
            }
            else
            {
                pl_typing_str[ 78 ] = ( ranlonglong( 33 , 126 ) + score ) % 94 + 33 ;
            } ;
        }
        else if ( score_mode == 3 )
        {
            if ( score == 32767 )
            {
                printf( "\nTyping-GTV - ENDED\nTime used: %lld seconds  Speed: %f characters/s\n" , time( NULL ) - start_time , 32767 / 1.0 / ( time( NULL ) - start_time ) ) ;
                return 0 ;
            }
            else if ( score > 32688 )
            {
                pl_typing_str[ 78 ] = ' ' ;
            }
            else
            {
                pl_typing_str[ 78 ] = ( ranlonglong( 33 , 126 ) + score ) % 94 + 33 ;
            } ;
        }
        else if ( score_mode == 4 )
        {
            if ( score == 65535 )
            {
                printf( "\nTyping-GTV - ENDED\nTime used: %lld seconds  Speed: %f characters/s\n" , time( NULL ) - start_time , 65536 / 1.0 / ( time( NULL ) - start_time ) ) ;
                return 0 ;
            }
            else if ( score > 65456 )
            {
                pl_typing_str[ 78 ] = ' ' ;
            }
            else
            {
                pl_typing_str[ 78 ] = ( ranlonglong( 33 , 126 ) + score ) % 94 + 33 ;
            } ;
        }
        else
        {
            pl_typing_str[ 78 ] = ( ranlonglong( 33 , 126 ) + score ) % 94 + 33 ;
        } ;
    } ;
    printf( "\nTyping-GTV - TERMINATED\nScore: %lld  Time used: %lld seconds  Speed: %f characters/s\n" , score , time( NULL ) - start_time , score / 1.0 / ( time( NULL ) - start_time ) ) ;
    return 0 ;
} ;
