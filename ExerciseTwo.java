package main.java;
import java.util.Scanner;

//Варіант 27. Є дійсна квадратна матриця порядку N. Знайти мінімальний елемент,
//розташований у заштрихованій області.

public class ExerciseTwo {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Введіть розмір матриці: ");
        int n = in.nextInt();
        int[][] matrix = new int[n][n];
        in.close();

        for (int i=0; i < matrix.length; i++){
            for (int j = 0; j < matrix.length; j++){
                matrix[i][j] = (int)(Math.random()*10);
            }
        }

        for (int i=0; i < matrix.length; i++){
            for (int j = 0; j < matrix.length; j++){
                System.out.print(matrix[i][j] + " ");
            }
            System.out.print("\n");
        }

        int min1 = 0;
        int min2 = 0;
        int k = 0;

        if (n%2 != 0){
            k = n/2;
        } else {
            k = n/2-1;
        }

        for (int i = 0; i <= n/2; i++){
            for(int j = i; j < n - i; j++){
                if ((i == 0 && j == 0) || matrix[i][j] <= min1){
                    min1 = matrix[i][j];
                }
            }
        }

        for (int i = n - 1; i > k; i--){
            for(int j = n - i - 1; j < i + 1; j++){
                if ((i == n-1 && j==0) || matrix[i][j] <= min2){
                    min2 = matrix[i][j];
                }
            }
        }

        if (min1 <= min2){
            System.out.println("Мінімальний елемент даної матриці в заданій області = " + min1);
        } else {
            System.out.println("Мінімальний елемент даної матриці в заданій області = " + min2);
        }
    }
}
