  /*
   ========Participated Group Members =========
   ========Name==================||======ID====
||    1. Henok Enyew ----------------1404188   ||
||	  2. Ephrem Kitachew-------------1404402   ||
||    3. Ermias Desalegn-------------1404196   ||
||	  4. Eyob Yihalem----------------1405506   ||
||    5. Ehenew Amogne---------------1404414   ||
||    6. Estifanos Kelemu------------1404642   ||
|| ============================================||
*/

#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
using namespace std;
struct customer{
  char firstName[30];
  char middleName[30];
  char sex;
  int  age;
  char phoneNumber[30];
  char driverLicenseNumber[30];
  char carType[30];
  char numberPlate[30];
  double rentalPrice;
  char rentalPeriod[30];
  customer *next;
};
struct customer *start=NULL;
int countAll=0;
void numberOfCustomers();
void searchByName();
void searchByAge();
void searchBySex();
void searchByPhone();
void searchByLicenseNumber();
void searchByCarType();
void searchByNumberPlate();
void searchByPrice();
void searchByPeriod();
void searchingLists();
void countNumberOfOccurrence();
void numberOfOccurrenceByAge();
void numberOfOccurrenceBySex();
void numberOfOccurrenceByCartype();
void numberOfOccurrenceByRentalPrice();
void numberOfOccurrenceByRentalPeriod();
void updatingFunction();
void updateFirstName();
void updateMiddleName();
void updateRentalPeriod();
void updateRentalPrice();
void updateCarType();
void updateDriverLicenseNumber();
void updatePlateNumber();
void updateSex();
void updatePhoneNumber();
void updateAge();
void display(customer *temp);
void sortingFunction();
void sort_by_phoneNumber();
void sort_by_sex();
void sort_by_rentalPrice();
void sort_by_numberPlate();
void sort_by_driverLicenseNumber();
void sort_by_age();
void sort_by_carType();
void sort_by_middleName();
void sort_by_firstName();
void display_node();
void swap(customer *,customer *);
void readFile();
void writeOnFile();
void displayFromFile();
void insertFromFile();
void notepadFile();
void menu();
void exit();
void insertData();
void insertAtEnd();
void insertAtMiddle();
void deleteAtBeginning();
void deleteAtEnd();
void deleteByName();
void deleteByAge();
void deleteBySex();
void deleteByPhone();
void deleteCarType();
void deleteByNumberPlate();
void deleteByRentalPrice();
void deleteByRentalPeriod();
void driverLicenseNumber();
void deleteNNode();
void minimumPrice();
void maximumPrice();
void averageAge(int n);
void averagePrice(int n);
void deleteMinimumAge();
void deleteMaximumAge();
void deleteFunction();
void deleteByFirstName();
void deleteByMiddleName();
void averagePrice(int countAll);
void averageAge(int countAll);
void sort_by_driverLicenseNumberTop();
void sort_by_middleNameTop();
void sort_by_firstNameTop();
void leastPeriodLists();
void TopPriced();
void FrequentlyNeededLists();
void sort_by_descending_rentalPrice();
void firstLicenseNumber();
void sort_by_decending_age();
void TopMiddleNameInAlphabet();
void TopNameInAlphabet();
void maxAgeList();
void infortmationOfANode(customer *ptr);
int main()
{
	cout<<"    ___________________________________________________________________________"<<endl;
	cout<<" /||                                                                           ||"<<endl;
	cout<<"||||        _______                                                            ||"<<endl;
	cout<<"||||    ___/|__|__|\\___       Welcome to Tana Car Rental Management System    ||"<<endl;
	cout<<"||||   |__   ______   _|<     ____________________________________________     ||"<<endl;
	cout<<"||||      (())    (())                                                         ||"<<endl;
	cout<<"||||                                                                           ||"<<endl;
	cout<<"||||___________________________________________________________________________||"<<endl;
	cout<<"||/___________________________________________________________________________//"<<endl<<endl;
	menu();
    return 0;
}
void exit(){
	cout<<"  _______________________________________________________"<<endl;
	cout<<"||                                                       ||"<<endl;
	cout<<"||  Thanks For Using Our Service, Please Come Back Soon. ||"<<endl;
	cout<<"||  ____________________________________________________ ||"<<endl;
	cout<<"||_______________________________________________________||"<<endl<<endl;
}
void menu(){
    int menuChoose;
    cout<<endl<<"\t Press 1 - to Read the file saved from Notepad."<<endl;
    cout<<"\t Press 2 - to Get a Sorted Data by Different Parametrs."<<endl;
    cout<<"\t Press 3 - to Search Data by Different Parametrs."<<endl;
    cout<<"\t Press 4 - to Get Top Ranked Lists."<<endl;
    cout<<"\t Press 5 - to Get Number of Occurrances."<<endl;
	cout<<"\t Press 6 - to Insert Data."<<endl;
	cout<<"\t Press 7 - to Delete Data."<<endl;
	cout<<"\t Press 8 - to get The Total number of Customers."<<endl;
	cout<<"\t Press 9 - to Update Customer's Data."<<endl;
	cout<<"\t Press 10 - to Save Customer's Data."<<endl;
	cout<<"\t Press 11 - to Exit"<<endl;
	cout<<"====>> ";
	cin>>menuChoose;
    cin.ignore();
    while(menuChoose<0 || menuChoose>11){
    	cout<<"Please Enter a valid number(1-11): ";
    	cin>>menuChoose;
    	cin.ignore();
	}
    switch(menuChoose){
        case 1:
            notepadFile();
            break;
        case 2:
        	sortingFunction();
        	break;
        case 3:
        	searchingLists();
        	break;
        case 4:
        	FrequentlyNeededLists();
        	break;
        case 5:
        	countNumberOfOccurrence();
        	break;
        case 6:
        	insertData();
        	break;
        case 7:
        	deleteFunction();
        	break;
        case 8:
        	cout<<"The total number of Customers is: "<<countAll<<endl;
        	menu();
        	break;
        case 9:
        	updatingFunction();
        	break;
        case 10:
        	writeOnFile();
        	break;
        case 11:
        	exit();
        	break;
    }
}
void notepadFile(){
    int size = 20;
    for(int i = 0;i<size;i++){
	insertFromFile();
    }
    readFile();
    displayFromFile();
    menu();
}
void insertFromFile(){
	struct customer *n = new customer;
	n->next=NULL;
	if(start==NULL)
		start=n;
	else{
		n->next=start;
		start=n;
	}
	countAll++;
}
void readFile(){
	struct customer *i=start;
	char fileName[20];
	ifstream readData;
	cout<<"Enter the name of file please: ";
	cin.getline(fileName,20);
	readData.open(fileName,ios::in);
	if(readData.fail()){
		int tryAgain;
		cout<<"The file is not found, \nPress 1 - to Try again\nPress 2 -  to return to the main menu: "<<endl;
		cin>>tryAgain;
		cin.ignore();
		if(tryAgain == 1){
			readFile();
			}
		else
			menu();
	}
	else{

		while(i!=NULL){
			while(!readData.eof()){
				readData>>i->firstName;
				readData>>i->middleName;
				readData>>i->sex;
				readData>>i->phoneNumber;
				readData>>i->driverLicenseNumber;
				readData>>i->carType;
				readData>>i->numberPlate;
				readData>>i->rentalPrice;
				readData>>i->rentalPeriod;
				readData>>i->age;
				i=i->next;
			}
		}
	}
}
void writeOnFile(){
	char fileName[30];
	cout<<"Enter the name of the file to store the Customers Data"<<endl;
	cin.getline(fileName,30);
	// creating an object to write on a text file;
      ofstream fout;
    //opening a text file with the name customerDocumentation is there is no it will create one with that name;
      fout.open(strcat(fileName , ".txt"));
      if(fout.fail()){
        cout<<"Error opening a file";
        menu();
        }
    else{
        for(struct customer *i=start;i!=NULL;i=i->next){
	        fout<<endl<<"------------------------------------------------------------------------------------------------------"<<endl;
	        fout<<"First Name of customer: "<<i->firstName<<endl;
	        fout<<"Middle Name of customer: "<<i->middleName<<endl;
	        fout<<"Sex: "<<i->sex<<endl;
	        fout<<"Phone-number: "<<i->phoneNumber<<endl;
	        fout<<"Customer's driver license number: "<<i->driverLicenseNumber<<endl;
	        fout<<"Type of car rented: "<<i->carType<<endl;
	        fout<<"Car number plate: "<<i->numberPlate<<endl;
	        fout<<"Price of rented Car: "<<i->rentalPrice<<endl;
	        fout<<"Start and end date of rented car: "<<i->rentalPeriod<<endl;
	        fout<<"Customer age: "<<i->age<<endl;
	        fout<<endl<<"------------------------------------------------------------------------------------------------------"<<endl;
	    }
    cout<<"The Customers Data Is Saved in "<<fileName<<endl;
    }
	fout.close();
	menu();
}
void displayFromFile(){
	if(start==NULL)
	cout<<"Cannot Display.";
	else{
		struct customer *temp=start;
		while(temp!=NULL){
			cout<<"||________________________________________________||"<<endl;
	        cout<<"||Name:\t\t\t"<<temp->firstName<<" "<<temp->middleName<<endl;
	        cout<<"||Sex:\t\t\t"<<temp->sex<<endl;
	        cout<<"||Age:\t\t\t"<<temp->age<<endl;
	        cout<<"||Phone No:\t\t"<<temp->phoneNumber<<endl;
	        cout<<"||License No:\t\t"<<temp->driverLicenseNumber<<endl;
	        cout<<"||Car type:\t\t"<<temp->carType<<endl;
	        cout<<"||Plate No:\t\t"<<temp->numberPlate<<endl;
	        cout<<"||Rental price:\t\t"<<temp->rentalPrice<<endl;
	        cout<<"||Rental period:\t"<<temp->rentalPeriod<<endl;
	        cout<<"||________________________________________________||"<<endl;
				temp=temp->next;
		}
	}
}
//This function prompts the user to enter his/her choice of data member by which the sorting is to be done
//All the sorting functions,defined here, sort in ascending order
void sortingFunction()
{
	int choice;
	cout<<"\n\nDo you want to :"<<endl;
	cout<<"\t1.Sort by first name"<<endl;
	cout<<"\t2.Sort by middle name"<<endl;
	cout<<"\t3.Sort by age"<<endl;
	cout<<"\t4.Sort by driver license number"<<endl;
	cout<<"\t5.Sort by plate number"<<endl;
	cout<<"\t6.Sort by rental price"<<endl;
	cout<<"\t7.Sort by sex(group customers with the same sex together)"<<endl;
	cout<<"\t8.Sort by phone number"<<endl;
	cout<<"\t9.Sort by car type"<<endl;
	cout<<"\t10. to Get back to Main Menu"<<endl;
	cout<<"Enter your choice: ";
	cin>>choice;
	while(choice<1||choice>10)
	{
		cout<<"Please enter a valid number(1-10):";
		cin>>choice;
	}
	switch(choice)
	{
		case 1:
			sort_by_firstName();
			break;
	    case 2:
		    sort_by_middleName();
		    break;
		case 3:
		    sort_by_age();
		    break;
		case 4:
			sort_by_driverLicenseNumber();
		    break;
		case 5:
			sort_by_numberPlate();
		    break;
		case 6:
			sort_by_rentalPrice();
		    break;
		case 7:
			sort_by_sex();
		    break;
		case 8:
			sort_by_phoneNumber();
		    break;
		case 9:
		    sort_by_carType();
			break;
		case 10:
			menu();
			break;
		default:
		break;
	}
}
void swap(customer *i,customer *j)
{
	//declare a temporary pointer and allocate dynamically
	customer *temp;
	temp=new customer;
	//give the value of the first pointer to the temporary pointer
    strcpy(temp->firstName,i->firstName);
	strcpy(temp->middleName,i->middleName);
	temp->sex=i->sex;
	temp->age=i->age;
	strcpy(temp->phoneNumber,i->phoneNumber);
	strcpy(temp->carType,i->carType);
	strcpy(temp->driverLicenseNumber,i->driverLicenseNumber);
	strcpy(temp->numberPlate,i->numberPlate);
	strcpy(temp->rentalPeriod,i->rentalPeriod);
	temp->rentalPrice=i->rentalPrice;
	//	assign the contents of the second ponter to the first pointer
	strcpy(i->firstName,j->firstName);
	strcpy(i->middleName,j->middleName);
	i->sex=j->sex;
	i->age=j->age;
	strcpy(i->phoneNumber,j->phoneNumber);
	strcpy(i->carType,j->carType);
	strcpy(i->driverLicenseNumber,j->driverLicenseNumber);
	strcpy(i->numberPlate,j->numberPlate);
	strcpy(i->rentalPeriod,j->rentalPeriod);
	i->rentalPrice=j->rentalPrice;
	//	assign the information of the temporary pointer to the first parameter
	strcpy(j->firstName,temp->firstName);
	strcpy(j->middleName,temp->middleName);
	j->sex=temp->sex;
	j->age=temp->age;
	strcpy(j->phoneNumber,temp->phoneNumber);
	strcpy(j->carType,temp->carType);
	strcpy(j->driverLicenseNumber,temp->driverLicenseNumber);
	strcpy(j->numberPlate,temp->numberPlate);
	strcpy(j->rentalPeriod,temp->rentalPeriod);
	j->rentalPrice=temp->rentalPrice;
	// delete the temp pointer so that dynamic memory will be freed
	delete temp;
}
void sort_by_firstName()
{
	customer *temp;
	if(start==NULL)
	{
		cout<<"List is empty!"<<endl;// check if the list is empty
		sortingFunction();
	}
	else
	{
		//use simple sorting algorithm style to compare the strings
		for(customer *i=start;i->next!=NULL;i=i->next)
		{
			for(customer *j=i->next;j!=NULL;j=j->next)
			{
				//strcmp returns a positive value if the first parameter is greater than the second
				if(strcmp(i->firstName,j->firstName)>0)
				{
					swap(i,j);//call the swapping function to swap the contents
				}
			}
		}
		display_node();
	}
}
void sort_by_phoneNumber()
{
	customer *temp;
	if(start==NULL)
	{
		cout<<"List is empty!"<<endl; // check whether the list is empty
		sortingFunction();
	}
	else
	{
		//use simple sorting algorithm style to compare the strings
		for(customer *i=start;i->next!=NULL;i=i->next)
		{
			for(customer *j=i->next;j!=NULL;j=j->next)
			{
				//strcmp returns a positive value if the first parameter is greater than the second
				if(strcmp(i->phoneNumber,j->phoneNumber)>0)
				{
					swap(i,j);
				}
			}
		}
		display_node();
	}
}
void sort_by_carType()
{
	customer *temp;
	if(start==NULL)
	{
		cout<<"List is empty!"<<endl; // check whether the list is empty
        sortingFunction();
	}
	else
	{
		//use simple sorting algorithm style to compare the strings
		for(customer *i=start;i->next!=NULL;i=i->next)
		{
			for(customer *j=i->next;j!=NULL;j=j->next)
			{
				//strcmp returns a positive value if the first parameter is greater than the second
				if(strcmp(i->carType,j->carType)>0)
				{
					swap(i,j);
				}
			}
		}
		display_node();
	}
}
void sort_by_numberPlate()
{
	customer *temp;
	if(start==NULL)
	{
		cout<<"List is empty!"<<endl; // check whether the list is empty
		sortingFunction();
		}
	else
	{
		//use simple sorting algorithm style to compare the strings
		for(customer *i=start;i->next!=NULL;i=i->next)
		{
			for(customer *j=i->next;j!=NULL;j=j->next)
			{
				//strcmp returns a positive value if the first parameter is greater than the second
				if(strcmp(i->numberPlate,j->numberPlate)>0)
				{
					swap(i,j);
				}
			}
		}
		display_node();
	}
}
void sort_by_driverLicenseNumber()
{
	customer *temp;
	if(start==NULL)
	{
		cout<<"List is empty!"<<endl; // check whether the list is empty
		sortingFunction();
	}
	else
	{
		//use simple sorting algorithm style to compare the strings
		for(customer *i=start;i->next!=NULL;i=i->next)
		{
			for(customer *j=i->next;j!=NULL;j=j->next)
			{
				//strcmp returns a positive value if the first parameter is greater than the second
				if(stricmp(i->driverLicenseNumber,j->driverLicenseNumber)>0)
				{
					swap(i,j);
				}
			}
		}
		display_node();
}
}
void sort_by_rentalPrice()
{
	customer *temp;
	if(start==NULL)
	{
		cout<<"List is empty!"<<endl; // check whether the list is empty
		sortingFunction();
	}
	else
	{
		//use simple sorting algorithm style to compare the strings
		for(customer *i=start;i->next!=NULL;i=i->next)
		{
			for(customer *j=i->next;j!=NULL;j=j->next)
			{
				if(i->rentalPrice > j->rentalPrice)
				{
					swap(i,j);
				}
			}
		}
		display_node();
	}
}
void sort_by_age()
{
	customer *temp;
	if(start==NULL)
	{
		cout<<"List is empty!"<<endl; // check whether the list is empty
		sortingFunction();
	}
	else
	{
		//use simple sorting algorithm style to compare the strings
		for(customer *i=start;i->next!=NULL;i=i->next)
		{
			for(customer *j=i->next;j!=NULL;j=j->next)
			{
				if(i->age>j->age)
				{
					swap(i,j);
				}
			}
		}
		display_node();
	}
}
//this function actually groups customers with the same sex together
void sort_by_sex()
{
	customer *temp;
	if(start==NULL)
	{
		cout<<"List is empty!"<<endl; // check whether the list is empty
		sortingFunction();
	}
	else
	{
		//use simple sorting algorithm style to compare the strings
		for(customer *i=start;i->next!=NULL;i=i->next)
		{
			for(customer *j=i->next;j!=NULL;j=j->next)
			{
				if(i->sex>j->sex)
				{
					swap(i,j);
				}
			}
		}
		display_node();
	}
}
void sort_by_middleName()
{
	customer *temp;
	if(start==NULL)
	{
		cout<<"List is empty!"<<endl; // check whether the list is empty
		sortingFunction();
	}
	else
	{
		//use simple sorting algorithm style to compare the strings
		for(customer *i=start;i->next!=NULL;i=i->next)
		{
			for(customer *j=i->next;j!=NULL;j=j->next)
			{
				if(strcmp(i->middleName,j->middleName)>0)
				{
					swap(i,j);
				}
			}
		}
		display_node();
	}
}
void display_node()
{
 customer *temp;
 temp=new customer;
 if(start==NULL)
 {
 	    cout<<"List is empty!"<<endl;
 		menu();
 }
 else
 {
  temp=start;
  while(temp!=NULL)
  {
        cout<<"||________________________________________________||"<<endl;
        cout<<"||Name:\t\t\t"<<temp->firstName<<" "<<temp->middleName<<endl;
        cout<<"||Sex:\t\t\t"<<temp->sex<<endl;
        cout<<"||Age:\t\t\t"<<temp->age<<endl;
        cout<<"||Phone No:\t\t"<<temp->phoneNumber<<endl;
        cout<<"||License No:\t\t"<<temp->driverLicenseNumber<<endl;
        cout<<"||Car type:\t\t"<<temp->carType<<endl;
        cout<<"||Plate No:\t\t"<<temp->numberPlate<<endl;
        cout<<"||Rental price:\t\t"<<temp->rentalPrice<<endl;
        cout<<"||Rental period:\t"<<temp->rentalPeriod<<endl;
        cout<<"||________________________________________________||"<<endl;
      temp=temp->next;
  }
 }
 menu();
}
void infortmationOfANode(customer *ptr){
	            cout<<"\nThe customer's information you searched for is displayed as:";
	 			cout<<"\n___________________________________________"<<endl;
				cout<<"||Full Name:\t\t"<<ptr->firstName <<" "<<ptr->middleName<<endl;
                cout<<"||Sex:\t\t\t"<<ptr->sex<<endl;
                cout<<"||Age:\t\t\t"<<ptr->age<<endl;
                cout<<"||Phone No:\t\t"<<ptr->phoneNumber<<endl;
                cout<<"||License No:\t\t"<<ptr->driverLicenseNumber<<endl;
                cout<<"||Car type:\t\t"<<ptr->carType<<endl;
                cout<<"||Plate No:\t\t"<<ptr->numberPlate<<endl;
                cout<<"||Rental price:\t\t"<<ptr->rentalPrice<<endl;
                cout<<"||Rental period:\t"<<ptr->rentalPeriod<<endl;
                cout<<"||___________________________________________"<<endl<<endl;
}
void searchByName (){
    char FirstName[30];
    char MiddleName[30];
    cout<<"Enter first name of the customer that you want to search in the data list. ";
    cin>>FirstName;
    cout<<"Enter middle name of the customer that you want to search in the data list. ";
    cin>>MiddleName;
    int key = 0;
    customer * ptr;   //pointer "ptr" is needed to search the customer's data one by one starting from start since we assign it as start.
    if (start == NULL){ // case when we have nothing as a start or no data available.
        cout <<"the list is empty and you have nothing to search. ";
    }
    else {
        for (ptr=start; ptr != NULL;ptr=ptr->next){
            if((stricmp(FirstName, ptr->firstName)==0) && (stricmp(MiddleName , ptr->middleName)==0)) //This function inside the if clause is used to compare 2 strings;
            {
                key = 1;
               infortmationOfANode(ptr);
            }
        }
        if (key == 0) {
            cout <<"The customer with this full name is not found in the list "<<endl;
            searchingLists();
        }
        else{
            cout<<"The information with a name that are similar to "<<FirstName<<" "<<MiddleName<<" are all this."<<endl;
            searchingLists();
        }
    }
}

void searchByAge(){
    int age;
    cout<<"Enter age of the customer: ";
    cin>>age;
    int key = 0;
    customer * ptr;   //pointer "ptr" is needed to search the customer's data one by one starting from start since we assign it as start.
    if (start == NULL){
        cout <<"the list is empty and you've nothing to search. ";
    }
    else {
        for (ptr=start; ptr!=NULL; ptr=ptr->next){
            if(age==ptr->age)
            {
                key = 1;
                   infortmationOfANode(ptr);
            }
        }
        if (key == 0) {
            cout <<"The customer with this age is not found in the list ";
            searchingLists();
        }
        else {
                cout<<"This are all the customers data with the age you entered "<<endl;
                searchingLists();
            }
        }
}
void searchBySex(){
    char customerSex;
    cout<<"Enter sex of the customer that you want to search, 'm' for male and 'f' for female: ";
    cin>>customerSex;
    int key = 0;
    customer * ptr;   //pointer "ptr" is needed to search the customers data by one by one starting from start since we assign it as start.
    if (start == NULL){
        cout <<"the list is empty and you have nothing to search. ";
    }
    else {
        for (ptr=start; ptr!=NULL; ptr=ptr->next){
            if(tolower(customerSex)==ptr->sex || toupper(customerSex)==ptr->sex)
            {
                key = 1; // when it is 1, it means that we have at least got 1 user in our customer data.
                infortmationOfANode(ptr);
            }
        }
        if (key == 0) { //when the key is as we first initialized there is no user the input sex.
            cout <<"The customer with this sex is not found in the list ";
            searchingLists();
        }
        else {
                cout<<"This are all the customers data with the same`sex that you wanted to search "<<endl;
                searchingLists();
            }
        }
}
void searchByPhone(){
    char phone[30];
    cout<<"Enter phone number of the customer that you want to search in the data list. ";
    cin>>phone;
    int key = 0;
    customer * ptr;   //pointer "ptr" is needed to search the customer's data one by one starting from start since we assign it as start.
    if (start == NULL){ // case when we have nothing as a start or no data available.
        cout <<"the list is empty and you have nothing to search. ";
    }
    else {
        for (ptr=start; ptr != NULL;ptr=ptr->next){
            if(stricmp(phone, ptr->phoneNumber)==0) //This function inside the if clause is used to compare 2 strings in this case the user's input and the phone numbers in the data list.
            {
                key = 1;
                infortmationOfANode(ptr);
				break; //expecting 1 customer information with 1 phone number
                //phone number is unique
            }
        }
        if (key == 0) {
            cout <<"The customer with this phone number is not found in the list "<<endl;
            searchingLists();
        }
        else { //this is when key is updated to 1,this happens only when the same phone number is found.
            cout<<"the user with a phone number of " <<phone<< " is found."<<endl;
            searchingLists();
            }
        }
}
void searchByLicenseNumber(){
    char licenseNumber[30];
    cout<<"Enter customer's license number that you want to search in the data list. ";
    cin>>licenseNumber;
    int key = 0; //To know if there is the same data item, which if this variable end up as 1 we get at least 1 data item similar.
    customer * ptr;   //pointer "ptr" is needed to search the customer's data one by one starting from start since we assign it as start.
    if (start == NULL){ // case when we have nothing as a start or no data available.
        cout <<"the list is empty and you have nothing to search. ";
    }
    else {
        for (ptr=start; ptr != NULL;ptr=ptr->next){
            if(stricmp(licenseNumber, ptr->driverLicenseNumber)==0) //This function inside the if clause is used to compare 2 strings in this case the user's input and the phone numbers in the data list.
            {
                key = 1;
                infortmationOfANode(ptr);
                break; //since we are expecting 1 customer information with in one licence number...
                //licence number is unique
            }
        }
        if (key == 0) {
            cout <<"The customer/driver with this license number is not found in the list "<<endl;
            searchingLists();
        }
        else { //this is when key is updated to 1,this happens only when the same phone number is found.
            cout<<"the user with a license number of " <<licenseNumber<< " is found."<<endl;
            searchingLists();
            }
        }
}
void searchByCarType(){
    char CarType[30];
    cout<<"Enter the type of car that you want to search: ";
    cin>>CarType;
    int key = 0;
    customer * ptr;   //pointer "ptr" is needed to search the customers data by one by one starting from start since we assign it as start.
    if (start == NULL){
        cout <<"the list is empty and you have nothing to search. ";
    }
    else {
        for (ptr=start; ptr!=NULL; ptr=ptr->next){
            if(stricmp(CarType,ptr->carType)==0)
            {
                key = 1; // we don't use a break statement after this because we might want to display all the cars with that type not just 1...
                infortmationOfANode(ptr);
            }
        }
        if (key == 0) { //when the key is as we first initialized there is no user the input sex.
            cout <<"The car with this type is not found in the list "<<endl;
            searchingLists();

        }
        else {
                cout<<"This are all the whole cars with the type that you wanted to search "<<endl;
                searchingLists();
            }
        }
}
void searchByNumberPlate(){
    char carNumberPlate[30];
    cout<<"Enter the number plate of the car that you want to search: ";
    cin>>carNumberPlate;
    int key = 0;
    customer * ptr;   //pointer "ptr" is needed to search the customers data by one by one starting from start since we assign it as start.
    if (start == NULL){
        cout <<"the list is empty and you have nothing to search. ";
    }
    else {
        for (ptr=start; ptr!=NULL; ptr=ptr->next){
            if(strcmp(carNumberPlate,ptr->numberPlate)==0)
            {
                key = 1; // when it is 1, it means that we have at least got 1 user in our customer data.
               infortmationOfANode(ptr);
			    break; //since we would have only 1 information about 1 number plate at a time.
                //number plate is unique
            }
        }
        if (key == 0) { //when the key is as we first initialized there is no user the input sex.
            cout <<"The car with this number plate is not found in the list "<<endl;
        }
        else {
               searchingLists();
            }
        }
}
void searchByPrice(){
    double price;
    cout<<"Enter rental price you wanted to find : ";
    cin>>price;
    int key = 0;
    customer * ptr;   //pointer "ptr" is needed to search the customer's data one by one starting from start since we assign it as start.
    if (start == NULL){
        cout <<"the list is empty and you've nothing to search. ";
    }
    else {
        for(ptr=start; ptr!=NULL; ptr=ptr->next){
            if(price == ptr->rentalPrice)
            {
                key = 1;
                infortmationOfANode(ptr);
				  }
        }
        if (key == 0) {
            cout <<"The customer data with this rental price is not found in the list "<<endl;
             searchingLists();
        }
        else {
                cout<<"This are all the customers data with a price that you entered "<<endl;
                searchingLists();
            }
        }
}
void searchByPeriod(){
    char period[30];
    cout<<"Enter the time period for the rent : ";
    cin>>period;
    int key = 0;
    customer * ptr;   //pointer "ptr" is needed to search the customers data by one by one starting from start since we assign it as start.
    if (start == NULL){
        cout <<"the list is empty and you have nothing to search. ";
    }
    else {
        for (ptr=start; ptr!=NULL; ptr=ptr->next){
            if(stricmp(period,ptr->rentalPeriod)==0)
            {
                key = 1; // we don't use a break statement after this because we might want to display all data with that period since we may have many other with the same period...
                infortmationOfANode(ptr);
            }
        }
        if (key == 0) { //when the key is as we first initialized there is no user the input sex.
            cout <<"The period you are searching is not found in the list "<<endl<<endl;
             searchingLists();
        }
        else {
                cout<<"This are all the data with the period that you wanted to search "<<endl;
                searchingLists();
            }
        }
}
void minimumPrice() {
    if (start == NULL) {
        cout << "No customer data available" << endl;
        searchingLists();
    }
    else {
        struct customer *temp = start;
        struct customer *minCustomer = temp;
        double minPrice = temp->rentalPrice;
        for (temp = start; temp != NULL; temp = temp->next) {
            if (temp->rentalPrice < minPrice) {
                minPrice = temp->rentalPrice;
                minCustomer = temp;
            }
        }
        cout<<"\n\nThe data of a Customer with Minimum Price: \n";
        cout << "\n________________________________________" << endl;
       	infortmationOfANode(minCustomer);
       	searchingLists();
    }

}
void maximumPrice() {
    if (start == NULL) {
        cout << "No customer data available" << endl;
        searchingLists();
    }
    else {
        struct customer *temp = start;
        struct customer *maxCustomer = temp;
        double maxPrice = temp->rentalPrice;
        for (temp = start; temp != NULL; temp = temp->next) {
            if (temp->rentalPrice > maxPrice) {
                maxPrice = temp->rentalPrice;
                maxCustomer = temp;
            }
        }
        cout << "\n\n____________________________________________" << endl;
        cout << "Customer with maximumrental price:" << endl;
        infortmationOfANode(maxCustomer);
        searchingLists();
    }
}

void averageAge(int n) {
    if (start == NULL) {
        cout << "No customer data available." << endl;
        searchingLists();
    }
    double sum = 0;
    struct customer *temp = start;
    while(temp != NULL) {
        sum += temp->age;
        temp = temp->next;
    }
    cout << "\n\nThe average age of all customers is: " << sum/n << "." << endl;
    searchingLists();
}
void averagePrice(int n) {      //function of average of rental prcice of the customer;
    if (start == NULL) {
        cout << "No customer data available." << endl;
    	searchingLists();
    }
    double sum = 0;
    struct customer *temp = start;
    while(temp != NULL) {
        sum += temp->rentalPrice;
        temp = temp->next;
    }
    cout << "\n\nThe average rental price of all customers is: " << sum/n << "." << endl;
    searchingLists();
}
void searchingLists(){
    int choice;
    cout<<"\nDo you wannt to:"<<endl;
    cout<<"\t 1.Search by name."<<endl;
    cout<<"\t 2.Search by age."<<endl;
    cout<<"\t 3.Search by sex."<<endl;
    cout<<"\t 4.Search by phone."<<endl;
    cout<<"\t 5.Search by license number."<<endl;
    cout<<"\t 6.Search by car type."<<endl;
    cout<<"\t 7.Search by vehicle number plate."<<endl;
    cout<<"\t 8.Search by price."<<endl;
    cout<<"\t 9.Search by period."<<endl;
    cout<<"\t 10.Search Minimum Price."<<endl;
    cout<<"\t 11.Search Maximum Price."<<endl;
    cout<<"\t 12.Search Average Price."<<endl;
    cout<<"\t 13.Search Average Age."<<endl;
	cout<<"\t 14.To Get Back to the Main Menu"<<endl;
    cout<<"Enter a valid value according to the above numbers: ";
    cin>>choice;
    while(choice<1||choice>14){
        cout<<"Please enter a valid value between 1 and 14: ";
        cin>>choice;
    }
    switch (choice){
        case 1:
            searchByName();
            break;
        case 2:
            searchByAge();
            break;
        case 3:
            searchBySex();
            break;
        case 4:
            searchByPhone();
            break;
        case 5:
            searchByLicenseNumber();
            break;
        case 6:
            searchByCarType();
            break;
        case 7:
            searchByNumberPlate();
            break;
        case 8:
            searchByPrice();
            break;
        case 9:
            searchByPeriod();
            break;
        case 10:
        	minimumPrice();
        	break;
        case 11:
        	maximumPrice();
        	break;
       case 12:
	   		averagePrice(countAll);
			break;
       case 13:
        	averageAge(countAll);
            break;
        case 14:
        	menu();
        default:
            break;
    }
}
void sort_by_firstNameTop()
{
	customer *temp;
	if(start==NULL)
	{
		cout<<"List is empty!"<<endl;// check if the list is empty
		sortingFunction();
	}
	else
	{
		//use simple sorting algorithm style to compare the strings
		for(customer *i=start;i->next!=NULL;i=i->next)
		{
			for(customer *j=i->next;j!=NULL;j=j->next)
			{
				//strcmp returns a positive value if the first parameter is greater than the second
				if(stricmp(i->firstName,j->firstName)>0)
				{
					swap(i,j);//call the swapping function to swap the contents
				}
			}
		}
	}
}
void TopNameInAlphabet() {
    customer* ptr = start;
    int count = 0;
    sort_by_firstNameTop();
    int n;
    cout<<"Enter how many customers you want to see at most: ";
    cin>>n;
     while(n<0){
    	cout<<"Please Enter the valid Number: ";
    	cin>>n;
	}
    while (ptr != NULL && count < n) {
        infortmationOfANode(ptr);
        ptr = ptr->next;
        count++;
    }
    cout<<"Successfully displayed top customers in alphabetical order of their first name "<<endl<<endl;
    FrequentlyNeededLists();
}
void sort_by_middleNameTop()
{
	customer *temp;
	if(start==NULL)
	{
		cout<<"List is empty!"<<endl; // check whether the list is empty
		sortingFunction();
	}
	else
	{
		//use simple sorting algorithm style to compare the strings
		for(customer *i=start;i->next!=NULL;i=i->next)
		{
			for(customer *j=i->next;j!=NULL;j=j->next)
			{
				if(stricmp(i->middleName,j->middleName)>0)
				{
					swap(i,j);
				}
			}
		}
	}
}
void TopMiddleNameInAlphabet() {
    customer* ptr = start;
    int count = 0;
    sort_by_middleNameTop();
    int n;
    cout<<"Enter how many customers you want to see at most: ";
    cin>>n;
     while(n<0){
    	cout<<"Please Enter the valid Number: ";
    	cin>>n;
	}
    while (ptr != NULL && count < n) {
        infortmationOfANode(ptr);
        ptr = ptr->next;
        count++;
    }
    cout<<"Successfully displayed in alphabetical order of their middle name. "<<endl<<endl;
    FrequentlyNeededLists();
}
void sort_by_decending_age(){
	customer *temp;
	if(start==NULL)
	{
		cout<<"List is empty!"<<endl; // check whether the list is empty
	}
	else
	{
		//use simple sorting algorithm style to compare the strings
		for(customer *i=start;i->next!=NULL;i=i->next)
		{
			for(customer *j=i->next;j!=NULL;j=j->next)
			{
				if(i->age<j->age)
				{
					swap(i,j);
				}
			}
		}
	}
}
void maxAgeList(){
      customer* ptr = start;
    int count = 0;
    sort_by_decending_age(); //we call this function to sort it first.
    int n;
    cout<<"Enter how many customers you want to see at most: ";
    cin>>n;
     while(n<0){
    	cout<<"Please Enter the valid Number: ";
    	cin>>n;
	}
    while (ptr != NULL && count < n) {
        infortmationOfANode(ptr);
        ptr = ptr->next; //the pointer iterates to access the data items one after the other till it becomes null.
        count++;
    }
    cout<<"Successfully displayed customers starting from the maximum age in descending order. "<<endl<<endl;
    FrequentlyNeededLists();
}
void sort_by_driverLicenseNumberTop()
{
	customer *temp;
	if(start==NULL)
	{
		cout<<"List is empty!"<<endl; // check whether the list is empty
		sortingFunction();
	}
	else
	{
		//use simple sorting algorithm style to compare the strings
		for(customer *i=start;i->next!=NULL;i=i->next)
		{
			for(customer *j=i->next;j!=NULL;j=j->next)
			{
				//strcmp returns a positive value if the first parameter is greater than the second
				if(stricmp(i->driverLicenseNumber,j->driverLicenseNumber)>0)
				{
					swap(i,j);
				}
			}
		}
}
}
void firstLicenseNumber(){
    customer* ptr = start;
    int count = 0;
    sort_by_driverLicenseNumberTop();
    int n;
     while(n<0){
    	cout<<"Please Enter the valid Number: ";
    	cin>>n;
	}
    cout<<"Enter how many customers you want to see at most. ";
    cin>>n;
    while (ptr != NULL && count < n) {
        infortmationOfANode(ptr);
        ptr = ptr->next;
        count++;
    }
    cout<<"Successfully displayed customers in ascending alphabetical order of their licence number. "<<endl;
    FrequentlyNeededLists();
}
void sort_by_descending_rentalPrice(){
	customer *temp;
	if(start==NULL)
	{
		cout<<"List is empty!"<<endl; // check whether the list is empty
	}
	else
	{
		//use simple sorting algorithm style to compare the strings
		for(customer *i=start;i->next!=NULL;i=i->next)
		{
			for(customer *j=i->next;j!=NULL;j=j->next)
			{
				if(i->rentalPrice < j->rentalPrice)
				{
					swap(i,j);
				}
			}
		}
	}
}
void TopPriced(){
    customer* ptr = start;
    int count = 0;
    int n;
    cout<<"Enter how many customers you want to see at most. ";
    cin>>n;
    while(n<0){
    	cout<<"Please Enter the valid Number: ";
    	cin>>n;
	}
    sort_by_descending_rentalPrice();
    while ((ptr != NULL) && (count <n) ) {
        infortmationOfANode(ptr);
        ptr = ptr->next;
        count++;
    }
    cout<<"This are all we can display with the highest rental price. "<<endl<<endl;
    FrequentlyNeededLists();
}
void FrequentlyNeededLists(){
    int choice;
    cout<<"\t 1.Customer data lists by ascending order of their first name."<<endl;
    cout<<"\t 2.Customer data lists by ascending order of their middle name."<<endl;
    cout<<"\t 3.Customer data lists starting from the highest age to lower ones"<<endl;
    cout<<"\t 4.Customer data lists in alphabetical order of their driver licence number."<<endl;
    cout<<"\t 5.Customer data lists in price starting from the highest"<<endl;
    cout<<"\t 6.To Get Back to the Main Menu. "<<endl;
    cout<<"Enter a number according to the above lists(1-6): ";
    cin>>choice;
    while(choice<1||choice>6){
        cout<<"Please Enter a valid value: ";
    }
    switch (choice){
        case 1:
            TopNameInAlphabet();
            break;
        case 2:
            TopMiddleNameInAlphabet();
            break;
        case 3:
            maxAgeList();
            break;
        case 4:
            firstLicenseNumber();
            break;
        case 5:
            TopPriced();
            break;
        case 6:
        	menu();
        	break;
        default:
            break;
    }
}
void numberOfOccurrenceByName(){
    customer *temp=start;
    int FirstOrMiddle;
    int count = 0;
    char key[20];
    cout<<"Do you want you want by First name or Middle Name? "<<endl;
    cout<<"Press 1 - to choose First Name"<<endl;
    cout<<"Press 2 - to choose Middle Name"<<endl;
    cin>>FirstOrMiddle;
    if(FirstOrMiddle==1){
        cout<<"Enter the First Name to count on: "<<endl;
        cin>>key;
        while(temp != NULL){
            if(stricmp(key,temp->firstName) == 0){
                count++;
            }
            temp=temp->next;
        }
        if(count>0){
            cout<<"There are "<< count<<" customers who has first name of "<<key<<endl;
            countNumberOfOccurrence();
        }
        else{
            cout<<"There is No customer found with given name."<<endl;
            countNumberOfOccurrence();
        }
    }
    else if(FirstOrMiddle ==2 ){
        cout<<"Enter the Middle Name to count on: "<<endl;
        cin>>key;
        while(temp != NULL){
            if(stricmp(key,temp->middleName) == 0){
                count++;
            }
            temp=temp->next;
        }
        if(count>0){
	        cout<<"There are "<< count<<" customers who has middle name of "<<key<<endl;
	        countNumberOfOccurrence();}
        else{
            cout<<"There is No customer found with given name."<<endl;
            countNumberOfOccurrence();
        }
    }
    else {
        int tryagain;
        cout<<"Invalid input \n";
        cout<<"Press 1 - to Try Again\n";
        cout<<"Press 2 - to go back \n";
        cin>>tryagain;
        if(tryagain==1){
            numberOfOccurrenceByName();
        }
        countNumberOfOccurrence();
    }
}
void numberOfOccurrenceByAge(){
    customer *temp=start;
    int count = 0;
    int ageToCount;
    cout<<"Enter tha age to count on: "<<endl;
    cin>>ageToCount;
    while(ageToCount<0){
    	cout<<"Please Enter a valid Age: ";
    	cin>>ageToCount;
	}
    while(temp != NULL){
            if(ageToCount == temp->age){
                count++;
            }
            temp=temp->next;
        }
        if(count>0){
        	cout<<"There are "<< count<<" customers who has Age of "<<ageToCount<<endl;
        	countNumberOfOccurrence();
        }
        else{
            cout<<"There is No customer found with given Age."<<endl<<endl;
            countNumberOfOccurrence();
        }
}
void numberOfOccurrenceBySex(){
    customer *temp=start;
    int count = 0;
    char sex;
    cout<<"Enter tha type of Sex to count on: "<<endl;
    cin>>sex;
        if((sex == 'm') || (sex == 'M' )||(sex == 'F') ||(sex == 'f')){
            while(temp != NULL){
                if(tolower(sex) == temp->sex ||toupper(sex)==temp->sex ){
                    count++;
                }
                temp=temp->next;
            }
        if(count>0 && (sex == 'M' || sex=='m')){
            cout<<"There are "<< count<<" Male customers"<<endl;
            countNumberOfOccurrence();
        }
        else if(count>0 && (sex == 'F' || sex=='f')){
            cout<<"There are "<< count<<" Female customers"<<endl;
            countNumberOfOccurrence();
        }
        else{
            cout<<"There is No customer found with given Sex."<<endl;
            countNumberOfOccurrence();
        }
        }
        else{
        int tryagain=0;
        cout<<"Invalid Input "<<endl;
        cout<<"Press 1 - to try again\n";
        cout<<"Press 2 - to leave";
        cin>>tryagain;
        if(tryagain==1)
            numberOfOccurrenceBySex();
        else
            countNumberOfOccurrence();
        }
}
void numberOfOccurrenceByCartype(){
    customer *temp=start;
    int count = 0;
    char key[20];
    cout<<"Enter the Car Name to count on: "<<endl;
    cin>>key;
        while(temp != NULL){
            if(stricmp(key,temp->carType) == 0){
                count++;
            }
            temp=temp->next;
        }
        if(count>0){
            cout<<"There are "<< count<<" customers who has rent car "<<key;
            countNumberOfOccurrence();
        }
        else{
            cout<<"There is No customer found with given car type."<<endl;
            countNumberOfOccurrence();
        }
}
void numberOfOccurrenceByRentalPrice(){
    customer *temp=start;
    int count = 0;
    int rentalPriceToCount;
    cout<<"Enter tha Rental Price to count on: "<<endl;
    cin>>rentalPriceToCount;
    while(rentalPriceToCount<0){
    	cout<<"Please Enter a valid Rental Price: ";
    	cin>>rentalPriceToCount;
	}
    while(temp != NULL){
            if(rentalPriceToCount == temp->rentalPrice){
                count++;
            }
            temp=temp->next;
        }
        if(count>0){
        cout<<"There are "<< count<<" customers who has rent at the price of "<<rentalPriceToCount;
        countNumberOfOccurrence();}
        else{
            cout<<"There is No customer found with given Rental Price."<<endl;
            countNumberOfOccurrence();
        }
}
void numberOfOccurrenceByRentalPeriod(){
    customer *temp=start;
    int count = 0;
    char rentalPeriodToCount[30];
    cout<<"Enter tha Rental Period to count on: "<<endl;
    cin>>rentalPeriodToCount;
    while(temp != NULL){
            if(stricmp(rentalPeriodToCount, temp->rentalPeriod)==0){
                count++;
            }
            temp=temp->next;
        }
        if(count>0){
            cout<<"There are "<< count<<" customers who has rent at for the period  of "<<rentalPeriodToCount;
            countNumberOfOccurrence();
        }
        else{
            cout<<"There is No customer found with given Rental period."<<endl;
            countNumberOfOccurrence();
        }
}
void countNumberOfOccurrence(){
    int chooseTypeOfOccurrence;
    cout<<"\n\nBy What parameter do you want to count occurrence?"<<endl;
    cout<<"\tPress 1 - to get number of occurrence by Name\n";
    cout<<"\tPress 2 - to get number of occurrence by Age\n";
    cout<<"\tPress 3 - to get number of occurrence by Sex\n";
    cout<<"\tPress 4 - to get number of occurrence by Cartype\n";
    cout<<"\tPress 5 - to get number of occurrence by Rental Price\n";
    cout<<"\tPress 6 - to get number of occurrence by Rental Period\n";
    cout<<"\tPress 7 - to get back to the Main Menu\n";
    cout<<"===> ";
	cin>>chooseTypeOfOccurrence;
    switch(chooseTypeOfOccurrence){
        case 1:
            numberOfOccurrenceByName();
            break;
        case 2:
            numberOfOccurrenceByAge();
            break;
        case 3:
            numberOfOccurrenceBySex();
            break;
        case 4:
            numberOfOccurrenceByCartype();
            break;
        case 5:
            numberOfOccurrenceByRentalPrice();
            break;
        case 6:
            numberOfOccurrenceByRentalPeriod();
            break;
        case 7:
        	menu();
        	break;
        default:
            int tryagain;
            cout<<"Invalid Input\n ";
            cout<<"Press 1 - to try again\n";
            cout<<"Press 2 - to leave from the Counting feature";
            cin>>tryagain;
            if(tryagain == 1)
                countNumberOfOccurrence();
            else if(tryagain==2)
                break;
        }
}
void insertData(){
	int insertOption;
	cout<<"\tPress 1 - to Insert Data at the End"<<endl;
	cout<<"\tPress 2 - to Insert Data at the Middle"<<endl;
	cout<<"\tPress 3 - to go back to the Main Menu"<<endl;
	cout<<"==> ";
	cin>>insertOption;
	while(insertOption <0 || insertOption>3){
		cout<<"Enter valid number (1-3): ";
		cin>>insertOption;
	}
	switch(insertOption){
		case 1:
			insertAtEnd();
			break;
		case 2:
			insertAtMiddle();
			break;
		case 3:
			menu();
			break;
	}
}
void insertAtEnd() {
	countAll++;
    // Create a new node
    struct customer *n = new customer;
    n->next = NULL;

    // the user to enter customer data
    cout << "Enter customer data: " << endl;
    cout << "First Name: ";
    cin >> n->firstName;
    cout << "Middle Name: ";
    cin >> n->middleName;
    cout << "Sex (M/F): ";
    cin >> n->sex;
    while(!(n->sex == 'M' || n->sex == 'm' || n->sex == 'F' || n->sex == 'f')) // allow only M F f m characters
         {
    cout << "Enter a valid character (M/F): " << endl;
    cin >> n->sex;
         }
    cout << "Phone Number: ";
    cin >> n->phoneNumber;
    // to make the phone number unique
    int y=0;
    for(customer*i=start;i!=NULL;i=i->next)
    {
        if(stricmp( n->phoneNumber,i->phoneNumber)==0)
        {
            y=1;
            break;
        }

    }
    while(y==1)
    {
        cout<<"Phone number already exists! Enter a new phone number: "<<endl;
        cin>>n->phoneNumber;
        y=0;
        for(customer*i=start;i!=NULL;i=i->next)
        {
            if(stricmp( n->phoneNumber,i->phoneNumber)==0)
            {
                y=1;
                break;
            }
        }
    }
  // to make driver licence number unique number
    cout << "Driver Licence Number: ";
    cin >> n->driverLicenseNumber;
     int x=0;
    for(customer*i=start;i!=NULL;i=i->next)
    {
        if(stricmp( n->driverLicenseNumber,i->driverLicenseNumber)==0)
        {
            x=1;
            break;
        }

    }
    while(x==1)
    {
        cout<<"The license number  already exists! Enter a new license number: "<<endl;
        cin>>n->driverLicenseNumber;
        x=0;
        for(customer*i=start;i!=NULL;i=i->next)
        {
            if(stricmp( n->driverLicenseNumber,i->driverLicenseNumber)==0)
            {
                x=1;
                break;
            }
        }
    }
    cout << "Car Type: ";
    cin >> n->carType;
    cout << "Number Plate: ";
    cin >> n->numberPlate;
     int z=0;
    for(customer*i=start;i!=NULL;i=i->next)
    {
        if(stricmp( n->numberPlate,i->numberPlate)==0)
        {
            z=1;
            break;
        }

    }
    while(z==1)
    {
        cout<<"The Number Plate already exists! Enter a new Number Plate: "<<endl;
        cin>>n->numberPlate;
        z=0;
        for(customer*i=start;i!=NULL;i=i->next)
        {
            if(stricmp( n->numberPlate,i->numberPlate)==0)
            {
                z=1;
                break;
            }
        }
    }
    cout << "Rental Price: ";
    cin >> n->rentalPrice;
    cout << "Rental Period: ";
    cin >> n->rentalPeriod;
    cout << "Customer Age: ";
    cin >> n->age;
    while(n->age<0)
    {
    cout<<"Enter a valid age again: "<<endl;
   cin>>n->age;
  }

    // If the linked list is empty, set the new node as the starting node
    if(start == NULL){
        start = n;
    }
    // Otherwise, traverse the linked list and add the new node at the end
    else{
        struct customer *i = start;

        while(i->next != NULL){
            i = i->next;
        }

        i->next = n;
             }
        display_node();
}
void insertAtMiddle() {
    // Create a new node
    cout<<endl<<"THIS IS THE NEW CUSTOMER DATA"<<endl;
  struct customer *n = new customer;
    n->next = NULL;

    // the user to enter new customer data
    cout << "Enter the new customer data: " << endl;
    cout << "First Name: ";
    cin >> n->firstName;
    cout << "Middle Name: ";
    cin >> n->middleName;
    cout<<"Enter Sex: ";
    cin>>n->sex;
    while(!(n->sex == 'M' || n->sex == 'm' || n->sex == 'F' || n->sex == 'f')) // allow only M F f m characters
         {
    cout << "Enter a valid character (M/F): " << endl;
    cin >> n->sex;
         }
    cout << "Phone Number: ";
    cin >> n->phoneNumber;
    // to make the phone number unique
    int y=0;
    for(customer*i=start;i!=NULL;i=i->next)
    {
        if(stricmp( n->phoneNumber,i->phoneNumber)==0)
        {
            y=1;
            break;
        }

    }
    while(y==1)
    {
        cout<<"Phone number already exists! Enter a new phone number: "<<endl;
        cin>>n->phoneNumber;
        y=0;
        for(customer*i=start;i!=NULL;i=i->next)
        {
            if(stricmp( n->phoneNumber,i->phoneNumber)==0)
            {
                y=1;
                break;
            }
        }
    }
  // to make driver licence number unique number
    cout << "Driver Licence Number: ";
    cin >> n->driverLicenseNumber;
     int x=0;
    for(customer*i=start;i!=NULL;i=i->next)
    {
        if(stricmp( n->driverLicenseNumber,i->driverLicenseNumber)==0)
        {
            x=1;
            break;
        }

    }
    while(x==1)
    {
        cout<<"The License number  already exists! Enter a new license number: "<<endl;
        cin>>n->driverLicenseNumber;
        x=0;
        for(customer*i=start;i!=NULL;i=i->next)
        {
            if(stricmp( n->driverLicenseNumber,i->driverLicenseNumber)==0)
            {
                x=1;
                break;
            }
        }
    }
    cout << "Car Type: ";
    cin >> n->carType;
    cout << "Number Plate: ";
    cin >> n->numberPlate;
     int z=0;
    for(customer*i=start;i!=NULL;i=i->next)
    {
        if(stricmp( n->numberPlate,i->numberPlate)==0)
        {
            z=1;
            break;
        }

    }
    while(z==1)
    {
        cout<<"The Number Plate already exists! Enter a new numberPlate: "<<endl;
        cin>>n->numberPlate;
        x=0;
        for(customer*i=start;i!=NULL;i=i->next)
        {
            if(strcmp( n->numberPlate,i->numberPlate)==0)
            {
                z=1;
                break;
            }
        }
    }
    cout << "Rental Price: ";
    cin >> n->rentalPrice;
    cout << "Rental Period: ";
    cin >> n->rentalPeriod;
    cout << "Customer Age: ";
    cin >> n->age;
    while(n->age<0)
    {
    cout<<"Enter a valid age again"<<endl;
   cin>>n->age;
  }
    customer*temp2=start;
    int found =0;
	cout<<"Enter the first name of the customer  you want to be get searched and the new customer will be  entered next to it: ";
	char j[20];
	cin>>j;
	if(start==NULL){
	  start=n;
	}
	else{
	while(temp2 != NULL){
	    if(stricmp(temp2->firstName,j)==0){
	    	found =1;
	    	break;
		}
		temp2=temp2->next;
	}
	if(found ==1){
	n->next = temp2->next;
	temp2->next = n;
	countAll++;
	display_node();
	}
	while(found ==0){
		int check;
		cout<<"The Name given is not found "<<endl;
		insertData();
		}
	}

	display_node();
}

// Deleting Function
void deleteFunction() {
    int choice;
    cout << "Do you want to delete customers by:" << endl;
    cout << "\t1. Beginning of the list" << endl;
    cout << "\t2. End of the list" << endl;
    cout << "\t3. First Name" << endl;
    cout << "\t4. Middle Name" << endl;
    cout << "\t5. Age" << endl;
    cout << "\t6. Sex" << endl;
    cout << "\t7. Phone number" << endl;
    cout << "\t8. Car type" << endl;
    cout << "\t9. Number plate" << endl;
    cout << "\t10. Rental price" << endl;
    cout << "\t11. Rental period" << endl;
    cout << "\t12. Driver license number" << endl;
    cout << "\t13. Remove Nth node" << endl;
    cout << "\t14. Delete customers with minimum age" << endl;
    cout << "\t15. Delete customers with maximum age" << endl;
    cout<<"\t16. To Go Back To The Main Menu"<<endl;
    cout << "Enter your choice: ";
    cin >> choice;
    while (choice < 1 || choice > 16) {
        cout << "Please enter a valid number (1-16): ";
        cin >> choice;
    }
     switch (choice) {
        case 1:
            deleteAtBeginning();
            break;
        case 2:
            deleteAtEnd();
            break;
    	case 3:
            deleteByFirstName();
            break;
       case 4:
           deleteByMiddleName();
            break;
       case 5:
           deleteByAge();
           break;
        case 6:
            deleteBySex();
            break;
    	case 7:
            deleteByPhone();
            break;
        case 8:
            deleteCarType();
            break;
        case 9:
            deleteByNumberPlate();
            break;
        case 10:
            deleteByRentalPrice();
            break;
        case 11:
            deleteByRentalPeriod();
            break;
        case 12:
            driverLicenseNumber();
            break;
        case 13:
            deleteNNode();
            break;
        case 14:
            deleteMinimumAge();
            break;
        case 15:
            deleteMaximumAge();
            break;
        case 16:
        	menu();
        	break;
        default:
            break;
    }
}
void deleteAtBeginning() {
	struct customer *temp = start;
    if (start == NULL) {
        cout << "No customer data available to delete" << endl;
        deleteFunction();
    }
    else {
        start = start->next;
        temp->next= NULL;
        delete temp;
        cout << "The first customer data has been deleted" << endl;
		cout << endl << "The updated customer list after deleting the first element:" << endl;
		countAll--;
    	display_node();
}
}
void deleteAtEnd() {
    if (start == NULL) {
        cout << "No customer data available to delete" << endl;
        deleteFunction();
    }
    else if (start->next == NULL) {
        start = NULL;
        delete start;
        cout << "The last customer data has been deleted" << endl;
        countAll--;
        deleteFunction();
    }
    else {
        struct customer *temp = start;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        temp->next = NULL;
        delete temp->next;
        cout << "The last customer data has been deleted" << endl;
        countAll--;
    }
cout << endl << "The updated customer list after deleting the last element:" << endl;
display_node();
}
void deleteByFirstName() {
    struct customer *temp=start;
    char name[30];
    bool found = false;
    cout << "Enter the customer's first name to delete: ";
    cin>>name;
    if (start == NULL) {
        cout << "No customer data available to delete" << endl;
        deleteFunction();
    }
    else if (stricmp(start->firstName,name) == 0) {
        start = start->next;
        delete temp;
        found = true;
        countAll--;
        deleteFunction();
    }
    else {
        struct customer *temp,*temp2 = start;
        while (temp2 != NULL) {
            if (stricmp(temp2->firstName, name) == 0) {
                temp->next = temp2->next;
                delete temp2;
                found = true;
                cout << "The customer data has been deleted" << endl;
                countAll--;
                break;
            }
            temp = temp2;
            temp2 = temp2->next;
        }
    }

    if (!found) {
        cout << "No customer data found in your search" << endl;
       deleteFunction();
    }
	cout << endl << "The updated customer list after deleting the customer:" << endl;
    display_node();
}
void deleteByMiddleName() {
    struct customer *temp=start;
    char name[30];
    bool found = false;
    cout << "Enter the customer's Middle name to delete: ";
    cin>>name;
    if (start == NULL) {
        cout << "No customer data available to delete" << endl;
        deleteFunction();
    }
    else if (stricmp(start->middleName,name) == 0) {
        start = start->next;
        delete temp;
        found = true;
        deleteFunction();
    }
    else {
        struct customer *temp,*temp2 = start;
        while (temp2 != NULL) {
            if (stricmp(temp2->middleName, name) == 0) {
                temp->next = temp2->next;
                delete temp2;
                found = true;
                cout << "The customer data has been deleted" << endl;
           		countAll--;
				break;
            }
            temp = temp2;
            temp2 = temp2->next;
        }
    }
    if (!found) {
       cout << "No customer data found in your search" << endl;
        deleteFunction();
    }
	cout << endl << "The updated customer list after deleting the customer:" << endl;
    display_node();
}
void deleteBySex() {
    struct customer *temp = start;
    char nsex;
    bool found = false;
    cout << "Enter the customer's sex to delete (M/F): ";
    cin >>nsex;
     //Check if the input is a valid character (M, m, F, or f)
    while (nsex !='M' && nsex != 'm' && nsex != 'F' && nsex != 'f') {
        cout << "Enter a valid character (M/F): " << endl;
        cin >> nsex;
    }
    if (start == NULL) {
        cout << "No customer data available to delete" << endl;
        deleteFunction();
    }
    else {
        while (temp != NULL) {
            if (tolower(temp->sex) == nsex || toupper(temp->sex)==nsex) {
                if (temp == start) {
                    start = temp->next;
                    delete temp;
                    countAll--;
                }
                else {
                    struct customer *prev = start;
                    while (prev->next != temp) {
                        prev = prev->next;
                    }
                    prev->next = temp->next;
                    delete temp;
                    countAll--;
                    temp = prev->next;
                }
                found = true;
                cout << "The customer data has been deleted" << endl;
            }
            else {
                temp = temp->next;
            }
        }
    }

    if (!found) {
        cout << "No customer data found in your search" << endl;
        deleteFunction();
 	   	}
    	cout << endl << "The updated customer list after deleting the customer:" << endl;
        display_node();
}
void deleteCarType() {
    struct customer *temp = start;
    char carType[30];
    bool found = false;
    cout << "Enter the customer's car type to delete: ";
    cin >> carType;
    if (start == NULL) {
        cout << "No customer data available to delete" << endl;
        deleteFunction();
    }
    else {
        while (temp != NULL) {
    		if (strcmp(temp->carType, carType) == 0) {
    			if (temp == start) {
                	start = temp->next;
                	countAll--;
                	delete temp;
        			temp = start;
    			}
           		else {
        			struct customer *prev = start;
		        	while (prev->next != temp) {
         		    prev = prev->next;
	        		}
			     	  prev->next = temp->next;
			          delete temp;
			          countAll--;
			          temp = prev->next;
	         }
        found = true;
        cout << "The customer data has been deleted" << endl;
         }
          else {
         temp = temp->next;
            }
        }
    }

    if (!found) {
        cout << "No customer data found in your search" << endl;
        deleteFunction();
    }
	cout << endl << "The updated customer list after deleting the customer:" << endl;
}
void deleteByNumberPlate(){
    struct customer *temp = start;
    char numberPlate[30];
    bool found = false;
    cout << "Enter the customer's number plate to delete: ";
    cin >> numberPlate;
    if (start == NULL) {
        cout << "No customer data available to delete" << endl;
        deleteFunction();
    }
    else {
        while (temp != NULL) {
			if(strcmp(temp->numberPlate, numberPlate) == 0) {
        		if (temp == start) {
                    start = temp->next;
        			delete temp;
        			countAll--;
             		temp = start;
         }
       else {
            struct customer *prev = start;
            while (prev->next != temp) {
            prev = prev->next;
        }
            prev->next = temp->next;
            delete temp;
            countAll--;
            temp = prev->next;
        }
	    found = true;
		cout<<"The customer data has been deleted" << endl;
    }
        else {
                temp = temp->next;
        }
      }
    }
    if (!found) {
        cout << "No customer data found in your search" << endl;
        deleteFunction();
    }
	cout << endl << "The updated customer list after deleting the customer:" << endl;
    display_node();
}
void deleteByRentalPrice(){
    struct customer *temp = start;
    double rentalPrice;
    bool found = false;
    cout << "Enter the customer's rental price to delete: ";
    cin >> rentalPrice;

    if (start == NULL) {
        cout << "No customer data available to delete" << endl;
        deleteFunction();
    }
    else {
        while (temp != NULL) {
         if (temp->rentalPrice==rentalPrice) {
        if (temp == start) {
                    start = temp->next;
                    delete temp;
                    countAll--;
                    temp = start;
                }
           else {
                    struct customer *prev = start;
                    while (prev->next != temp) {
                  prev = prev->next;
               }
                    prev->next = temp->next;
                    delete temp;
                    countAll--;
                    temp = prev->next;
              }
                found = true;
                cout << "The customer data has been deleted" << endl;
            }
            else {
                temp = temp->next;
            }
        }
    }

    if (!found) {
        cout << "No customer data found in your search" << endl;
        deleteFunction();
    }
 	cout << endl << "The updated customer list after deleting the customer:" << endl;
    display_node();
}
void deleteByRentalPeriod() {
    struct customer *temp = start;
    char rentalPeriod[30];
    bool found = false;
    cout << "Enter the customer's rental period to delete: ";
    cin >> rentalPeriod;
    if (start == NULL) {
        cout << "No customer data available to delete" << endl;
        deleteFunction();
    }
    else {
        while (temp != NULL) {
            if (strcmp(temp->rentalPeriod, rentalPeriod) == 0) {
                if (temp == start) {
                    start = temp->next;
                    delete temp;
                    countAll--;
                    temp = start;
                }
                else {
                    struct customer *prev = start;
                    while (prev->next != temp) {
                        prev = prev->next;
                    }
                    prev->next = temp->next;
                    delete temp;
                    countAll--;
                    temp = prev->next;
                }
                found = true;
                cout << "The customer data has been deleted" << endl;
            }
            else {
                temp = temp->next;
            }
        }
    }
    if (!found) {
        cout << "No customer data found in your search" << endl;
        deleteFunction();
    }
	cout << endl << "The updated customer list after deleting the customer:" << endl;
    display_node();
}
void driverLicenseNumber() {
    struct customer *temp = start;
    char driverLicenseNumber[30];
    bool found = false;
    cout << "Enter the customer's driver license number to delete: ";
    cin >> driverLicenseNumber;

    if (start == NULL) {
        cout << "No customer data available to delete" << endl;
        deleteFunction();
    }
    else {
        while (temp != NULL) {
            if (strcmp(temp->driverLicenseNumber, driverLicenseNumber) == 0) {
                if (temp == start) {
                    start = temp->next;
                    delete temp;
                    countAll--;
                    temp = start;
                }
                else {
                    struct customer *prev = start;
                    while (prev->next != temp) {
                        prev = prev->next;
                    }
                    prev->next = temp->next;
                    delete temp;
                    countAll--;
                    temp = prev->next;
                }
                found = true;
                cout << "The customer data has been deleted" << endl;
            }
            else {
                temp = temp->next;
            }
        }
    }

    if (!found) {
        cout << "No customer data found in your search" << endl;
        deleteFunction();
    }
	cout << endl << "The updated customer list after deleting the customer:" << endl;
    display_node();
}
void deleteNNode(){
    customer *temp, *temp2;
    int position;
    int count = 0;

    // Count the number of nodes in the list
    temp = start;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    // Ask the user to enter a valid position
    cout << "Enter the position of the node to be deleted: ";
    cin >> position;
    // Check if the position is valid, and prompt the user to enter a valid position if necessary
    while (position < 1 || position > count) {
        cout << "Invalid position. Please enter a valid position (1-" << count << "): ";
        cin >> position;
    }
    // Reset temp to the start of the list
    temp = start;
    temp2 = start;
    // Traverse the list to the position before the node to be deleted
    for (int i = 1; i < position; i++) {
        temp2 = temp;
        temp = temp->next;
    }
    // Update pointers and delete the node
    temp2->next = temp->next;
    delete temp;
    countAll--;
	cout<< endl << "The updated customer list after deleting the customer:" << endl;
    display_node();
}
void deleteMinimumAge() {
    if (start == NULL) {
        cout << "No customer data available" << endl;
        deleteFunction();
    }
    else {
        struct customer *temp = start;
        struct customer *minCustomer = temp;
        double minage = temp->age;
        // Find minimum age customer
        while (temp != NULL) {
            if (temp->age < minage) {
                minage = temp->age;
                minCustomer = temp;
            }
            temp = temp->next;
        }
        // Remove minimum age customer node
        if (minCustomer == start) {
            start = start->next;
        } else {
            temp = start;
            while (temp->next != minCustomer) {
                temp = temp->next;
            }
            temp->next = minCustomer->next;
        }
        delete minCustomer;
        countAll--;
        cout << "Minimum age customer has been deleted" << endl;
        cout<<"The new customer lists afte deleted the minimum age customer is/are"<<endl;
    }
display_node();
}
void deleteMaximumAge() {
    if (start == NULL) {
        cout << "No customer data available" << endl;
        deleteFunction();
    }
    else {
        struct customer *temp = start;
        struct customer *maxCustomer = temp;
        double maxage = temp->age;
        // Find minimum age customer
        while (temp != NULL) {
            if (temp->age > maxage) {
                maxage = temp->age;
                maxCustomer = temp;
            }
            temp = temp->next;
        }
        // Remove Maximum age customer node
        if (maxCustomer == start) {
            start = start->next;
        } else {
            temp = start;
            while (temp->next != maxCustomer) {
                temp = temp->next;
            }
            temp->next = maxCustomer->next;
        }
        delete maxCustomer;
        countAll--;
        cout << "Maximum age customer  deleted" << endl;
        cout<<"The new customer lists afte deleted the maximum age customer is/are"<<endl;
    }
display_node();
}
void deleteByPhone(){
    struct customer *temp = start;
    char phoneNumber[30];
    bool found = false;
    cout << "Enter the customer's phone number to delete: ";
    cin >> phoneNumber;
    if (start == NULL) {
        cout << "No customer data available to delete" << endl;
        deleteFunction();
    }
    else {
    while (temp != NULL) {
    if (strcmp(temp->phoneNumber, phoneNumber) == 0) {
        if (temp == start) {
             start = temp->next;
           	 delete temp;
           	 countAll--;
             temp = start;
     }
	else {
      	struct customer *prev = start;
    	while (prev->next != temp) {
          prev = prev->next;
		  }
    	prev->next = temp->next;
    	delete temp;
    	countAll--;
    	temp = prev->next;
      }
    	found = true;
    	cout << "The customer data has been deleted" << endl;
      }
      else {
                temp = temp->next;
      }
        }
    }

    if (!found) {
        cout << "No customer data found in your search" << endl;
        deleteFunction();
	}
	cout << endl << "The updated customer list after deleting the customer:" << endl;
    display_node();
}
void deleteByAge() {
    struct customer *temp = start;
    int AGE;
    bool found = false;
    cout << "Enter the customer's age to delete: ";
    cin >> AGE;
    if (start == NULL) {
        cout << "No customer data available to delete" << endl;
        deleteFunction();
    }
    else {
        while (temp != NULL) {
         if (temp->age==AGE) {
        if (temp == start) {
                    start = temp->next;
                    delete temp;
                    countAll--;
                    temp = start;
                }
           else {
                    struct customer *prev = start;
                    while (prev->next != temp) {
                  prev = prev->next;
               }
                    prev->next = temp->next;
                    delete temp;
                    countAll--;
                    temp = prev->next;
              }
                found = true;
                cout << "The customer data has been deleted" << endl;
            }
            else {
                temp = temp->next;
            }
        }
    }
    if (!found) {
        cout << "No customer data found in your search" << endl;
        deleteFunction();
    }
	cout << endl << "The updated customer list after deleting the customer:" << endl;
    display_node();
}
void updatingFunction(){
    //prompt the user to enter his choice of the data item to be updated
    int choice;
    cout<<"Do you want to:"<<endl;
    cout<<"\t 1.Update first name."<<endl;
    cout<<"\t 2.Update middle name."<<endl;
    cout<<"\t 3.Update age "<<endl;
    cout<<"\t 4.Update phone number."<<endl;
    cout<<"\t 5.Update driver license number."<<endl;
    cout<<"\t 6.Update car type."<<endl;
    cout<<"\t 7.Update plate number."<<endl;
    cout<<"\t 8.Update rental price."<<endl;
    cout<<"\t 9.Update rental period."<<endl;
    cout<<"\t 10.Update sex"<<endl;
    cout<<"\t 11.To Go Back to the Main Menu"<<endl;
    cout<<"Enter your choice:";
    cin>>choice;
    //exception handling if invalid number is inserted
    while(choice<1||choice>11)
    {
        cout<<"Please enter a valid number(1-11):";
        cin>>choice;
    }
    switch(choice)
    {
    case 1:
        updateFirstName();
        break;
   case 2:
        updateMiddleName();
        break;
    case 3:
        updateAge();
        break;
    case 4:
        updatePhoneNumber();
        break;
    case 5:
        updateDriverLicenseNumber();
        break;
    case 6:
        updateCarType();
        break;
    case 7:
        updatePlateNumber();
        break;
    case 8:
        updateRentalPrice();
        break;
    case 9:
        updateRentalPeriod();
        break;
    case 10:
        updateSex();
        break;
    case 11:
    	menu();
    	break;
    }
}
void updateFirstName()
{
    if(start==NULL)
    {
        cout<<"List is empty!"<<endl;
        menu();
    }
    char fname[15],pnumber[15],Fname[15];
    int found=0;
    //selecting the customer whose data fields are to be updated
    cout<<"Enter the first name of the customer whose first name is be to updated:";
    cin>>fname;
    for(customer *i=start;i!=NULL;i=i->next)
    {
        //use stricmp function so that fname is case resistive
        if(stricmp(i->firstName,fname)==0)
            found++;
    }
    if(found==0)
    {
        cout<<"The name you entered doesn't exist!"<<endl;
        updatingFunction();
    }
    else if(found==1)
    {
        for(customer *i=start;i!=NULL;i=i->next)
        if(stricmp(i->firstName,fname)==0)
        {
            //update the targeted data
            cout<<"Enter the new first name of the customer:";
            cin>>Fname;
            strcpy(i->firstName,Fname);
            cout<<"The targeted data has been updated successfully!"<<endl;
            display(i);
            updatingFunction();
        }
    }
    else if(found>1)
    {
        //if more than one customer has the same name we don't know whose data is to be updated
        //so as phone number is unique prompt the user to enter the phone number of the customer
        cout<<"There are more than one persons who are named "<<fname<<"."<<endl;
        cout<<"Please enter the phone number of the customer so that we can uniquely identify him/her:";
        cin>>pnumber;
        for(customer *i=start;i!=NULL;i=i->next)
        {
            //use stricmp function so that fname is case resistive
            if(stricmp(i->firstName,fname)==0&&stricmp(i->phoneNumber,pnumber)==0)
                {
                    //update the targeted data
                    cout<<"Enter the new first name of the customer:";
                    cin>>Fname;
                    strcpy(i->firstName,Fname);
                    cout<<"The targeted data has been updated successfully!"<<endl;
                    display(i);
                    updatingFunction();
                }
         }
                //if the specified phone number is invalid(doesn't exist )
                cout<<"None of the customers registered as "<<fname<<" has the specified phone number!"<<endl;
                updatingFunction();
    }
}
void updateMiddleName()
{
    if(start==NULL)
    {
        cout<<"List is empty!"<<endl;
        menu();
    }
    char fname[15],pnumber[15],mname[15];
    int found=0;
    //selecting the customer whose data fields are to be updated
    cout<<"Enter the first name of the customer whose name is to updated:";
    cin>>fname;
    for(customer *i=start;i!=NULL;i=i->next)
    {
        //use stricmp function so that fname is case resistive
        if(stricmp(i->firstName,fname)==0)
            found++;
    }
    if(found==0)
    {
        cout<<"The name you entered doesn't exist!"<<endl;
        updatingFunction();
    }
    else if(found==1)
    {
        for(customer *i=start;i!=NULL;i=i->next)
        //use stricmp function so that fname is case resistive
        if(stricmp(i->firstName,fname)==0)
        {
            //update the targeted data
            cout<<"Enter the new middle name of the customer:";
            cin>>mname;
            strcpy(i->middleName,mname);
            cout<<"The targeted data has been updated successfully!"<<endl;
            display(i);
            updatingFunction();
        }
    }
    else if(found>1)
    {
         //if more than one customer has the same name we don't know whose data is to be updated
        //so as phone number is unique prompt the user to enter the phone number of the customer
        cout<<"There are more than one persons who are named "<<fname<<"."<<endl;
        cout<<"Please enter the phone number of the customer so that we can uniquely identify him/her:";
        cin>>pnumber;
        for(customer *i=start;i!=NULL;i=i->next)
        {
            //use stricmp function so that fname is case resistive
            if(stricmp(i->firstName,fname)==0&&stricmp(i->phoneNumber,pnumber)==0)
                {
                    //update the targeted data
                    cout<<"Enter the new middle name of the customer:";
                    cin>>mname;
                    strcpy(i->middleName,mname);
                    cout<<"The targeted data has been updated successfully!"<<endl;
                    display(i);
                    updatingFunction();
                }
        }
                cout<<"None of the customers registered as "<<fname<<" has the specified phone number!"<<endl;
                updatingFunction();
    }
}
void updateRentalPeriod()
{
    if(start==NULL)
    {
        cout<<"List is empty!"<<endl;
        menu();
    }
    char fname[15],pnumber[15],rperiod[30];
    int found=0;
    //selecting the customer whose data fields are to be updated
    cout<<"Enter the first name of the customer whose rental price is to updated:";
    cin>>fname;
    for(customer *i=start;i!=NULL;i=i->next)
    {
        //use stricmp function so that fname is case resistive
        if(stricmp(i->firstName,fname)==0)
            found++;
    }
    if(found==0)
    {
        cout<<"The name you entered doesn't exist!"<<endl;
        updatingFunction();
    }
    else if(found==1)
    {
        for(customer *i=start;i!=NULL;i=i->next)
        if(stricmp(i->firstName,fname)==0)
        {
            //use stricmp function so that fname is case resistive
            cout<<"Enter the new rental period:";
            cin>>rperiod;
            //update the targeted data
            strcpy(i->rentalPeriod,rperiod);
            cout<<"The targeted data has been updated successfully!"<<endl;
            display(i);
            updatingFunction();
        }
    }
    else if(found>1)
    {
         //if more than one customer has the same name we don't know whose data is to be updated
        //so as phone number is unique prompt the user to enter the phone number of the customer
        cout<<"There are more than one persons who are named "<<fname<<"."<<endl;
        cout<<"Please enter the phone number of the customer so that we can uniquely identify him/her:";
        cin>>pnumber;
        for(customer *i=start;i!=NULL;i=i->next)
        {
            //use stricmp function so that fname is case resistive
            if(stricmp(i->firstName,fname)==0&&stricmp(i->phoneNumber,pnumber)==0)
                {
                    cout<<"Enter the new rental period:";
                    cin>>rperiod;
                    //update the targeted data
                    strcpy(i->rentalPeriod,rperiod);
                    cout<<"The targeted data has been updated successfully!"<<endl;
                    display(i);
                    updatingFunction();
                }
        }
                cout<<"None of the customers registered as "<<fname<<" has the specified phone number!"<<endl;
                updatingFunction();
    }
}
void updateRentalPrice()
{
    if(start==NULL)
    {
        cout<<"List is empty!"<<endl;
        menu();
    }
    char fname[15],pnumber[15];
    double rprice;
    int found=0;
    //selecting the customer whose data fields are to be updated
    cout<<"Enter the first name of the customer whose rental price is to updated:";
    cin>>fname;
    for(customer *i=start;i!=NULL;i=i->next)
    {
        //use stricmp function so that fname is case resistive
        if(stricmp(i->firstName,fname)==0)
            found++;
    }
    if(found==0)
    {
        cout<<"The name you entered doesn't exist!"<<endl;
        updatingFunction();
    }
    else if(found==1)
    {
        for(customer *i=start;i!=NULL;i=i->next)
        if(stricmp(i->firstName,fname)==0)
        {
            cout<<"Enter the new rental price:";
            cin>>rprice;
            //update the targeted data
            i->rentalPrice=rprice;
            cout<<"The targeted data has been updated successfully!"<<endl;
            display(i);
            updatingFunction();
        }
    }
    else if(found>1)
    {
         //if more than one customer has the same name we don't know whose data is to be updated
        //so as phone number is unique prompt the user to enter the phone number of the customer
        cout<<"There are more than one persons who are named "<<fname<<"."<<endl;
        cout<<"Please enter the phone number of the customer so that we can uniquely identify him/her:";
        cin>>pnumber;
        for(customer *i=start;i!=NULL;i=i->next)
        {
            //use stricmp function so that fname is case resistive
            if(stricmp(i->firstName,fname)==0&&stricmp(i->phoneNumber,pnumber)==0)
                {
                    cout<<"Enter the new rental price:";
                    cin>>rprice;
                    //update the targeted data
                    i->rentalPrice=rprice;
                    cout<<"The targeted data has been updated successfully!"<<endl;
                    display(i);
                    updatingFunction();
                }
        }
                cout<<"None of the customers registered as "<<fname<<" has the specified phone number!"<<endl;
                updatingFunction();
    }
}
void updateCarType()
{
    if(start==NULL)
    {
        cout<<"List is empty!"<<endl;
        menu();
    }
    char fname[15],pnumber[15],car[30];
    int found=0;
    //selecting the customer whose data fields are to be updated
    cout<<"Enter the first name of the customer whose car type is to be updated:";
    cin>>fname;
    for(customer *i=start;i!=NULL;i=i->next)
    {
        //use stricmp function so that fname is case resistive
        if(stricmp(i->firstName,fname)==0)
            found++;
    }
    if(found==0)
    {
        cout<<"The name you entered doesn't exist!"<<endl;
        updatingFunction();
    }
    else if(found==1)
    {
        for(customer *i=start;i!=NULL;i=i->next)
        //use stricmp function so that fname is case resistive
        if(stricmp(i->firstName,fname)==0)
        {
            cout<<"Enter the new car type:";
            cin>>car;
            //update the targeted data
            strcpy(i->carType,car);
            cout<<"The targeted data has been updated successfully!"<<endl;
            display(i);
            updatingFunction();
        }
    }
    else if(found>1)
    {
         //if more than one customer has the same name we don't know whose data is to be updated
        //so as phone number is unique prompt the user to enter the phone number of the customer
        cout<<"There are more than one persons who are named "<<fname<<"."<<endl;
        cout<<"Please enter the phone number of the customer so that we can uniquely identify him/her:";
        cin>>pnumber;
        for(customer *i=start;i!=NULL;i=i->next)
        {
            //use stricmp function so that fname is case resistive
            if(stricmp(i->firstName,fname)==0&&stricmp(i->phoneNumber,pnumber)==0)
                {
                    cout<<"Enter the new car type:";
                    cin>>car;
                    //update the targeted data
                    strcpy(i->carType,car);
                    cout<<"The targeted data has been updated successfully!"<<endl;
                    display(i);
                    updatingFunction();
                }
        }
                cout<<"None of the customers registered as "<<fname<<" has the specified phone number!"<<endl;


    }
}
void updateDriverLicenseNumber()
{
    if(start==NULL)
    {
        cout<<"List is empty!"<<endl;
        updatingFunction();
    }
    char fname[15],pnumber[15],license[30];
    int found=0;
    //selecting the customer whose data fields are to be updated
    cout<<"Enter the first name of the customer whose car driver license number is to be updated:";
    cin>>fname;
    for(customer *i=start;i!=NULL;i=i->next)
    {
        //use stricmp function so that fname is case resistive
        if(stricmp(i->firstName,fname)==0)
            found++;
    }
    if(found==0)
    {
        cout<<"The name you entered doesn't exist!"<<endl;
        updatingFunction();
    }
    else if(found==1)
    {
        for(customer *i=start;i!=NULL;i=i->next)
        if(stricmp(i->firstName,fname)==0)
        {
            cout<<"Enter the new driver license number:";
            cin>>license;
            //check whether the new license number is unique
            for(customer *check=start;check!=NULL;check=check->next)
            {
                while(stricmp(license,check->driverLicenseNumber)==0)
                      {
                          cout<<"The typed driver license number already exists!Please enter a unique number:";
                          cin>>license;
                      }
            }
            //update the targeted data
            strcpy(i->driverLicenseNumber,license);
            cout<<"The targeted data has been updated successfully!"<<endl;
            display(i);
            updatingFunction();
        }
    }
    else if(found>1)
    {
         //if more than one customer has the same name we don't know whose data is to be updated
        //so as phone number is unique prompt the user to enter the phone number of the customer
        cout<<"There are more than one persons who are named "<<fname<<"."<<endl;
        cout<<"Please enter the phone number of the customer so that we can uniquely identify him/her:";
        cin>>pnumber;
        for(customer *i=start;i!=NULL;i=i->next)
        {
            //use stricmp function so that fname is case resistive
            if(stricmp(i->firstName,fname)==0&&stricmp(i->phoneNumber,pnumber)==0)
            {
                    cout<<"Enter the new driver license number:";
                    cin>>license;
                    //check whether the new license number is unique
                     for(customer *check=start;check!=NULL;check=check->next)
                    {
                          while(stricmp(license,check->driverLicenseNumber)==0)
                        {
                              cout<<"The typed driver license number already exists!Please enter a unique number:";
                              cin>>license;
                        }
            }
                    //update the targeted data
                    strcpy(i->driverLicenseNumber,license);
                    cout<<"The targeted data has been updated successfully!"<<endl;
                    display(i);
                    updatingFunction();
                }

        }
                cout<<"None of the customers registered as "<<fname<<" has the specified phone number!"<<endl;
                updatingFunction();
    }
}
void updatePlateNumber()
{
    if(start==NULL)
    {
        cout<<"List is empty!"<<endl;
        menu();
    }
    char fname[15],pnumber[15],plate[30];
    int found=0;
    //selecting the customer whose data fields are to be updated
    cout<<"Enter the first name of the customer whose plate number is to be updated:";
    cin>>fname;
    for(customer *i=start;i!=NULL;i=i->next)
    {
        //use stricmp function so that fname is case resistive
        if(stricmp(i->firstName,fname)==0)
            found++;
    }
    if(found==0)
    {
        cout<<"The name you entered doesn't exist!"<<endl;
        updatingFunction();
    }
    else if(found==1)
    {
        for(customer *i=start;i!=NULL;i=i->next)
        if(stricmp(i->firstName,fname)==0)
        {
            cout<<"Enter the new plate number:";
            cin>>plate;
            //check whether the new number plate is unique
            for(customer *check=start;check!=NULL;check=check->next)
            {
                while(stricmp(plate,check->numberPlate)==0)
                      {
                          cout<<"The typed plate number already exists!Please enter a unique number:";
                          cin>>plate;
                      }
            }
            //update the targeted data
            strcpy(i->numberPlate,plate);
            cout<<"The targeted data has been updated successfully!"<<endl;
            display(i);
            updatingFunction();
        }
    }
    else if(found>1)
    {
         //if more than one customer has the same name we don't know whose data is to be updated
        //so as phone number is unique prompt the user to enter the phone number of the customer
        cout<<"There are more than one persons who are named "<<fname<<"."<<endl;
        cout<<"Please enter the phone number of the customer so that we can uniquely identify him/her:";
        cin>>pnumber;
        for(customer *i=start;i!=NULL;i=i->next)
        {
            if(stricmp(i->firstName,fname)==0&&stricmp(i->phoneNumber,pnumber)==0)
                {
                    cout<<"Enter the new plate number:";
                    cin>>plate;
                    //check whether the new number plate is unique
                    for(customer *check=start;check!=NULL;check=check->next)
                    {
                        while(stricmp(plate,check->numberPlate)==0)
                              {
                                  cout<<"The typed plate number already exists!Please enter a unique number:";
                                  cin>>plate;
                              }
                    }
                    //update the targeted data
                    strcpy(i->numberPlate,plate);
                    cout<<"The targeted data has been updated successfully!"<<endl;
                    display(i);
                    updatingFunction();
                }
        }
                cout<<"None of the customers registered as "<<fname<<" has the specified phone number!"<<endl;
                updatingFunction();
    }
}
void updateSex()
{
    if(start==NULL)
    {
        cout<<"List is empty!"<<endl;
        menu();
    }
    char fname[15],pnumber[15],nsex;
    int found=0;
    //selecting the customer whose data fields are to be updated
    cout<<"Enter the first name of the customer whose sex is to be updated:";
    cin>>fname;
    for(customer *i=start;i!=NULL;i=i->next)
    {
        //use stricmp function so that fname is case resistive
        if(stricmp(i->firstName,fname)==0)
            found++;
    }
    if(found==0)
    {
        cout<<"The name you entered doesn't exist!"<<endl;
    }
    else if(found==1)
    {
        for(customer *i=start;i!=NULL;i=i->next)
        if(stricmp(i->firstName,fname)==0)
        {
            cout<<"Enter the updated sex:";
            cin>>nsex;
            while(nsex!='m' && nsex!='f' && nsex!='M' && nsex!='F')
            {
                cout<<"Please enter a valid character(m/M or f/F):";
                cin>>nsex;
            }
            //update the targeted data
            i->sex=nsex;
            cout<<"The targeted data has been updated successfully!"<<endl;
            display(i);
            updatingFunction();
        }
    }
    else if(found>1)
    {
         //if more than one customer has the same name we don't know whose data is to be updated
        //so as phone number is unique prompt the user to enter the phone number of the customer
        cout<<"There are more than one persons who are named "<<fname<<"."<<endl;
        cout<<"Please enter the phone number of the customer so that we can uniquely identify him/her:";
        cin>>pnumber;
        for(customer *i=start;i!=NULL;i=i->next)
        {
            //use stricmp function so that fname is case resistive
            if(stricmp(i->firstName,fname)==0&&stricmp(i->phoneNumber,pnumber)==0)
                {
                    cout<<"Enter the updated sex:";
                    cin>>nsex;
                    //update the targeted data
                    i->sex=nsex;
                    cout<<"The targeted data has been updated successfully!"<<endl;
                    display(i);
                    updatingFunction();
                }
        }

                cout<<"None of the customers registered as "<<fname<<" has the specified phone number!"<<endl;
                updatingFunction();
    }
}
void updatePhoneNumber()
{
    if(start==NULL)
    {
        cout<<"List is empty!"<<endl;
        menu();
    }
    char fname[15],pnumber[15],nphone[30];
    int found=0;
    //selecting the customer whose data fields are to be updated
    cout<<"Enter the first name of the customer whose phone number is to be updated:";
    cin>>fname;
    for(customer *i=start;i!=NULL;i=i->next)
    {
        if(stricmp(i->firstName,fname)==0)
            found++;
    }
    if(found==0)
    {
        cout<<"The name you entered doesn't exist!"<<endl;
        updatingFunction();
    }
    else if(found==1)
    {
        for(customer *i=start;i!=NULL;i=i->next)
        //use stricmp function so that fname is case resistive
        if(stricmp(i->firstName,fname)==0)
        {
            cout<<"Enter the new phone number:";
            cin>>nphone;
            //check whether the new phone number is unique
            for(customer *check=start;check!=NULL;check=check->next)
                    {
                        while(stricmp(nphone,check->phoneNumber)==0)
                              {
                                  cout<<"The typed phone number already exists!Please enter a unique number:";
                                  cin>>nphone;
                              }
                    }
            //update the targeted data
            strcpy(i->phoneNumber,nphone);
            cout<<"The targeted data has been updated successfully!"<<endl;
            display(i);
            updatingFunction();
        }
    }
    else if(found>1)
    {
         //if more than one customer has the same name we don't know whose data is to be updated
        //so as phone number is unique prompt the user to enter the phone number of the customer
        cout<<"There are more than one persons who are named "<<fname<<"."<<endl;
        cout<<"Please enter the phone number of the customer so that we can uniquely identify him/her:";
        cin>>pnumber;
        for(customer *i=start;i!=NULL;i=i->next)
        {
            //use stricmp function so that fname is case resistive
            if(stricmp(i->firstName,fname)==0&&stricmp(i->phoneNumber,pnumber)==0)
                {
                    cout<<"Enter the new phone number:";
                    cin>>nphone;
                    //check whether the new phone number is unique
                    for(customer *check=start;check!=NULL;check=check->next)
                            {
                                while(stricmp(nphone,check->phoneNumber)==0)
                                      {
                                          cout<<"The typed plate number already exists!Please enter a unique number:";
                                          cin>>nphone;
                                      }
                            }
                    //update the targeted data
                    strcpy(i->phoneNumber,nphone);
                    cout<<"The targeted data has been updated successfully!"<<endl;
                    display(i);
                    updatingFunction();
                }
        }
                cout<<"None of the customers registered as "<<fname<<" has the specified phone number!"<<endl;
				updatingFunction();
    }
}
void updateAge()
{
    if(start==NULL)
    {
        cout<<"List is empty!"<<endl;
        menu();
    }
    char fname[15],pnumber[15];
    int nage,found=0;
    //selecting the customer whose data fields are to be updated
    cout<<"Enter the first name of the customer whose age is to be updated:";
    cin>>fname;
    for(customer *i=start;i!=NULL;i=i->next)
    {
        if(stricmp(i->firstName,fname)==0)
            found++;
    }
    if(found==0)
    {
        cout<<"The name you entered doesn't exist!"<<endl;
        updatingFunction();
    }
    else if(found==1)
    {
        for(customer *i=start;i!=NULL;i=i->next)
        //use stricmp function so that fname is case resistive
        if(stricmp(i->firstName,fname)==0)
        {
            cout<<"Enter the new age:";
            cin>>nage;
            while(nage<0){
            	cout<<"Invalid age, please try again(age>0): ";
            	cin>>nage;
			}
            //update the targeted data
            i->age=nage;
            cout<<"The targeted data has been updated successfully!"<<endl;
            display(i);
            updatingFunction();
        }
    }
    else if(found>1)
    {
         //if more than one customer has the same name we don't know whose data is to be updated
        //so as phone number is unique prompt the user to enter the phone number of the customer
        cout<<"There are more than one persons who are named "<<fname<<"."<<endl;
        cout<<"Please enter the phone number of the customer so that we can uniquely identify him/her:";
        cin>>pnumber;
        for(customer *i=start;i!=NULL;i=i->next)
        {
            //use stricmp function so that fname is case resistive
            if(stricmp(i->firstName,fname)==0&&stricmp(i->phoneNumber,pnumber)==0)
                {
                    cout<<"Enter the new age:";
                    cin>>nage;
                      while(nage<0){
            			cout<<"Invalid age, please try again(age>0): ";
            			cin>>nage;
					}
                    //update the targeted data
                    i->age=nage;
                    cout<<"The targeted data has been updated successfully!"<<endl;
                    display(i);
                    updatingFunction();
                }
        }
                cout<<"None of the customers registered as "<<fname<<" has the specified phone number!"<<endl;
				updatingFunction();
    }
}
void display(customer *temp){
        cout<<"The updated customer's data is displayed as: "<<endl;
        cout<<"||___________________________________________||"<<endl;
        cout<<"||Name:\t\t\t"<<temp->firstName<<" "<<temp->middleName<<endl;
        cout<<"||Sex:\t\t\t"<<temp->sex<<endl;
        cout<<"||Age:\t\t\t"<<temp->age<<endl;
        cout<<"||Phone No:\t\t"<<temp->phoneNumber<<endl;
        cout<<"||License No:\t\t"<<temp->driverLicenseNumber<<endl;
        cout<<"||Car type:\t\t"<<temp->carType<<endl;
        cout<<"||Plate No:\t\t"<<temp->numberPlate<<endl;
        cout<<"||Rental price:\t\t"<<temp->rentalPrice<<endl;
        cout<<"||Rental period:\t"<<temp->rentalPeriod<<endl;
        cout<<"||___________________________________________||"<<endl;
}
