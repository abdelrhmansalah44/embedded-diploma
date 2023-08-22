/*
 * queue.c
 *
 *  Created on: Aug 16, 2023
 *      Author: abdalrahman salah
 */

#include "queue.h"

#define f fflush(stdin);fflush(stdout);

void show_student_data(student_element *ptr)
{
	printf("student id number is: %d\n",ptr->student_id);
	printf("student first name is: %s\n",ptr->first_name);
	printf("student last name is: %s\n",ptr->last_name);
	printf("student gpa is: %f\n",ptr->gpa);
	for(int i=1;i<=5;i++)
	{
		printf("student course no:%d id is:%d\n ",i,ptr->course_id[i]);
	}
printf("===========================================\n");

}
//=======================================================================================
//=======================================================================================


void queue_init()
{
	qu.head = queue_arr;
	qu.tail = queue_arr;
	qu.base = queue_arr;
	qu.count = 0;
	qu.length = 50;

}
//=======================================================================================
//=======================================================================================



 queue_status add_student_manually()
{
	 int new_id;
	 //check if the queue is empty or not
	 if(!qu.base || !qu.head || !qu.tail)
		 return queue_empty;

	 //check if queue full or not
	 if(qu.length == qu.count)
		 return queue_full;

	 //not full
	 printf("enter the student data\n");
	 printf("========================\n");


	 printf("enter student id\n");
	 f
	 scanf("%d",&new_id);

	//check if the id is unique
	 int unique = 1;
	 for(int i=0;i<qu.count ; i++)
	 {
		 if(qu.tail->student_id == new_id)
			 unique =0;
		 qu.tail++;
	 }
	 qu.tail =qu.base;

	 //adding student id.
	 if(unique)
	 {
	 qu.head->student_id = new_id;

	 }
	 else{
		 printf("[ERROR] id already taken\n");
		 printf("==========================");
		 return queue_error;
	 }

	 //entering student first name
	 printf("enter student first name\n");
	 f
	 scanf("%s",qu.head->first_name);

	 //entering student last name
	 printf("enter student last name\n");
	 f
	 scanf("%s",qu.head->last_name);

	 //entering student gpa
	 printf("enter student gpa\n");
	 f
	 scanf("%f",&(qu.head->gpa));

	 //entering student courses
	 for(int i=1; i<=5; i++)
	 {
		 printf("course %d ID:",i);
		 f
		 scanf("%d",&(qu.head->course_id[i]));
		 printf("\n");
	 }

	 printf("[info] student data has been updated\n");
	 printf("======================================\n");


	 qu.head++;
		 qu.count++;




	return queue_no_error;
}
//=======================================================================================
//=======================================================================================



queue_status add_student_file()
{
	 if(!qu.base || !qu.head || !qu.tail)
			 return queue_empty;

		 //check if queue full or not
		 if(qu.length == qu.count)
			 return queue_full;



		 FILE *filepointer;
		 filepointer = fopen("file2.txt","r");

		 if(filepointer!=NULL)
		 {

		 while(!feof(filepointer) && ferror(filepointer)) //loop until the end of file
		 {
			 int file_id;
			 printf("enter the student id from file\n");
			 f
			 fscanf(filepointer,"%d",&file_id);

			 //check if the id is unique
			 int unique = 1;
			 	 for(int i=0;i<qu.count ; i++)
			 	 {
			 		 if(qu.tail->student_id == file_id)
			 		 {
			 			 unique =0;
			 		     fscanf(filepointer, "%*[^\n]");
			 	 }
			 		     qu.tail++;
		 }
			 	 qu.tail =qu.base;


			 	 if(unique)
			 	 {
			 		 qu.head->student_id= file_id;
			 		 printf("student first name from file is:\n");
			 		 f
					 fscanf(filepointer,"%s",qu.head->first_name);

			 		 printf("student last name from file is:\n");
			 		 f
					 fscanf(filepointer,"%s",qu.head->last_name);

			 		 printf("student gpa from file is:\n");
			 		 f
					 fscanf(filepointer,"%f",&qu.head->gpa);

			 		 for(int i=1;i<=5;i++)
			 		 {
			 			 printf("student courses is");
			 		 	 f
						 fscanf(filepointer,"%u",&qu.head->course_id[i]);
			 		 }

			 		 printf("student info from file added succesfully\n");
			 		 printf("===================================\n");
			 		 qu.head++;
			 		 qu.count++;
			 	 }

			 	 else
			 	 {
			 		 printf("[error] id is already taken\n");
			 		 printf("======================\n");
			 		 return queue_error;
			 	 }

		 }
		 }

		 else
		 {
		printf("[error] no file found\n");
		printf("====================\n");
		return queue_error;

		 }
		 fclose(filepointer);


return queue_no_error;
}
//=======================================================================================
//=======================================================================================


queue_status find_ID()
{
	 int find_id;

	if(qu.count != 0) {

	printf("enter the id you want to found\n");
	 f
	 scanf("%d",&find_id);



	 for(int i=0;i<qu.count ;i++)
	 {

		 if(qu.tail->student_id == find_id)
		 {
			 printf("student id no:%d is found\n",find_id);
			 show_student_data(qu.tail);
			 return queue_no_error;
		 }
		 else
		 {

	 printf("[error] id not found\n");
	 printf("-----------------------\n");
	 break;
		 }
		    qu.tail++;
	 }
	 qu.tail =qu.base;


}

	else
	{

		printf("id not found\n");
		printf("====================\n");
		return queue_error;
	}
	 return queue_no_error;
}
//=======================================================================================
//=======================================================================================


queue_status find_firstname()
{
int flag=1;
	 unsigned char find_f_name[15];


		 if(qu.count != 0)
		 {
		 printf("enter the student first name you want to found\n");
		 f
		 scanf("%s",find_f_name);

		 for(int i=0;i<qu.count ;i++)
		 {

			 if(!strcmp(find_f_name,qu.tail->first_name))
			 {
				 show_student_data(qu.tail);
				 flag=1;
				 break;
			 }
                qu.tail++;

		 }
			 qu.tail =qu.base;

		if(!flag)//-|-
		{
			printf("first name not found\n");
			printf("=======================\n");
		}
		else
		{
			return queue_no_error;
		}

		 }

		 else {

			 printf("queue is empty \n");
			 return queue_empty;
		 }

		 return queue_no_error;
	}
//=======================================================================================
//=======================================================================================


queue_status find_course()
{
	//If buffer is empty
		if(!qu.count){
			puts("[ERROR] There is NO Data");
			return queue_empty;
		}

		//IF buffer is not empty
		unsigned int  wanted_CourseID;
		printf("Enter the Course ID: ");
		f
		scanf("%u",&wanted_CourseID);

		uint32_t count = 0;
		//loops till find wanted course ID
		for(int i = 0;  i<qu.count; i++){
			for(int j = 0; j<5; j++){
				if(wanted_CourseID == qu.tail->course_id[j]){
					show_student_data(qu.tail);
					count++;
				}
			}
			qu.tail++;
		}
		//reset tail
		qu.tail = qu.base;

		//IF course ID exists
		if(count){
			printf("[INFO] Total Numbers of Students Enrolled: %u\n",count);
			puts("------------------------");
			return queue_no_error;
		}
		//IF course ID does NOT exist
		else
		{
			printf("[ERROR] Course ID %d was not found\n",wanted_CourseID);
			puts("------------------------");
			return queue_error;
		}
		 return queue_no_error;
	}
//===============================================================================
//===============================================================================


queue_status count()
{
   if(!qu.count)
   {
	   printf("queue is empty\n");
	   printf("================\n");
	   return queue_empty;
   }
   else if(qu.count == 50)
   {
	   printf("queue is full\n");
	   printf("================\n");
	  return queue_full;
   }
   else
   {
	   printf("number of students in the data base is: %d\n",qu.count);
	   printf("you can add more %d students\n",50-qu.count);
	   printf("=============================================\n");

   }
   return queue_no_error;
}
//==================================================================================
//==================================================================================


queue_status delete_student()
{
	 int delete_id;
     student_element swap={0};
    if(qu.count)
    {
    	printf("enter the id of the student you want to delete\n");
    	f
		scanf("%d",&delete_id);

    	for(int i=0; i<qu.count;i++)
    	{
			if(qu.tail->student_id == delete_id)
			{
				*(qu.tail)=swap;
				qu.count--;
                qu.head--;
			}
			qu.tail++;
    	}
    	printf("student deleted\n");
    	printf("==================\n");

    }
    else
    {
    	 printf("[error] no data\n");
    			 printf("==================\n");
    			 return queue_empty;
    }

    return queue_no_error;

}
//=======================================================================================
//=======================================================================================


 queue_status update_student()
{
    int update_id;
int flag=1;
    if(qu.count==0)

    {
    			printf("[error] no data\n");
    			printf("==================\n");
    			return queue_empty;
    }

    else
    {
    printf("enter the id of the student you want to update\n");
    f
	scanf("%d",&update_id);

    	for(int i=0;i<qu.count;i++)
    	{
    		if(qu.tail->student_id == update_id)
    		{

    		  flag =1;
    			int choise;
    			printf("1. update first name\n");
    			printf("2. update last name\n");
    			printf("3. update gpa \n");
    			printf("4. update id \n");



    			printf("enter your choice:\n");
    			f
				scanf("%d",&choise);

    			switch(choise)
    			{

    			case 1:
    			printf("enter the new first name\n");
    			f
				scanf("%s",qu.tail->first_name);
    			break;

    			case 2:
    			printf("enter the new last name\n");
    			f
				scanf("%s",qu.tail->last_name);
    			break;

    			case 3:
    			printf("enter the new gpa\n");
    			f
				scanf("%f",&qu.tail->gpa);
    			break;

    			case 4:
    				printf("enter the new id \n");
					f
					scanf("%d",&qu.tail->student_id);
    			break;

    			default:
    				printf("wrong choice please try again\n");
    				break;
    			}
    		break;
    		}
    		qu.tail++;


    		if(!flag)
    		{
    			printf("id not found\n");
    			printf("======================\n");
    			return queue_error;
    		}

    	}
    		qu.tail=qu.base;


    }


  return queue_no_error;
}

//=======================================================================================
//=======================================================================================


 queue_status show_all()
{
	 if(!qu.count)
	 {
		 printf("[error] no data\n");
		 printf("==================\n");
		 return queue_empty;
	 }


		 for(int i=0;i<qu.count;i++)
		 {
			 show_student_data(qu.tail);
			 qu.tail++;
		 }
		 qu.tail=qu.base;


	 return queue_no_error;
}
