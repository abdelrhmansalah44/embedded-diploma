/*
 ============================================================================
 Name        : single.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define printing(...)  {fflush(stdout); \
						fflush(stdin); \
                       printf(__VA_ARGS__); \
					   fflush(stdout); \
						fflush(stdin);}

struct sdata{
	char name[40];
	int id;
	float height;

};

struct sstudent{
	struct sdata student;
	struct sstudent *pnextstudent;
};

struct sstudent *pfirststudent = NULL;

void addstudent() {

	struct sstudent *pnewstudent;
	struct sstudent *plaststudent;
	char dataarr[40];

	if(pfirststudent == NULL)
	{
		pnewstudent = (struct sstudent*)malloc(sizeof(struct sstudent));
		pfirststudent = pnewstudent;
	}
	else
	{
		plaststudent = pfirststudent;
		while(plaststudent->pnextstudent)
		{
			plaststudent =plaststudent->pnextstudent;
		}

		pnewstudent = (struct sstudent*)malloc(sizeof(struct sstudent));

		plaststudent->pnextstudent = pnewstudent;


	}

	printing("enter the student name \n");
	gets(pnewstudent->student.name);

	printing("enter the student id \n");
	gets(dataarr);
	pnewstudent->student.id = atoi(dataarr);

	printing("enter the student height \n");
	gets(dataarr);
	pnewstudent->student.height = atof(dataarr);




	pnewstudent->pnextstudent=NULL;


};

int delete()
{
	char dataarr[40];
	int selected_id;

	printing("enter the student id to be deleted\n");
	gets(dataarr);
	selected_id = atoi(dataarr);


     struct sstudent *pselectedstudent=pfirststudent;
     struct sstudent *pprevious_student = NULL;

     if(pfirststudent)
     {

    while(pselectedstudent)
     {
         if(pselectedstudent->student.id == selected_id)
         {
        	 if(pprevious_student)
        	 {
                pprevious_student->pnextstudent = pselectedstudent->pnextstudent;
        	 }

        	 else
        	 {
        		 //first student is the choosen
        		 pfirststudent = pselectedstudent->pnextstudent;

        	 }

        	 free(pselectedstudent);
        	 return 1;
         }
         // if the pselected is not the selected id then we will jump to the next record
         // increment
    pprevious_student =pselectedstudent;
    pselectedstudent = pselectedstudent->pnextstudent;

     }
    //in case we get out of the while loop without finding the id then it didnt exist
    printing("id not found on the list");
    return 0;

     }
     return 0;

};


void viewstudents()
{
	struct sstudent *pviewstudents = pfirststudent;
	int count =1;
	if(!pfirststudent)
	{
		printing("empty list\n");

	}

	else
	{
	while(pviewstudents)
	{
		printing("student id: %d",pviewstudents->student.id);
		printing("student id: %s",pviewstudents->student.name);
		printing("student id: %f",pviewstudents->student.height);

		pviewstudents = pviewstudents->pnextstudent;
		count++;
	}
	}

};


void deleteall()
{
	struct sstudent *pviewstudents = pfirststudent;

		if(pfirststudent)
		{
			printing("empty list\n");

		}

		else
		{
		while(pviewstudents)
		{
			struct sstudent *pdeleted=pviewstudents;

			pviewstudents = pviewstudents->pnextstudent;
            free(pdeleted);

		}
		}
		pfirststudent = NULL;

};

void Nthnode()
{
	struct sstudent *pnthnode=pfirststudent;
	int count=1;
	int indx;
	char dataarr[40];
	printing("\tenter the index\n");
	gets(dataarr);
	indx = atoi(dataarr);


	if(pfirststudent)
	{
	while(pnthnode)
	{

		if(count == indx)
		{

			printing("name of student at index %d is:%s \n",indx,pnthnode->student.name);
			printing("id of student at index %d is:%d \n",indx,pnthnode->student.id);
			printing("height of student at index %d is:%f \n",indx,pnthnode->student.height);
			break;
		}
		else{

			pnthnode = pnthnode->pnextstudent;
			count++;
		}
	}

	}

};

void getlength()
{

	struct sstudent *plength=pfirststudent;
	int count =1;

	if(pfirststudent)
	{
		while(plength->pnextstudent !=NULL)
		{
			plength=plength->pnextstudent;
			count++;
		}

		printing("length of the list is:%d\n",count);
	}



};


void Nthnode_reversed()
{
	struct sstudent *pmain=pfirststudent , *pref=pfirststudent;
	int indx;
	char dataarr[40];
		printing("\tenter the index\n");
		gets(dataarr);
		indx = atoi(dataarr);

	if(pfirststudent)
	{
		for(int i=1;i<=indx;i++)
		{
			pref=pref->pnextstudent;
		}


		while(pref!=NULL)
		{
			pmain=pmain->pnextstudent;
            pref=pref->pnextstudent;
		}
		printing("the id at index %d from the end is %d\n",indx,pmain->student.id);
		printing("the name at index %d from the end is %s\n",indx,pmain->student.name);
		printing("the height at index %d from the end is %f\n",indx,pmain->student.height);

	}

};


void middlerecord()
{
	struct sstudent *pfast=pfirststudent , *pslow= pfirststudent;
if(pfirststudent)
{
	while(pfast)
	{

		if(pfast->pnextstudent!=NULL)
		{
			pslow = pslow->pnextstudent;
			pfast = pfast->pnextstudent->pnextstudent;

		}
		else
		{
			pfast=pfast->pnextstudent;
		}


	}
		printing("the id of the middle record is %d\n", pslow->student.id);
		printing("the name of the middle record is %s\n", pslow->student.name);
		printing("the height of the middle record is %f\n",pslow->student.height);
}
};



int main()
{

     char dataview[40];
     while(1)
     {
     printing("\tchoose the operation \n");
     printing("=============================\n");
     printing("1: addstudent\n");
     printing("2: deletestudent\n");
     printing("3: viewstudent\n");
     printing("4: deleteall\n");
     printing("5: Nthnode\n");
     printing("6: getlength\n");
     printing("7: Nthnode_reversed\n");
     printing("8: middle record\n");
     printing("=============================\n");
     printing("enter option number\n");

     gets(dataview);

     switch(atoi(dataview))
     {
     case 1:
    	 addstudent();
    	 break;

     case 2:
    	 delete();
    	 break;
     case 3:
    	 viewstudents();
    	 break;

     case 4:
    	 deleteall();
    	 break;

     case 5:
    	 Nthnode();
    	 break;

     case 6:
    	 getlength();
    	 break;

     case 7:
    	 Nthnode_reversed();
    	 break;

     case 8:
    	 middlerecord();
    	 break;

     default:
    	 printing("wrong option \n");
    	 break;

     }
     }
     return 0;



};







