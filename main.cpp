/*********************************************************************
                                                   
88        88   ,ad8888ba,  88b           d88 88        88  ad88888ba   
88        88  d8"'    `"8b 888b         d888 88        88 d8"     "8b  
88        88 d8'           88`8b       d8'88 88        88 Y8,          
88aaaaaaaa88 88            88 `8b     d8' 88 88        88 `Y8aaaaa,    
88""""""""88 88            88  `8b   d8'  88 88        88   `"""""8b,  
88        88 Y8,           88   `8b d8'   88 88        88         `8b  
88        88  Y8a.    .a8P 88    `888'    88 Y8a.    .a8P Y8a     a8P  
88        88   `"Y8888Y"'  88     `8'     88  `"Y8888Y"'   "Y88888P"   

                                   est.1941 @ PHYSICS AND ENGINEERING

COPYRIGHT 2024 @ DEVELOPED BY [GROUP 1] 

Github repo (GROUP 1): github.com/Phong12HexDockwork/KTLTC_BTL
VNU @ University of Science   
227 Nguyen Van Cu Street, District 5, Ho Chi Minh City
                                                 
**********************************************************************/

///////////////////////////////////////////////////////////////////////////////////////////////////////
#include        <bits/stdc++.h>
#define         size_equation                        100
#define         array_size                           50
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
const char      *calculation              =         "+ ";

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
               
bool            condition_global          =         false; 
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

        char        *pointer,
                    *number_equation;
        
        pointer     =  equation ;

        while (number_equation   =   strtok(pointer, 
                                            calculation)) {

                pointer                     =   NULL;
                str_number_equation [index] =   number_equation; 
                index++ ;

        }

        for ( int i = 0 ; i < index; i++ ) { split_coefficient_exponent(str_number_equation[i], 
                                                                        base, 
                                                                        exponent);}

        return ;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void    split_coefficient_exponent          (const string& equation, 
                                             int& base, 
                                             int& exponent) {

        size_t x_pos    =   equation.find('x');
        size_t pow_pos  =   equation.find('^');

        if   ( x_pos    ==  string::npos ) { base     =   stoi( equation );   exponent = 0; }  
        else { base     =   stoi ( equation.substr ( 0, x_pos ) );

        if ( pow_pos    !=  string::npos ) { exponent =   stoi( equation.substr( pow_pos + 1 ) ); }  
        else { exponent = 1; }}
        
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
        
        for( int index  =  0 ; index  <=  array_size ;  index++ )     {

                multiplication_saving_number_result[index]      =    multiplication_saving_number          [index] 
                                                                   * multiplication_saving_number_part2    [index];

                subtraction_saving_number_result   [index]      =    subtraction_saving_number             [index] 
                                                                   - subtraction_saving_number_part2       [index];

                divide_saving_number_result        [index]      =    divide_saving_number                  [index] 
                                                                   / divide_saving_number_part2            [index];

                divide_saving_number_remainder     [index]      =    fmod(divide_saving_number             [index], 
                                                                          divide_saving_number_part2       [index]);

        }
        return;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void    output_number                           (int saving_number[50]){

        bool ping_check  =  true ;
        for ( int index  =  array_size ; index  >=  0 ;  index-- )    { 

                switch (index) {
                        case 0: if ( saving_number [index]  !=  0 ){ 

                                ping_check  =      false;
                                cout        <<     abs(saving_number[index]) ; } 
                                break;

                        case 1: if ( saving_number  [index]  !=  0 ){

                                ping_check  =       false; 
                                cout        <<      abs(saving_number[index])    
                                            <<      "x" ; } 
                                break;

                        default:if ( saving_number  [index]   != 0 ){

                                ping_check  =       false;
                                cout        <<      abs(saving_number[index])    
                                            <<      "x^" 
                                            <<      index ; } 
                                break;

            }
            if ( saving_number [index-1]  > 0 && ping_check == false ) { cout << "+" ;   } else 
            if ( saving_number [index-1]  < 0                        ) { cout << "-" ;   }   
        }

        cout << endl;
        return;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void    output_number_split                     (float saving_number[50]){

        bool ping_check  =  true ;
        for ( int index  =  50 ; index  >=  0 ;  index-- )    { 

                switch (index) {
                        case 0:  if ( saving_number [index]  >  0 ||
                                      saving_number [index]  <  0   ){ 

                                ping_check  =      false;
                                cout        <<     fixed      
                                            <<     setprecision (1)    
                                            <<     abs( saving_number [index] ) ; } 
                                break;

                        case 1:  if ( saving_number [index]  >   0 || 
                                      saving_number [index]  <   0   ){

                                ping_check  =      false; 
                                cout        <<     fixed       
                                            <<     setprecision (3)    
                                            <<     abs( saving_number [index] ) ;

                                if ( condition_global  ==  true ) { cout <<  "x"  ; } } 
                                break;

                        default: if ( saving_number[index]   >   0 || 
                                saving_number[index]   <   0   ){

                                ping_check  =       false;
                                cout        <<      fixed      
                                            <<      setprecision(3)    
                                            <<      abs( saving_number [index] ) ;
                                if ( condition_global  ==  true ) { cout <<  "x^" << index ; } }
                                break;

            }
            if ( saving_number [index-1]  > 0 && ping_check == false ) { cout << "+" ;   } else 
            if ( saving_number [index-1]  < 0                        ) { cout << "-" ;   }   
        }
        cout << endl;
        return;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void    process_string                     (char equation[]) {

        int size_string  =  strlen (equation);
        for ( int index  =  0  ; index  < size_string ; ++index )  { 
                if ( equation [index]  ==  '-') {

                        if ( index  >  0   &&  equation[index - 1]  !=  ' ') 
                        { memmove( &equation[index + 1] , &equation[index] , size_string - index + 1 ) ; equation[index] = ' ' ; }
                        if ( equation [index + 1]  ==  ' ') 
                        { memmove( &equation[index + 1] , &equation[index + 2] , size_string - index ) ; }     
            }
        }
        return; 
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void    add_one                            (char equation[]) {
        int  size_add_one  =  strlen(equation);
        for ( int index    =  size_add_one + 1 ; index > 0; index-- ) { equation [index]  =  equation [index-1]; }

        equation [0] = ' ';

        for ( int index    =  0 ; index   <  size_add_one; index++ ) {

                if (( equation [index]      == '+'  || equation [index]  == '-'  || equation [index]  == '*'  || equation [index]  == ' ') 
                &&    equation [index+1]    == 'x'  ){

                        for ( int jump  =  size_add_one + 1 ; jump > index + 1 ; jump--) { equation[jump]  =  equation [jump - 1]; }
                        equation [index + 1] = '1' ; size_add_one++; 

            }
        }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void    identify_parentheses               (char equation[]){

        int    jump  =  0;
        bool   following_condition_par  =  false,
               following_condition_exp  =  false;
        string temp_equation               [array_size],
               expanded_equation           [array_size];

        for ( int index = 0; index <= strlen(equation); index++) {

                //Taking equation in '(' and ')'
                if ( equation [index]  ==  '(' ) { following_condition_par  =  true ; }
                if ( equation [index]  !=  '(' &&  following_condition_par  &&  equation[index]  !=  ')') { temp_equation [jump] += equation [index]; }
                if ( equation [index]  ==  ')' ) {

                        //Taking equation after ')' 
                        if ( equation [index + 1]  !=  '+' && equation [index + 1]  !=  '-' && equation [index + 1]  !=  '\0') {

                                        following_condition_exp = true;
                                        index++; 
                                        while ( equation [index]  !=  '+' && equation [index]  !=  '-' && equation[index]  !=  '\0') {
                                                expanded_equation[jump]  +=  equation[index];
                                                index++;
                                        }
                        } else {expanded_equation [jump]  =  "1";}
                        following_condition_par  =  false ; jump++;
                }
        }
        cout << temp_equation[2] << " ";
        cout << expanded_equation[2];

}
////////////////////////////////////////////////////////////////////////////////////////////////////////
int     main                               () {
////////////////////////////////////////////////////////////////////////////////////////////////////////
        cin.getline                   (first_equation,    size_equation);
        cin.getline                   (second_equation,   size_equation);
////////////////////////////////////////////////////////////////////////////////////////////////////////
        add_one(first_equation);
        add_one(second_equation);

        process_string                (first_equation);
        process_string                (second_equation);

        identify_parentheses          (first_equation);
        //identify_parentheses          (second_equation);
////////////////////////////////////////////////////////////////////////////////////////////////////////
        /**solution_equation             (first_equation); 
        condition_global              =                  true; 
        solution_equation             (second_equation);
////////////////////////////////////////////////////////////////////////////////////////////////////////
        deploy_submit_number          ();
////////////////////////////////////////////////////////////////////////////////////////////////////////
        output_number                 (addition_saving_number); 
        output_number                 (subtraction_saving_number_result);
        output_number                 (multiplication_saving_number_result) ;

        condition_global              =                  true; 
        output_number_split           (divide_saving_number_result);
        condition_global              =                  false;
        output_number_split           (divide_saving_number_remainder);**/
////////////////////////////////////////////////////////////////////////////////////////////////////////
        return 0;
} 

