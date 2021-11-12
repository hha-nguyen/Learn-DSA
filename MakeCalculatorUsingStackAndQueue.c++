#include <iostream>
#include <sstream>
#include <list>
#include <stack>
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <stdlib.h>
// Em su dung thuat toan Shunting-yard de giai (chuyen tu ky hieu inflix sang RPN (reverse Polish notation))
const int LEFT_ASSOC  = 0;    
const int RIGHT_ASSOC = 1; 

// Map cac toan tu khac nhau lai voi nhau: +, -, *, / etc  
typedef std::map< std::string, std::pair< int,int >> OpMap;   
typedef std::vector<std::string>::const_iterator cv_iter;
typedef std::string::iterator s_iter;

const OpMap::value_type assocs[] =   
    {  OpMap::value_type( "+", std::pair<int,int>( 0, LEFT_ASSOC ) ),    
        OpMap::value_type( "-", std::pair<int,int>( 0, LEFT_ASSOC ) ),      
        OpMap::value_type( "*", std::pair<int,int>( 5, LEFT_ASSOC ) ),      
        OpMap::value_type( "/", std::pair<int,int>( 5, LEFT_ASSOC ) ) };  

const OpMap opmap( assocs, assocs + sizeof( assocs ) / sizeof( assocs[ 0 ] ) );  

// kiem tra neu token truyen vao la dau ngoac don 
bool isParenthesis( const std::string& token)        
{        
    return token == "(" || token == ")";      
}      

// kiem tra neu token truyen vao la 1 toan tu      
bool isOperator( const std::string& token)        
{        
    return  token == "+" || token == "-" ||      
            token == "*" || token == "/";      
}      

// kiem tra tinh ket hop cua token truyen vao       
bool isAssociative( const std::string& token, const int& type)        
{            
    const std::pair<int,int> p = opmap.find( token )->second;        
    return p.second == type;        
}        

// so sanh quyen uu tien cua cac toan tu        
int cmpPrecedence( const std::string& token1, const std::string& token2 )        
{        
    const std::pair<int,int> p1 = opmap.find( token1 )->second;      
    const std::pair<int,int> p2 = opmap.find( token2 )->second;      
    return p1.first - p2.first;        
}        

// chuyen tu dinh dang inflix sang dinh dang RPN      
bool infixToRPN( const std::vector<std::string>& inputTokens,   
                const int& size,   
                std::vector<std::string>& strArray )        
{     
    bool success = true;    
    std::list<std::string> out;      
    std::stack<std::string> stack;      
    
    for ( int i = 0; i < size; i++ )        
    {      
        //duyet cac token  
        const std::string token = inputTokens[ i ];      
        // If token is an operator        
        if ( isOperator( token ) )  
        {                    

            const std::string o1 = token;        
            if ( !stack.empty() )    
            {    
                std::string o2 = stack.top();    
                while ( isOperator( o2 ) &&        
                        ( ( isAssociative( o1, LEFT_ASSOC ) &&  cmpPrecedence( o1, o2 ) == 0 ) ||    
                        ( cmpPrecedence( o1, o2 ) < 0 ) ) )    
                {        
                    // xoa o2 khoi stack, chuyen sang output queue;                        
                    stack.pop();      
                    out.push_back( o2 );                            
                    if ( !stack.empty() )     
                        o2 = stack.top();      
                    else   
                        break;    
                }         
            }    
            // dua o1 vao stack.     
            stack.push( o1 );        
        }        
        // neu token la dau ngoac mo thi dua vao stack.    
        else if ( token == "(" )        
        {        
            // dua token len dau (top) cua stack     
            stack.push( token );        
        }        
        // neu token la dau ngoac dong.         
        else if ( token == ")" )        
        {      
            // den khi top of stack la dau ngoac mo, xoa toan tu cua stack roi dua vao out queue   
            std::string topToken  = stack.top();  
            while ( topToken != "(" )        
            {                        
                out.push_back(topToken );        
                stack.pop();    
                if ( stack.empty() ) break;  
                topToken = stack.top();  
            }                                        
            // xoa dau ngoac mo khoi stack, nhung khong dua vao output queue.                              
            if ( !stack.empty() ) stack.pop();                             
            // neu stack khong tim thay dau ngoac mo, co nghia la input dua vao thieu dau               
            if ( topToken != "(" )    
            {                        
                return false;    
            }                                          
        }        
        // neu token la 1 so, dua vao output queue     
        else       
        {        
            out.push_back( token );        
        }        
    }      
    // lap den khi het toan tu token trong stack  
    while ( !stack.empty() )        
    {      
        const std::string stackToken = stack.top();    
        // neu stack khong tim thay dau ngoac mo, co nghia la input dua vao thieu dau 
        if ( isParenthesis( stackToken )   )  
        {    
            return false;    
        }    
        // xoa toan tu khoi stack va dua vao output queue  
        out.push_back( stackToken );                      
        stack.pop();      
    }        

    strArray.assign( out.begin(), out.end() );  
    
    return success;    
}        


double RPNtoDouble( std::vector<std::string> tokens )        
{        
    std::stack<std::string> st;              
    for ( int i = 0; i < (int) tokens.size(); ++i )        
    {       
        const std::string token = tokens[ i ];      
        // neu token khong phai NULL thi dua no vao stack       
        if ( !isOperator(token) )        
        {        
            st.push(token);        
        }        
        else       
        {  
            double result =  0.0;        
            const std::string val2 = st.top();      
            st.pop();      
            const double d2 = strtod( val2.c_str(), NULL );        

            if ( !st.empty() )  
            {  
                const std::string val1 = st.top();      
                st.pop();      
                const double d1 = strtod( val1.c_str(), NULL );     

                result = token == "+" ? d1 + d2 :        
                        token == "-" ? d1 - d2 :        
                        token == "*" ? d1 * d2 :        
                                        d1 / d2;        
            }  
            else 
            {  
                if ( token == "-" )  
                    result = d2 * -1;  
                else  
                    result = d2;  
            }  

            // dua ket qua vao stack      
            std::ostringstream s;      
            s << result;      
            st.push( s.str() );        
        }        
    }                
    return strtod( st.top().c_str(), NULL );      
}        

std::vector<std::string> getExpressionTokens(const std::string& expression )  
{  
    std::vector<std::string> tokens;        
    std::string str = "";    
    for ( int i = 0; i < (int) expression.length(); ++i )    
    {    
        const std::string token( 1, expression[ i ] );    
        if ( isOperator( token ) || isParenthesis( token ) )    
        {
            if ( !str.empty() )
            {
                tokens.push_back( str ) ;
            }
            str = "";               
            tokens.push_back( token );              
        }    
        else   
        {       
            // nhap so    
            if ( !token.empty() && token != " " )    
            {                   
                str.append( token );    
            }    
            else    
            {    
                if ( str != "" )    
                {    
                    tokens.push_back( str );        
                    str = "";    
                }    
            }
            //Neu chuoi khong ket thuc bang dau ')'
            if (expression[i+1] == 0) {
                tokens.push_back(str);
            }      
        }     
    }      
    return tokens;  
}

template<typename T, typename InputIterator>
void Print( const std::string& message,
            const InputIterator& itbegin,   
            const InputIterator& itend,   
            const std::string& delimiter)  
{  
    std::cout << message << std::endl;
    std::copy(itbegin,   
            itend,   
            std::ostream_iterator<T>(std::cout, delimiter.c_str()));  
    std::cout << std::endl;
}  

int main()        
{       
    std::string s;
    std::cin >> s;          
    Print<char, s_iter>( "Ham vua nhap la:", s.begin(), s.end(), "" );                
    //chuyen input thanh cac token     
    std::vector<std::string> tokens = getExpressionTokens( s );     
    Print<std::string, cv_iter>( "tokens:  ", tokens.begin(), tokens.end(), " " );                      
    // danh gia tinh kha thi cua ham input 
    std::vector<std::string> rpn;        
    if ( infixToRPN( tokens, tokens.size(), rpn ) )      
    {     
        double d = RPNtoDouble( rpn );      
        Print<std::string, cv_iter>( "RPN tokens:  ", rpn.begin(), rpn.end(), " " );
        std::cout << "Ket qua la: " << d << std::endl;      
    }      
    else     
    {      
        std::cout << "Input ban nhap khong dung" << std::endl;      
    }         
    return 0;        
}  