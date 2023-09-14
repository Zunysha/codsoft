 #include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <stdexcept>
using namespace std;




float stringToFloat(const std::string& str) 
{ 
    std::istringstream ss(str);
    float result;

    if (!(ss >> result)) {
        throw std::invalid_argument("Invalid conversion to float");
    }

    return result;
}

bool rightInput(const std::string& value) // check funcion
{ 
    std::istringstream ss(value);
    float value1;
    
    if (ss >> value1) {
        char left;
        if (!(ss >> left)) {
            return true; 
        }
    }
    
    return false; 
}


int main()
{
		cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
cout<<"\t\t\t\t\tBASIC CALCULATOR TO PERFORM BASIC OPERATIONS"<<endl;
cout<<"\t\t\t\t\t\t\t( +,-,*,/)"<<endl<<endl;
cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
	
	
	string num1,num2;
	float result;
	char op;
	char var;
	do{
	
	cout<<"ENTER EXPRESSION\n";
	abc:
	cin>>num1;
	
	if (!rightInput(num1))
	{
		cout<<"ENTER A NUMERIC VALUE ONLY TO PERFORM AN OPERATION\n";
		goto abc;
	}
	
		
		
	cin>>op;
	
	abc3:
	cin>>num2;
	if (!rightInput(num2))
	{
		cout<<"ENTER  NUMERIC VALUE ONLY TO PERFORM AN OPERATION\n";
		goto abc3;
	}
	
	
	

	
	float num11=stringToFloat(num1);
	float num22=stringToFloat(num2);
	
	switch(op){
		case '+':
			result=num11+num22;
			break;
			case '-':
				result=num11-num22;
				break;
				
					case'/':
						result=num11/num22;
						break;
						case '*':
						result=num11*num22;
						break;
						
						default:
							cout<<"NOT AN ARITHEMATIC OPERATION CHOOSE OPERATOR WISELY"<<endl;
							goto abc;
	}
	cout<<"RESULT:"<<result<<endl;
	cout<<"PRESS Y TO PERFORM ANOTHER CALCULATION OR PRESS ANYOTHER KEY TO EXIT"<<endl;
	cin>>var;
	cout<<endl;
}while(var=='y'|| var=='Y');
	
}