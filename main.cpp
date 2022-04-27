//
// Created by Kayla Ou on 4/26/22.

#include<iostream>
#include<string>

using namespace std;
int Basic_Roman_Numerals(char);
bool Check_Space(char);
int Roman_to_Decimal(char[]);
void Decimal_to_Roman(int);

int main(){
    char Roman_Numerals_Input[9];
    int Decimal_Input;

    cout<<"-----------------Roman Numerals Converter------------------"<<endl;
    cout<< "To convert to decimal number, please enter a Roman Numeral: "<<endl;
    cin>>Roman_Numerals_Input;
    cout<<"To convert to roman numeral, please enter a decimal number: "<<endl;
    cin>>Decimal_Input;

//Roman Numerals to Decimal
    Roman_to_Decimal(Roman_Numerals_Input);
//Decimal to Roman Numerals
    Decimal_to_Roman(Decimal_Input);



return 0;

}
int Basic_Roman_Numerals(char Input){

    int output=0;

    if(sizeof(Input)==1){
        if(Input =='I'){
            output=1;
        }
        else if(Input =='V'){
            output=5;
        }
        else if(Input =='X'){
            output=10;
        }
        else if(Input =='L'){
            output=50;
        }
        else if(Input =='C'){
            output=100;
        }
        else if(Input =='D'){
            output=500;
        }
        else if(Input =='M'){
            output=500;
        }
        else{
            cout<<"Invalid Input"<< endl;
        }
        return output;
    }


}
bool Check_Space(char Input){
    if(Input=='\0'){
        return true;
    }
    else
        return false;
}
int Roman_to_Decimal(char Roman_Numerals_Input[]){
    int Decimal_Result =0;
    if(Roman_Numerals_Input!=NULL){
        // size = 1
        if(sizeof(Roman_Numerals_Input)==1){

            Decimal_Result=Basic_Roman_Numerals(Roman_Numerals_Input[0]);
        }

            //size > 1
        else {
            for(unsigned int i=0; i<sizeof(Roman_Numerals_Input); i++){


                if(Roman_Numerals_Input[i]=='\0'){

                    break;
                }
                else if(i==0){
                    if(Basic_Roman_Numerals(Roman_Numerals_Input[i]) < Basic_Roman_Numerals(Roman_Numerals_Input[i+1])){
                        int sub_result=0;
                        sub_result = Basic_Roman_Numerals(Roman_Numerals_Input[i+1])-Basic_Roman_Numerals(Roman_Numerals_Input[i]);
                        Decimal_Result += sub_result;

                        i+=1;
                        if (Check_Space(Roman_Numerals_Input[i+1])==true){
                            break;
                        }
                    }
                    else{
                        Decimal_Result = Basic_Roman_Numerals(Roman_Numerals_Input[i]);
                    }

                }
                else{
                    //Subtraction
                    if(Basic_Roman_Numerals(Roman_Numerals_Input[i]) < Basic_Roman_Numerals(Roman_Numerals_Input[i+1])){
                        int sub_result=0;
                        sub_result = Basic_Roman_Numerals(Roman_Numerals_Input[i+1])-Basic_Roman_Numerals(Roman_Numerals_Input[i]);
                        Decimal_Result += sub_result;

                        i+=1;
                        if (Check_Space(Roman_Numerals_Input[i+1])==true){
                            break;
                        }

                    }
                        //addition
                    else{
                        Decimal_Result += Basic_Roman_Numerals(Roman_Numerals_Input[i]);


                    }
                }
            }
        }

    }
    cout<<"Decimal Output: "<<Decimal_Result<<endl;

}
void Decimal_to_Roman(int input){
    string Roman_Numerals_array[]={"M","D","C","L","X","V","I"};
    int values_array[]={1000,500,100,50,10,5,1};
    string Roman_Numerals_Result;

    for(unsigned int i=0; i<7; i++){
        while(input-values_array[i]>=0){
            Roman_Numerals_Result += Roman_Numerals_array[i];
            input-=values_array[i];
        }
    }
    cout<<"Roman Numerals Result: "<<Roman_Numerals_Result<<endl;
}