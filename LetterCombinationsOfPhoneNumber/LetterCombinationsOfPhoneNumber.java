import java.io.*;
import java.util.*;
import java.lang.*;

public class LetterCombinationsOfPhoneNumber {

    // Implement your solution by completing the below function
    public List<String> letterCombinations(String digits) {

        return new List<String>();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line = in.readLine();
        List<String> combinations = new LetterCombinationsOfPhoneNumber().letterCombinations(line);
        for (String cmbn : combinations)
            System.out.print(cmbn + " ");
    }
}