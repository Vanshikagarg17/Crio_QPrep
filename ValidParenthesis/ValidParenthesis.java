import java.io.*;
import java.util.*;

public class ValidParenthesis {
    // Implement your solution by completing the below function
    public boolean isValid(String s) {

		return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String parenthesis = in.readLine();
        boolean result = new ValidParenthesis().isValid(parenthesis);
        System.out.print(String.valueOf(result));
    }
}
