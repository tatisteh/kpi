package main.java;
import java.util.Arrays;
import java.util.Scanner;

//Варіант 27. У наданому тексті видалити символ , та порахувати кількість символів, що
//було видалено.

public class ExerciseOne {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int count_comma = 0;

        System.out.println("Введіть текст: ");
        String sentence = in.nextLine();
        System.out.println("Вихідний масив: " + sentence);
        in.close();

        char[] charArray = new char[sentence.length()];

        for (int i = 0; i < sentence.length(); i++) {
            charArray[i] = sentence.charAt(i);
        }

        for (int i = 0; i < sentence.length(); i++){
            if(charArray[i] == ','){
                count_comma += 1;
            }
        }

        char[] charArraySecond = Arrays.copyOf(charArray, charArray.length-count_comma);

        for(int i = 0, j = 0; i < charArray.length; i++) {
            if(charArray[i] != ',') {
                charArraySecond[j++] = charArray[i];
            }
        }

        String secondSentence = new String(charArraySecond);

        System.out.println("Масив без знаку , : " + secondSentence);
        System.out.println("Кількість видаленних символів у масиві: " + count_comma);

    }
}
