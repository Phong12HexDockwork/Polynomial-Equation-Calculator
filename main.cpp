#include        <bits/stdc++.h>
#define         size_equation                        100
#define         array_size                           50
#define         MAX_LENGTH_CHAR                      256

const char      *calculation              =         "+ ";

char            difficult_equation                  [2*size_equation],
                first_equation                      [size_equation], 
                second_equation                     [size_equation], 
                hostname                            [MAX_LENGTH_CHAR];

int             menu_choice              =           0,

                addition_saving_number              [array_size], 

                subtraction_saving_number           [array_size], 
                subtraction_saving_number_part2     [array_size], 
                subtraction_saving_number_result    [array_size],

                saving_base_exponent_poly1          [array_size],
                saving_base_exponent_poly2          [array_size],
                counting_saving_poly1,
                counting_saving_poly2,

                highest_exponent_poly1   =          -1,
                highest_exponent_poly2   =          -1;
               
bool            condition_global         =          false,
                stopLoading              =          false,
                thread_check             =          false;

using           namespace                           std;
////////////////////////////////////////////////////////////////////////////////////////
void    split_coefficient_exponent          (const string& equation, 
                                             int& base, 
                                             int& exponent);
////////////////////////////////////////////////////////////////////////////////////////
//Reverse the vector from lowest to highest exponent 
void    checking_system         (){ 
        #if __linux__   
                system("clear");
        #elif __WIN32   
                system("cls"); 
        #elif __APPLE__ 
                system("clear");
        #endif
}

void    reverseVector                       ( vector <double> & vec ) {reverse(vec.begin(), vec.end());}

// Loading animation
void    loadingAnimation                    () {
        const int numOfFrames = 5;
        const char frames[numOfFrames] = {'|', '/', '-', '\\'};
        int frameIndex = 0;

        cout << endl;

        while (!stopLoading) {
                cout  <<  "\r( Computer @ "
                      <<  hostname
                      <<  " ) Dang tinh toan " << frames[frameIndex] << flush;

                this_thread::sleep_for(chrono::milliseconds(100)); frameIndex = (frameIndex + 1) % numOfFrames;
        }
}
/////////////////////////////////////////////////////////////////////////////////////////
void     string_split_ploy                   (char equation[]) {

        int     length_equation  =  strlen (equation),
                temp_position    =  0;

        for ( int index  =  0 ; index < length_equation ; index++ ) { if ( equation [index]  ==  ')' && equation [index+1]  ==  '(' ) { temp_position = index ;}}

        strncpy ( first_equation  , equation + 1  , temp_position - 1 );
        strncpy ( second_equation , equation + temp_position + 3 , length_equation );

        int     length_equation_poly2  =  strlen (second_equation);
        second_equation [length_equation_poly2 - 1 ]  =  ' ';
        
        return;
}

char    *process_string                     (char equation[]) {

        int size_string  =  strlen (equation);
        for ( int index  =  0  ; index  < size_string ; ++index )  { 
                if ( equation [index]  ==  '-') {

                        if ( index  >  0   &&  equation[index - 1]  !=  ' ') 
                        { memmove( &equation[index + 1] , &equation[index] , size_string - index + 1 ) ; equation[index] = ' ' ; }
                        if ( equation [index + 1]  ==  ' ') 
                        { memmove( &equation[index + 1] , &equation[index + 2] , size_string - index ) ; }     
            }
        }
        return equation; 
}

char   *add_one                            (char equation[]) {
        int  size_add_one  =  strlen(equation);
        for ( int index    =  size_add_one + 1 ; index > 0; index-- ) { equation [index]  =  equation [index-1]; }

        equation [0] = ' ';

        for ( int index  =  0 ; index  <  size_add_one ; index++ ) {

                if (( equation [index]   ==  ')' || equation [index]  ==  '(' ||  equation [index]   == '+'  || equation [index]  == '-'  || equation [index]  == '*'  || equation [index]  == ' ') 
                &&    equation [index+1] == 'x'  ){

                        for ( int jump   =  size_add_one + 1 ; jump  >  index + 1 ; jump--) { equation[jump]  =  equation [jump - 1]; }
                        equation [index + 1] = '1' ; size_add_one++; 

                }
        }
        return equation;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//Optimizing parentheses in equations 
char    *identify_parentheses               (char equation[]){

        string str_equation(equation);
        int    jump   =  0,
               saving_point                [size_equation];

        bool   following_condition_par  =  false,
               following_condition_exp  =  false;

        string temp_equation               [array_size],
               expanded_equation           [array_size];
       
        for ( int index  =  0 ; index  <=  strlen (equation) ; index++) {
        
                //Taking equation in '(' and ')'
                if ( equation [index]  ==  '(' ) { 
                        if (equation[index-1] =='-'){saving_point[jump] = -1;}
                        else {saving_point[jump] = 1;}
                        following_condition_par  =  true ; }
                if ( equation [index]  !=  '(' &&  following_condition_par  &&  equation[index]  !=  ')') { temp_equation [jump] += equation [index]; }
                if ( equation [index]  ==  ')' ) {

                        //Taking equation after ')' 
                        if ( equation [index + 1]  !=  '+' && equation [index + 1]  !=  '-' && equation [index + 1]  !=  '\0') {
                                        
                                        following_condition_exp = true;
                                        index++; 
                                        while ( equation [index]  !=  '+' && equation [index]  !=  '-' && equation[index]  !=  '\0') {
                                                expanded_equation[jump]  +=  equation [index];
                                                index++;
                                        }
                        } else {expanded_equation [jump]  =  "1";}   
                        following_condition_par  =  false ; jump++;
                }
        }
        //delete parentheses in equations 
        if ( str_equation[1] == '(' ) {str_equation.insert(1,"+") ;}

        for ( int index  =  0 ; index < jump ; index++ ){

                        string delete_equation =  "(" + temp_equation[index] + ")" ;
                        
                        if ( saving_point [index]  ==   1 )     {delete_equation  =  "+" + delete_equation ;}
                        if ( saving_point [index]  ==  -1 )     {delete_equation  =  "-" + delete_equation ;}
                        if ( expanded_equation [index] != "1")  {delete_equation  += expanded_equation[index];}
                        if ( str_equation[0]       ==  '('  ){}
                        size_t pos  =  str_equation.find(delete_equation);

                        while (pos != string::npos) { str_equation.erase (pos, delete_equation.length()) ; pos  =  str_equation.find (delete_equation, pos);}
        }
        //Do equation multiple in for () and outside equation 
        int     base_equation [size_equation],
                expo_equation [size_equation];

        for ( int index   =  0 ; index  <  jump ; index++ ) { 

                int base_count    =  0,
                    base_out_mum  =  0,
                    expo_out_num  =  0;

                char   trauma   =  NULL, 
                       trauma2  =  NULL;

                string t_loop_equation  =  temp_equation [index],
                       final_equation;

                stringstream analyst(expanded_equation[index]);
                analyst >>  base_out_mum 
                        >>  trauma
                        >>  trauma2
                        >>  expo_out_num;
                
                if ( trauma == 'x' && trauma2 != '^') {expo_out_num = 1;}
                if ( trauma != 'x' )                  {expo_out_num = 0;}
                for ( int clue  =  0 ; clue  <  t_loop_equation.size() ; clue++){

                                bool   check_expo    =  false;

                                if ( t_loop_equation [clue-2]  ==  'x' && t_loop_equation [clue-1] == '^') { check_expo = true ; }
                                if ( isdigit(t_loop_equation [clue]) || (t_loop_equation[clue] == '-' && isdigit(t_loop_equation[clue+1]))) {

                                                stringstream temp;
                                                while ( isdigit (t_loop_equation [clue]) || t_loop_equation [clue] == '-' ) {

                                                        temp << t_loop_equation[clue];
                                                        ++clue;
                                                }
                                        if ( check_expo   == false ){
                                                
                                                temp >> base_equation [base_count]; 
                                                if ( t_loop_equation  [clue] == 'x' && t_loop_equation[clue+1]  !=  '^' ){expo_equation[base_count++] = 1;}
                                                if ( t_loop_equation  [clue] != 'x')                                     {expo_equation[base_count++] = 0;}
                                                
                                        } 
                                        if ( check_expo  ==  true ){temp >> expo_equation [base_count++];}
                                }
                }
                //adding into equation
                for ( int t = 0 ; t < base_count ; t++){ base_equation[t]  = saving_point[index] * base_equation[t]*base_out_mum ;}
                for ( int t = 0 ; t < base_count ; t++){ expo_equation [t] =  expo_equation[t]+expo_out_num ;}
                for ( int t = 0 ; t < base_count ; t++ ){

                        switch (expo_equation[t]){
                                case 0: 
                                        if (base_equation[t] > 0) {final_equation += "+";}
                                        final_equation = final_equation + to_string(base_equation[t]) ; break;
                                case 1:
                                        if (base_equation[t] > 0) {final_equation += "+";}
                                        final_equation = final_equation + to_string(base_equation[t]) + "x"; break;
                                default:
                                        if (base_equation[t] > 0) {final_equation += "+";}
                                        final_equation = final_equation + to_string(base_equation[t]) + "x^" + to_string(expo_equation[t]) ; break;
                        }
                       
                }
                str_equation = str_equation + final_equation;
        }

        string null_equation   =  str_equation;
        char *return_equation  =  new char [null_equation.length() + 1]; 
        for (int index  =  0; index  <  null_equation.length(); index++) { return_equation [index] = null_equation [index];}

        return_equation [null_equation.length()] = '\0'; return return_equation;
}  
// Split to base and exponent of equations 
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

        for ( int i = 0 ; i < index ; i++ ) { split_coefficient_exponent(str_number_equation[i], 
                                                                        base, 
                                                                        exponent);}

        return ;
}
//Covert into integer and save it into vector 
void    split_coefficient_exponent          (const string& equation, 
                                             int& base, 
                                             int& exponent) {

        size_t x_pos    =   equation.find('x');
        size_t pow_pos  =   equation.find('^');

        if   ( x_pos    ==  string::npos ) { base     =   stoi( equation );   exponent = 0; }  else { base     =   stoi ( equation.substr ( 0, x_pos ) );
        if ( pow_pos    !=  string::npos ) { exponent =   stoi( equation.substr( pow_pos + 1 ) ); }  else { exponent = 1; }}
        
        addition_saving_number  [exponent]  +=  base;

        if ( condition_global  ==  false ) { 

                if ( highest_exponent_poly1  <   exponent ) {highest_exponent_poly1 = exponent;}
                saving_base_exponent_poly1      [exponent]       +=  base;
                subtraction_saving_number       [exponent]       +=  base;
        } else { 

                if ( highest_exponent_poly2  <   exponent ) {highest_exponent_poly2 = exponent;}
                saving_base_exponent_poly2      [exponent]       +=  base;
                subtraction_saving_number_part2 [exponent]       +=  base; }

        for( int index  =  0 ; index  <=  array_size ;  index++ ){subtraction_saving_number_result [index] = subtraction_saving_number [index] - subtraction_saving_number_part2 [index];        }
        return;
}
//Multi Twos equations 
int     *multiplyTwoPolynomials(int poly1[], int poly2[], int size_poly1, int size_poly2) {

        int *productPolynomial = new int [size_poly1 + size_poly2 - 1];

        for ( int index  =  0 ; index < size_poly1 + size_poly2 - 1 ; index++ ) { productPolynomial [index] = 0; }
        for ( int index  =  0 ; index < size_poly1 ; index++ ) { for ( int jndex = 0; jndex < size_poly2 ; jndex++)  
                
                {productPolynomial [index + jndex] += poly1[index] * poly2[jndex];}}

        return productPolynomial;
}
//Divide two equations 
class Polynomial{
public:
        //Sign Vector with highest to lowest expo 
        Polynomial ( unsigned deg ) : m_deg (deg), m_coeffs (deg+1){}
        Polynomial ( unsigned deg , initializer_list <double> cs)  : m_deg(deg) , m_coeffs(deg+1)
        {
                assert ( cs.size() <= deg + 1 );
                for (auto it = cs.begin(); it != cs.end(); ++it) m_coeffs[it - cs.begin()] = *it;
        }

        Polynomial ( initializer_list <double> cs ) : m_deg (cs.size() - 1), m_coeffs(cs) {}

        Polynomial ( const vector<double>& cs ) : m_deg ( cs.size() == 0 ? 0 : cs.size() - 1), m_coeffs (cs)
        {
                if ( m_coeffs.size () ==  0 )
                m_coeffs.resize(1);
        }

        unsigned    degree()       const { return m_deg; }
        const auto& coefficients() const { return m_coeffs; }

        Polynomial operator+(const Polynomial& other) const
        {
                if (m_deg < other.degree()) return other + *this;

                Polynomial sum(m_coeffs);
                for (size_t i = 0; i <= other.degree(); ++i) sum.m_coeffs[m_deg - other.degree() + i] += other.m_coeffs[i];
                return sum;
        }

        Polynomial operator- (const Polynomial& other) const
        {
                if (m_deg < other.degree()) return Polynomial{-1.0} * other + *this;

                Polynomial sum (m_coeffs);
                for (size_t i = 0; i <= other.degree(); ++i)
                sum.m_coeffs[m_deg-other.degree()+i] -= other.m_coeffs[i];

                return sum;
        }

        Polynomial operator*(const Polynomial& other) const
        {
                Polynomial prod(m_deg + other.degree());
                for (size_t i = 0; i <= m_deg; ++i)
                for (size_t j = 0; j <= other.degree(); ++j)
                        prod.m_coeffs[i+j] += m_coeffs[i] * other.m_coeffs[j];

                return prod;
        }

        Polynomial truncate() const
        {
                if (m_coeffs[0] != 0 || m_coeffs.size() == 1) 
                return *this;
                else
                return Polynomial(std::vector<double>(m_coeffs.begin()+1, 
                                                        m_coeffs.end())).truncate();
        }

        // Returns a pair (quotient, remainder)
        auto operator/(const Polynomial& other) const
        {
                if (m_deg < other.m_deg)
                return std::make_pair(Polynomial(0), other);
                Polynomial quotient(m_deg - other.degree());
                Polynomial remainder(*this);

                while ((remainder = remainder.truncate()).degree() >= other.degree()) {
                Polynomial multiplier(remainder.degree() - other.degree(), 
                        { remainder.m_coeffs[0] / other.m_coeffs[0] });

                remainder = remainder - (multiplier * other);
                quotient  = quotient + multiplier;
                }

                return std::make_pair(quotient, remainder);
        }

        friend std::ostream& operator<<(std::ostream&, const Polynomial&);

private:
        unsigned m_deg;
        std::vector<double> m_coeffs;
};
//Output the vector after optimized
std::ostream& operator<<(std::ostream& os, const Polynomial& p)
{
        if (p.m_deg == 0)
                return (os << p.m_coeffs[0]);
        
        for (size_t i = 0; i < p.m_deg - 1; ++i)
                if (p.m_coeffs[i]) os << p.m_coeffs[i] << "x^" << p.m_deg-i << "+";

        return (os << p.m_coeffs[p.m_deg-1] << "x+" << p.m_coeffs[p.m_deg]);
}
//Print the equation following vector defined 
void    output_number                           (int saving_number[50]){

        bool ping_check     =  true ;
        
        for ( int index  =  array_size ; index  >=  0 ;  index-- ){ if ( saving_number [index] == 0 ) { thread_check = true; }else{thread_check = false; break;}}
        for ( int index  =  array_size ; index  >=  0 ;  index-- ){ 
                if ( saving_number [index] != 0 ) {!thread_check;}
                switch (index) {
                        case 0: if ( saving_number [index]  !=  0 ){ 

                                ping_check  =      false;
                                cout        <<     abs(saving_number[index]) ; } 
                                break;

                        case 1: if ( saving_number  [index]  !=  0 ){

                                ping_check  =       false; 
                                if ( saving_number [index] == 1 || saving_number [index] == -1 ){cout   <<  "x" ;} else
                                cout        <<      abs(saving_number[index])    
                                            <<      "x" ; }  
                                break;

                        default:if ( saving_number  [index]   != 0 ){

                                ping_check  =       false;
                                if ( saving_number [index] == 1 || saving_number [index] == -1 ){cout   <<  "x^"  <<  index ;} else
                                cout        <<      abs(saving_number[index])    
                                            <<      "x^" 
                                            <<      index ; } 
                                break;
            }
            if ( saving_number [index-1]  > 0 && ping_check == false ) { cout << "+" ;   } else 
            if ( saving_number [index-1]  < 0                        ) { cout << "-" ;   }   
        }
        if ( thread_check == true ) { cout << "0";}
        cout << endl;
        return;
}

int     main                               () {

        try{
        gethostname(hostname, sizeof(hostname));
        checking_system();

        cout  <<   "========================Chuong trinh tinh toan 2 da thuc========================"
              <<   endl;
        cout  <<   "+ Nhap Vao lua chon: "
              <<   endl 
              <<   "     1. Nhap lan luot."
              <<   endl
              <<   "     2. Nhap theo cum co dau ngoac."
              <<   endl 
              <<   "Lua chon:" ;
        cin   >>   menu_choice ;


        if (menu_choice == 1) {goto menu_one;}
        else {
                cout  <<  "+ Nhap vao cum chua dau ngoac : "; cin  >>  difficult_equation;
                string_split_ploy (difficult_equation); goto menu_two;
        }

        menu_one:

        cin.ignore(); cout  <<  endl;
        cout <<   "+ Nhap Vao da thuc dau tien:  ";
        cin.getline                   (first_equation,    size_equation);

        cout <<   endl
             <<   "+ Nhap Vao da thuc thu hai :  ";
        cin.getline                   (second_equation,   size_equation);

        menu_two:
        char *temp_equation_one = first_equation,
             *temp_equation_two = second_equation;

        temp_equation_one = add_one (first_equation);
        temp_equation_two = add_one (second_equation);

        strcpy(first_equation, temp_equation_one);
        strcpy(second_equation, temp_equation_two);

        temp_equation_one = process_string (first_equation);
        temp_equation_two = process_string (second_equation);

        strcpy(first_equation, temp_equation_one);
        strcpy(second_equation, temp_equation_two);
       
        temp_equation_one = identify_parentheses (first_equation);
        temp_equation_two = identify_parentheses (second_equation);
        strcpy(first_equation, temp_equation_one);
        strcpy(second_equation, temp_equation_two);

        temp_equation_one = add_one (first_equation);
        temp_equation_two = add_one (second_equation);

        strcpy(first_equation, temp_equation_one);
        strcpy(second_equation, temp_equation_two);


        temp_equation_one = process_string (first_equation);
        temp_equation_two = process_string (second_equation);

        strcpy(first_equation, temp_equation_one);
        strcpy(second_equation, temp_equation_two);

        
        solution_equation             (first_equation) ; 
        condition_global              =                  true; 
        solution_equation             (second_equation) ;

        thread loadingThread(loadingAnimation);
        this_thread::sleep_for(chrono::seconds(2));
        stopLoading = true;loadingThread.join();

        cout <<  "\r( Computer @ "
             <<  hostname
             <<  " ) Tinh toan hoan tat!          " << endl
             <<  "=============================================================================="
             <<   endl; 


        cout <<   "+ Phep nhan va chia:";

        
        int size_poly1  =  sizeof (saving_base_exponent_poly1) / sizeof (saving_base_exponent_poly1[0]);
        int size_poly2  =  sizeof (saving_base_exponent_poly2) / sizeof (saving_base_exponent_poly2[0]);


        int *prod = multiplyTwoPolynomials(saving_base_exponent_poly1, saving_base_exponent_poly2, size_poly1, size_poly2); 

        menu_multi:
	cout <<   endl
             <<   endl
             <<   "     - Nhan 2 da thuc:     "; 
        output_number (prod);
        if (thread_check == true) {cout << "0";}
        
//////////////////////////////////////////////////////////////////////////////////,,//////////////////////
        vector<double> coeffs_p2 (saving_base_exponent_poly1, 
                                  saving_base_exponent_poly1 + ++highest_exponent_poly1 );
        vector<double> coeffs_p1 (saving_base_exponent_poly2, 
                                  saving_base_exponent_poly2 + ++highest_exponent_poly2 );

        reverse(coeffs_p1.begin(), coeffs_p1.end());
        reverse(coeffs_p2.begin(), coeffs_p2.end());

        Polynomial p1 (coeffs_p1);
        Polynomial p2 (coeffs_p2);

        auto div        = p1 / p2;
        auto quotient   = div.first;
        auto remainder  = div.second;

        
        cout  <<   endl 
              <<   "     - Chia 2 da thuc:     " 
              <<   quotient 
              <<   endl 
              <<   endl 
              <<   "     - Phan du 2 da thuc:  " 
              <<   remainder 
              <<   endl;

////////////////////////////////////////////////////////////////////////////////////////////////////////
        cout  <<   endl 
              <<   "+ Phep cong va tru:" 
              <<   endl ;

        menu_add:
        cout  <<   endl 
              <<   "     - Cong 2 da thuc la:  ";  output_number (addition_saving_number);
        
        cout  <<   endl 
              <<   "     - Tru 2 da thuc la :  " ; output_number (subtraction_saving_number_result);

////////////////////////////////////////////////////////////////////////////////////////////////////////
        cout  <<   "====================================HET=======================================";

        } catch ( const exception& errors ) { cerr << "Chuong trinh loi : " << errors.what() << '\n'; }
        return 0;
} 
