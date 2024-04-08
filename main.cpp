#include        <bits/stdc++.h>

#define         size_equation                        100
#define         array_size                            50
const char      *calculation      =               "+ ";

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

bool            condition_global    =          false; 

void    split_coefficient_exponent          (const string& equation, 
                                            int& base, 
                                            int& exponent);

void    solution_equation                   (char equation[]) {

        int         index = 0, 
                    base, 
                    exponent; 

        string      str_number_equation [size_equation] ;

        char        *pointer,
                    *number_equation;
        
        pointer  =    equation ;

        while (number_equation     =   strtok(pointer, calculation)) {

            pointer              =   NULL;
            str_number_equation [index] =   number_equation; 
            index++ ;
        }

        for (int i = 0; i < index; i++) { split_coefficient_exponent(str_number_equation[i], 
                                                                    base, 
                                                                    exponent);}


        return ;
}

void    split_coefficient_exponent          (const string& equation, 
                                            int& base, 
                                            int& exponent) {

        size_t x_pos   =    equation.find('x');
        size_t pow_pos =    equation.find('^');

        if ( x_pos   ==    string::npos ) {   base       =  stoi(equation);       exponent = 0;}  else { base     = stoi ( equation.substr ( 0, x_pos ) );
        if ( pow_pos !=    string::npos ) {   exponent   =  stoi(equation.substr(pow_pos + 1));}  else { exponent = 1; }}
        
        addition_saving_number                 [exponent]    +=  base;

        if (condition_global  ==  false) {

            multiplication_saving_number       [exponent]      =  base;
            subtraction_saving_number          [exponent]      =  base;

        } else {

            multiplication_saving_number_part2 [exponent]      =  base;
            subtraction_saving_number_part2    [exponent]      =  base;
        }

        return;
}

void    deploy_submit_number               () {
        
        for       ( int i  =  0 ; i  <=  50;  i++ )     {
                  multiplication_saving_number_result[i]      =    multiplication_saving_number[i] * multiplication_saving_number_part2[i];
                  subtraction_saving_number_result   [i]      =    subtraction_saving_number   [i] - subtraction_saving_number_part2   [i];
        }
        return;

}

void    output_number                      (int saving_number[50]){

        bool      ping_check              =      true ;
        for       ( int i  =  50 ; i  >=  0;  i-- )    { 
        switch (i) {

                case 0:     if  ( saving_number[i]   !=   0 ) { 

                            cout         <<     abs(saving_number[i]); 
                            ping_check   =      false; } 
                            break;
                case 1:     if ( saving_number[i]    !=   0 ) {

                            ping_check  =       false; 
                            cout        <<      abs(saving_number[i])    << "x" ;} 
                            break;
                default:    if ( saving_number[i]   !=   0 ) {

                            ping_check  =       false;
                            cout        <<      abs(saving_number[i])    << "x^" << i ;} 
                            break;
            }

        if ( saving_number[i-1]  > 0 && ping_check == false ) { cout << "+" ;   } else 
        if ( saving_number[i-1]  < 0                        ) { cout << "-" ;   }   
        }
        cout << endl;
        return;
}

void    process_string                     (char str[]) {

        int   len               =          strlen(str);

        for ( int i = 0 ; i < len ; ++i )  { if  (str [i]  == '-') {    if (i > 0 && str[i - 1] != ' ') {
                    memmove(  &str[i + 1], &str[i],     len - i + 1);    str[i] = ' ';
                }

            if (str[i + 1] == ' ') {
                    memmove(  &str[i + 1], &str[i + 2], len - i);
                }
            }
        }
        return; 
}

int     main                               () {

        char    first_equation        [size_equation], 
                second_equation       [size_equation]; 
        
        cin.getline                   (first_equation,    size_equation);
        cin.getline                   (second_equation,   size_equation);
       
        process_string                (first_equation);
        process_string                (second_equation);

        solution_equation             (first_equation); 
        condition_global               =                  true; 
        solution_equation             (second_equation);

        deploy_submit_number          ();
         
        output_number                 (addition_saving_number); 
        output_number                 (subtraction_saving_number_result);
        output_number                 (multiplication_saving_number_result) ;

        return 0;
} 
