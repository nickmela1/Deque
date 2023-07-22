import java.util.Scanner;

public class Deque
{
   static int arraySize = 0;
   static int fill = 0;
   static int[] array = new int[arraySize];
   static int[] array2 = new int[arraySize];
   static boolean flag = true;
   static boolean flag2 = false;
   static String yesOrNo = "";
   static String yesOrNo2 = "";
   public static void main(String[] args)
   {
      Scanner scan = new Scanner(System.in);
      System.out.print("\nEnter the size of the deque: ");
      arraySize = scan.nextInt();
      System.out.print("\n");
      fillDeque(arraySize);
      System.out.print("");
      do
      {
         flag2 = false;
         System.out.print("\nWould you like to add to the deque?\ny = yes\nn = no: ");
         yesOrNo = scan.nextLine();
         if (yesOrNo.equals("y") || yesOrNo.equals("Y"))
         {
            flag = false;
            arraySize++;
         }
         else if (yesOrNo.equals("n") || yesOrNo.equals("N"))
         {
            System.exit(0);
         }
         else
         {
            System.out.print("\nMust type y or n\n");
            flag2 = true;
         }
      } while (flag2);
      pushFront();
   }

   public static void pushFront()
   {
      Scanner scan = new Scanner(System.in);
      int toFront = 0;   
      System.out.print("\nWhat would you like to add?: ");
      toFront = scan.nextInt();
      System.out.print("\n");
      array2[0] = toFront;
      System.out.print(array2[0]);
      array[arraySize] = toFront;
      for (int i = 0; i < arraySize; i++)
      {
         System.out.print("\n" + array[i]);    
      }
      do
      {
         flag2 = false;
         System.out.print("\n\nWould you like to add another item to the deque?\ny = yes\nn = no: ");
         yesOrNo2 = scan.nextLine();
         if (yesOrNo2.equals("y") || yesOrNo2.equals("Y"))
         {
            flag = false;
            arraySize++;
         }
         else if (yesOrNo2.equals("n") || yesOrNo2.equals("N"))
         {
            System.exit(0);
         }
         else
         {
            System.out.print("\nMust type y or n");
            flag2 = true;
         }
      } while (flag2);
      pushFront();
   }
   
   public static void fillDeque(int size)
   {
      Scanner scan = new Scanner(System.in);
      for (int i = 0; i < arraySize; i++)
      {
         System.out.print("Fill the array: ");
         fill = scan.nextInt();
         array[i] = fill;
      }
      System.out.print("\n");   
      for (int i = 0; i < arraySize; i++)
      {
         System.out.print(array[i] + "\n"); 
      }
   }
}