#include <iostream>
#include <limits>

/**
   This implementation of a double-ended queue (deque) utilizes two different arrays to achieve 
   a program with which a user can add to the front, add to the rear, remove from the front, remove from the rear,
   display the front, display the rear, and add all values of the deque in seamless fashion and at their leisure  
**/

int arraySize, arraySize2, toFront, toBack, sum = 0;
int *array = new int[arraySize];
int *array2 = new int[arraySize2];
bool flag = true;
bool flag2 = false;
bool isNumber = true;
bool exists = true;
std::string selection = "";

/**
   void method pushFront to add an element to the front of the deque
   refer to lines 59 to 67 for main logic, the rest is mostly input validation and styling 
**/

void pushFront()
{
   do
   {
      isNumber = false;
      exists = false;
      std::cout << "\nWhat would you like to add to the front?: ";
      std::cin >> toFront;
      if (std::cin.fail())
      {
         isNumber = true;
         toFront = 0;
         std::cout << "\nMust enter a number\n";
         std::cin.clear();
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      for (int i = 0; i < arraySize; i++)
      {
         if (toFront == array[i])
         {
            exists = true;   
         }
      }
      for (int i = 0; i < arraySize2; i++)
      {
         if (toFront == array2[i])
         {
            exists = true;   
         }
      }
      if (exists)
      {
         std::cout << "\n" << toBack << " already exists within the deque\n";
      }
   } while (isNumber || exists);
   for (int i = arraySize; i >= 0; i--)
   {
      array[arraySize] = toFront;
      std::cout << "\n" << array[i];    
   }
   for (int i = 0; i < arraySize2; i++)
   {
      std::cout << "\n" << array2[i];    
   }
   std::cout << "\n";
}

/**
   void method pushBack to add an element to the back or "rear" of the deque
   refer to lines 111 to 119 for main logic, the rest is mostly input validation and styling 
**/

void pushBack()
{
   do
   {
      isNumber = false;
      exists = false;
      std::cout << "\nWhat would you like to add to the back?: ";
      std::cin >> toBack;
      if (std::cin.fail())
      {
         isNumber = true;
         toBack = 0;
         std::cout << "\nMust enter a number\n";
         std::cin.clear();
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      for (int i = 0; i < arraySize2 - 1; i++)
      {
         if (toBack == array2[i])
         {
            exists = true;   
         }
      }
      for (int i = 0; i < arraySize; i++)
      {
         if (toBack == array[i])
         {
            exists = true;   
         }
      }
      if (exists)
      {
         std::cout << "\n" << toBack << " already exists within the deque\n";
      }
   } while (isNumber || exists);
   for (int i = arraySize - 1; i >= 0; i--)
   {
      std::cout << "\n" << array[i];
   }
   for (int i = 0; i < arraySize2; i++)
   {
      array2[arraySize2 - 1] = toBack;
      std::cout << "\n" << array2[i];    
   }
   std::cout << "\n";
}

/**
   void method popFront to remove an element from the front of the deque
   checks if deque (both arrays) are empty
   size of array(s) decrease(s) when an element is removed  
**/

void popFront()
{
   if (arraySize == 0 && arraySize2 <= 1)
   {
      arraySize = 0;
      arraySize2 = 0;
      std::cout << "\nDeque is empty";
   }
   else if (arraySize <= 1 && arraySize2 == 0)
   {
      arraySize = 0;
      arraySize2 = 0;
      std::cout << "\nDeque is empty";
   }
   else if (arraySize == 0 && arraySize2 != 0)
   {
      for (int i = 0; i < arraySize2; i++)
      {
         array2[i] = array2[i + 1];           
      }
      arraySize2--;
      for (int i = 0; i < arraySize2; i++)
      {
         std::cout << "\n" << array2[i];           
      }      
   }
   else
   {
      arraySize--;
      for (int i = arraySize - 1; i >= 0; i--)
      {
         std::cout << "\n" << array[i];    
      }
      for (int i = 0; i < arraySize2; i++)
      {
         std::cout << "\n" << array2[i];    
      }
   }
   std::cout << "\n";
}

/**
   void method popBack to remove an element from the back or "rear" of the deque
   checks if deque (both arrays) are empty
   size of array(s) decrease(s) when an element is removed  
**/

void popBack()
{
   if (arraySize2 == 0 && arraySize <= 1)
   {
      arraySize = 0;
      arraySize2 = 0;
      std::cout << "\nDeque is empty";
   }
   else if (arraySize2 <= 1 && arraySize == 0)
   {
      arraySize = 0;
      arraySize2 = 0;
      std::cout << "\nDeque is empty";
   }
   else if (arraySize2 == 0)
   {
      for (int i = 0; i < arraySize; i++)
      {
         array[i] = array[i + 1];
      }
      arraySize--;   
      for (int i = arraySize - 1; i >= 0; i--)
      {
         std::cout << "\n" << array[i];           
      }
   }
   else
   {
      for (int i = arraySize - 1; i >= 0; i--)
      {
         std::cout << "\n" << array[i];    
      }
      arraySize2--;
      for (int i = 0; i < arraySize2; i++)
      {
         std::cout << "\n" << array2[i];    
      }
   }
   std::cout << "\n";   
}

/**
   void method peekFront to display the the value at the front of the deque
   checks if deque (both arrays) are empty  
**/

void peekFront()
{
   if (arraySize == 0 && arraySize2 != 0)
   {
      std::cout << "\n" << array2[0] << "\n";
   }
   else if (arraySize2 == 0 && arraySize == 0)
   {
      std::cout << "\nDeque is empty\n";
   }
   else
   {
      std::cout << "\n" << array[arraySize - 1] << "\n";
   }
}

/**
   void method peekBack to display the the value at the back of the deque
   checks if deque (both arrays) are empty  
**/

void peekBack()
{
   if (arraySize2 == 0 && arraySize != 0)
   {
      std::cout << "\n" << array[0] << "\n";   
   }
   else if (arraySize2 == 0 && arraySize == 0)
   {
      std::cout << "\nDeque is empty\n";
   }
   else
   {
      std::cout << "\n" << array2[arraySize2 - 1] << "\n";
   }
}

/**
   int method add to add all values of the deque and return the sum
   @return sum  
**/

int add()
{
   sum = 0;
   for (int i = 0; i < arraySize; i++)
   {
      sum += array[i];
   }
   for (int i = 0; i < arraySize2; i++)
   {
      sum += array2[i];
   }
   return sum;
}

/**
   void method mainMenu to allow the user to interact freely with the deque methods
   user can pushFront, pushBack, popFront, popBack, peekFront, peekBack, add (all values of deque), and exit the program  
**/

void mainMenu()
{  
   do
   {
      do
      {
         flag2 = false;
         std::cout << "\n----------Main menu----------\n\nPush front = 1\nPush back = 2\nPop front = 3\nPop back = 4\nPeek front = 5\nPeek back = 6\nAdd all values = 7\nExit program = 8\n\nMake selection here: ";
         std::getline(std::cin >> std::ws, selection);
         if (selection == "1")
         {
            pushFront();
            arraySize++;
         }
         else if (selection == "2")
         {
            arraySize2++;
            pushBack();
         }
         else if (selection == "3")
         {
            popFront();
         }
         else if (selection == "4")
         {
            popBack();
         }
         else if (selection == "5")
         {
            peekFront();
         }
         else if (selection == "6")
         {
            peekBack();
         }
         else if (selection == "7")
         {
            std::cout << "\n" << add() << "\n";
         }
         else if (selection == "8")
         {
            exit(0);
         }
         else
         {
            std::cout << "\n" << selection << " is not a valid option\n";
            flag2 = true;
         }
      } while (flag2);
   } while (selection != "8");
}

main()
{
   mainMenu();
}