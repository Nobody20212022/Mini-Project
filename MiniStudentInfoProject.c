#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
struct node
{
  char id[15], name[30], email[30], cell[15], blood[5];
  struct node *next;
};
struct node *studentlist = NULL; // declaring globally for using from anywhere & it's the head of the list
// inserting student data into the newnode
struct node *createstudent(char *id, char *name, char *email, char *cell, char *blood)
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  if (newnode == NULL)
  {
    printf("Memory allocation failed.\n");
    exit(1);
  }
  strcpy(newnode->id, id);
  strcpy(newnode->name, name);
  strcpy(newnode->email, email);
  strcpy(newnode->cell, cell);
  strcpy(newnode->blood, blood);
  newnode->next = NULL;
  return newnode;
}
// inserting newstudent at the end of the list
void insertstudent(char *id, char *name, char *email, char *cell, char *blood)
{
  struct node *newstudent = createstudent(id, name, email, cell, blood);
  if (studentlist == NULL)
  {
    studentlist = newstudent;
  }
  else
  {
    struct node *current = studentlist;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = newstudent;
  }
}
// taking data from user & inserting newstudent at the end of the list
void addnewstudent()
{
  char id[15], name[30], email[30], cell[15], blood[5];
  printf("Enter ID: ");
  scanf("%s", id);
  printf("Enter Name: ");
  getchar();
  gets(name);
  printf("Enter Email: ");
  scanf("%s", email);
  printf("Enter Cell: ");
  scanf("%s", cell);
  printf("Enter Blood Group: ");
  scanf("%s", blood);
  insertstudent(id, name, email, cell, blood);
  printf("New student added successfully!\n\n");
}
// displaying one node
void display(struct node *current)
{
  printf("ID: %s\n", current->id);
  printf("Name: %s\n", current->name);
  printf("Email: %s\n", current->email);
  printf("Cell: %s\n", current->cell);
  printf("Blood Group: %s\n\n", current->blood);
}
// displaying full list
void displaystudent()
{
  struct node *current = studentlist;
  while (current != NULL)
  {
    display(current);
    current = current->next;
  }
}
// searching by id
void searchid(char *id)
{
  struct node *current = studentlist;
  int c = 0;
  while (current != NULL)
  {
    if (strcmp(current->id, id) == 0)
    {
      if (c != 1)
        printf("\nStudent found:\n");
      display(current);
      c = 1;
    }
    current = current->next;
  }
  if (c == 0)
    printf("\nStudent's Information Not Found\n");
}
// searching by name
void searchname(char *name)
{
  struct node *current = studentlist;
  int c = 0;
  while (current != NULL)
  {
    if (strcmp(current->name, name) == 0)
    {
      if (c != 1)
        printf("\nStudent found:\n");
      display(current);
      c = 1;
    }
    current = current->next;
  }
  if (c == 0)
    printf("\nStudent's Information Not Found\n");
}
// searching by email
void searchemail(char *email)
{
  struct node *current = studentlist;
  int c = 0;
  while (current != NULL)
  {
    if (strcmp(current->email, email) == 0)
    {
      if (c != 1)
        printf("\nStudent found:\n");
      display(current);
      c = 1;
    }
    current = current->next;
  }
  if (c == 0)
    printf("\nStudent's Information Not Found\n");
}
// searching by cell number
void searchcell(char *cell)
{
  struct node *current = studentlist;
  int c = 0;
  while (current != NULL)
  {
    if (strcmp(current->cell, cell) == 0)
    {
      if (c != 1)
        printf("\nStudent found:\n");
      display(current);
      c = 1;
    }
    current = current->next;
  }
  if (c == 0)
    printf("\nStudent's Information Not Found\n");
}
// searching by blood
void searchblood(char *blood)
{
  struct node *current = studentlist;
  int c = 0;
  while (current != NULL)
  {
    if (strcmp(current->blood, blood) == 0)
    {
      if (c != 1)
        printf("\nStudent found:\n");
      display(current);
      c = 1;
    }
    current = current->next;
  }
  if (c == 0)
    printf("\nStudent's Information Not Found\n");
}
// main searching function
void searchstudent()
{
  while (1)
  {
    system("cls");
    printf("Search Student Information\n");
    printf("=============================================\n");
    printf("1.Search By ID\n2.Search By Name\n3.Search By Email\n4.Search By Cell Phone Number\n5.Search By Blood\n6.Back TO Main Menu\n\n");
    printf("Enter your choice: ");
    int x;
    scanf("%d", &x);
    if (x == 1)
    {
      printf("Enter the ID: ");
      char id[15];
      scanf("%s", &id);
      system("cls");
      searchid(id);
    }
    else if (x == 2)
    {
      printf("Enter the Name: ");
      char name[30];
      getchar();
      gets(name);
      system("cls");
      searchname(name);
    }
    else if (x == 3)
    {
      printf("Enter the Email: ");
      char email[30];
      scanf("%s", email);
      system("cls");
      searchemail(email);
    }
    else if (x == 4)
    {
      printf("Enter the Cell Phone Number: ");
      char cell[15];
      scanf("%s", cell);
      system("cls");
      searchcell(cell);
    }
    else if (x == 5)
    {
      printf("Enter the Blood Group: ");
      char blood[5];
      scanf("%s", blood);
      system("cls");
      searchblood(blood);
    }
    else
      return;
    printf("Press Enter to continue...");
    getchar();
    getchar();
  }
}
// updating by id
void update()
{
  char id[15], name[30], email[30], cell[15], blood[5];
  printf("Enter the student ID to update: ");
  scanf("%s", id);
  struct node *current = studentlist;
  while (current != NULL)
  {
    if (strcmp(current->id, id) == 0)
    {
      printf("\nEnter the updated information for student %s:\n", id);
      printf("Enter Name: ");
      getchar();
      gets(name);
      printf("Enter Email: ");
      scanf("%s", email);
      printf("Enter Cell: ");
      scanf("%s", cell);
      printf("Enter Blood Group: ");
      scanf("%s", blood);
      strcpy(current->name, name);
      strcpy(current->email, email);
      strcpy(current->cell, cell);
      strcpy(current->blood, blood);
      printf("Student %s updated successfully!\n\n", id);
      return;
    }
    current = current->next;
  }
  printf("Student with ID %s not found.\n\n", id);
}
// inserting newstudent at a specific position
void insertatposition()
{
  char id[15], name[30], email[30], cell[15], blood[5];
  int position;
  printf("Enter the position: ");
  scanf("%d", &position);
  printf("Enter ID: ");
  scanf("%s", id);
  printf("Enter Name: ");
  getchar();
  gets(name);
  printf("Enter Email: ");
  scanf("%s", email);
  printf("Enter Cell: ");
  scanf("%s", cell);
  printf("Enter Blood Group: ");
  scanf("%s", blood);
  struct node *newStudent = createstudent(id, name, email, cell, blood);
  if (position == 1)
  {
    newStudent->next = studentlist;
    studentlist = newStudent;
  }
  else
  {
    struct node *current = studentlist;
    int currentPosition = 1;

    while (current != NULL && currentPosition < position - 1)
    {
      current = current->next;
      currentPosition++;
    }

    if (current == NULL)
    {
      printf("Invalid position. The linked list is not long enough for the specified position.\n\n");
      free(newStudent);
      return;
    }
    newStudent->next = current->next;
    current->next = newStudent;
  }
  printf("New student added at position %d successfully!\n\n", position);
}
// deleting from the list
void delete()
{
  char id[15];
  printf("Enter the student ID to delete: ");
  scanf("%s", id);
  struct node *current = studentlist;
  struct node *prev = NULL;
  while (current != NULL)
  {
    if (strcmp(current->id, id) == 0)
    {
      if (prev == NULL)
      {
        studentlist = current->next;
      }
      else
      {
        prev->next = current->next;
      }
      free(current);
      printf("Student with ID %s deleted successfully!\n\n", id);
      return;
    }
    prev = current;
    current = current->next;
  }
  printf("Student with ID %s not found.\n\n", id);
}

int main()
{
  int choice;
  insertstudent("221-15-4755", "Nasima Akter", "nasima15-4755@diu.edu.bd", "0171", "A+");
  insertstudent("221-15-4792", "Anuradha Das", "anuradha15-4792@diu.edu.bd", "0172", "A-");
  insertstudent("221-15-4794", "Rakib Hosen", "rakib15-4794@diu.edu.bd", "0173", "B+");
  insertstudent("221-15-4802", "Salman Ahmed", "salman15-4802@diu.edu.bd", "0174", "B-");
  insertstudent("221-15-4893", "Mirajul", "mirajul15-4893@diu.edu.bd", "0175", "O+");
  insertstudent("221-15-4902", "Tanjina Ahmed", "tanjina15-4902@diu.edu.bd", "0176", "O-");
  insertstudent("221-15-4903", "Tanjid Ahammed", "tanjid15-4903@diu.edu.bd", "0177", "AB+");
  insertstudent("221-15-4916", "Sabbir Ahmed", "sabbir15-4916@diu.edu.bd", "0178", "AB-");
  insertstudent("221-15-4918", "Rumaia Khan", "rumaia15-4918@diu.edu.bd", "0179", "A+");
  insertstudent("221-15-4928", "Jannatul Ferdous", "jannatul15-4928@diu.edu.bd", "0180", "A-");
  insertstudent("221-15-4953", "Sohana Sultana", "sohana15-4953@diu.edu.bd", "0181", "B+");
  insertstudent("221-15-4982", "Jannatul Ferdaus", "jannatul15-4982@diu.edu.bd", "0182", "B-");
  insertstudent("221-15-5077", "Sumaiya binte", "sumaiya15-5077@diu.edu.bd", "0183", "O+");
  insertstudent("221-15-5100", "Lamia Akter", "lamia15-5100@diu.edu.bd", "0184", "O-");
  insertstudent("221-15-5115", "Tonima", "tonima15-5115@diu.edu.bd", "0185", "AB+");
  insertstudent("221-15-5127", "Md. Najmus", "md15-5127@diu.edu.bd", "0186", "AB-");
  insertstudent("221-15-5142", "Anika Afrin", "anika15-5142@diu.edu.bd", "0187", "A+");
  insertstudent("221-15-5151", "RAFID", "rafid15-5151@diu.edu.bd", "0188", "O+");
  insertstudent("221-15-5156", "Jarif", "jarif15-5156@diu.edu.bd", "0189", "B+");
  insertstudent("221-15-5222", "Jamil Hasan", "jamil15-5222@diu.edu.bd", "01701", "B-");
  insertstudent("221-15-5251", "Eiamin Hasan", "eiamin15-5251@diu.edu.bd", "01702", "O+");
  insertstudent("221-15-5292", "Atique Enam", "atique15-5292@diu.edu.bd", "01703", "O-");
  insertstudent("221-15-5300", "Nehal", "nehal15-5300@diu.edu.bd", "01704", "AB+");
  insertstudent("221-15-5308", "Iftekharul Islam", "iftekharul15-5308@diu.edu.bd", "01705", "AB-");
  insertstudent("221-15-5322", "Jahangir Alam", "jahangir15-5322@diu.edu.bd", "01706", "A+");
  insertstudent("221-15-5334", "Nahid", "nahid15-5334@diu.edu.bd", "01707", "A-");
  insertstudent("221-15-5371", "Rinvi Jaman", "rinvi15-5371@diu.edu.bd", "01708", "B+");
  insertstudent("221-15-5375", "Atia Sultana", "atia15-5375@diu.edu.bd", "01709", "B-");
  insertstudent("221-15-5376", "Pulak Deb", "pulak15-5376@diu.edu.bd", "01710", "O+");
  insertstudent("221-15-5390", "Sirajes", "sirajes15-5390@diu.edu.bd", "01711", "O-");
  insertstudent("221-15-5428", "Hossain Mohammad", "hossain15-5428@diu.edu.bd", "01712", "AB+");
  insertstudent("221-15-5448", "Mahfuj Ahmed", "mahfuj15-5448@diu.edu.bd", "01713", "AB-");
  insertstudent("221-15-5459", "Md. Abir", "md15-5459@diu.edu.bd", "01714", "A+");
  insertstudent("221-15-5494", "Rafi", "rafi15-5494@diu.edu.bd", "01715", "A-");
  insertstudent("221-15-5498", "Islam", "islam15-5498@diu.edu.bd", "01716", "B+");
  insertstudent("221-15-5540", "Adnan", "adnan15-5540@diu.edu.bd", "01717", "B-");
  insertstudent("221-15-5557", "Emon", "emon15-5557@diu.edu.bd", "01718", "O+");
  insertstudent("221-15-5569", "Azmira", "azmira15-5569@diu.edu.bd", "01719", "O-");
  insertstudent("221-15-5588", "Prapti Saha", "prapti15-5588@diu.edu.bd", "01720", "AB+");
  insertstudent("221-15-5598", "MD Rofiqul", "md15-5598@diu.edu.bd", "01721", "AB-");
  insertstudent("221-15-5609", "FOUJIA Afrose Tanha", "foujia15-5609@diu.edu.bd", "01722", "A+");
  insertstudent("221-15-5643", "Kouser Ahamed", "kouser15-5643@diu.edu.bd", "01723", "A-");
  insertstudent("221-15-5655", "Arpon", "arpon15-5655@diu.edu.bd", "01724", "B+");
  insertstudent("221-15-5671", "Happy", "happy15-5671@diu.edu.bd", "01725", "B-");
  insertstudent("221-15-5713", "Abdullah Al Noman", "abdullah15-5713@diu.edu.bd", "01726", "O+");
  insertstudent("221-15-5740", "Mahamudul Hasan", "mahamudul15-5740@diu.edu.bd", "01727", "O-");
  insertstudent("221-15-5750", "Taifur Rahman", "taifur15-5750@diu.edu.bd", "01728", "AB+");
  insertstudent("221-15-5777", "Sazzad Mahmud", "sazzad15-5777@diu.edu.bd", "01729", "AB-");
  insertstudent("221-15-5785", "Shovan Samanta", "shovan15-5785@diu.edu.bd", "01730", "A+");
  insertstudent("221-15-5786", "Hasan", "hasan15-5786@diu.edu.bd", "01731", "A-");
  insertstudent("221-15-5924", "Siam akter", "siam15-5924@diu.edu.bd", "01732", "B+");
  while (1)
  {
    system("cls");
    system("color 9");
    printf("=============================================\n");
    printf("         Student Information Mini Project\n");
    printf("=============================================\n");
    printf("1. Add New Student\n");
    printf("2. Add a New Student At a Specific Position\n");
    printf("3. Search\n");
    printf("4. Update\n");
    printf("5. Delete\n");
    printf("6. Display Student List\n");
    printf("7. Exit\n");
    printf("=============================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      // Option to add a new student
      system("cls");
      printf("Add New Student\n");
      printf("=============================================\n");
      addnewstudent();
      getchar();
      break;
    case 2:
      // Option to add a new student at a specific position
      system("cls");
      printf("Add New Student At a Specific Position\n");
      printf("=============================================\n");
      insertatposition();
      getchar();
      break;
    case 3:
      // Option to search for a student
      searchstudent();
      getchar();
      break;
    case 4:
      // Option to update a student's information
      system("cls");
      printf("Upadte Student Information\n");
      printf("=============================================\n");
      update();
      getchar();
      break;
    case 5:
      // Option to delete a student
      system("cls");
      printf("Delete Student Information\n");
      printf("=============================================\n");
      delete ();
      getchar();
      break;
    case 6:
      // Option to display the student list
      system("cls");
      printf("Students List\n");
      printf("=============================================\n");
      displaystudent();
      getchar();
      break;
    case 7:
      system("cls");
      printf("Exiting program");
      for (int i = 0; i < 5; i++)
      {
        printf(".");
        usleep(500000);
      }
      break;
    default:
      printf("Invalid choice. Please enter a valid option.\n");
      getchar();
    }
    if (choice == 7)
      break;
    printf("Press Enter to continue...");
    getchar();
  }
}
/*Important notes:  1. use char pointer in parameter for string
                    2. use strcpy for assinging string into the node
                    3. use strcmp for comparison
                    4. strcmp is 0 if the two strings are equal
*/
