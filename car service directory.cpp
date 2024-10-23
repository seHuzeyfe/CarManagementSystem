
//Huzeyfe B��ak��-20164684

#include <iostream>
#include <cstdlib>
#include<string.h>
#include<windows.h>
#define SIZE 100

using namespace std;

int addNewCar(int);
int deleteCar(struct car[],int *,int );
int listCar(struct car [] );
int searchforid(struct car[], int);
int searchforregyear(struct car[],int);
int insertCar(struct car[],int);
void sortCar(car * carOwner);


	struct date
       {
       int day, month, year;
       };
    struct car
       {
       
      long long int carID,phoneNumber;
       char ownerName[20], ownerSurname[20], carModel[20];
       struct date regDate, nsDate; 
       }carOwner[100];

    int main()
    {
	int option,searchid,newNumber,size,searchyear,flag = 0;
	char searchname[20];
			
	cout<<endl<<endl<<"--------------------------------------------------"<<endl<<endl;
	
	cout<<"-----MENU-----"<<endl;
	cout<<"1- Add a new car to directory"<<endl;
	cout<<"2- Delete a car from the directory"<<endl;
	cout<<"3- List available cars in the directory"<<endl;
	cout<<"4- Search a car:"<<endl;
	cout<<"     A- Search according to car id"<<endl;
	cout<<"     B- Search according to registration year"<<endl;
	cout<<"5- Update car information"<<endl;
	cout<<"6- Sort the list:"<<endl;
	cout<<"     A- According to id"<<endl;
	cout<<"     B- Acoording to Surname"<<endl;
	cout<<"     C- According to Moedel"<<endl;
	cout<<"Please choose an option:"<<endl;
	cout<<"-";cin>>option;
							
	switch(option)
	{
		case 1:
			cout<<"How many cars will you register?"<<endl;
	        cin>>size;
			addNewCar(size);
			main();
			break;
			
		case 2:			
		    cout<<"Enter the id of the car you want to delete:"<<endl;
		    cin>>searchid;
		    deleteCar(carOwner,&size,searchid);		    
		    main();
		    break;
		 	
		case 3:
			cout<<"Available cars:"<<endl;
			listCar(carOwner);
			main();
			break;
			
		case 4:
			char key;
			
			cout<<"A-Search for id:"<<endl;
			cout<<"B-Search for registration year:"<<endl;
			cin>>key;
			
			if(key == 'a')
			{
				int searchid;
				cout<<"Please enter an id to search:";
	            cin>>searchid;
	            flag = searchforid(carOwner,searchid);
	            if (flag==0)
	            {				
	            cout<<"Not found...";
	            }
				
			}
			else if (key == 'b')
			{			
			cout<<"Please enter a registration year to search:";
	        cin>>searchyear;
	        flag = searchforregyear(carOwner,searchyear);
	        
			 if (flag==0)
			{			 
	        cout<<"Not found...";
	        }	        
		    }		    
	        else
			{
				cout<<"You entered wrong key!";
		    }
		    main();
			break;
		case 5:
			cout<<"Enter the id of the car you want to update:"<<endl;
		    cin>>newNumber;
		    insertCar(carOwner,newNumber);
			main();		    		    
			break;	
		case 6:
			sortCar(carOwner);
			main();
			break;
			
		case 7:	
				cout<<"Program Is Closing In:  ";
		
		for(int i=5;i>=1;i--)
        {
           cout<<i<<"...";
           Sleep(1000);
        }
        exit(1);
		return 0;
			break;
			
			
	}				
    }
    int	addNewCar(int size)
    {        
	char searchname[20];
	int i,searchid,flag=0;
	
	for (i=0;i<size;i++)
	{
		cout<<"Please enter "<<i+1<<"-car id: ";
		cin>>carOwner[i].carID;
		cout<<"Please enter "<<i+1<<"-car model: ";
		gets(carOwner[i].carModel);
		gets(carOwner[i].carModel);
		cout<<"Please enter "<<i+1<<"-owner name:";
		gets(carOwner[i].ownerName);		
		cout<<"Please enter "<<i+1<<"-owner surname:";
		gets(carOwner[i].ownerSurname);
		cout<<"Please enter "<<i+1<<"-phone number:";
		cin>>carOwner[i].phoneNumber;
		cout<<"Please enter "<<i+1<<"-registration date:"<<endl;
		cout<<"Day:";cin>>carOwner[i].regDate.day;
		cout<<"Month:";cin>>carOwner[i].regDate.month;
		cout<<"Year:";cin>>carOwner[i].regDate.year;
		cout<<"Please enter "<<i+1<<"-next service date:"<<endl;
		cout<<"Day:";cin>>carOwner[i].nsDate.day;
		cout<<"Month:";cin>>carOwner[i].nsDate.month;
		cout<<"Year:";cin>>carOwner[i].nsDate.year;
	}
					
    }
   

    int deleteCar(struct car carOwner[],int *size,int x)
    {
	for(int i=0;i<=*size;i++)
	{
		if(x == carOwner[i].carID)
		{
			for(int j=1;j<=*size;j++)
			carOwner[j]=carOwner[j+1];
			*size=*size-1;
		}
	}
	return 0;
    }

    int listCar(struct car carOwner[])
    {
	for (int i=0;i<SIZE;i++)
	{
		if(carOwner[i].carID==0)
		      {continue;}
		      
		else
		{
		
		cout<<"Car ID : "<<carOwner[i].carID<<endl;
		cout<<"Car Model : ";puts(carOwner[i].carModel);
		cout<<"Owner Name : ";puts(carOwner[i].ownerName);
		cout<<"Owner Surname : ";puts(carOwner[i].ownerSurname);
		cout<<"Phone Number : "<<carOwner[i].phoneNumber<<endl;
		cout<<"Car Registration Date : "<<carOwner[i].regDate.day<<"/"<<carOwner[i].regDate.month<<"/"<<carOwner[i].regDate.year<<endl;
		cout<<"Car Next Service Date : "<<carOwner[i].nsDate.day<<"/"<<carOwner[i].nsDate.month<<"/"<<carOwner[i].nsDate.year<<endl<<endl<<endl;
	}
		
	}
	return 0;
	
    }


    int searchforid(struct car carOwner[],int searchid)
	{
		int i;
		for (i=0;i<SIZE;i++)
    	{
		if (carOwner[i].carID == searchid){
		
		   cout<<carOwner[i].carID<<"  "<<carOwner[i].carModel<<endl;
		   return 1; 
    	   }
        }
        return 0; 
    }
	int searchforregyear(struct car carOwner[],int searchyear)
	{
		int i;
		for (i=0;i<SIZE;i++)
    	{
		if (carOwner[i].regDate.year == searchyear){
		
		   cout<<carOwner[i].carID<<"  "<<carOwner[i].carModel<<"  Registration year ->"<<carOwner[i].regDate.year<<endl;
		   return 1; 
    	   }
        }
        return 0; 
    }
	
	int insertCar(struct car carOwner[],int x) 
	{
		int newid,option1,phone,rm,rd,ry,nsd,nsm,nsy;
		
		for(int i=0;i<SIZE;i++)
		{
			if(x==carOwner[i].carID)
			{
				cout<<"Which information of car you want to update ?"<<endl;
				cout<<"1-CAR ID"<<endl;
				cout<<"2-CAR MODEL"<<endl;
				cout<<"3-OWNER NAME"<<endl;
				cout<<"4-OWNER SURNAME"<<endl;
				cout<<"5-PHONE NUMBER"<<endl;
				cout<<"6-REGISTRATION DATE"<<endl;
				cout<<"7-NEXT SERVICE DATE"<<endl;
				cin>>option1;
				
				switch(option1)
				{
					case 1:
					cout<<"New car id:"<<endl;
				    cin>>newid;
				    carOwner[i].carID = newid;
				  	
					break;
					
					case 2:
					cout<<"New car model:"<<endl;
				    gets( carOwner[i].carModel);
				    gets( carOwner[i].carModel);				    				    	
					break;
					
					case 3:
					cout<<"New owner name:"<<endl;
				    gets( carOwner[i].ownerName);
				    gets( carOwner[i].ownerName);					    				    					
					break;
					
					case 4:
					cout<<"New owner surname:"<<endl;	
					gets( carOwner[i].ownerSurname);
				    gets( carOwner[i].ownerSurname);			    				    	
					break;
					
					case 5:
					cout<<"New phone number:"<<endl;
				    cin>>phone;
				    carOwner[i].phoneNumber= phone;
				    
					break;
					
					case 6:
					cout<<"New registration date:"<<endl;
					cout<<"Day:";cin>>rd;
					carOwner[i].regDate.day = rd;
					cout<<"Month:";cin>>rm;
				    carOwner[i].regDate.month = rm;
				    cout<<"Year:";cin>>ry;
				    carOwner[i].regDate.year = ry;
										    
					break;
					
					case 7:
					cout<<"New next service date:"<<endl;
					cout<<"Day:";cin>>nsd;
					carOwner[i].regDate.day = nsd;
					cout<<"Month:";cin>>nsm;
				    carOwner[i].regDate.month = nsm;
				    cout<<"Year:";cin>>nsy;
				    carOwner[i].regDate.year = nsy;
				    
					break;
					
					
				}																
			}
		}
		main();			
	} 

    void sortCar(car *carOwner)
{

  int option;
	cout<<"Please Enter Menu Number "<<endl;
	cout<<"1- Ascending Mode"<<endl;
	cout<<"2- Descending Mode"<<endl;
	cin>>option;
		
	if(option==1)
	    {

    char key;
	cout<<"Please Enter Sort Mode You Want To Sort"<<endl;
	cout<<" A- According to id"<<endl;
	cout<<" B- According to Surname"<<endl;
	cout<<" C- According to Model"<<endl;
	cin>>key;
	switch(key) {
	case 'a' :
	{
       

     for (int i=0;i<100-1;i++)
     {
         for(int j=0;j<100-1-i;j++)
         {
              if (carOwner[j].carID>carOwner[j+1].carID)
              {
              	struct car temp[100],temp2[100];
				  
                 temp[j]= carOwner[j];
                 carOwner[j] = carOwner[j+1];
                 carOwner[j+1]= temp[j];
                
                 
                 
              }
         }
     }
     
     cout<<"\n------------------------------------------------------"<<endl;
     
     for(int i=0; i<101; i++)
		{
			if(carOwner[i].carID==0)
		      {continue;}	 
			else{
		
			cout<<"Car ID : "<<carOwner[i].carID<<endl;
			cout<<"Car Owner Name : "<<carOwner[i].ownerName<<endl;
			cout<<"Car Owner Surname : "<<carOwner[i].ownerSurname<<endl;
			cout<<"Car Model : "<<carOwner[i].carModel<<endl;
			cout<<"Phone Number : "<<carOwner[i].phoneNumber<<endl;
			cout<<"Car Registration Date : "<<carOwner[i].regDate.day<<" "<<carOwner[i].regDate.month<<" "<<carOwner[i].regDate.year<<endl;
			cout<<"Car Next Service Date : "<<carOwner[i].nsDate.day<<" "<<carOwner[i].nsDate.month<<" "<<carOwner[i].nsDate.year<<endl<<endl<<endl;
		
				
				}
		}	
	 
	 
	}
	main();
	break;
	
	
	case 'b' :
	{
       

     for (int i=0;i<100-1;i++)
     {
         for(int j=0;j<100-1-i;j++)
         {
              if (carOwner[j].ownerSurname>carOwner[j+1].ownerSurname)
              {
                 struct car temp[100];
				  
                 temp[j]= carOwner[j];
                 carOwner[j] = carOwner[j+1];
                 carOwner[j+1]= temp[j];
              }
         }
     }
     cout<<"\n-----------------------------------------------------"<<endl;
     for(int i=0; i<101; i++)
		{
			if(carOwner[i].carID==0)
		      {continue;}	 
			else{
		
			cout<<"Car ID : "<<carOwner[i].carID<<endl;
			cout<<"Car Owner Name : "<<carOwner[i].ownerName<<endl;
			cout<<"Car Owner Surname : "<<carOwner[i].ownerSurname<<endl;
			cout<<"Car Model : "<<carOwner[i].carModel<<endl;
			cout<<"Phone Number : "<<carOwner[i].phoneNumber<<endl;
			cout<<"Car Registration Date : "<<carOwner[i].regDate.day<<" "<<carOwner[i].regDate.month<<" "<<carOwner[i].regDate.year<<endl;
			cout<<"Car Next Service Date : "<<carOwner[i].nsDate.day<<" "<<carOwner[i].nsDate.month<<" "<<carOwner[i].nsDate.year<<endl<<endl;
			
				
				}
		}	
	
     
	}
	main();
	break;
	
	case 'c' :
	{
       

     for (int i=0;i<100-1;i++)
     {
         for(int j=0;j<100-1-i;j++)
         {
              if (carOwner[j].carModel>carOwner[j+1].carModel)
              {
                 struct car temp[100];
				  
                 temp[j]= carOwner[j];
                 carOwner[j] = carOwner[j+1];
                 carOwner[j+1]= temp[j];
              }
         }
     }
     cout<<"\n-----------------------------------------------------------"<<endl;
     for(int i=0; i<101; i++)
		{
			if(carOwner[i].carID==0)
		      {continue;}	 
			else{
		
			cout<<"Car ID : "<<carOwner[i].carID<<endl;
			cout<<"Car Owner Name : "<<carOwner[i].ownerName<<endl;
			cout<<"Car Owner Surname : "<<carOwner[i].ownerSurname<<endl;
			cout<<"Car Model : "<<carOwner[i].carModel<<endl;
			cout<<"Phone Number : "<<carOwner[i].phoneNumber<<endl;
			cout<<"Car Registration Date : "<<carOwner[i].regDate.day<<" "<<carOwner[i].regDate.month<<" "<<carOwner[i].regDate.year<<endl;
			cout<<"Car Next Service Date : "<<carOwner[i].nsDate.day<<" "<<carOwner[i].nsDate.month<<" "<<carOwner[i].nsDate.year<<endl<<endl;
			
				
				}
		}		    
     
	}
	main();
	break;												
    }
	}
			
	else if(option==2)	    
{

    char key;
	cout<<"Please Enter Sort Option You Want To Sort"<<endl;
	cout<<" A- According to id"<<endl;
	cout<<" B- According to Surname"<<endl;
	cout<<" C- According to Model"<<endl;
	cin>>key;
	switch(key) {
	case 'a' :
	{
      
       

     for (int i=0;i<100-1;i++)
     {
         for(int j=0;j<100-1-i;j++)
         {
              if (carOwner[j].carID<carOwner[j+1].carID)
              {
                 struct car temp[100];
				  
                 temp[j]= carOwner[j];
                 carOwner[j] = carOwner[j+1];
                 carOwner[j+1]= temp[j];
              }
         }
     }
     cout<<"\n-------------------------------------------------------------------"<<endl;
     for(int i=0; i<101; i++)
		{
			if(carOwner[i].carID==0)
		      {continue;}	 
			else{
		
			cout<<"Car ID : "<<carOwner[i].carID<<endl;
			cout<<"Car Owner Name : "<<carOwner[i].ownerName<<endl;
			cout<<"Car Owner Surname : "<<carOwner[i].ownerSurname<<endl;
			cout<<"Car Model : "<<carOwner[i].carModel<<endl;
			cout<<"Phone Number : "<<carOwner[i].phoneNumber<<endl;
			cout<<"Car Registration Date : "<<carOwner[i].regDate.day<<" "<<carOwner[i].regDate.month<<" "<<carOwner[i].regDate.year<<endl;
			cout<<"Car Next Service Date : "<<carOwner[i].nsDate.day<<" "<<carOwner[i].nsDate.month<<" "<<carOwner[i].nsDate.year<<endl<<endl<<endl;
			
			
				}
		}	

	}
	main();
	break;
	
	
	case 'b' :
	{
       

     for (int i=0;i<100-1;i++)
     {
         for(int j=0;j<100-1-i;j++)
         {
              if (carOwner[j].ownerSurname<carOwner[j+1].ownerSurname)
              {
                struct car temp[100];
				  
                 temp[j]= carOwner[j];
                 carOwner[j] = carOwner[j+1];
                 carOwner[j+1]= temp[j];
              }
         }
     }
     cout<<"\n----------------------------------------------------------------"<<endl;
     for(int i=0; i<101; i++)
		{
			if(carOwner[i].carID==0)
		      {continue;}	 
			else{
		
			cout<<"Car ID : "<<carOwner[i].carID<<endl;
			cout<<"Car Owner Name : "<<carOwner[i].ownerName<<endl;
			cout<<"Car Owner Surname : "<<carOwner[i].ownerSurname<<endl;
			cout<<"Car Model : "<<carOwner[i].carModel<<endl;
			cout<<"Phone Number : "<<carOwner[i].phoneNumber<<endl;
			cout<<"Car Registration Date : "<<carOwner[i].regDate.day<<" "<<carOwner[i].regDate.month<<" "<<carOwner[i].regDate.year<<endl;
			cout<<"Car Next Service Date : "<<carOwner[i].nsDate.day<<" "<<carOwner[i].nsDate.month<<" "<<carOwner[i].nsDate.year<<endl<<endl<<endl;
			
			
				}
		}	

	}
	main();
			break;
	
	case 'c' :
	{
       
       

     for (int i=0;i<100-1;i++)
     {
         for(int j=0;j<100-1-i;j++)
         {
              if (carOwner[j].carModel<carOwner[j+1].carModel)
              {
                 struct car temp[100];
				  
                 temp[j]= carOwner[j];
                 carOwner[j] = carOwner[j+1];
                 carOwner[j+1]= temp[j];
              }
         }
     }
     cout<<"\n----------------------------------------------------------------------------"<<endl;
     for(int i=0; i<101; i++)
		{
			if(carOwner[i].carID==0)
		      {continue;}	 
			else{
		
			cout<<"Car ID : "<<carOwner[i].carID<<endl;
			cout<<"Car Owner Name : "<<carOwner[i].ownerName<<endl;
			cout<<"Car Owner Surname : "<<carOwner[i].ownerSurname<<endl;
			cout<<"Car Model : "<<carOwner[i].carModel<<endl;
			cout<<"Phone Number : "<<carOwner[i].phoneNumber<<endl;
			cout<<"Car Registration Date : "<<carOwner[i].regDate.day<<" "<<carOwner[i].regDate.month<<" "<<carOwner[i].regDate.year<<endl;
			cout<<"Car Next Service Date : "<<carOwner[i].nsDate.day<<" "<<carOwner[i].nsDate.month<<" "<<carOwner[i].nsDate.year<<endl<<endl<<endl;
			
				
				}
		}	

	}
	main();
			break;			
}				
}
}

	

