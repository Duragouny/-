///////////////////////////////////////////////////////////////////////////////
#include <algorithm>
#include <cctype>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>
///////////////////////////////////////////////////////////////////////////////
typedef std::map        < char,     char    >   T_key;
typedef std::string                             T_text;
typedef std::set        < char  >               T_char_set;
typedef std::vector     < char  >               T_symbols;
///////////////////////////////////////////////////////////////////////////////
char    get_rand_symb()
{
    return  rand() % ( CHAR_MAX - CHAR_MIN + 1 ) + CHAR_MIN;
}
///////////////////////////////////////////////////////////////////////////////
void    make_rand_key
    (
        T_key   &   key,
        T_key   &   reverse_key
    )
{
    const   char    FIRST_ALPHABET_LETTER   =   'a';
    const   char    LAST_ALPHABET_LETTER    =   'z';
 
    const   size_t  ALPHABET_SIZE           =       LAST_ALPHABET_LETTER
                                                -   FIRST_ALPHABET_LETTER
                                                +   1;
 
    T_char_set      symbols_set;
 
    while   (
                    symbols_set.size()
                <   ALPHABET_SIZE
            )
    {
        char    rand_alnum_symb{};
 
        do
        {
            rand_alnum_symb     =   get_rand_symb();
        }
        while   (
                    !isalnum( rand_alnum_symb )
                );
 
        symbols_set.insert( rand_alnum_symb );
    }//while
 
    T_symbols   symbols (
                            symbols_set.begin   (),
                            symbols_set.end     ()
                        );
 
    std::random_shuffle
        (
            symbols.begin   (),
            symbols.end     ()
        );
 
    for (
            char
            symb{ FIRST_ALPHABET_LETTER };
            symb    <=  LAST_ALPHABET_LETTER;
            ++symb
        )
    {
        key[ symb ]     =   symbols[ symb   -   FIRST_ALPHABET_LETTER ];
 
        reverse_key
            [
                key[ symb ]
            ]
            =   symb;
    }//for
}
///////////////////////////////////////////////////////////////////////////////
void    input_text( T_text  &   text )
{
    std::cout   <<  "\n\nEnter text in lower-case Latin letters:\n-> ";
    std::cin    >>  text;
}
///////////////////////////////////////////////////////////////////////////////
void    encrypt_text
    (
        T_text  const   &   text,
        T_key   const   &   key,
        T_text          &   encrypted_text
    )
{
    for( auto   symb    :   text )
    {
        auto    it  =   key.find( symb );
 
        if  (
                it  ==  key.end()
            )
        {
            throw   std::domain_error("Invalid symbol in text.");
        }
 
        encrypted_text.push_back( it->second );
    }//for
}
///////////////////////////////////////////////////////////////////////////////
void    print_text_with_comment
    (
        T_text  const   &   text,
        T_text  const   &   comment
    )
{
    std::cout   <<  std::endl
                <<  comment
                <<  std::endl
                <<  text
                <<  std::endl;
}
///////////////////////////////////////////////////////////////////////////////
int     main()
{
    std::ios::sync_with_stdio(false);
    srand(unsigned(time(0)));
 
    T_key   key;
    T_key   reverse_key;
 
    make_rand_key
        (
            key,
            reverse_key
        );
 
    for(;;)
    {
        T_text   text;
        input_text( text );
        T_text   encrypted_text;
 
        try
        {
            encrypt_text
                (
                    text,
                    key,
                    encrypted_text
                );
        }
        catch   (
                    std::exception  &   e
                )
        {
            std::cout   <<  e.what()
                        <<  std::endl;
 
            continue;
        }//catch
 
        print_text_with_comment
            (
                encrypted_text,
                "Encrypted text:"
            );
 
        T_text   decrypted_text;
 
        encrypt_text
            (
                encrypted_text,
                reverse_key,
                decrypted_text
            );
 
        print_text_with_comment
            (
                decrypted_text,
                "Decrypted text:"
            );
    }//for
}
