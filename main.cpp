///////////////////////////////////////////////////////////////////////////////////////////////////////
#include        <bits/stdc++.h>
#define         size_equation                        100
#define         array_size                            50
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
const char      *calculation         =              "+ ";

char            first_equation                      [size_equation], 
                second_equation                     [size_equation]; 

using namespace std;

int             addition_saving_number              [array_size], 

                subtraction_saving_number           [array_size], 
                subtraction_saving_number_part2     [array_size], 
                subtraction_saving_number_result    [array_size],
                
                multiplication_saving_number        [array_size],
                multiplication_saving_number_part2  [array_size],
                multiplication_saving_number_result [array_size];

                


float           divide_saving_number_remainder      [array_size],
                divide_saving_number                [array_size],
                divide_saving_number_part2          [array_size],
                divide_saving_number_result         [array_size];
               
bool            condition_global    =          false; 
///////////////////////////////////////////////////////////////////////////////////////////////////////
void    split_coefficient_exponent          (const string& equation, 
                                            int& base, 
                                            int& exponent);
///////////////////////////////////////////////////////////////////////////////////////////////////////
void    solution_equation                   (char equation[]) {

        int         index = 0, 
                    base, 
                    exponent; 

        string      str_number_equation [size_equation] ;

        char         *pointer,
                     *number_equation;
        
        pointer   =  equation ;

        while (number_equation     =   strtok(pointer, 
                                             calculation)) {

            pointer                =   NULL;
            str_number_equation [index] =   number_equation; 
            index++ ;
        }

        for (int i = 0; i < index; i++) { split_coefficient_exponent(str_number_equation[i], 
                                                                    base, 
                                                                    exponent);}


        return ;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void    split_coefficient_exponent          (const string& equation, 
                                            int& base, 
                                            int& exponent) {

        size_t x_pos   =    equation.find('x');
        size_t pow_pos =    equation.find('^');

        if ( x_pos   ==     string::npos ) {    base           =  stoi(equation);       exponent = 0;}  else { base     = stoi ( equation.substr ( 0, x_pos ) );
        if ( pow_pos !=     string::npos ) {    exponent       =  stoi(equation.substr(pow_pos + 1));}  else { exponent = 1; }}
        
        addition_saving_number                 [exponent]      +=  base;

        if (condition_global  ==  false) {
            

            multiplication_saving_number       [exponent]      =  base;
            subtraction_saving_number          [exponent]      =  base;
            divide_saving_number               [exponent]      =  base; 

        } else {

            multiplication_saving_number_part2 [exponent]      =  base;
            subtraction_saving_number_part2    [exponent]      =  base;
            divide_saving_number_part2         [exponent]      =  base; 
        }

        return;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void    deploy_submit_number               () {
        
        for     ( int i  =  0 ; i  <=  50;  i++ )     {

                multiplication_saving_number_result[i]      =    multiplication_saving_number[i] * multiplication_saving_number_part2[i];
                subtraction_saving_number_result   [i]      =    subtraction_saving_number   [i] - subtraction_saving_number_part2   [i];
                divide_saving_number_result        [i]      =    divide_saving_number        [i] / divide_saving_number_part2        [i];
                divide_saving_number_remainder     [i]      =    fmod(divide_saving_number   [i] , divide_saving_number_part2        [i]);

        }
        return;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void    output_number                           (int saving_number[50]){

        bool      ping_check              =      true ;
        for       ( int i  =  50 ; i  >=  0;  i-- )    { 
            switch (i) {

                case 0:     if (  saving_number [i]   !=   0 ) { 

                            ping_check   =      false;
                            cout         <<     abs(saving_number[i]);                  } 
                            break;

                case 1:     if ( saving_number  [i]    !=   0 ) {

                            ping_check  =       false; 
                            cout        <<      abs(saving_number[i])    << "x" ;       } 
                            break;

                default:    if ( saving_number  [i]   !=   0 ) {

                            ping_check  =       false;
                            cout        <<      abs(saving_number[i])    << "x^" << i ; } 
                            break;

            }

            if ( saving_number[i-1]  > 0 &&
                 ping_check == false ) { cout << "+" ;   } else 

            if ( saving_number[i-1]  < 0                        ) { cout << "-" ;   }   
        }
        cout << endl;
        return;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void    output_number_split                     (float saving_number[50]){

        bool      ping_check              =      true ;
        for       ( int i  =  50 ; i  >=  0;  i-- )    { 
            switch (i) {

                case 0:     if  ( saving_number[i]   >   0 ||
                                  saving_number[i]   <   0 ){ 

                            ping_check   =      false;
                            cout         <<     fixed      << setprecision(1)    <<  abs(saving_number[i]);                } 
                            break;

                case 1:     if ( saving_number[i]   >   0 || 
                                 saving_number[i]   <   0 ){

                            ping_check  =       false; 
                            cout        <<     fixed      << setprecision(3)    <<  abs(saving_number[i]) ;

                            if (  condition_global  ==  true ) 
                               {  cout <<      "x"           ;}} 
                            break;

                default:    if ( saving_number[i]   >   0 || 
                                 saving_number[i]   <   0 ){

                            ping_check  =       false;
                            cout        <<      fixed      << setprecision(3)    <<  abs(saving_number[i]) ;
                             if (  condition_global  ==  true ) 
                                {  cout <<      "x^"     << i;}}
                            break;

            }

            if ( saving_number[i-1]  > 0 && ping_check == false ) { cout << "+" ;   } else 
            if ( saving_number[i-1]  < 0                        ) { cout << "-" ;   }   
        }
        cout << endl;
        return;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void    process_string                     (char str[]) {

        int   len           =               strlen(str);

        for    (int i       =  0    ;   i  < len ; ++i )  { 

            if (str [i]     == '-') {    
            if (i           >  0    && str[i - 1] != ' ') {memmove( &str[i + 1], 
                                                                    &str[i],
                                                                    len - i + 1);    
                                                                    str[i] = ' ';       }
            if (str[i + 1]  == ' ')                       {memmove( &str[i + 1], 
                                                                    &str[i + 2], 
                                                                    len - i);           }         
            }
        }
        return; 
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void    add_one                            (char equation[]) {
        int     size_add_one =              strlen(equation),
                j = 0;
        for     (int i = size_add_one +1 ; i >0;i--)         {equation[i] = equation [i-1];}
        equation [0] = ' ';

        for     (int i = 0; i < size_add_one; i++) {
            if ((   equation[i] == '+'  || 
                    equation[i] == '-'  || 
                    equation[i] == '*'  || 
                    equation[i] == ' ') && 
                    equation[i+1] == 'x'){

        for     (int k = size_add_one + 1; k > i + 1; k--)   {equation[k] = equation[k - 1];}

                equation[i + 1] = '1';
                size_add_one++; 

            }
        }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
int     main                                () {
///////////////////////////////////////////////////////////////////////////////////////////////////////
        cin.getline                   (first_equation,    size_equation);
        cin.getline                   (second_equation,   size_equation);
///////////////////////////////////////////////////////////////////////////////////////////////////////
        add_one(first_equation);
        add_one(second_equation);

        process_string                (first_equation);
        process_string                (second_equation);
///////////////////////////////////////////////////////////////////////////////////////////////////////
        solution_equation             (first_equation); 
        condition_global              =                  true; 
        solution_equation             (second_equation);
///////////////////////////////////////////////////////////////////////////////////////////////////////
        deploy_submit_number          ();
///////////////////////////////////////////////////////////////////////////////////////////////////////
        output_number                 (addition_saving_number); 
        output_number                 (subtraction_saving_number_result);
        output_number                 (multiplication_saving_number_result) ;

        condition_global              =                  true; 
        output_number_split           (divide_saving_number_result);
        condition_global              =                  false;
        output_number_split           (divide_saving_number_remainder);
///////////////////////////////////////////////////////////////////////////////////////////////////////
        return 0;
} 
