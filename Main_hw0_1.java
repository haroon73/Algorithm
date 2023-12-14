/*
 * INSTRUCTION:
 *     This is a Java starting code for hw0_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "Main.java".
 *     But rename it to "Main_hw0_1.java".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Main_hw0_1.java
 * Abstract: This program find the sum of two integer numbers and find the differences of two interger numbers where using if condational statements to find that number.
 * ID: 7263
 * Name: Mohammad Haroon
 * Date: 01/24/2023
 */
 import java.util.Scanner;
class Main 
{
    public static void main(String[] args) {

     Integer num1 , num2 , sum , diff;

        Scanner sc = new Scanner(System.in);
        num1 = sc.nextInt();
        num2 = sc.nextInt();

        sum = (num1 + num2);

        if(num1 > num2){
            diff = (num1 - num2);
        }
        else if(num2 > num1){
            diff =(num2 - num1);
        }
        else{
            diff = 0;
        }
        System.out.println("SUM:" + sum);
        System.out.println("DIFF:" + diff);



      
    }
}

