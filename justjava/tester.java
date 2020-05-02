import java.util.Scanner;

public class tester{

    public static void main(String[] args){
        
        Scanner x = new Scanner(System.in);

        System.out.println("Enter First Int: ");
        int length = x.nextInt();

        System.out.println("Enter Second Int: ");
        int width = x.nextInt();

        System.out.println("Enter Integer for X at that index: ");
        int value = x.nextInt();

        int board[][] = new int[length][width];
        char pegBoard[][] = new char[length][width];


        
        int number = 0;

        for(int runner = 0; runner < length ; runner++){
            for(int runnerTwo = 0; runnerTwo < width; runnerTwo++){
                board[runner][runnerTwo] = number;

                number++;
            }
        }

        System.out.println();
        System.out.println("Origin Top Left: ");
        System.out.println();


        for(int runner = 0; runner < length ; runner++){
            for(int runnerTwo = 0; runnerTwo < width; runnerTwo++){
                System.out.print(" " + board[runner][runnerTwo] + " ");
            }
            System.out.println();
        }

        System.out.println();

        System.out.println();
        System.out.println("Origin Bottom Left: ");
        System.out.println();


        for(int runner = length - 1 ; runner >= 0  ; runner--){
            for(int runnerTwo = 0; runnerTwo < width; runnerTwo++){
                System.out.print(" " + board[runner][runnerTwo] + " ");
            }
            System.out.println();
        }


        System.out.println();
        System.out.println("Origin Bottom Right: ");
        System.out.println();


        for(int runner = length - 1 ; runner >= 0  ; runner--){
            for(int runnerTwo = width - 1; runnerTwo >= 0; runnerTwo--){
                System.out.print(" " + board[runner][runnerTwo] + " ");
            }
            System.out.println();
        }

        System.out.println();
        System.out.println("Origin Top Right: ");
        System.out.println();


        for(int runner = 0 ; runner < length  ; runner++){
            for(int runnerTwo = width - 1; runnerTwo >= 0; runnerTwo--){
                System.out.print(" " + board[runner][runnerTwo] + " ");
            }
            System.out.println();
        }

        System.out.println();
        System.out.println();
        System.out.println();

    while(true){

        System.out.println("Enter Integer for X at that index: ");
        value = x.nextInt();

            for(int runner = 0; runner < length ; runner++){
                for(int runnerTwo = 0; runnerTwo < width; runnerTwo++){

                    if((runner + runnerTwo) % value == 0){
                        pegBoard[runner][runnerTwo] = 'X';
                    }else{
                        pegBoard[runner][runnerTwo] = 'O';
                    }
                    number++;
                }
            }


            for(int runner = 0; runner < length ; runner++){
                for(int runnerTwo = 0; runnerTwo < width; runnerTwo++){
                    System.out.print(" " + pegBoard[runner][runnerTwo] + " ");
                }
                System.out.println();
            }


        }

    }



}