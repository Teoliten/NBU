import java.util.*;
import java.lang.*;
import java.io.*;

/*
 * listInput1, representing the array with size of listInput1_size.
 * listInput2, representing the array with size of listInput2_size.
 */
public class Solution {
    public static int countOfElement(int[] listInput1, int[] listInput2) {
        int answer = 0;

        for (int i = 0; i < listInput1.length; i++) {
            boolean unique = true;
            for (int j = 0; j < listInput2.length; j++) {
                if (listInput1[i] == listInput2[j]) {
                    unique = false;
                    break;
                }
            }
            if (unique) {
                answer++;
            }
        }

        for (int i = 0; i < listInput2.length; i++) {
            boolean unique = true;
            for (int j = 0; j < listInput1.length; j++) {
                if (listInput2[i] == listInput1[j]) {
                    unique = false;
                    break;
                }
            }
            if (unique) {
                answer++;
            }
        }

        return answer;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // input for listInput1
        // int listInput1_size = in.nextInt();
        // int listInput1[] = new int[listInput1_size];
        int listInput1[] = { 1, 1, 2, 3, 4, 5, 5, 7, 6, 9, 10 };

        // for (int idx = 0; idx < listInput1_size; idx++) {
        // listInput1[idx] = in.nextInt();
        // }
        // input for listInput2
        // int listInput2_size = in.nextInt();
        // int listInput2[] = new int[listInput2_size];
        int listInput2[] = { 11, 12, 13, 4, 5, 6, 7, 18, 19, 20 };

        // for (int idx = 0; idx < listInput2_size; idx++) {
        // listInput2[idx] = in.nextInt();
        // }

        int result = countOfElement(listInput1, listInput2);
        System.out.print(result);

    }
}