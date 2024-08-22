import java.util.Scanner;
// check if two strings are anagrams 
public class App {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.println("Word one:");
        String str1 = s.nextLine();

        System.out.println("Word two:");
        String str2 = s.nextLine();

        if(str1.length() == str2.length())
        {
            boolean answer = IsAnagram(str1, str2);
            System.out.println(answer);
        }
        else
        {
            System.out.println(false);
        }
        
       
    }

    public static boolean IsAnagram(String str1, String str2)
    {
        boolean result = true;

        char[] char1 = str1.toCharArray();
        char[] char2 = str2.toCharArray();

        int wordLen = char1.length;
        //A NAGRAM
        //N A G A R A M
        for(int i = 0; i < wordLen; i++)
        {
            for(int j = 0; j < wordLen; j++)
            {
                if(char1[i] == char2[j])
                {
                    char2[j] = '0';
                    break;
                }
            }
        }

        for(int i = 0; i < wordLen; i++)
        {
            if(char2[i] != '0')
            {
                result = false;
            }
        }

        return result;
    }

}


//other seperate programs
// check if the first letter of a word is uppercase or lowercase
// find the first biggest and second biggest number