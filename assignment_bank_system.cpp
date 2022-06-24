#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<unordered_map>

#define ll long long int 
using namespace std;
ll acc_nu = 100000000000;
ll atm_nu = 1000000000000000;


ll arr[26];
int calander[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

// valid contact number 
bool isvalid_contact(string temp) {
    
    if(temp.size()!=10) return false;

    for(int i = 0 ; i <temp.size(); i++) {
        if(temp[i]-'0'>9 or temp[i]-'0'<0) return false;
    }

    return true;

} 

// valid year
bool isvalid_year(string temp) {
    
    if(temp>="2022" or temp <="1920") return false;
    for(int i = 0 ; i <temp.size(); i++) {
        if(temp[i]-'0'>9 or temp[i]-'0'<0) return false;
    }

    return true;

}

// valid month
bool isvalid_month(string x) {
    if(x>="1" and x<="12") return true;
    else return false;
}

// valid day
bool isvalid_day(string temp, int x) {

    if(temp.size()>2) return false;
    for(int i = 0 ; i <temp.size(); i++) {
        if(temp[i]-'0'>9 or temp[i]-'0'<0) return false;
    }

    int t = stoi(temp);
    if(t>0 and calander[x-1]>=t) return true;
    else return false;
}

// valid integer 
bool isvalid_int(string temp) {
    for(int i = 0 ; i < temp.size(); i++) {
        if(temp[i]-'0'>9 or temp[i]-'0'<0) return false;
    }

    return true;
}


class date{
    public :
    int date;
    int month;
    int year;
};

class user{
    public :
    string first_name;
    string sur_name ;
    string email;
    string adress ;
    string contact;
    date dob; 
    int total_balance ;

    user() {
        total_balance = 0;
    }

};



class user_saving{
    public:
    int account_number ;
    int balance;
    int atm_number ;
    date atm_expiry ;
    int cvv ; 
};

class user_current{
    public:
    int account_number;
    int balance;
};

class user_loan{
    public:
    int balance;
    int account_number;
    float total_loan;
    float home_loan;
    float car_loan;
    float personal_loan;
    float bussiness_loan;
    float total_interest;

    user_loan() {
        balance = 0;
        total_loan=0;
        home_loan=0;
        car_loan=0;
        personal_loan=0;
        bussiness_loan=0;
        total_interest=0;
    }

};

unordered_map<ll, user > user_detail; 
unordered_map<ll, user_saving> user_saving_detail;
unordered_map<ll, user_current> user_current_detail;
unordered_map<ll, user_loan> user_loan_detail;

// valid user_id
bool isvalid_userid(ll user_id){
    if(user_detail.find(user_id)==user_detail.end()) return true;
    else return false;
}

// check is there saving account for corresponding userid
bool have_saving_account(ll user_id){
    if(user_saving_detail.find(user_id)==user_saving_detail.end()) return true;
    else return false;
}

// check is there current account for corresponding userid
bool have_current_account(ll user_id) {
    if(user_current_detail.find(user_id)==user_current_detail.end()) return true;
    else return false;
}

// check is there loan account for corresponding userid
bool have_loan_account(ll user_id) {
    if(user_loan_detail.find(user_id)==user_loan_detail.end()) return true;
    else return false;
}

void default_info() {
    cout <<"Welcome to XYZ bank" << endl;
    cout << "Please Choose an option : " << endl ;
    cout << " 1. Create an account " << endl;
    cout << " 2. Balance Inquiry " << endl;
    cout << " 3. Deposit " << endl;
    cout << " 4. Withdraw " << endl;
    cout << " 5. Quit " << endl ;
    cout << " Enter : " ;
    return ;
}

//create user id 
int create_userid(string name){
    ll a = 0 ;
    for(int i = 0 ; i < name.size(); i++) {
        a+=arr[i];
    }
    return a ;
}

// create saving account
void saving_account() {
    
    cout << "Have you already an any existing account in this bank  : " << endl ;
    cout << "1. Yes " << endl ;
    cout << "2. No " << endl ;
    cout << "Enter : " ;
    int option ; cin >> option ;
    
    user u;
    if(option==2) {
        
        cout << "Enter your first name : ";
        cin >> u.first_name;
        cout << "Enter your sur name : ";
        cin >> u.sur_name; 
        cout << "Enter your mail : ";
        cin >> u.email; 
        cout << "Enter your adress : " ;
        cin >> u.adress ; 
        
        int x = 1; 
        while(x==1) {
            cout << "Enter your 10 digit mobile number : " ;
            cin>>u.contact;
            if(isvalid_contact(u.contact)) x=0;
            else {
                cout<<"Sorry, It is invalid contact number !!" <<endl;
                
            }
            
        }
        
        x=1;
        while(x==1){
            cout<< "Enter year of your DOB : " ;
            string temp;  cin >> temp;
            if(isvalid_year(temp)){ 
                u.dob.year = stoi(temp);
                x=0;
            }
            else{
                cout<<"Sorry, Invalid year !!" << endl;
    
            }
        }

        x=1;
        while(x==1){
            cout<< "Enter month of your DOB : " ;
            string temp; cin >> temp;
            if(isvalid_month(temp)) {
                u.dob.month = stoi(temp);
                x=0;
            }
            else{
                cout <<"Sorry , Invalid month !!" << endl;
            }

        }

        x=1;
        while(x==1){
            cout<< "Enter date of your DOB : " ;
            string temp ; cin >> temp;
            
            if( isvalid_day(temp, u.dob.month)) {
                u.dob.date = stoi(temp);
                x=0;
            }
            else {
                cout << "Sorry, Invalid date for this month !! " << endl;
            }
        }


        x=1 ; 
        while(x==1) {
            cout<<"Please, Deposit at least 100000 INR to open the saving account : " ;
            string amount ; cin >> amount;
            if( isvalid_int(amount) and   stoi(amount)>=10000 and (2022-u.dob.year>=18) ) {
                ll user_id = create_userid(u.first_name); 
                user_detail[user_id] = u;
                
                user_saving us;
                us.account_number = acc_nu;
                acc_nu = acc_nu+1;
                us.balance = stoi(amount);
                us.atm_number = atm_nu;
                atm_nu = atm_nu+1;
                us.cvv = (u.dob.year)/10;
                date d ;
                d.date = 12;
                d.month = 5;
                d.year = 2030;
                us.atm_expiry = d;
                
                user_saving_detail[user_id] = us;

                cout << "Hello, " << u.first_name << " your saving account number is : " << us.account_number << endl;
                cout << "Your balance is : " << us.balance << endl ;
                cout<< "Your atm number is : " << us.atm_number << endl ; 
                cout << "Your cvv is : " << us.cvv << endl ;
                x = 0;
            }
            else {
                cout<<"Sorry, You have either deposite less than 10000 or you are less than 18 years old " <<endl;
            };
        }
        
    }
    
    default_info();
    return ;
}

// Home loan 
void home_loan(ll user_id) {
    
    int x = 1 ; 
    while(x==1) {
        
        int amount, duration ; 
    
        cout << "Enter the amount needed : " ;
        cin >> amount ;
      
        cout << "Enter the loan duration in month " ; 
        cin >> duration ;
    
        int age  = (2022-user_detail[user_id].dob.year); 

        int total_amount = user_detail[user_id].total_balance;
    
        int minm_amount_for_loan = total_amount * 0.4;



        if(amount>=500000 and duration >=24 and age>=25 and amount<=minm_amount_for_loan ) {

            float total_principle =  amount * (1 + pow((float(7/2)), (duration/12) ));
            float interest = total_principle-amount;
            
            user_loan_detail[user_id].total_interest += interest;
            user_loan_detail[user_id].total_loan+=interest;
            user_loan_detail[user_id].home_loan = total_principle;

            x=0;

        }

        else{
            cout << "Sorry, you are not eligble for home loan ";
        } 

    }

}


// car loan 
void car_loan(ll user_id) {

}

// personal loan 
void personal_loan(ll user_id) {


}

// business loan
void business_loan(ll user_id) {


}


// Create Loan account 

void loan_account() {
    
    cout <<"Have you either saving account or current account in this bank ? " << endl ;
    cout << "1. YES " << endl ;
    cout << "2. No " << endl ;

    int option ; cin >> option ; 
    if(option==1) {
        
        int x = 1 ; 
        
        while(x==1) {
            cout << "Enter your user id : " << endl ;
            int user_id ; cin >> user_id ; 

            if(isvalid_userid(user_id)) {
                
                cout << "which type of loan do you want : " << endl ;
                cout << "1. Home Loan" << endl ;
                cout << "2. Car Loan" << endl ;
                cout << "3. Business Loan " <<endl;
                cout <<"4. Personal Loan" << endl ;
                cout << "Enter : " ;

                int t ; cin >> t ; 

                if(t==1) home_loan(user_id);
                else if(t==2) car_loan(user_id);
                else if(t==3) business_loan(user_id);
                else if(t==4) personal_loan(user_id);
                x=0;
            }

            else {
                cout << "Incorrect userid !! " ; 
            }

        }
        
    }


    else if(option==2) {
        cout << "Please first create any saving or current account" ; 
    }

    return ;
}




// create an account
void create_account( ) {
    cout << "choose to open different types of account " << endl ;
    cout << "1. saving account " << endl ;
    cout << "2. current account " << endl;
    cout <<"3. loan account " << endl ;
    cout << "Enter : " ;
    int option ; cin >> option;

    if(option==1) saving_account();
    //else if(option=2) current_account();
    //else if(option==3) loan_account();
    // else {

    // }
}


void balance_inquiry( ){
    
    int x = 1 ; 
    while(x==1){

        cout << "Enter your user id : " << endl;
        ll user_id ; cin >> user_id;
        
        if(isvalid_userid(user_id)) {
            
            cout << "Selection the option : " << endl;
            cout << "1. Saving Account Balance " << endl ;
            cout << "2. Current Account Balance " << endl ;
            cout <<"3. Loan Account Balance " << endl ;
            cout <<"4. Quit" << endl ; 
            cout <<"Enter : " << endl ;
            
            int p = 1; 
            
            while(p==1) {
                int option ; cin >> option ; 
                if(option==1) {
                // check saving account for corresponding userid
                    if(have_saving_account(user_id)) {
                       cout <<"Your Saving Balance is : " << user_saving_detail[user_id].balance;
        
                    }
                    else {
                    cout <<"Here is no saving account corrensponding your user id" <<endl;
                    p=0;
                    }

                }

                else if(option==2) {
                    if(have_current_account(user_id)) {
                    cout <<"Your Current Balance is : " << user_current_detail[user_id].balance;

                    }
                    else {
                    cout <<"Here is no current account corrensponding your user id" <<endl;
                    p=0;
                    }

                }

                else if(option==3) {
                    if(have_loan_account(user_id)) {
                    cout <<"Your Loan Balance is : " << user_loan_detail[user_id].balance;

                    }
                else {
                    cout <<"Here is no loan account for this user id" <<endl;
                    p=0;
                }

                }
                
                else if(option ==4) return ;

                else {
                    cout << "You choosed incorrect option" ; 
                    p=0;
                }

            }
               
        }

        else {
            cout <<"Sorry, It's incorrect user id !!" ;
            x = 0;
        }

    }
    
}

void deposit() {

        int x = 1; 
        while(x==1) {
            cout << "Please enter the user id : " << endl;
            ll user_id ; cin >> user_id ;
            if(isvalid_userid(user_id)) {
                cout<<"where do you want to deposit ?" << endl ;
                cout << "1. In saving account " << endl;
                cout << "2. In current account " << endl;
                cout << "3. In loan account " << endl;
                cout <<"4. Quit" <<endl ;
                cout << "Enter : " <<endl ;

                int option; cin >> option;

                int p = 1; 

                if(option==1){
                    
                    while(p==1) {
                        if(have_saving_account(user_id)==true) {
                            cout << "Enter deposit money : " ;
                            int amount ; cin >>amount; 
                            user_saving_detail[user_id].balance+=amount;
                            user_detail[user_id].total_balance+=amount;
                            cout <<"Hello " << user_detail[user_id].first_name << ", your balance is " << user_saving_detail[user_id].balance << endl;
                            p=0;
                        }
                        else {
                            cout << "There is no saving account for this user id " ;
                        }
                    }

                }

                else if(option==2){
                    p=1;
                    while(p==1) {
                        if(have_current_account(user_id)==true) {
                            cout << "Enter deposit money : " ;
                            int amount ; cin >>amount; 
                            user_current_detail[user_id].balance+=amount;
                            user_detail[user_id].total_balance+=amount;
                            cout <<"Hello " << user_detail[user_id].first_name << ", your balance is " << user_current_detail[user_id].balance << endl;
                            p=0;
                        }
                        else {
                            cout << "There is no current account for this user id " ;

                        }
                    }

                }

                else if(option==3){
                    p=1;
                    while(p==1) {
                        if(have_loan_account(user_id)==true) {
                            cout << "Enter deposit money : " ;
                            int amount ; cin >>amount; 
                            user_loan_detail[user_id].balance+=amount;
                            user_detail[user_id].total_balance+=amount;
                            cout <<"Hello " << user_detail[user_id].first_name << ", your balance is " << user_loan_detail[user_id].balance << endl;
                            p=0;
                        }
                        else {
                            cout << "There is no current account for this user id " ;

                        }
                    }

                }

                else  return ;
                x= 0;

            }
            
             else {
            cout << "It is incorrect user id : ";
            }
            
        }
 
}




int main() {
    
    arr[0] = 1; 

    for(int i =1; i<26; i++) {
        arr[i] = arr[i-1]*2 + (i+1) ;
    }
 
    default_info();
    
    int option ; cin >> option ;
    
    if(option==1) {
        create_account();
    }

    else if(option==2) balance_inquiry();
    else if(option==3) deposit();
    default_info();

    
    return 0 ;

}

